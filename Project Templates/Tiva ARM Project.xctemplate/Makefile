#******************************************************************************
#
# Makefile - Rules for building the Project Zero Example.
#
# Copyright (c) 2012-2015 Texas Instruments Incorporated.  All rights reserved.
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
# This is part of revision 2.1.2.111 of the EK-TM4C123GXL Firmware Package.
#
#******************************************************************************

#
# PRODUCT_PART : Defines the part type that this project uses.
#
PART=___VARIABLE_tivaPart:RFC1034Identifier___

#
# PRODUCT_NAME : Defines the name of this project.
#
PRODUCT_NAME=___VARIABLE_productName:RFC1034Identifier___

#
# TIVA_ROOT : The base directory for TivaWare.
#
TIVA_ROOT=___VARIABLE_tivaRoot___

#
# The suffix for the folder where the final product will be built.
#
SUFFIX=-build

#
# Include the common make definitions.
#
include ${TIVA_ROOT}/makedefs

#
# Where to find source files that do not live in this directory.
#
VPATH=./drivers
VPATH+=${TIVA_ROOT}/utils

#
# Where to find header files that do not live in the source directory.
#
IPATH=./include
IPATH+=${TIVA_ROOT}

#
# The default rule, which causes the Project Zero Example to be built.
#
all: ${COMPILER}${SUFFIX}
all: ${COMPILER}${SUFFIX}/${PRODUCT_NAME}/${PRODUCT_NAME}.axf

#
# The rule to clean out all the build products.
#
clean:
	@rm -Rf ${COMPILER}${SUFFIX} ${wildcard *~}

#
# The rule to flash your device with your program.
#
install: all
	@openocd -f ../scripts/board/ek-tm4c123gxl.cfg -c "program ${COMPILER}${SUFFIX}/${PRODUCT_NAME}/${PRODUCT_NAME}.axf verify reset exit"

#
# The rule to create the target directory.
#
${COMPILER}${SUFFIX}:
	@mkdir -p ${COMPILER}${SUFFIX}/${PRODUCT_NAME}

#
# Rules for building the Project Zero Example.
#
${COMPILER}${SUFFIX}/${PRODUCT_NAME}/${PRODUCT_NAME}.axf: ${COMPILER}${SUFFIX}/${PRODUCT_NAME}/${PRODUCT_NAME}.o
${COMPILER}${SUFFIX}/${PRODUCT_NAME}/${PRODUCT_NAME}.axf: ${COMPILER}${SUFFIX}/${PRODUCT_NAME}/startup_${COMPILER}.o
${COMPILER}${SUFFIX}/${PRODUCT_NAME}/${PRODUCT_NAME}.axf: ${TIVA_ROOT}/driverlib/${COMPILER}/libdriver.a
${COMPILER}${SUFFIX}/${PRODUCT_NAME}/${PRODUCT_NAME}.axf: ${PRODUCT_NAME}.ld
SCATTERgcc_${PRODUCT_NAME}=${PRODUCT_NAME}.ld
ENTRY_${PRODUCT_NAME}=ResetISR
CFLAGSgcc=-DTARGET_IS_TM4C123_RB1

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${COMPILER}${SUFFIX}/${PRODUCT_NAME}/*.d} __dummy__
endif
