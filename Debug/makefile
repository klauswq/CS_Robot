################################################################################
# Automatically-generated file. Do not edit!
################################################################################

CG_TOOL_ROOT := /Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS

GEN_OPTS__FLAG := --cmd_file="configPkg/compiler.opt"
GEN_CMDS__FLAG := -l"configPkg/linker.cmd"

ORDERED_OBJS += \
"./MSP_EXP432P401R.obj" \
"./Range_Read.obj" \
"./buttons.obj" \
"./heartBeatTask.obj" \
"./main.obj" \
"./motor.obj" \
"./screenTask.obj" \
"./timer2.obj" \
"./LCDDriver/Sharp96x96.obj" \
"./LCDDriver/Sharp96x96utils.obj" \
"./fonts/fontcm20b.obj" \
"./fonts/fontcm30b.obj" \
"./fonts/fontcm40b.obj" \
"./grlib/circle.obj" \
"./grlib/context.obj" \
"./grlib/image.obj" \
"./grlib/line.obj" \
"./grlib/rectangle.obj" \
"./grlib/string.obj" \
"../MSP_EXP432P401R.cmd" \
$(GEN_CMDS__FLAG) \
-l"/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx/ccs/msp432p4xx_driverlib.lib" \
-llibc.a \

-include ../makefile.init

RM := rm -rf
RMDIR := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include LCDDriver/subdir_vars.mk
-include fonts/subdir_vars.mk
-include grlib/subdir_vars.mk
-include subdir_rules.mk
-include LCDDriver/subdir_rules.mk
-include fonts/subdir_rules.mk
-include grlib/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
CSRobot_01.out \

EXE_OUTPUTS__QUOTED += \
"CSRobot_01.out" \

BIN_OUTPUTS += \
CSRobot_01.hex \

BIN_OUTPUTS__QUOTED += \
"CSRobot_01.hex" \


# All Target
all: CSRobot_01.out

# Tool invocations
CSRobot_01.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM Linker'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi -z -m"CSRobot_01.map" --heap_size=1024 --stack_size=512 -i"/Applications/ti/ccsv7/ccs_base/arm/include" -i"/Applications/ti/ccsv7/ccs_base/arm/include" -i"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/lib" -i"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="CSRobot_01_linkInfo.xml" --rom_model -o "CSRobot_01.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

CSRobot_01.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: ARM Hex Utility'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armhex" --memwidth=8 --romwidth=8 -o "CSRobot_01.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_CMDS__QUOTED)$(GEN_MISC_FILES__QUOTED)$(BIN_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)$(GEN_OPTS__QUOTED)
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-$(RM) "MSP_EXP432P401R.obj" "Range_Read.obj" "buttons.obj" "heartBeatTask.obj" "main.obj" "motor.obj" "screenTask.obj" "timer2.obj" "LCDDriver/Sharp96x96.obj" "LCDDriver/Sharp96x96utils.obj" "fonts/fontcm20b.obj" "fonts/fontcm30b.obj" "fonts/fontcm40b.obj" "grlib/circle.obj" "grlib/context.obj" "grlib/image.obj" "grlib/line.obj" "grlib/rectangle.obj" "grlib/string.obj" 
	-$(RM) "MSP_EXP432P401R.d" "Range_Read.d" "buttons.d" "heartBeatTask.d" "main.d" "motor.d" "screenTask.d" "timer2.d" "LCDDriver/Sharp96x96.d" "LCDDriver/Sharp96x96utils.d" "fonts/fontcm20b.d" "fonts/fontcm30b.d" "fonts/fontcm40b.d" "grlib/circle.d" "grlib/context.d" "grlib/image.d" "grlib/line.d" "grlib/rectangle.d" "grlib/string.d" 
	-$(RM) "LCDDriver/Sharp96x96utils.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

