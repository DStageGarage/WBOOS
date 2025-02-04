// =========================================================================================
// === DStage WBOOS - SLC Free tribute =====================================================
// =========================================================================================
// This program is a heavily modified version of the 
// 14point7 SLC Free open wideband oxygen sensor controller
//
// Version 1.2.0 2025.02.02
// 
// email: dstagegarage@gmail.com
// YT: www.youtube.com/DStageGarage
// GitHub: https://github.com/DStageGarage/WBOOS/
// =========================================================================================

//----------------------------------------------------------------------------
// C main line
//----------------------------------------------------------------------------
#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"    // PSoC API definitions for all User Modules
extern BYTE ADC_Counter; //Variable Declared in ADCININT.asm
extern BYTE Ri_Max_x1; //Variable Declared in ADCININT.asm
extern BYTE Ri_Min_x1; //Variable Declared in ADCININT.asm
extern BYTE ip_x1; //Variable Declared in ADCININT.asm
extern BYTE ADC_IF; //Variable Declared in ADCININT.asm
extern BYTE Sleep_Counter; //Variable Declared in SleepTimerINT.asm

#define Vout_Lookup_Counter_Set 25

//============================================
// Configure system here
//============================================
// set how often display gets refreshed, 50 is a default value meaning roughly 50x2ms=100ms or 10 times per second
#define LCD_Counter_Set 50

// define outout signal, Lin_Out (wide band) and NB_Out (narrow band) can be both present at once
#define Lin_Out
#define NB_Out

// define display type and content following these guidlines:
//   - LCD Lmbda and AFR digits can be used at the same time but without Lambda/Temperature Graph
//   - LCD Lambda/Temperature Graph cannot be used at the same time
//   - LCD Temperature digits can be used together with Lambda/AFR digits
//   - LED and LCD cannot be used at the same time
//   - LED AFR and Lambda can be used at the same time and switched with a pin
//   - comment out #define for unused options
// #define LCD_Lambda_Graph
 #define LCD_AFR_digits
#define LCD_Lambda_digits
//#define LCD_Temperature_Graph
 #define LCD_Temperature_digits
//#define DStage_logo
//#define LED_AFR
//#define LED_Lambda

// Define port/pin for LED display controller TM1637
#define DIO_PORT 1
#define DIO_PIN 0
#define CLK_PORT 1
#define CLK_PIN 1
#define SWITCH_PORT 1
#define SWITCH_PIN 7
//============================================

#define SWPIN (1 << SWITCH_PIN)
#if SWITCH_PORT == 1
	#define SWPORT PRT1DR
	#define	SWDM2 PRT1DM2
	#define	SWDM1 PRT1DM1
	#define	SWDM0 PRT1DM0
#elif SWITCH_PORT == 2
	#define SWPORT PRT2DR
	#define	SWDM2 PRT2DM2
	#define	SWDM1 PRT2DM1
	#define	SWDM0 PRT2DM0
#else
	#define SWPORT PRT0DR
	#define	SWDM2 PRT0DM2
	#define	SWDM1 PRT0DM1
	#define	SWDM0 PRT0DM0
#endif


//#define PID_Tune
#define Ri_Filter_Strength 4
#define ip_Filter_Strength 4

#ifdef PID_Tune
	INT Ri_Mid_Target= 286;//271; //
	INT Ia_PID_Kp = 25; //35;
	INT Ia_PID_Ki = 4; //8;
	INT Ia_Output_Bias = 256;
	INT Ri_Delta_Target=143; //PID Target peak to peak Voltage of Nermest Cell
	INT Heater_PID_Kp =-72;
	INT Heater_PID_Ki =-4;
	INT Heater_PID_Output_Bias =128;
#else
	#define Ri_Mid_Target 286 //271 //256+14.769 = 2.53v = 2.08v(VGND) + 0.45v, PID Target Voltage of Nermest Cell
	#define Ia_PID_Kp 25
	#define Ia_PID_Ki 4
	#define Ia_Output_Bias 256
	#define Ri_Delta_Target 143 //PID Target peak to peak Voltage of Nermest Cell
	#define Heater_PID_Kp -72
	#define Heater_PID_Ki -4
	#define Heater_PID_Output_Bias 128
#endif

#ifdef Lin_Out
	#define ip_to_Vout_Lookup_Start 135
	#define ip_to_Vout_Lookup_Size 158
	const BYTE ip_to_Vout_Lookup[ip_to_Vout_Lookup_Size] = {0,1,1,2,3,4,4,5,6,7,8,8,9,10,11,12,12,13,14,15,16,17,17,18,19,20,21,22,22,23,24,25,26,27,27,28,29,30,31,32,33,34,34,35,36,37,38,39,40,41,42,43,44,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,76,77,78,79,80,81,82,83,84,86,87,88,89,90,91,92,94,95,96,97,98,100,101,102,103,105,106,107,108,110,111,112,113,115,116,117,119,120,123,126,129,132,135,138,141,144,147,151,154,157,161,164,168,171,175,178,182,186,190,194,197,201,206,210,214,218,222,227,231,236,240,245,250,255}; 
#endif

#ifdef LCD_Lambda_Graph
	#define ip_to_Lambda_Lookup_Start 135
	#define ip_to_Lambda_Lookup_Size 158
	const BYTE ip_to_Graph_Lookup[ip_to_Lambda_Lookup_Size]={1,8,8,9,9,9,9,9,10,10,10,10,10,11,11,11,11,12,12,12,12,12,13,13,13,13,14,14,14,14,14,15,15,15,15,16,16,16,16,16,17,17,17,17,18,18,18,18,19,19,19,19,20,20,20,20,21,21,21,21,22,22,22,22,23,23,23,23,24,24,24,25,25,25,25,26,26,26,26,27,27,27,28,28,28,28,29,29,29,30,30,30,31,31,31,31,32,32,32,33,33,33,34,34,34,35,35,35,36,36,36,37,37,37,38,38,38,39,39,39,40,40,41,42,42,43,44,45,46,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,70,71,72,73,75,80};
												 // lambda = 0.68  0.69      0.70           0.71        0.72           0.73        0.74           0.75        0.76           0.77        0.78        0.79        0.8         0.81        0.82           0.83     0.84     0.85        0.86        0.87     0.88        0.89     0.90     0.91        0.92     0.93     0.94     0.95     0.96     0.97     0.98     0.99     1.00
												 // AFR    = 10.0  10.14     10.3           10.44       10.58          10.73       10.88          11.03
#endif

#if defined LCD_AFR_digits || defined LED_AFR 
	#define ip_to_AFR_Lookup_Start 135
	#define ip_to_AFR_Lookup_Size 158
	const BYTE ip_to_AFR_Lookup[ip_to_AFR_Lookup_Size] = {0xFC,0x00,0x00,0x01,0x01,0x02,0x02,0x02,0x02,0x03,0x03,0x03,0x04,0x04,0x04,0x05,0x05,0x05,0x05,0x06,0x06,0x07,0x07,0x07,0x07,0x08,0x08,0x09,0x09,0x09,0x09,
														  0x10,0x10,0x11,0x11,0x11,0x12,0x12,0x12,0x13,0x13,0x13,0x13,0x14,0x14,0x15,0x15,0x15,0x16,0x16,0x16,0x17,0x17,0x17,0x18,0x18,0x18,0x19,0x19,
														  0x20,0x20,0x20,0x21,0x21,0x22,0x22,0x22,0x23,0x23,0x24,0x24,0x24,0x25,0x25,0x25,0x26,0x26,0x27,0x27,0x27,0x28,0x28,0x29,0x29,
														  0x30,0x30,0x31,0x31,0x31,0x32,0x32,0x33,0x33,0x34,0x34,0x35,0x35,0x35,0x36,0x36,0x37,0x37,0x38,0x38,0x38,0x39,
														  0x40,0x40,0x40,0x41,0x42,0x42,0x42,0x43,0x44,0x44,0x44,0x45,0x45,0x46,0x47,0x47,0x48,0x49,
														  0x51,0x52,0x53,0x54,0x55,0x56,0x58,0x59,
														  0x60,0x62,0x63,0x64,0x66,0x67,0x69,
														  0x70,0x71,0x73,0x75,0x76,0x77,0x79,
														  0x81,0x82,0x84,0x85,0x87,0x89,
														  0x91,0x93,0x94,0x96,0x98,
														  0xFE}; 
#endif

#if defined LCD_Lambda_digits || defined LED_Lambda
	#define ip_to_LambdaD_Lookup_Start 135
	#define ip_to_LambdaD_Lookup_Size 158
	const BYTE ip_to_Lambda_Lookup[ip_to_LambdaD_Lookup_Size]= {0xFC,0x68,0x68,0x69,0x69,0x69,0x69,0x69,
																0x70,0x70,0x70,0x70,0x70,0x71,0x71,0x71,0x71,0x72,0x72,0x72,0x72,0x72,0x73,0x73,0x73,0x73,0x74,0x74,0x74,0x74,0x74,0x75,0x75,0x75,0x75,0x76,0x76,0x76,0x76,0x76,0x77,0x77,0x77,0x77,0x78,0x78,0x78,0x78,0x79,0x79,0x79,0x79,
																0x80,0x80,0x80,0x80,0x81,0x81,0x81,0x81,0x82,0x82,0x82,0x82,0x83,0x83,0x83,0x83,0x84,0x84,0x84,0x85,0x85,0x85,0x85,0x86,0x86,0x86,0x86,0x87,0x87,0x87,0x88,0x88,0x88,0x88,0x89,0x89,0x89,
																0x90,0x90,0x90,0x91,0x91,0x91,0x91,0x92,0x92,0x92,0x93,0x93,0x93,0x94,0x94,0x94,0x95,0x95,0x95,0x96,0x96,0x96,0x97,0x97,0x97,0x98,0x98,0x98,0x99,0x99,0x99,
																0x00,0x00,0x01,0x02,0x02,0x03,0x04,0x05,0x06,0x06,0x07,0x08,0x09,
																0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,
																0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,
																0x30,0x31,0x32,0x33,0x35,
																0xFE};
#endif

#ifdef LCD_Temperature_Graph
	#define Ri_Delta_to_Temperature_C_Start 113
	#define Ri_Delta_to_Temperature_C_Size 75
	const BYTE Ri_Delta_to_Graph[Ri_Delta_to_Temperature_C_Size]={80,78,77,75,74,73,71,70,68,67,65,64,63,61,60,59,58,56,55,54,52,51,50,49,48,46,45,44,43,42,41,40,39,37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,18,17,16,15,14,13,12,11,11,10,9,8,7,6,5,5,4,3,2,1,1,0};
#endif

#ifdef LCD_Temperature_digits
	#define Ri_Delta_to_Temperature_C_dig_Start 113
	#define Ri_Delta_to_Temperature_C_dig_Size 75
	const BYTE Ri_Delta_to_dig[Ri_Delta_to_Temperature_C_dig_Size]={0xFE,
																	0x18,0x17,0x15,0x14,0x13,0x11,0x10,
																	0x08,0x07,0x05,0x04,0x03,0x01,0x00,
																	0x99,0x98,0x96,0x95,0x94,0x92,0x91,0x90,
																	0x89,0x88,0x86,0x85,0x84,0x83,0x82,0x81,0x80,
																	0x79,0x77,0x76,0x75,0x74,0x73,0x72,0x71,0x70,
																	0x69,0x68,0x67,0x66,0x65,0x64,0x63,0x62,0x61,0x60,
																	0x59,0x58,0x58,0x57,0x56,0x55,0x54,0x53,0x52,0x51,0x51,0x50,
																	0x49,0x48,0x47,0x46,0x45,0x45,0x44,0x43,0x42,0x41,0x40,0xFC,};
#endif

#if defined LED_AFR || defined LED_Lambda
	void TM1637_init(void);
	void TM1637_setBrightness(BYTE, BYTE);
	void TM1637_setSegments(BYTE*, BYTE, BYTE);
	void TM1637_clear(void);
	void TM1637_showNumberDec(int, BYTE, BYTE, BYTE);
	void TM1637_showNumberDecEx(int, BYTE, BYTE, BYTE, BYTE);
	void TM1637_showNumberHexEx(unsigned int, BYTE, BYTE, BYTE, BYTE);
	void TM1637_showNumberBaseEx(BYTE, unsigned int, BYTE, BYTE, BYTE, BYTE);
	void TM1637_start(void);
	void TM1637_stop(void);
	BYTE TM1637_writeByte(BYTE);
	void TM1637_showDots(BYTE, BYTE*);
	BYTE TM1637_encodeDigit(BYTE);
	
	//      A
	//     ---
	//  F |   | B
	//     -G-
	//  E |   | C
	//     ---
	//      D
	const BYTE digitToSegment[] = {
	// XGFEDCBA
	0b00111111,    // 0
	0b00000110,    // 1
	0b01011011,    // 2
	0b01001111,    // 3
	0b01100110,    // 4
	0b01101101,    // 5
	0b01111101,    // 6
	0b00000111,    // 7
	0b01111111,    // 8
	0b01101111,    // 9
	//0b01110111,    // A
	//0b01111100,    // b
	//0b00111001,    // C
	//0b01011110,    // d
	//0b01111001,    // E
	//0b01110001     // F
	};
#endif

INT Ri_Mid_Error_Sum=0;
INT Ri_Mid;
INT Ri_Delta_Error_Sum=0;
INT Ri_Delta;
#define Ia_PID_Counter_Set 1
#define Heatup_Counter_Set 100
#define Heater_PID_Counter_Set 25
BYTE Heatup_Heater_Output=100;

INT Ri_Delta_Error;
INT Heater_Output;
INT Heater_Pout;
INT Heater_Iout;

//PID Controller, Input is Ri_Delta (The Peak to peak voltage on the Vs Port of the sensor) output is PWM8_Heater, PWM8_Heater is controlled such that Ri_Delta is maintained at 80 (80 =750C)
//Only a PI controller is used as adding the D term does not effect performance 
//Everything is inflated by a factor of 4 so that floating point is avioded
void Heater_PID(void) // Ned to run this when counter >50
{

	Ri_Delta_Error=Ri_Delta_Target-Ri_Delta;
	//Put limits on Error so PID does not go Fubar, and also so that the worst case multiplication does not overflow
	if (Ri_Delta_Error>(-127*16/Heater_PID_Kp))
	{
		Ri_Delta_Error=(-127*16/Heater_PID_Kp); // -> 28, used to be 56...
	}
	if (Ri_Delta_Error<(127*16/Heater_PID_Kp))
	{
		Ri_Delta_Error=(127*16/Heater_PID_Kp); // -> -28, used to be -56...
	}
	Heater_Pout=(Heater_PID_Kp*Ri_Delta_Error)/16;
	Ri_Delta_Error_Sum=Ri_Delta_Error_Sum+Ri_Delta_Error;
	//If the sensor is too hot, then disreguard the Integratal contribution and just use the proportional to quickly correct the sensor temperature
	/*
	if((Ri_Delta<60)&&(Ri_Delta_Error_Sum>0))
	{
		Ri_Delta_Error_Sum=0;
	}
	*/
	//Put limits on Error so PID does not go Fubar, and also so that the worst case multiplication does not overflow
	if (Ri_Delta_Error_Sum>(-127*16/Heater_PID_Ki))
	{
		Ri_Delta_Error_Sum=(-127*16/Heater_PID_Ki); // -> 508, used to be 1024...
	}
	if (Ri_Delta_Error_Sum<(127*16/Heater_PID_Ki))
	{
		Ri_Delta_Error_Sum=(127*16/Heater_PID_Ki); // -> -508, used to be -1024...
	}
	Heater_Iout=(Heater_PID_Ki*Ri_Delta_Error_Sum)/16;
	if (Heatup_Heater_Output<255) // if Heatup_Heater_Output is < 255 that means the unit just turned on and to give control to the heatup routine
	{
		Heater_Output=Heatup_Heater_Output;	
	}
	else
	{	
		Heater_Output=Heater_PID_Output_Bias+Heater_Pout+Heater_Iout;			
	}
	//Heater_Output=Heater_PID_Output_Bias+Heater_Pout+Heater_Iout;	
	if (Heater_Output<0)
	{
		Heater_Output=0;
	}
	if (Heater_Output>255)
	{
		Heater_Output=255;
	}


	PWM8_Heater_WritePulseWidth(Heater_Output);
	//PWM8_Heater_WritePulseWidth(200);
}

INT Ri_Mid_Error;
INT Ia_Output;
INT Ia_Pout;
INT Ia_Iout;
//PID Controller, Input is Ri_Mid (The average voltage on the Vs Port of the sensor) output is DAC9_Ia, DAC9_Ia sink/sources current to the Sensor pump cell such that Ri_Mid is is the same voltage as Vref
//Only a PI controller is used as adding the D term does not effect performance 
//Everything is inflated by a factor of 4 so that floating point is avioded
void Ia_PID(void)
{


	Ri_Mid_Error=Ri_Mid_Target-Ri_Mid;
	//Put limits on Error so PID does not go Fubar, and also so that the worst case multiplication does not overflow
	if (Ri_Mid_Error>(255*16/Ia_PID_Kp))
	{
		Ri_Mid_Error=(255*16/Ia_PID_Kp); // 163
	}
	if (Ri_Mid_Error<(-255*16/Ia_PID_Kp))
	{
		Ri_Mid_Error=(-255*16/Ia_PID_Kp); // -163
	}
	Ia_Pout=(Ia_PID_Kp*Ri_Mid_Error)/16;
	Ri_Mid_Error_Sum=Ri_Mid_Error_Sum+Ri_Mid_Error;
	//Put limits on Error so PID does not go Fubar, and also so that the worst case multiplication does not overflow
	if (Ri_Mid_Error_Sum>(255*16/Ia_PID_Ki))
	{
		Ri_Mid_Error_Sum=(255*16/Ia_PID_Ki); // 1020
	}
	if (Ri_Mid_Error_Sum<(-255*16/Ia_PID_Ki))
	{
		Ri_Mid_Error_Sum=(-255*16/Ia_PID_Ki); // -1020
	}
	Ia_Iout=(Ia_PID_Ki*Ri_Mid_Error_Sum)/16;
	Ia_Output=Ia_Output_Bias+Ia_Pout+Ia_Iout;
	//9 Bit Dac so only 0-511 is allowed, for some reason i put the limit at 510, I foget exactly why.
	if (Ia_Output<0)
	{
		Ia_Output=0;
	}
	if (Ia_Output>510)
	{
		Ia_Output=510;
	}
	DAC9_Ia_WriteStall (Ia_Output);
	//DAC9_Ia_WriteStall (256);
}
INT IIR_Int(INT Vin, INT Vout, BYTE A)
{
	return (Vout + (Vin - Vout)/A);
}


BYTE Ia_PID_Counter=0;
BYTE Vout_Lookup_Counter=0;
BYTE Heater_PID_Counter=0;
BYTE LCD_Counter=0;
BYTE Heatup_Counter=0;
INT Ri_Min,Ri_Max;
INT ip,ip_Justified;
BYTE Lambda_x100;
INT LSU_Temperature_C;
//char Str1[] = "Lambda=x.xx";
//char Str2[] = "Temperature=xxxC"; 
void main(void)
{
	unsigned long temp_ulong;
	INT temp_int,temp_int2;
	BYTE temp_byte;
	
	#if defined LED_AFR || defined LED_Lambda
		// empty, 1, -, -
		BYTE digits[4] = {0b00000000, 0b00000110, 0b01000000, 0b01000000};
	#endif
	
	AMUX4_0_InputSelect(AMUX4_0_PORT0_1);        
   	AMUX4_1_InputSelect(AMUX4_1_PORT0_0);
   	INSAMP_Start(INSAMP_LOWPOWER); 
    ADCINC_Start(ADCINC_HIGHPOWER);      
   	DAC9_Ia_Start(DAC9_Ia_HIGHPOWER);
	DAC6_VGND_Start(DAC6_VGND_MEDPOWER);
	DAC6_VGND_WriteStall (31);
    PWM8_Vout_DisableInt();  
    PWM8_Vout_Start();     
    PWM8_Heater_DisableInt();  
    PWM8_Heater_Start();
	PWM8_NB_Out_DisableInt();  
    PWM8_NB_Out_Start(); 
	ADCINC_GetSamples(0);
	SleepTimer_Start();  
   	SleepTimer_SetInterval(SleepTimer_512_HZ);  
   	SleepTimer_EnableInt();   
	M8C_EnableGInt ;  
	
	// initialize LCD only when needed (DStage WBOOS can be used with LED or without any display)
	#if defined LCD_AFR_digits || defined LCD_Lambda_digits || defined LCD_Temperature_digits || defined DStage_logo || defined LCD_Lambda_Graph || defined LCD_Temperature_Graph
		LCD_Start();                  // Initialize LCD
		LCD_InitBG(LCD_SOLID_BG);
	#endif

	#ifdef LCD_AFR_digits
		LCD_Position(0,0);
		LCD_PrCString("AFR: 1\0");
	#endif
	
	#ifdef LCD_Lambda_digits
		#ifndef LCD_AFR_digits
			LCD_Position(0,0);
			LCD_PrCString("LAM: 0\0");
		#else
			LCD_Position(1,0);
			LCD_PrCString("LAM: 0\0");
		#endif
	#endif
	
	#ifdef LCD_Temperature_digits
		#if defined LCD_Lambda_Graph || (defined LCD_AFR_digits && defined LCD_Lambda_digits)
			LCD_Position(0,10);
			LCD_PrCString("T:\0");
			LCD_Position(0,15);
			LCD_WriteData(0xDF); // degre
		#else
			LCD_Position(1,0);
			LCD_PrCString("TMP:\0");
			LCD_Position(1,8);
			LCD_WriteData(0xDF); // degre
		#endif
	#endif
	
	#ifdef DStage_logo
		#ifndef LCD_Lambda_Graph
			LCD_Position(0,10);
			LCD_PrCString("DStage\0");
			LCD_Position(1,10);
			LCD_PrCString("Garage\0");
		#endif
	#endif
	
	#if defined LED_AFR || defined LED_Lambda
		TM1637_init();
		TM1637_setSegments(digits, 4, 0);
		//TM1637_showNumberDec(123, 0, 3, 1);
	#endif

	for(;;)
    {
		temp_ulong++;
		if ((ADC_IF&1)==1)
		{
			ADC_IF=ADC_IF&254;
			Ri_Min=IIR_Int(Ri_Min_x1*2,Ri_Min,Ri_Filter_Strength);
			Ri_Delta=Ri_Max-Ri_Min;
			Ri_Mid=(Ri_Max+Ri_Min)/2;
		}
		if ((ADC_IF&2)==2)
		{
			ADC_IF=ADC_IF&253;
			Ri_Max=IIR_Int(Ri_Max_x1*2,Ri_Max,Ri_Filter_Strength);
			Ri_Delta=Ri_Max-Ri_Min;
			Ri_Mid=(Ri_Max+Ri_Min)/2;
		}
		if ((ADC_IF&4)==4)
		{
			ADC_IF=ADC_IF&251;
			ip=IIR_Int(ip_x1*2,ip,ip_Filter_Strength);
		}
		Ia_PID_Counter+=Sleep_Counter;
		Heater_PID_Counter+=Sleep_Counter;
		Heatup_Counter+=Sleep_Counter;
		Vout_Lookup_Counter+=Sleep_Counter;
		LCD_Counter+=Sleep_Counter;
		Sleep_Counter=0;
		if (Ia_PID_Counter>Ia_PID_Counter_Set)
		{
			Ia_PID_Counter=0;
			Ia_PID();
		}
		if (Heater_PID_Counter>Heater_PID_Counter_Set)
		{
			Heater_PID_Counter=0;
			Heater_PID();
		}
		if (Vout_Lookup_Counter>Vout_Lookup_Counter_Set)
		{
			Vout_Lookup_Counter=0;
			temp_int=ip-ip_to_Vout_Lookup_Start;
			if (temp_int<0)
			{
				temp_int=0;
			}
			if (temp_int>(ip_to_Vout_Lookup_Size-1))
			{
				temp_int=(ip_to_Vout_Lookup_Size-1);
			}
			PWM8_Vout_WritePulseWidth(ip_to_Vout_Lookup[temp_int]);
			
			#ifdef NB_Out
				temp_byte=23;//0.45v
				if (ip<251) // 251 =0.9797787392968
				{
					temp_byte=46; //0.9v
					
				}
				if (ip>259) //259 = 1.02295956968912
				{
					temp_byte=0; //0v
				}
				PWM8_NB_Out_WritePulseWidth(temp_byte);
			#endif
			
		}
		if (LCD_Counter>LCD_Counter_Set)
		{
			LCD_Counter=0;
			
			#ifdef LCD_Lambda_Graph
				temp_int=ip-ip_to_Lambda_Lookup_Start;
				if (temp_int<0)
				{
					temp_int=0;
				}
				if (temp_int>(ip_to_Lambda_Lookup_Size-1))
				{
					temp_int=(ip_to_Lambda_Lookup_Size-1);
				}
				Lambda_x100=ip_to_Graph_Lookup[temp_int];
				
				// if both numeric AFR and Lambda bargraph is to be used put bargraph in second row
				#ifdef LCD_AFR_digits
					LCD_DrawBG(1,0,16,Lambda_x100);
				#else
					#ifdef LCD_Lambda_digits
						LCD_DrawBG(1,0,16,Lambda_x100);
					#else
						LCD_DrawBG(0,0,16,Lambda_x100);
					#endif
				#endif
			#endif
			
			#ifdef LCD_AFR_digits
				temp_int=ip-ip_to_AFR_Lookup_Start;
				if (temp_int<0)
				{
					temp_int=0;
				}
				if (temp_int>(ip_to_AFR_Lookup_Size-1))
				{
					temp_int=(ip_to_AFR_Lookup_Size-1);
				}
				temp_byte = temp_int;	// code size optimization
				
				// AFR integer part (temporarly first digit is always "1")
				LCD_Position(0,6);
				LCD_WriteData('0' + ((ip_to_AFR_Lookup[temp_byte] & 0xF0) >> 4));
				
				// AFR decimal point part
				LCD_WriteData('.');
				LCD_WriteData('0' + (ip_to_AFR_Lookup[temp_byte] & 0x0F));
			#endif
			
			#ifdef LCD_Lambda_digits
				temp_int=ip-ip_to_LambdaD_Lookup_Start;	
				if (temp_int<0)
				{
					temp_int=0;
				}
				if (temp_int>(ip_to_LambdaD_Lookup_Size-1))
				{
					temp_int=(ip_to_LambdaD_Lookup_Size-1);
				}
				temp_byte = temp_int;	// code size optimization
				
				// Lambda int part	
				#ifndef LCD_AFR_digits
					LCD_Position(0,5);
				#else
					LCD_Position(1,5);
				#endif
				if (temp_byte < 120) 	// 120th value is equal to lambda 1.00
					Lambda_x100 = '0';
				else
					Lambda_x100 = '1';
				LCD_WriteData(Lambda_x100);
				
				// Lambda 0.x part
				LCD_WriteData('.');
				LCD_WriteData('0' + ((ip_to_Lambda_Lookup[temp_byte] & 0xF0) >> 4));
				
				// Lambda 0.0x part
				LCD_WriteData('0' + (ip_to_Lambda_Lookup[temp_byte] & 0x0F));
			#endif
			
			#ifdef LCD_Temperature_Graph
				temp_int=Ri_Delta-Ri_Delta_to_Temperature_C_Start;
				if (temp_int<0)
				{
					temp_int=0;
				}
				if (temp_int>(Ri_Delta_to_Temperature_C_Size-1))
				{
					temp_int=(Ri_Delta_to_Temperature_C_Size-1);
				}
				LSU_Temperature_C=Ri_Delta_to_Graph[temp_int];
				LCD_DrawBG(1,0,16,LSU_Temperature_C);
			#endif
			
			#ifdef LCD_Temperature_digits
				temp_int=Ri_Delta-Ri_Delta_to_Temperature_C_dig_Start;
				if (temp_int<0)
				{
					temp_int=0;
				}
				if (temp_int>(Ri_Delta_to_Temperature_C_dig_Size-1))
				{
					temp_int=(Ri_Delta_to_Temperature_C_dig_Size-1);
				}
				temp_byte = temp_int;	// code size optimization
	
				// Temperature hundreds part (7 or 8)	
				#if defined LCD_Lambda_Graph || (defined LCD_AFR_digits && defined LCD_Lambda_digits)
					LCD_Position(0,12);
				#else
					LCD_Position(1,5);
				#endif

				if (temp_byte < 15)
					Lambda_x100 = '8';
				else
					Lambda_x100 = '7';
				
				LCD_WriteData(Lambda_x100);
						
				// Temperature tens part
				LCD_WriteData('0' + ((Ri_Delta_to_dig[temp_int] & 0xF0) >> 4));
				
				// Temperature ones part
				LCD_WriteData('0' + (Ri_Delta_to_dig[temp_int] & 0x0F));
			#endif
			
			#ifdef LED_AFR		
				temp_int=ip-ip_to_AFR_Lookup_Start;
				if (temp_int<0)
				{
					temp_int=0;
				}
				if (temp_int>(ip_to_AFR_Lookup_Size-1))
				{
					temp_int=(ip_to_AFR_Lookup_Size-1);
				}
				temp_byte = temp_int;	// code size optimization
				
				/*// AFR integer part (temporarly first digit is always "1"), add dot
				digits[0] = digitToSegment[(ip_to_AFR_Lookup[temp_byte] & 0xF0) >> 4] | 0x80;
				
				// AFR decimal part
				digits[1] = digitToSegment[ip_to_AFR_Lookup[temp_byte] & 0x0F];
				
				TM1637_setSegments(digits, 2, 2);*/
				
				#ifdef LED_Lambda
					if ((SWPORT & SWPIN) == 0)
					{
						// AFR integer part (temporarly first digit is always "1"), add dot
						digits[1] = digitToSegment[(ip_to_AFR_Lookup[temp_byte] & 0xF0) >> 4] | 0x80;
						
						// AFR decimal part
						digits[2] = digitToSegment[ip_to_AFR_Lookup[temp_byte] & 0x0F];
						
						digits[0] = digitToSegment[1]; // temporarly first digit is always "1"
						TM1637_setSegments(digits, 3, 1);
					}	
				#else
					// AFR integer part (temporarly first digit is always "1"), add dot
					digits[0] = digitToSegment[(ip_to_AFR_Lookup[temp_byte] & 0xF0) >> 4] | 0x80;
				
					// AFR decimal part
					digits[1] = digitToSegment[ip_to_AFR_Lookup[temp_byte] & 0x0F];
				
					TM1637_setSegments(digits, 2, 2);
				#endif
			#endif
			
			#ifdef LED_Lambda
				temp_int=ip-ip_to_LambdaD_Lookup_Start;	
				if (temp_int<0)
				{
					temp_int=0;
				}
				if (temp_int>(ip_to_LambdaD_Lookup_Size-1))
				{
					temp_int=(ip_to_LambdaD_Lookup_Size-1);
				}
				temp_byte = temp_int;	// code size optimization
				
				#ifdef LED_AFR
					if ((SWPORT & SWPIN) != 0)
					{
						// Lambda int part, add dot
						if (temp_byte < 120) 	// 120th value is equal to lambda 1.00
							digits[0] = digitToSegment[0] | 0x80;
						else
							digits[0] = digitToSegment[1] | 0x80;
					
						// Lambda 0.x0 part
						digits[1] = digitToSegment[(ip_to_Lambda_Lookup[temp_byte] & 0xF0) >> 4];
					
						// Lambda 0.0x part
						digits[2] = digitToSegment[ip_to_Lambda_Lookup[temp_byte] & 0x0F];
							
						TM1637_setSegments(digits, 3, 1);
					}
				#else
					// Lambda int part, add dot
					if (temp_byte < 120) 	// 120th value is equal to lambda 1.00
						digits[0] = digitToSegment[0] | 0x80;
					else
						digits[0] = digitToSegment[1] | 0x80;
					
					// Lambda 0.x0 part
					digits[1] = digitToSegment[(ip_to_Lambda_Lookup[temp_byte] & 0xF0) >> 4];
					
					// Lambda 0.0x part
					digits[2] = digitToSegment[ip_to_Lambda_Lookup[temp_byte] & 0x0F];
							
					TM1637_setSegments(digits, 3, 1);
				#endif
			#endif
		}
		if (Heatup_Heater_Output<255)
		{   
			if (Heatup_Counter>Heatup_Counter_Set)
			{
				Heatup_Counter=0;
				Heatup_Heater_Output++;
			}
			if ((Ri_Min>50) && (Ri_Max<475) && (Ri_Delta<Ri_Delta_Target))
			{
				Heatup_Heater_Output=255;
				Ri_Delta_Error_Sum=0;
			}
		}
	}
}

#if defined LED_AFR || defined LED_Lambda
// ================================================================================
// === TM1637 control functions ===================================================
// ================================================================================

//  Modified (heavily) for PSoC 1 CY8C24423-24 by: dstagegarage@gmail.com
//  Original author for Arduino: avishorp@gmail.com
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

// ----------------------------------------
#if DIO_PORT == 1
	#define DIOPORT PRT1DR
	#define	DIODM2 PRT1DM2
	#define	DIODM1 PRT1DM1
	#define	DIODM0 PRT1DM0
#elif DIO_PORT == 2
	#define DIOPORT PRT2DR
	#define	DIODM2 PRT2DM2
	#define	DIODM1 PRT2DM1
	#define	DIODM0 PRT2DM0
#else
	#define DIOPORT PRT0DR
	#define	DIODM2 PRT0DM2
	#define	DIODM1 PRT0DM1
	#define	DIODM0 PRT0DM0
#endif
#if CLK_PORT == 1
	#define CLKPORT PRT1DR
	#define	CLKDM2 PRT1DM2
	#define	CLKDM1 PRT1DM1
	#define	CLKDM0 PRT1DM0
#elif CLK_PORT == 2
	#define CLKPORT PRT2DR
	#define	CLKDM2 PRT2DM2
	#define	CLKDM1 PRT2DM1
	#define	CLKDM0 PRT2DM0
#else
	#define CLKPORT PRT0DR
	#define	CLKDM2 PRT0DM2
	#define	CLKDM1 PRT0DM1
	#define	CLKDM0 PRT0DM0
#endif
#define DIOPIN (1 << DIO_PIN)
#define CLKPIN (1 << CLK_PIN)
#define TM1637_CLK_L CLKPORT &= ~CLKPIN
#define TM1637_CLK_H CLKPORT |= CLKPIN
#define TM1637_DIO_L DIOPORT &= ~DIOPIN
#define TM1637_DIO_H DIOPORT |= DIOPIN
#define TM1637_DIO_READ DIOPORT & DIOPIN
/*#define IOPIN7	0x80
#define TM1637_CLK_L PRT1DR &= ~IOPIN7
#define TM1637_CLK_H PRT1DR |= IOPIN7
#define TM1637_DIO_L PRT2DR &= ~IOPIN7
#define TM1637_DIO_H PRT2DR |= IOPIN7
#define TM1637_DIO_READ PRT2DR & IOPIN7*/

#define BITDELAY 2

#define TM1637_I2C_COMM1    0x40
#define TM1637_I2C_COMM2    0xC0
#define TM1637_I2C_COMM3    0x80

BYTE m_brightness = 0x0C;

/* moved to the top of main.c//
//      A
//     ---
//  F |   | B
//     -G-
//  E |   | C
//     ---
//      D
const BYTE digitToSegment[] = {
 // XGFEDCBA
  0b00111111,    // 0
  0b00000110,    // 1
  0b01011011,    // 2
  0b01001111,    // 3
  0b01100110,    // 4
  0b01101101,    // 5
  0b01111101,    // 6
  0b00000111,    // 7
  0b01111111,    // 8
  0b01101111,    // 9
  //0b01110111,    // A
  //0b01111100,    // b
  //0b00111001,    // C
  //0b01011110,    // d
  //0b01111001,    // E
  //0b01110001     // F
  };*/

//static const BYTE minusSegments = 0b01000000;

void TM1637_init(void)
{
	// DStage DSpeed has extra pads for pins P1.7 and P2.7 and programming pins P1.0 and P1.1
	// DStage WBOOS has extra pads for pins P0.4, P1.2, P1.3, P1.7, P2.7, programming pins P1.0 and P1.1 and all LCD pins are free in this mode
	
	// CLK line 
	// 001 strong high and low; theoritically it should be resistive high strong low to allow for display response but
	// it requires stronger pull-up resistor most likey and was ustable in experiments, would be good to check current when ACK i aplied by the display
	CLKDM2 &= ~CLKPIN;
	CLKDM1 &= ~CLKPIN;
	CLKDM0 |= CLKPIN;
	TM1637_CLK_H;
	
	// DIO line
	// 001 strong high and low; theoritically it should be resistive high strong low to allow for display response but
	// it requires stronger pull-up resistor most likey and was ustable in experiments, would be good to check current when ACK i aplied by the display
	DIODM2 &= ~DIOPIN;
	DIODM1 &= ~DIOPIN;
	DIODM0 |= DIOPIN;
	TM1637_DIO_H;
	
	#if defined LED_AFR && defined LED_Lambda
		// LED AFR/Lambda switch line
		// 011 resistive high (pull-up), strong low -> used as input with pull-up, recommended external pull-up or direct high/low state switching
		SWDM2 &= ~SWPIN;
		SWDM1 |= SWPIN;
		SWDM0 |= SWPIN;
		SWPORT |= SWPIN;
	#endif
}

/*void TM1637_setBrightness(BYTE brightness, BYTE on)
{
	m_brightness = (brightness & 0x7) | (on? 0x08 : 0x00);
}*/

void TM1637_setSegments(BYTE segments[], BYTE length, BYTE pos)
{
	BYTE k;
    // Write COMM1
	TM1637_start();
	TM1637_writeByte(TM1637_I2C_COMM1);
	TM1637_stop();

	// Write COMM2 + first digit address
	TM1637_start();
	TM1637_writeByte(TM1637_I2C_COMM2 + (pos & 0x03));

	// Write the data bytes
	for (k=0; k < length; k++)
	  TM1637_writeByte(segments[k]);

	TM1637_stop();

	// Write COMM3 + brightness
	TM1637_start();
	TM1637_writeByte(TM1637_I2C_COMM3 + (m_brightness & 0x0f));
	TM1637_stop();
}

/*void TM1637_clear()
{
    BYTE data[] = { 0, 0, 0, 0 };
	TM1637_setSegments(data);
}*/
/*
void TM1637_showNumberDec(int num, BYTE leading_zero, BYTE length, BYTE pos)
{
  TM1637_showNumberDecEx(num, 0, leading_zero, length, pos);
}

void TM1637_showNumberDecEx(int num, BYTE dots, BYTE leading_zero, BYTE length, BYTE pos)
{
  TM1637_showNumberBaseEx(num < 0? -10 : 10, num < 0? -num : num, dots, leading_zero, length, pos);
}

void TM1637_showNumberHexEx(unsigned int num, BYTE dots, BYTE leading_zero, BYTE length, BYTE pos)
{
  TM1637_showNumberBaseEx(16, num, dots, leading_zero, length, pos);
}

void TM1637_showNumberBaseEx(BYTE base, unsigned int num, BYTE dots, BYTE leading_zero, BYTE length, BYTE pos)
{
	int i;
    BYTE negative = 0;
	BYTE digits[4];
	BYTE digit;
	
	if (base < 0) 
	{
	    base = -base;
		negative = 1;
	}

	if (num == 0 && !leading_zero) 
	{
		// Singular case - take care separately
		for(i = 0; i < (length-1); i++)
			digits[i] = 0;
		digits[length-1] = TM1637_encodeDigit(0);
	}
	else 
	{
		//uint8_t i = length-1;
		//if (negative) {
		//	// Negative number, show the minus sign
		//    digits[i] = minusSegments;
		//	i--;
		//}
		
		for(i = length-1; i >= 0; --i)
		{
		    digit = num % base;
			
			if (digit == 0 && num == 0 && leading_zero == 0)
			    // Leading zero is blank
				digits[i] = 0;
			else
			    digits[i] = TM1637_encodeDigit(digit);
				
			if (digit == 0 && num == 0 && negative) 
			{
			    digits[i] = minusSegments;
				negative = 0;
			}

			num /= base;
		}
    }
	
	if(dots != 0)
	{
		TM1637_showDots(dots, digits);
	}
    
    TM1637_setSegments(digits, length, pos);
}
*/
/*void TM1637_LCD_Delay50uTimes(BITDELAY)
{
	TM1637_delayMicroseconds(m_bitDelay);
}*/

void TM1637_start(void)
{
  TM1637_DIO_L;
  LCD_Delay50uTimes(BITDELAY);
}

void TM1637_stop(void)
{
	TM1637_DIO_L;
	LCD_Delay50uTimes(BITDELAY);
	TM1637_CLK_H;
	LCD_Delay50uTimes(BITDELAY);
	TM1637_DIO_H;
	LCD_Delay50uTimes(BITDELAY);
}

BYTE TM1637_writeByte(BYTE b)
{
  BYTE data = b;
  BYTE i, ack;

  // 8 Data Bits
  for(i = 0; i < 8; i++) {
    // CLK low
    TM1637_CLK_L;
    LCD_Delay50uTimes(BITDELAY);

	// Set data bit
    if (data & 0x01)
      TM1637_DIO_H;
    else
      TM1637_DIO_L;

    LCD_Delay50uTimes(BITDELAY);

	// CLK high
    TM1637_CLK_H;
    LCD_Delay50uTimes(BITDELAY);
    data = data >> 1;
  }

  // Wait for acknowledge
  // CLK to zero
  TM1637_CLK_L;
  TM1637_DIO_H;
  LCD_Delay50uTimes(BITDELAY);

  // CLK to high
  TM1637_CLK_H;
  LCD_Delay50uTimes(BITDELAY);
  ack = TM1637_DIO_READ; //digitalRead(m_pinDIO);
  if (ack == 0)
    TM1637_DIO_L;

  LCD_Delay50uTimes(BITDELAY);
  TM1637_CLK_L;
  LCD_Delay50uTimes(BITDELAY);
  
  if (ack == 0)
  	return 0;
  else
    return 1;
  //return ack;
}

/*void TM1637_showDots(BYTE dots, BYTE* digits)
{
	BYTE i;
    for(i = 0; i < 4; ++i)
    {
        digits[i] |= (dots & 0x80);
        dots <<= 1;
    }
}

BYTE TM1637_encodeDigit(BYTE digit)
{
	return digitToSegment[digit & 0x0f];
}*/
// ================================================================================
#endif