;;*****************************************************************************
;;*****************************************************************************
;;  FILENAME: PWM8_Vout.inc
;;   Version: 2.60, Updated on 2015/3/4 at 22:26:52
;;  Generated by PSoC Designer 5.4.3191
;;
;;  DESCRIPTION: Assembler declarations for the PWM8 user module interface
;;-----------------------------------------------------------------------------
;;  Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
;;*****************************************************************************
;;*****************************************************************************

include "m8c.inc"


;--------------------------------------------------
; Constants for PWM8_Vout API's.
;--------------------------------------------------

PWM8_Vout_CONTROL_REG_START_BIT:           equ 0x01    ; Control register start bit
PWM8_Vout_INT_REG:                         equ 0x0e1
PWM8_Vout_INT_MASK:                        equ 0x04


;--------------------------------------------------
; Constants for PWM8_Vout user defined values
;--------------------------------------------------

PWM8_Vout_PERIOD:                          equ 0xff
PWM8_Vout_PULSE_WIDTH:                     equ 0x00


;--------------------------------------------------
; Register Address Constants for PWM8_Vout
;--------------------------------------------------

PWM8_Vout_COUNTER_REG:                 equ 0x28   ; DR0 Count register
PWM8_Vout_PERIOD_REG:                  equ 0x29   ; DR1 Period register
PWM8_Vout_COMPARE_REG:                 equ 0x2a   ; DR2 Compare register
PWM8_Vout_CONTROL_REG:                 equ 0x2b   ; Control register
PWM8_Vout_FUNC_REG:                    equ 0x28   ; Function register
PWM8_Vout_INPUT_REG:                   equ 0x29   ; Input register
PWM8_Vout_OUTPUT_REG:                  equ 0x2a   ; Output register


;--------------------------------------------------
; PWM8_Vout Macro 'Functions'
;--------------------------------------------------

   macro PWM8_Vout_Start_M
   or    reg[PWM8_Vout_CONTROL_REG],  PWM8_Vout_CONTROL_REG_START_BIT
   endm

   macro PWM8_Vout_Stop_M
   and   reg[PWM8_Vout_CONTROL_REG], ~PWM8_Vout_CONTROL_REG_START_BIT
   endm

   macro PWM8_Vout_EnableInt_M
   M8C_EnableIntMask PWM8_Vout_INT_REG, PWM8_Vout_INT_MASK
   endm

   macro PWM8_Vout_DisableInt_M
   M8C_DisableIntMask PWM8_Vout_INT_REG, PWM8_Vout_INT_MASK
   endm


; end of file PWM8_Vout.inc
