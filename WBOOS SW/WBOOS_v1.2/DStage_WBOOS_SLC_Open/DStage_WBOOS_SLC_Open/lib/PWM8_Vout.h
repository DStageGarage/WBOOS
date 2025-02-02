//*****************************************************************************
//*****************************************************************************
//  FILENAME: PWM8_Vout.h
//   Version: 2.60, Updated on 2015/3/4 at 22:26:52
//  Generated by PSoC Designer 5.4.3191
//
//  DESCRIPTION: PWM8 User Module C Language interface file
//-----------------------------------------------------------------------------
//  Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
//*****************************************************************************
//*****************************************************************************
#ifndef PWM8_Vout_INCLUDE
#define PWM8_Vout_INCLUDE

#include <m8c.h>

#pragma fastcall16 PWM8_Vout_EnableInt
#pragma fastcall16 PWM8_Vout_DisableInt
#pragma fastcall16 PWM8_Vout_Start
#pragma fastcall16 PWM8_Vout_Stop
#pragma fastcall16 PWM8_Vout_bReadCounter              // Read  DR0
#pragma fastcall16 PWM8_Vout_WritePeriod               // Write DR1
#pragma fastcall16 PWM8_Vout_bReadPulseWidth           // Read  DR2
#pragma fastcall16 PWM8_Vout_WritePulseWidth           // Write DR2

// The following symbols are deprecated.
// They may be omitted in future releases
//
#pragma fastcall16 bPWM8_Vout_ReadCounter              // Read  DR0 (Deprecated)
#pragma fastcall16 bPWM8_Vout_ReadPulseWidth           // Read  DR2 (Deprecated)


//-------------------------------------------------
// Prototypes of the PWM8_Vout API.
//-------------------------------------------------

extern void PWM8_Vout_EnableInt(void);                        // Proxy Class 1
extern void PWM8_Vout_DisableInt(void);                       // Proxy Class 1
extern void PWM8_Vout_Start(void);                            // Proxy Class 1
extern void PWM8_Vout_Stop(void);                             // Proxy Class 1
extern BYTE PWM8_Vout_bReadCounter(void);                     // Proxy Class 2
extern void PWM8_Vout_WritePeriod(BYTE bPeriod);              // Proxy Class 1
extern BYTE PWM8_Vout_bReadPulseWidth(void);                  // Proxy Class 1
extern void PWM8_Vout_WritePulseWidth(BYTE bPulseWidth);      // Proxy Class 1

// The following functions are deprecated.
// They may be omitted in future releases
//
extern BYTE bPWM8_Vout_ReadCounter(void);            // Deprecated
extern BYTE bPWM8_Vout_ReadPulseWidth(void);         // Deprecated


//--------------------------------------------------
// Constants for PWM8_Vout API's.
//--------------------------------------------------

#define PWM8_Vout_CONTROL_REG_START_BIT        ( 0x01 )
#define PWM8_Vout_INT_REG_ADDR                 ( 0x0e1 )
#define PWM8_Vout_INT_MASK                     ( 0x04 )


//--------------------------------------------------
// Constants for PWM8_Vout user defined values
//--------------------------------------------------

#define PWM8_Vout_PERIOD                       ( 0xff )
#define PWM8_Vout_PULSE_WIDTH                  ( 0x00 )


//-------------------------------------------------
// Register Addresses for PWM8_Vout
//-------------------------------------------------

#pragma ioport  PWM8_Vout_COUNTER_REG:  0x028              //DR0 Count register
BYTE            PWM8_Vout_COUNTER_REG;
#pragma ioport  PWM8_Vout_PERIOD_REG:   0x029              //DR1 Period register
BYTE            PWM8_Vout_PERIOD_REG;
#pragma ioport  PWM8_Vout_COMPARE_REG:  0x02a              //DR2 Compare register
BYTE            PWM8_Vout_COMPARE_REG;
#pragma ioport  PWM8_Vout_CONTROL_REG:  0x02b              //Control register
BYTE            PWM8_Vout_CONTROL_REG;
#pragma ioport  PWM8_Vout_FUNC_REG: 0x128                  //Function register
BYTE            PWM8_Vout_FUNC_REG;
#pragma ioport  PWM8_Vout_INPUT_REG:    0x129              //Input register
BYTE            PWM8_Vout_INPUT_REG;
#pragma ioport  PWM8_Vout_OUTPUT_REG:   0x12a              //Output register
BYTE            PWM8_Vout_OUTPUT_REG;
#pragma ioport  PWM8_Vout_INT_REG:       0x0e1             //Interrupt Mask Register
BYTE            PWM8_Vout_INT_REG;


//-------------------------------------------------
// PWM8_Vout Macro 'Functions'
//-------------------------------------------------

#define PWM8_Vout_Start_M \
   PWM8_Vout_CONTROL_REG |=  PWM8_Vout_CONTROL_REG_START_BIT

#define PWM8_Vout_Stop_M  \
   PWM8_Vout_CONTROL_REG &= ~PWM8_Vout_CONTROL_REG_START_BIT

#define PWM8_Vout_EnableInt_M   \
   M8C_EnableIntMask(PWM8_Vout_INT_REG, PWM8_Vout_INT_MASK)

#define PWM8_Vout_DisableInt_M  \
   M8C_DisableIntMask(PWM8_Vout_INT_REG, PWM8_Vout_INT_MASK)

#endif
// end of file PWM8_Vout.h
