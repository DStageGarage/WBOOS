Project:      output/DStage_WBOOS_SLC_Open
Build Number: 0
Date:         Thu Feb 19 23:43:10 2026
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   0150   01EE =    494. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       0150  _ip_to_Vout_Lookup
       01EE  _ip_to_AFR_Lookup
       028C  _digitToSegment
       029E  LoadConfigTBL_DStage_WBOOS_28pin_Bank0
       0303  LoadConfigTBL_DStage_WBOOS_28pin_Bank1
       033E  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   033E   000B =     11. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       033E  __idata_start
       0349  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   0349   00CC =    204. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0349  LoadConfigTBL_DStage_WBOOS_28pin_Ordered
       03AE  _LoadConfigInit
       03AE  LoadConfigInit
       03BE  _LoadConfig_DStage_WBOOS_28pin
       03BE  LoadConfig_DStage_WBOOS_28pin
       0415  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   0415   0367 =    871. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0415  _SleepTimer_ISR
       0437  _SleepTimer_EnableInt
       0437  SleepTimer_EnableInt
       043B  _SleepTimer_Start
       043B  SleepTimer_Start
       043B  _SleepTimer_DisableInt
       044C  SleepTimer_SetInterval
       044C  _SleepTimer_SetInterval
       044C  _SleepTimer_Stop
       045E  _SleepTimer_TickWait
       045E  _SleepTimer_SetTimer
       045E  _SleepTimer_SyncWait
       045E  _SleepTimer_bGetTickCntr
       045E  _SleepTimer_bGetTimer
       045E  _SleepTimer_iGetTickCntr
       045E  _SleepTimer_lGetTickCntr
       045E  _PWM8_Vout_ISR
       045F  _PWM8_Vout_DisableInt
       045F  PWM8_Vout_DisableInt
       045F  _PWM8_Vout_EnableInt
       0463  PWM8_Vout_Start
       0463  _PWM8_Vout_Start
       0467  PWM8_Vout_WritePulseWidth
       0467  _PWM8_Vout_WritePulseWidth
       0467  _PWM8_Vout_Stop
       0467  _PWM8_Vout_WritePeriod
       046A  bPWM8_Vout_ReadPulseWidth
       046A  _bPWM8_Vout_ReadPulseWidth
       046A  bPWM8_Vout_ReadCounter
       046A  _PWM8_Vout_bReadCounter
       046A  _PWM8_Vout_bReadPulseWidth
       046A  _PWM8_NB_Out_ISR
       046A  _bPWM8_Vout_ReadCounter
       046B  PWM8_NB_Out_DisableInt
       046B  _PWM8_NB_Out_EnableInt
       046B  _PWM8_NB_Out_DisableInt
       046F  _PWM8_NB_Out_Start
       046F  PWM8_NB_Out_Start
       0473  _PWM8_NB_Out_Stop
       0473  _PWM8_NB_Out_WritePulseWidth
       0473  _PWM8_NB_Out_WritePeriod
       0473  PWM8_NB_Out_WritePulseWidth
       0476  _PWM8_Heater_ISR
       0476  _PWM8_NB_Out_bReadCounter
       0476  _bPWM8_NB_Out_ReadCounter
       0476  _PWM8_NB_Out_bReadPulseWidth
       0476  bPWM8_NB_Out_ReadCounter
       0476  _bPWM8_NB_Out_ReadPulseWidth
       0476  bPWM8_NB_Out_ReadPulseWidth
       0477  _PWM8_Heater_DisableInt
       0477  PWM8_Heater_DisableInt
       0477  _PWM8_Heater_EnableInt
       047B  _PWM8_Heater_Start
       047B  PWM8_Heater_Start
       047F  PWM8_Heater_WritePulseWidth
       047F  _PWM8_Heater_WritePeriod
       047F  _PWM8_Heater_Stop
       047F  _PWM8_Heater_WritePulseWidth
       0482  _bPWM8_Heater_ReadPulseWidth
       0482  bPWM8_Heater_ReadPulseWidth
       0482  _PWM8_Heater_bReadCounter
       0482  _bPWM8_Heater_ReadCounter
       0482  bPWM8_Heater_ReadCounter
       0482  _LCD_PrCString
       0482  LCD_PrCString
       0482  _PWM8_Heater_bReadPulseWidth
       0494  LCD_HEX_STR
       04A4  _LCD_PrHexByte
       04A4  LCD_PrHexByte
       04B7  LCD_PrString
       04B7  _LCD_PrString
       04B7  _LCD_PrHexInt
       04C1  LCD_WriteData
       04C1  LCD_Write_Data
       04C1  _LCD_WriteData
       04C1  _LCD_Write_Data
       04D5  LCD_Control
       04D5  _LCD_Control
       057C  LCD_ROW_OFFSET
       057C  LCD_Init
       057C  _LCD_Init
       057C  _LCD_Start
       0580  LCD_Position
       0580  _LCD_Position
       058C  _LCD_Delay50uTimes
       058C  LCD_Delay50uTimes
       0592  LCD_Delay50u_Table
       059A  _LCD_Delay50u
       059A  LCD_Delay50u
       05AE  LCD_BG_TYPE1
       05AE  _LCD_InitVBG
       05B5  LCD_BG_TYPE2
       05BC  _INSAMP_SetPower
       05BC  INSAMP_Start
       05BC  _LCD_InitBG
       05BC  _INSAMP_Start
       05BC  INSAMP_SetPower
       05D2  _DAC9_Ia_Start
       05D2  _INSAMP_SetGain
       05D2  DAC9_Ia_Start
       05D2  _INSAMP_Stop
       05D2  DAC9_Ia_SetPower
       05D2  _DAC9_Ia_SetPower
       05E8  _DAC9_Ia_WriteStall
       05E8  DAC9_Ia_WriteStall
       05E8  _DAC9_Ia_WriteBlind
       05E8  DAC9_Ia_WriteBlind2B
       05E8  _DAC9_Ia_WriteBlind2B
       0617  DAC9_Ia_WriteStall2B
       0617  _DAC9_Ia_WriteStall2B
       0628  _DAC9_Ia_Stop
       0628  DAC6_VGND_Start
       0628  _DAC6_VGND_Start
       0628  _DAC6_VGND_SetPower
       0628  DAC6_VGND_SetPower
       062F  DAC6_VGND_WriteStall
       062F  _DAC6_VGND_WriteBlind
       062F  _DAC6_VGND_WriteStall
       064B  AMUX4_1_InputSelect
       064B  _DAC6_VGND_Stop
       064B  _AMUX4_1_InputSelect
       0662  _AMUX4_1_Start
       0662  _AMUX4_1_Stop
       0662  _AMUX4_0_InputSelect
       0662  AMUX4_0_InputSelect
       0679  _AMUX4_0_Start
       0679  _AMUX4_0_Stop
       0679  _ADCINC_ADConversion_ISR
       0733  ADCINC_Start
       0733  _ADCINC_Start
       0745  _ADCINC_SetPower
       0745  ADCINC_SetPower
       0753  ADCINC_GetSamples
       0753  _ADCINC_GetSamples
       0753  _ADCINC_Stop
       076F  _ADCINC_StopADC
       076F  _ADCINC_fIsDataAvailable
       076F  _ADCINC_iClearFlagGetData
       076F  ADCINC_wClearFlagGetData
       076F  ADCINC_iClearFlagGetData
       076F  _ADCINC_wClearFlagGetData
       077C  __UserModules_end
       077C  _ADCINC_wGetData
       077C  ADCINC_bClearFlagGetData
       077C  _ADCINC_fClearFlag
       077C  _ADCINC_iGetData
       077C  ADCINC_cGetData
       077C  _ADCINC_cClearFlagGetData
       077C  _ADCINC_bClearFlagGetData
       077C  _ADCINC_cGetData
       077C  _ADCINC_WritePulseWidth
       077C  _ADCINC_bGetData
       077C  ADCINC_wGetData

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   077C   0779 =   1913. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       077C  _Heater_PID
       077C  __text_start
       08D6  _Ia_PID
       09F8  _IIR_Int
       0A2F  _main
       0D0D  _TM1637_init
       0D3B  _TM1637_setSegments
       0D86  _TM1637_start
       0D91  _TM1637_stop
       0DB0  _TM1637_writeByte
       0EB0  <created procedures>
       0EF5  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   000B =     11. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  _m_brightness
       0000  __data_start
       0001  _Ri_Mid_Error_Sum
       0003  _Ri_Delta_Error_Sum
       0005  _Heatup_Heater_Output
       0006  _Ia_PID_Counter
       0007  _Vout_Lookup_Counter
       0008  _Heater_PID_Counter
       0009  _LCD_Counter
       000A  _Heatup_Counter
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

