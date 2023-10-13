#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Fan_Contraller_System.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/Fan_Contraller_System.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_layer/LCD/ecu_lcd.c ECU_layer/Motor/ecu_motor.c MCAL_layer/ADC/adc.c MCAL_layer/CCP/ccp.c MCAL_layer/GPIO/gpio.c MCAL_layer/Interrupt/interrupt_internal.c MCAL_layer/Interrupt/interrupt_manager.c MCAL_layer/TIMER2/timer2.c Fan_contraller.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 ${OBJECTDIR}/ECU_layer/Motor/ecu_motor.p1 ${OBJECTDIR}/MCAL_layer/ADC/adc.p1 ${OBJECTDIR}/MCAL_layer/CCP/ccp.p1 ${OBJECTDIR}/MCAL_layer/GPIO/gpio.p1 ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.p1 ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.p1 ${OBJECTDIR}/MCAL_layer/TIMER2/timer2.p1 ${OBJECTDIR}/Fan_contraller.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d ${OBJECTDIR}/ECU_layer/Motor/ecu_motor.p1.d ${OBJECTDIR}/MCAL_layer/ADC/adc.p1.d ${OBJECTDIR}/MCAL_layer/CCP/ccp.p1.d ${OBJECTDIR}/MCAL_layer/GPIO/gpio.p1.d ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.p1.d ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.p1.d ${OBJECTDIR}/MCAL_layer/TIMER2/timer2.p1.d ${OBJECTDIR}/Fan_contraller.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 ${OBJECTDIR}/ECU_layer/Motor/ecu_motor.p1 ${OBJECTDIR}/MCAL_layer/ADC/adc.p1 ${OBJECTDIR}/MCAL_layer/CCP/ccp.p1 ${OBJECTDIR}/MCAL_layer/GPIO/gpio.p1 ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.p1 ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.p1 ${OBJECTDIR}/MCAL_layer/TIMER2/timer2.p1 ${OBJECTDIR}/Fan_contraller.p1

# Source Files
SOURCEFILES=ECU_layer/LCD/ecu_lcd.c ECU_layer/Motor/ecu_motor.c MCAL_layer/ADC/adc.c MCAL_layer/CCP/ccp.c MCAL_layer/GPIO/gpio.c MCAL_layer/Interrupt/interrupt_internal.c MCAL_layer/Interrupt/interrupt_manager.c MCAL_layer/TIMER2/timer2.c Fan_contraller.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/Fan_Contraller_System.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1: ECU_layer/LCD/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LCD" 
	@${RM} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 ECU_layer/LCD/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.d ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/Motor/ecu_motor.p1: ECU_layer/Motor/ecu_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Motor" 
	@${RM} ${OBJECTDIR}/ECU_layer/Motor/ecu_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Motor/ecu_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Motor/ecu_motor.p1 ECU_layer/Motor/ecu_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Motor/ecu_motor.d ${OBJECTDIR}/ECU_layer/Motor/ecu_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Motor/ecu_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/ADC/adc.p1: MCAL_layer/ADC/adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_layer/ADC/adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/ADC/adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/ADC/adc.p1 MCAL_layer/ADC/adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/ADC/adc.d ${OBJECTDIR}/MCAL_layer/ADC/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/ADC/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/CCP/ccp.p1: MCAL_layer/CCP/ccp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/CCP" 
	@${RM} ${OBJECTDIR}/MCAL_layer/CCP/ccp.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/CCP/ccp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/CCP/ccp.p1 MCAL_layer/CCP/ccp.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/CCP/ccp.d ${OBJECTDIR}/MCAL_layer/CCP/ccp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/CCP/ccp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/GPIO/gpio.p1: MCAL_layer/GPIO/gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/GPIO/gpio.p1 MCAL_layer/GPIO/gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/GPIO/gpio.d ${OBJECTDIR}/MCAL_layer/GPIO/gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/GPIO/gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.p1: MCAL_layer/Interrupt/interrupt_internal.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.p1 MCAL_layer/Interrupt/interrupt_internal.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.d ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.p1: MCAL_layer/Interrupt/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.p1 MCAL_layer/Interrupt/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.d ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/TIMER2/timer2.p1: MCAL_layer/TIMER2/timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/TIMER2" 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER2/timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER2/timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/TIMER2/timer2.p1 MCAL_layer/TIMER2/timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/TIMER2/timer2.d ${OBJECTDIR}/MCAL_layer/TIMER2/timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/TIMER2/timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Fan_contraller.p1: Fan_contraller.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Fan_contraller.p1.d 
	@${RM} ${OBJECTDIR}/Fan_contraller.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Fan_contraller.p1 Fan_contraller.c 
	@-${MV} ${OBJECTDIR}/Fan_contraller.d ${OBJECTDIR}/Fan_contraller.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Fan_contraller.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1: ECU_layer/LCD/ecu_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/LCD" 
	@${RM} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1 ECU_layer/LCD/ecu_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.d ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/LCD/ecu_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/Motor/ecu_motor.p1: ECU_layer/Motor/ecu_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/Motor" 
	@${RM} ${OBJECTDIR}/ECU_layer/Motor/ecu_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/Motor/ecu_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_layer/Motor/ecu_motor.p1 ECU_layer/Motor/ecu_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/Motor/ecu_motor.d ${OBJECTDIR}/ECU_layer/Motor/ecu_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/Motor/ecu_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/ADC/adc.p1: MCAL_layer/ADC/adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_layer/ADC/adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/ADC/adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/ADC/adc.p1 MCAL_layer/ADC/adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/ADC/adc.d ${OBJECTDIR}/MCAL_layer/ADC/adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/ADC/adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/CCP/ccp.p1: MCAL_layer/CCP/ccp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/CCP" 
	@${RM} ${OBJECTDIR}/MCAL_layer/CCP/ccp.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/CCP/ccp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/CCP/ccp.p1 MCAL_layer/CCP/ccp.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/CCP/ccp.d ${OBJECTDIR}/MCAL_layer/CCP/ccp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/CCP/ccp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/GPIO/gpio.p1: MCAL_layer/GPIO/gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/GPIO/gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/GPIO/gpio.p1 MCAL_layer/GPIO/gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/GPIO/gpio.d ${OBJECTDIR}/MCAL_layer/GPIO/gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/GPIO/gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.p1: MCAL_layer/Interrupt/interrupt_internal.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.p1 MCAL_layer/Interrupt/interrupt_internal.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.d ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_internal.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.p1: MCAL_layer/Interrupt/interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.p1 MCAL_layer/Interrupt/interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.d ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Interrupt/interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/TIMER2/timer2.p1: MCAL_layer/TIMER2/timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/TIMER2" 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER2/timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/TIMER2/timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_layer/TIMER2/timer2.p1 MCAL_layer/TIMER2/timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/TIMER2/timer2.d ${OBJECTDIR}/MCAL_layer/TIMER2/timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/TIMER2/timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Fan_contraller.p1: Fan_contraller.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Fan_contraller.p1.d 
	@${RM} ${OBJECTDIR}/Fan_contraller.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Fan_contraller.p1 Fan_contraller.c 
	@-${MV} ${OBJECTDIR}/Fan_contraller.d ${OBJECTDIR}/Fan_contraller.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Fan_contraller.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/Fan_Contraller_System.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Fan_Contraller_System.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Fan_Contraller_System.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/Fan_Contraller_System.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/Fan_Contraller_System.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/Fan_Contraller_System.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mno-default-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/Fan_Contraller_System.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
