# Makefile for a TM4C project
# Based on the one provided by TI and the one at uctools.github.com

### User configuration ###
# TARGET: name of the target binary output file
TARGET = tm4c-audio
# MCU: part number to build for
MCU = TM4C123GH6PM
# CPU: flag for gcc and as about CPU type
CPU = -mcpu=cortex-m4
# FPU: floating-point options
FPU = -mfpu=fpv4-sp-d16 -mfloat-abi=softfp
# BUILD: directory to use for the building process
BUILD = build
# SRC: directory of source C, assembly, and header files
SRC = src
# CSRCS: list of input C source files
CSRCS = $(shell ls $(SRC)/*.c)
# ASMSRCS: list of input assembly source files
ASMSRCS = $(shell ls $(SRC)/*.s)
# TIVAWARE_PATH: path to tivaware folder
TIVAWARE_PATH = /home/trey/etc/tiva-ware
# LIBDRIVER: binary blob from TI :(
LIBDRIVER = $(TIVAWARE_PATH)/driverlib/gcc/libdriver.a

# LD_SCRIPT: linker script
LD_SCRIPT = $(MCU).ld

# flags for compiler and linker
WFLAGS = -Wall -pedantic
DFLAGS = -DPART_$(MCU) -g
IFLAGS = -I$(TIVAWARE_PATH)

CFLAGS = -mthumb $(CPU) $(FPU) $(WFLAGS) $(DFLAGS) $(IFLAGS)
CFLAGS +=-Os -ffunction-sections -fdata-sections -MD -std=c99 -c
LDFLAGS = -T $(LD_SCRIPT) --entry ResetISR --gc-sections
ASMFLAGS = -mthumb $(CPU) $(FPU)

# PREFIX: prefixes compiler, linker, assembler, archiver, objcopy
PREFIX=arm-none-eabi


### Make Magic ###
CC = $(PREFIX)-gcc
LD = $(PREFIX)-ld
AS = $(PREFIX)-as
AR = $(PREFIX)-ar
OBJCOPY = $(PREFIX)-objcopy

LIBGCC:=$(shell $(CC) $(CFLAGS) -print-libgcc-file-name)
LIBC:=$(shell $(CC) $(CFLAGS) -print-file-name=libc.a)
LIBM:=$(shell $(CC) $(CFLAGS) -print-file-name=libm.a)

# All object files are placed in the build directory
# COBJS: list of object files that came from C source files
COBJS = $(addprefix $(BUILD)/,$(notdir $(CSRCS:.c=.c.o)))
ASMOBJS = $(addprefix $(BUILD)/,$(notdir $(ASMSRCS:.s=.s.o)))

# default: build bin
all: $(TARGET)

flash: $(TARGET)
	@echo "  lm4flash" $^
	@lm4flash -v $(TARGET)

$(BUILD)/%.c.o: $(SRC)/%.c | $(BUILD)
	@echo "  CC  " $^
	@$(CC) -o $@ $^ $(CFLAGS)

$(BUILD)/%.s.o: $(SRC)/%.s | $(BUILD)
	@echo "  AS  " $^
	@$(AS) -o $@ $^ $(ASMFLAGS)

# Is this really needed?
#$(BUILD)/%.a: %.a
#	@echo "  AR  " $^
#	@$(AR) -cr $@ $^

$(BUILD)/$(TARGET).axf: $(COBJS) $(ASMOBJS)
	@echo "  LD  " $@
	@$(LD) $(LDFLAGS) -o $(@) $(filter %.o %.a, $(^)) $(LIBM) $(LIBC) $(LIBGCC)

$(TARGET): $(BUILD)/$(TARGET).axf
	@echo "  OBJCOPY  " $@
	@$(OBJCOPY) -O binary $< $@

$(BUILD):
	@mkdir $(BUILD)

clean:
	@echo "  Cleaning"
	@rm -rf $(BUILD)
	@rm -f $(TARGET)

