;@******************************************************************************
;@
;@ Useful functions.
;@
;@******************************************************************************
.global DisableInterrupts
.global EnableInterrupts
.global StartCritical
.global EndCritical
.global WaitForInterrupt

;@*********** DisableInterrupts ***************
;@ disable interrupts
;@ inputs:  none
;@ outputs: none
DisableInterrupts:
        CPSID  I
        BX     LR

;@*********** EnableInterrupts ***************
;@ disable interrupts
;@ inputs:  none
;@ outputs: none
EnableInterrupts:
        CPSIE  I
        BX     LR

;@*********** StartCritical ************************
;@ make a copy of previous I bit, disable interrupts
;@ inputs:  none
;@ outputs: previous I bit
StartCritical:
        MRS    R0, PRIMASK  ;@ save old status
        CPSID  I            ;@ mask all (except faults)
        BX     LR

;@*********** EndCritical ************************
;@ using the copy of previous I bit, restore I bit to previous value
;@ inputs:  previous I bit
;@ outputs: none
EndCritical:
        MSR    PRIMASK, R0
        BX     LR

;@*********** WaitForInterrupt ************************
;@ go to low power mode while waiting for the next interrupt
;@ inputs:  none
;@ outputs: none
WaitForInterrupt:
        WFI
        BX     LR

