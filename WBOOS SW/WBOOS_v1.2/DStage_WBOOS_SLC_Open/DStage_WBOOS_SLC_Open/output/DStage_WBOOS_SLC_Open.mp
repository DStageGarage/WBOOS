Project:      output/DStage_WBOOS_SLC_Open
Build Number: 0
Date:         Sun Feb 02 15:37:34 2025
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   0150   0288 =    648. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       0150  _ip_to_Vout_Lookup
       01EE  _ip_to_AFR_Lookup
       028C  _ip_to_Lambda_Lookup
       032A  _digitToSegment
       0338  LoadConfigTBL_slc_free_28_pin_feb_16_2013_Bank0
       039D  LoadConfigTBL_slc_free_28_pin_feb_16_2013_Bank1
       03D8  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   03D8   000B =     11. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       03D8  __idata_start
       03E3  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   03E3   00CC =    204. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       03E3  LoadConfigTBL_slc_free_28_pin_feb_16_2013_Ordered
       0448  LoadConfigInit
       0448  _LoadConfigInit
       0458  _LoadConfig_slc_free_28_pin_feb_16_2013
       0458  LoadConfig_slc_free_28_pin_feb_16_2013
       04AF  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   04AF   0367 =    871. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       04AF  _SleepTimer_ISR
       04D1  _SleepTimer_EnableInt
       04D1  SleepTimer_EnableInt
       04D5  _SleepTimer_Start
       04D5  SleepTimer_Start
       04D5  _SleepTimer_DisableInt
       04E6  SleepTimer_SetInterval
       04E6  _SleepTimer_SetInterval
       04E6  _SleepTimer_Stop
       04F8  _SleepTimer_TickWait
       04F8  _SleepTimer_SetTimer
       04F8  _SleepTimer_SyncWait
       04F8  _SleepTimer_bGetTickCntr
       04F8  _SleepTimer_bGetTimer
       04F8  _SleepTimer_iGetTickCntr
       04F8  _SleepTimer_lGetTickCntr
       04F8  _PWM8_Vout_ISR
       04F9  _PWM8_Vout_DisableInt
       04F9  PWM8_Vout_DisableInt
       04F9  _PWM8_Vout_EnableInt
       04FD  PWM8_Vout_Start
       04FD  _PWM8_Vout_Start
       0501  PWM8_Vout_WritePulseWidth
       0501  _PWM8_Vout_WritePulseWidth
       0501  _PWM8_Vout_Stop
       0501  _PWM8_Vout_WritePeriod
       0504  bPWM8_Vout_ReadPulseWidth
       0504  _bPWM8_Vout_ReadPulseWidth
       0504  bPWM8_Vout_ReadCounter
       0504  _PWM8_Vout_bReadCounter
       0504  _PWM8_Vout_bReadPulseWidth
       0504  _PWM8_NB_Out_ISR
       0504  _bPWM8_Vout_ReadCounter
       0505  PWM8_NB_Out_DisableInt
       0505  _PWM8_NB_Out_EnableInt
       0505  _PWM8_NB_Out_DisableInt
       0509  _PWM8_NB_Out_Start
       0509  PWM8_NB_Out_Start
       050D  _PWM8_NB_Out_Stop
       050D  _PWM8_NB_Out_WritePulseWidth
       050D  _PWM8_NB_Out_WritePeriod
       050D  PWM8_NB_Out_WritePulseWidth
       0510  _PWM8_Heater_ISR
       0510  _PWM8_NB_Out_bReadCounter
       0510  _bPWM8_NB_Out_ReadCounter
       0510  _PWM8_NB_Out_bReadPulseWidth
       0510  bPWM8_NB_Out_ReadCounter
       0510  _bPWM8_NB_Out_ReadPulseWidth
       0510  bPWM8_NB_Out_ReadPulseWidth
       0511  _PWM8_Heater_DisableInt
       0511  PWM8_Heater_DisableInt
       0511  _PWM8_Heater_EnableInt
       0515  _PWM8_Heater_Start
       0515  PWM8_Heater_Start
       0519  PWM8_Heater_WritePulseWidth
       0519  _PWM8_Heater_WritePeriod
       0519  _PWM8_Heater_Stop
       0519  _PWM8_Heater_WritePulseWidth
       051C  _bPWM8_Heater_ReadPulseWidth
       051C  bPWM8_Heater_ReadPulseWidth
       051C  _PWM8_Heater_bReadCounter
       051C  _bPWM8_Heater_ReadCounter
       051C  bPWM8_Heater_ReadCounter
       051C  _LCD_PrCString
       051C  LCD_PrCString
       051C  _PWM8_Heater_bReadPulseWidth
       052E  LCD_HEX_STR
       053E  _LCD_PrHexByte
       053E  LCD_PrHexByte
       0551  LCD_PrString
       0551  _LCD_PrString
       0551  _LCD_PrHexInt
       055B  LCD_WriteData
       055B  LCD_Write_Data
       055B  _LCD_WriteData
       055B  _LCD_Write_Data
       056F  LCD_Control
       056F  _LCD_Control
       0616  LCD_ROW_OFFSET
       0616  LCD_Init
       0616  _LCD_Init
       0616  _LCD_Start
       061A  LCD_Position
       061A  _LCD_Position
       0626  _LCD_Delay50uTimes
       0626  LCD_Delay50uTimes
       062C  LCD_Delay50u_Table
       0634  _LCD_Delay50u
       0634  LCD_Delay50u
       0648  LCD_BG_TYPE1
       0648  _LCD_InitVBG
       064F  LCD_BG_TYPE2
       0656  _INSAMP_SetPower
       0656  INSAMP_Start
       0656  _LCD_InitBG
       0656  _INSAMP_Start
       0656  INSAMP_SetPower
       066C  _DAC9_Ia_Start
       066C  _INSAMP_SetGain
       066C  DAC9_Ia_Start
       066C  _INSAMP_Stop
       066C  DAC9_Ia_SetPower
       066C  _DAC9_Ia_SetPower
       0682  _DAC9_Ia_WriteStall
       0682  DAC9_Ia_WriteStall
       0682  _DAC9_Ia_WriteBlind
       0682  DAC9_Ia_WriteBlind2B
       0682  _DAC9_Ia_WriteBlind2B
       06B1  DAC9_Ia_WriteStall2B
       06B1  _DAC9_Ia_WriteStall2B
       06C2  _DAC9_Ia_Stop
       06C2  DAC6_VGND_Start
       06C2  _DAC6_VGND_Start
       06C2  _DAC6_VGND_SetPower
       06C2  DAC6_VGND_SetPower
       06C9  DAC6_VGND_WriteStall
       06C9  _DAC6_VGND_WriteBlind
       06C9  _DAC6_VGND_WriteStall
       06E5  AMUX4_1_InputSelect
       06E5  _DAC6_VGND_Stop
       06E5  _AMUX4_1_InputSelect
       06FC  _AMUX4_1_Start
       06FC  _AMUX4_1_Stop
       06FC  _AMUX4_0_InputSelect
       06FC  AMUX4_0_InputSelect
       0713  _AMUX4_0_Start
       0713  _AMUX4_0_Stop
       0713  _ADCINC_ADConversion_ISR
       07CD  ADCINC_Start
       07CD  _ADCINC_Start
       07DF  _ADCINC_SetPower
       07DF  ADCINC_SetPower
       07ED  ADCINC_GetSamples
       07ED  _ADCINC_GetSamples
       07ED  _ADCINC_Stop
       0809  _ADCINC_StopADC
       0809  _ADCINC_fIsDataAvailable
       0809  _ADCINC_iClearFlagGetData
       0809  ADCINC_wClearFlagGetData
       0809  ADCINC_iClearFlagGetData
       0809  _ADCINC_wClearFlagGetData
       0816  __UserModules_end
       0816  _ADCINC_wGetData
       0816  ADCINC_bClearFlagGetData
       0816  _ADCINC_fClearFlag
       0816  _ADCINC_iGetData
       0816  ADCINC_cGetData
       0816  _ADCINC_cClearFlagGetData
       0816  _ADCINC_bClearFlagGetData
       0816  _ADCINC_cGetData
       0816  _ADCINC_WritePulseWidth
       0816  _ADCINC_bGetData
       0816  ADCINC_wGetData

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0816   07E7 =   2023. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0816  _Heater_PID
       0816  __text_start
       0970  _Ia_PID
       0A92  _IIR_Int
       0AC9  _main
       0DE2  _TM1637_init
       0E13  _TM1637_setSegments
       0E5E  _TM1637_start
       0E69  _TM1637_stop
       0E88  _TM1637_writeByte
       0F88  <created procedures>
       0FFD  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   000B =     11. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start
       0000  _Ri_Mid_Error_Sum
       0002  _Ri_Delta_Error_Sum
       0004  _Heatup_Heater_Output
       0005  _Ia_PID_Counter
       0006  _Vout_Lookup_Counter
       0007  _Heater_PID_Counter
       0008  _LCD_Counter
       0009  _Heatup_Counter
       000A  _m_brightness
       000B  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
               virtual_registers   000B   0007 =      7. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       000B  __rZ
       000C  __rY
       000D  __rX
       000E  __r3
       000F  __r2
       0010  __r1
       0011  __r0
       0012  __virtual_registers_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                    InterruptRAM   0012   0018 =     24. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0012  _SleepTimer_fTick
       0012  SleepTimer_fTick
       0013  _SleepTimer_bTimerValue
       0013  SleepTimer_bTimerValue
       0014  SleepTimer_bCountDown
       0014  _SleepTimer_bCountDown
       0015  _SleepTimer_TickCount
       0015  SleepTimer_TickCount
       0019  _Sleep_Counter
       0019  Sleep_Counter
       001A  _Port_2_Data_SHADE
       001A  NO_SHADOW
       001A  _NO_SHADOW
       001A  Port_2_Data_SHADE
       001B  _Port_2_DriveMode_0_SHADE
       001B  Port_2_DriveMode_0_SHADE
       001C  _Port_2_DriveMode_1_SHADE
       001C  Port_2_DriveMode_1_SHADE
       001D  _ADCINC_iResult
       001D  ADCINC_iResult
       0021  ADCINC_fStatus
       0021  _ADCINC_fStatus
       0022  _ADCINC_bState
       0022  ADCINC_bState
       0023  _ADCINC_fMode
       0023  ADCINC_fMode
       0024  ADCINC_bNumSamples
       0024  _ADCINC_bNumSamples
       0025  _ADC_Counter
       0025  ADC_Counter
       0026  _Ri_Max_x1
       0026  Ri_Max_x1
       0027  Ri_Min_x1
       0027  _Ri_Min_x1
       0028  _ip_x1
       0028  ip_x1
       0029  _ADC_IF
       0029  ADC_IF
       002A  __InterruptRAM_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   002A   001F =     31. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       002A  _LSU_Temperature_C
       002A  __bss_start
       002C  _Lambda_x100
       002D  _ip_Justified
       002F  _ip
       0031  _Ri_Max
       0033  _Ri_Min
       0035  _Ia_Iout
       0037  _Ia_Pout
       0039  _Ia_Output
       003B  _Ri_Mid_Error
       003D  _Heater_Iout
       003F  _Heater_Pout
       0041  _Heater_Output
       0043  _Ri_Delta_Error
       0045  _Ri_Delta
       0047  _Ri_Mid
       0049  __ramareas_end
       0049  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             TOP   0000   00D4 =    212. bytes (abs,ovr,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0068  __Start
       00D1  _bGetPowerSetting
       00D1  bGetPowerSetting

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/main.o	[ main.c ]
<library>	[ sleeptimerint.asm, sleeptimer.asm, pwm8_voutint.asm, pwm8_vout.asm, pwm8_nb_outint.asm, pwm8_nb_out.asm ]
[ pwm8_heaterint.asm, pwm8_heater.asm, psocconfigtbl.asm, psocconfig.asm, lcd.asm, insamp.asm ]
[ dac9_ia.asm, dac6_vgnd.asm, amux4_1.asm, amux4_0.asm, adcincint.asm, adcinc.asm, rZ.asm, rY.asm ]
[ rX.asm, r3.asm, r2.asm, r1.asm, r0.asm, divmod_16x16_16_util.asm, i_div16_block_util.asm ]

Area Definitions

-blit:0x150.0xfff
-bdata:0.0xff
-rwh:SSCParmBlk:0xf7.0xff

