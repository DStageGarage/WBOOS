;;*****************************************************************************
;;*****************************************************************************
;;  FILENAME:   INSAMP.inc
;;  Version: 2.2, Updated on 2015/3/4 at 22:26:35
;;  Generated by PSoC Designer 5.4.3191
;;
;;  DESCRIPTION:
;;    Assembler declarations for a two-OpAmp Instrumentation Amplifier
;;    topology in the 22/24/27/28xxx family of PSoC devices
;;-----------------------------------------------------------------------------
;;  Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
;;*****************************************************************************
;;*****************************************************************************

include "m8c.inc"

;--------------------------------------------------
; Constants for INSAMP API's.
;--------------------------------------------------

INSAMP_OFF:                        equ 0
INSAMP_LOWPOWER:                   equ 1
INSAMP_MEDPOWER:                   equ 2
INSAMP_HIGHPOWER:                  equ 3

INSAMP_G16_0:                      equ 00h
INSAMP_G8_00:                      equ 10h
INSAMP_G5_33:                      equ 20h
INSAMP_G4_00:                      equ 30h
INSAMP_G3_20:                      equ 40h
INSAMP_G2_67:                      equ 50h
INSAMP_G2_27:                      equ 60h
INSAMP_G2_00:                      equ 70h

;--------------------------------------------------
; Register Address Constants for INSAMP
;--------------------------------------------------

INSAMP_INV_CR0:                    equ 0x71  ; CT Block Control Register 0
INSAMP_INV_CR1:                    equ 0x72  ; CT Block Control Register 1
INSAMP_INV_CR2:                    equ 0x73  ; CT Block Control Register 2
INSAMP_INV_CR3:                    equ 0x70  ; CT Block Control Register 3

INSAMP_NON_INV_CR0:                equ 0x75  ; CT Block Control Register 0
INSAMP_NON_INV_CR1:                equ 0x76  ; CT Block Control Register 1
INSAMP_NON_INV_CR2:                equ 0x77  ; CT Block Control Register 2
INSAMP_NON_INV_CR3:                equ 0x74  ; CT Block Control Register 3


; end of file INSAMP.inc
