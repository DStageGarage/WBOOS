;;*****************************************************************************
;;*****************************************************************************
;;  FILENAME:   AMUX4_1.asm
;;  Version: 1.50, Updated on 2015/3/4 at 22:21:30
;;  Generated by PSoC Designer 5.4.3191
;;
;;  DESCRIPTION: AMux4 User Module software implementation file devices.
;;
;;  NOTE: User Module APIs conform to the fastcall16 convention for marshalling
;;        arguments and observe the associated "Registers are volatile" policy.
;;        This means it is the caller's responsibility to preserve any values
;;        in the X and A registers that are still needed after the API functions
;;        returns. For Large Memory Model devices it is also the caller's 
;;        responsibility to perserve any value in the CUR_PP, IDX_PP, MVR_PP and 
;;        MVW_PP registers. Even though some of these registers may not be modified
;;        now, there is no guarantee that will remain the case in future releases.
;;-----------------------------------------------------------------------------
;;  Copyright (c) Cypress Semiconductor 2015. All Rights Reserved.
;;*****************************************************************************
;;*****************************************************************************


include "AMUX4_1.inc"
include "m8c.inc"
include "memory.inc"

;-----------------------------------------------
;  Global Symbols
;-----------------------------------------------
export  AMUX4_1_InputSelect
export _AMUX4_1_InputSelect

export  AMUX4_1_Start
export _AMUX4_1_Start

export  AMUX4_1_Stop
export _AMUX4_1_Stop

;-----------------------------------------------
;  EQUATES
;-----------------------------------------------

MUXMASK:                     equ 03h

AREA UserModules (ROM, REL)
.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: AMUX4_1_InputSelect
;
;  DESCRIPTION:
;    Place the signal from one of four port0 pins on the Analog Column bus.
;
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:
;    A contains the mux input control value
;
;      Input           Code
;   Mux input 0,1       00h
;   Mux input 2,3       01h
;   Mux input 4,5       02h
;   Mux input 6,7       03h
;
;  RETURNS: none
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 AMUX4_1_InputSelect:
_AMUX4_1_InputSelect:
    RAM_PROLOGUE RAM_USE_CLASS_2
	
IF (AMUX4_1_COL_COUNT)
	M8C_SetBank1      ; ACE_AMX_IN is in Bank 1
ENDIF
	
    and  A, MUXMASK                    ; Mask off only valid port0 input bits
    mov  X,AMUX4_1_MUX_COL
.AMUX4_ShiftIt:                         ; Shift value to correct bit position for Mux
    dec  X
    jc   .AMUX4_SetIt
    asl  A
    asl  A
    jmp  .AMUX4_ShiftIt                ; Loop until bits shifted to 2 LSBs

.AMUX4_SetIt:
    mov  X,SP                          ; Get current stack location
    push A                             ; Save a to OR it to AMX_IN later	
IF (AMUX4_1_COL_COUNT)
	mov  A, reg[ACE_AMX_IN]                 ; Get current value of mux control register    
ELSE
	mov  A, reg[AMX_IN]                 ; Get current value of mux control register
ENDIF
    and  A,~AMUX4_1_MUX_MASK           ; Mask off the bits for this Mux
    or   A,[X]                         ; OR in the mux control bits
IF (AMUX4_1_COL_COUNT)
	mov  reg[ACE_AMX_IN], A                 ; Get current value of mux control register    
ELSE
	mov  reg[AMX_IN], A                 ; Write out mux value to mux control register
ENDIF	
    pop  A                             ; Restore the stack
	
IF (AMUX4_1_COL_COUNT)
	M8C_SetBank0
ENDIF
    RAM_EPILOGUE RAM_USE_CLASS_2
    ret
.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: AMUX4_1_Start
;
;  DESCRIPTION:
;   This function does nothing at this time.  It is only here for
;   future compatibility.
;
;-----------------------------------------------------------------------------
;
;  ARGUMENTS: none
;
;  RETURNS: none
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 AMUX4_1_Start:
_AMUX4_1_Start:
    RAM_PROLOGUE RAM_USE_CLASS_1
    RAM_EPILOGUE RAM_USE_CLASS_1
    ret
.ENDSECTION

.SECTION
;-----------------------------------------------------------------------------
;  FUNCTION NAME: AMUX4_1_Stop
;
;  DESCRIPTION:
;   This function does nothing at this time.  It is only here for
;   future compatibility.
;
;-----------------------------------------------------------------------------
;
;  ARGUMENTS:  none
;
;  RETURNS: none
;
;  SIDE EFFECTS:
;    The A and X registers may be modified by this or future implementations
;    of this function.  The same is true for all RAM page pointer registers in
;    the Large Memory Model.  When necessary, it is the calling function's
;    responsibility to perserve their values across calls to fastcall16 
;    functions.
;
 AMUX4_1_Stop:
_AMUX4_1_Stop:
    RAM_PROLOGUE RAM_USE_CLASS_1
    RAM_EPILOGUE RAM_USE_CLASS_1
    ret
.ENDSECTION
; End of File AMUX4_1.asm
