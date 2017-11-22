################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
LCDDriver/Sharp96x96.obj: ../LCDDriver/Sharp96x96.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Users/wangqi/workspace_v7/CSRobot_01/grlib" --include_path="/Users/wangqi/workspace_v7/CSRobot_01/LCDDriver" --include_path="/Users/wangqi/workspace_v7/CSRobot_01" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc/CMSIS" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="LCDDriver/Sharp96x96.d" --obj_directory="LCDDriver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

LCDDriver/Sharp96x96utils.obj: ../LCDDriver/Sharp96x96utils.asm $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Users/wangqi/workspace_v7/CSRobot_01/grlib" --include_path="/Users/wangqi/workspace_v7/CSRobot_01/LCDDriver" --include_path="/Users/wangqi/workspace_v7/CSRobot_01" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc/CMSIS" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="LCDDriver/Sharp96x96utils.d" --obj_directory="LCDDriver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

LCDDriver/Sharp96x96utils.obj: ../LCDDriver/Sharp96x96utils.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="/Applications/ti/ccsv7/ccs_base/arm/include" --include_path="/Users/wangqi/workspace_v7/CSRobot_01/grlib" --include_path="/Users/wangqi/workspace_v7/CSRobot_01/LCDDriver" --include_path="/Users/wangqi/workspace_v7/CSRobot_01" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc/CMSIS" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/inc" --include_path="/Applications/ti/tirtos_msp43x_2_20_00_06/products/msp432_driverlib_3_21_00_05/driverlib/MSP432P4xx" --include_path="/Applications/ti/ccsv7/tools/compiler/ti-cgt-arm_16.9.3.LTS/include" --include_path="/Applications/ti/ccsv7/ccs_base/arm/include/CMSIS" --advice:power=all --advice:power_severity=suppress --define=__MSP432P401R__ --define=TARGET_IS_MSP432P4XX --define=ccs --define=MSP432WARE -g --gcc --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="LCDDriver/Sharp96x96utils.d" --obj_directory="LCDDriver" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


