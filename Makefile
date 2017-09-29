#******************************************************************************
#
# Makefile - Rules for building the $(PROGRAM) example.
#
# Copyright (c) 2012-2017 Texas Instruments Incorporated.  All rights reserved.
# Software License Agreement
# 
# Texas Instruments (TI) is supplying this software for use solely and
# exclusively on TI's microcontroller products. The software is owned by
# TI and/or its suppliers, and is protected under applicable copyright
# laws. You may not combine this software with "viral" open-source
# software in order to form a larger program.
# 
# THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
# NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
# NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
# CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
# DAMAGES, FOR ANY REASON WHATSOEVER.
# 
# This is part of revision 2.1.4.178 of the EK-TM4C123GXL Firmware Package.
#
#******************************************************************************

# The name of the file to be generated
PROGRAM = tm4c-audio

# The base directory for TivaWare/other include files
IPATH=/home/trey/etc/tiva-ware

include $(IPATH)/makedefs

SCATTERgcc_$(PROGRAM)=$(PROGRAM).ld
ENTRY_$(PROGRAM)=ResetISR
CFLAGSgcc=-DTARGET_IS_TM4C123_RB1

# The default rule, which causes the $(PROGRAM) example to be built.
all: $(COMPILER)
all: $(COMPILER)/$(PROGRAM).axf

# The rule to clean out all the build products.
clean:
	@rm -rf $(COMPILER)

# The rule to create the target directory.
$(COMPILER):
	@mkdir -p $(COMPILER)

# Rules for building the $(PROGRAM) example.
$(COMPILER)/$(PROGRAM).axf: $(COMPILER)/lookup.o
$(COMPILER)/$(PROGRAM).axf: $(COMPILER)/percussion.o
$(COMPILER)/$(PROGRAM).axf: $(COMPILER)/timers.o
$(COMPILER)/$(PROGRAM).axf: $(COMPILER)/dac.o
$(COMPILER)/$(PROGRAM).axf: $(COMPILER)/pll.o
$(COMPILER)/$(PROGRAM).axf: $(COMPILER)/$(PROGRAM).o
$(COMPILER)/$(PROGRAM).axf: $(COMPILER)/startup.o
$(COMPILER)/$(PROGRAM).axf: $(IPATH)/driverlib/$(COMPILER)/libdriver.a
$(COMPILER)/$(PROGRAM).axf: $(PROGRAM).ld

