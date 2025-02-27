;  Generated by PSoC Designer 5.4.3191
;
;==========================================================================
;  PSoCConfig.asm
;  @PSOC_VERSION
;
;  Version: 0.85
;  Revised: June 22, 2004
;  Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
;
;  This file is generated by the Device Editor on Application Generation.
;  It contains code which loads the configuration data table generated in
;  the file PSoCConfigTBL.asm
;
;  DO NOT EDIT THIS FILE MANUALLY, AS IT IS OVERWRITTEN!!!
;  Edits to this file will not be preserved.
;==========================================================================
;
include "m8c.inc"
include "memory.inc"
include "GlobalParams.inc"

export LoadConfigInit
export _LoadConfigInit
export LoadConfig_slc_free_28_pin_feb_16_2013
export _LoadConfig_slc_free_28_pin_feb_16_2013
export Port_2_Data_SHADE
export _Port_2_Data_SHADE
export Port_2_DriveMode_0_SHADE
export _Port_2_DriveMode_0_SHADE
export Port_2_DriveMode_1_SHADE
export _Port_2_DriveMode_1_SHADE


export NO_SHADOW
export _NO_SHADOW

FLAG_CFG_MASK:      equ 10h         ;M8C flag register REG address bit mask
END_CONFIG_TABLE:   equ ffh         ;end of config table indicator

AREA psoc_config(rom, rel)

;---------------------------------------------------------------------------
; LoadConfigInit - Establish the start-up configuration (except for a few
;                  parameters handled by boot code, like CPU speed). This
;                  function can be called from user code, but typically it
;                  is only called from boot.
;
;       INPUTS: None.
;      RETURNS: Nothing.
; SIDE EFFECTS: Registers are volatile: the A and X registers can be modified!
;               In the large memory model currently only the page
;               pointer registers listed below are modified.  This does
;               not guarantee that in future implementations of this
;               function other page pointer registers will not be
;               modified.
;          
;               Page Pointer Registers Modified: 
;               CUR_PP
;
_LoadConfigInit:
 LoadConfigInit:
    RAM_PROLOGUE RAM_USE_CLASS_4
    
	mov		[Port_2_Data_SHADE], 0h
	mov		[Port_2_DriveMode_0_SHADE], ffh
	mov		[Port_2_DriveMode_1_SHADE], 0h

	lcall	LoadConfig_slc_free_28_pin_feb_16_2013
	lcall	LoadConfigTBL_slc_free_28_pin_feb_16_2013_Ordered


    RAM_EPILOGUE RAM_USE_CLASS_4
    ret

;---------------------------------------------------------------------------
; Load Configuration slc_free_28_pin_feb_16_2013
;
;    Load configuration registers for slc_free_28_pin_feb_16_2013.
;    IO Bank 0 registers a loaded first,then those in IO Bank 1.
;
;       INPUTS: None.
;      RETURNS: Nothing.
; SIDE EFFECTS: Registers are volatile: the CPU A and X registers may be
;               modified as may the Page Pointer registers!
;               In the large memory model currently only the page
;               pointer registers listed below are modified.  This does
;               not guarantee that in future implementations of this
;               function other page pointer registers will not be
;               modified.
;          
;               Page Pointer Registers Modified: 
;               CUR_PP
;
_LoadConfig_slc_free_28_pin_feb_16_2013:
 LoadConfig_slc_free_28_pin_feb_16_2013:
    RAM_PROLOGUE RAM_USE_CLASS_4

	push	x
    M8C_SetBank0                    ; Force bank 0
    mov     a, 0                    ; Specify bank 0
    asr     a                       ; Store in carry flag
                                    ; Load bank 0 table:
    mov     A, >LoadConfigTBL_slc_free_28_pin_feb_16_2013_Bank0
    mov     X, <LoadConfigTBL_slc_free_28_pin_feb_16_2013_Bank0
    lcall   LoadConfig              ; Load the bank 0 values

    mov     a, 1                    ; Specify bank 1
    asr     a                       ; Store in carry flag
                                    ; Load bank 1 table:
    mov     A, >LoadConfigTBL_slc_free_28_pin_feb_16_2013_Bank1
    mov     X, <LoadConfigTBL_slc_free_28_pin_feb_16_2013_Bank1
    lcall   LoadConfig              ; Load the bank 1 values

    M8C_SetBank0                    ; Force return to bank 0
	pop		x

    RAM_EPILOGUE RAM_USE_CLASS_4
    ret




;---------------------------------------------------------------------------
; LoadConfig - Set IO registers as specified in ROM table of (address,value)
;              pairs. Terminate on address=0xFF.
;
;  INPUTS:  [A,X] points to the table to be loaded
;           Flag Register Carry bit encodes the Register Bank
;           (Carry=0 => Bank 0; Carry=1 => Bank 1)
;
;  RETURNS: nothing.
;
;  STACK FRAME:  X-4 I/O Bank 0/1 indicator
;                X-3 Temporary store for register address
;                X-2 LSB of config table address
;                X-1 MSB of config table address
;
LoadConfig:
    RAM_PROLOGUE RAM_USE_CLASS_2
    add     SP, 2                   ; Set up local vars
    push    X                       ; Save config table address on stack
    push    A
    mov     X, SP
    mov     [X-4], 0                ; Set default Destination to Bank 0
    jnc     .BankSelectSaved        ; Carry says Bank 0 is OK
    mov     [X-4], 1                ; No Carry: default to Bank 1
.BankSelectSaved:
    pop     A
    pop     X

LoadConfigLp:
    M8C_SetBank0                    ; Switch to bank 0
    M8C_ClearWDT                    ; Clear the watchdog for long inits
    push    X                       ; Preserve the config table address
    push    A
    romx                            ; Load register address from table
    cmp     A, END_CONFIG_TABLE     ; End of table?
    jz      EndLoadConfig           ;   Yes, go wrap it up
    mov     X, SP                   ;
    tst     [X-4], 1                ; Loading IO Bank 1?
    jz      .IOBankNowSet           ;    No, Bank 0 is fine
    M8C_SetBank1                    ;   Yes, switch to Bank 1
.IOBankNowSet:
    mov     [X-3], A                ; Stash the register address
    pop     A                       ; Retrieve the table address
    pop     X
    inc     X                       ; Advance to the data byte
    adc     A, 0
    push    X                       ; Save the config table address again
    push    A
    romx                            ; load config data from the table
    mov     X, SP                   ; retrieve the register address
    mov     X, [X-3]
    mov     reg[X], A               ; Configure the register
    pop     A                       ; retrieve the table address
    pop     X
    inc     X                       ; advance to next table entry
    adc     A, 0
    jmp     LoadConfigLp            ; loop to configure another register
EndLoadConfig:
    add     SP, -4
    RAM_EPILOGUE RAM_USE_CLASS_2
    ret

AREA InterruptRAM(ram, rel)

NO_SHADOW:
_NO_SHADOW:
; write only register shadows
_Port_2_Data_SHADE:
Port_2_Data_SHADE:	BLK	1
_Port_2_DriveMode_0_SHADE:
Port_2_DriveMode_0_SHADE:	BLK	1
_Port_2_DriveMode_1_SHADE:
Port_2_DriveMode_1_SHADE:	BLK	1

