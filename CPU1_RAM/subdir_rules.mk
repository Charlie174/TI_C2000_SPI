################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/Applications/ti/ccs2002/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --include_path="/Users/charlie/workspace_ccstheia/try_spi_" --include_path="/Users/charlie/ti/C2000Ware_5_04_00_00" --include_path="/Users/charlie/workspace_ccstheia/try_spi_/device" --include_path="/Users/charlie/ti/C2000Ware_5_04_00_00/driverlib/f28003x/driverlib/" --include_path="/Applications/ti/ccs2002/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=RAM --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="/Users/charlie/workspace_ccstheia/try_spi_/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1147734497: ../spi_int_.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"/Applications/ti/ccs2002/ccs/utils/sysconfig_1.23.0/sysconfig_cli.sh" --script "/Users/charlie/workspace_ccstheia/try_spi_/spi_int_.syscfg" -o "syscfg" -s "/Users/charlie/ti/C2000Ware_5_04_00_00/.metadata/sdk.json" -b "/boards/LAUNCHXL_F280039C" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-1147734497 ../spi_int_.syscfg
syscfg/board.h: build-1147734497
syscfg/board.cmd.genlibs: build-1147734497
syscfg/board.opt: build-1147734497
syscfg/board.json: build-1147734497
syscfg/pinmux.csv: build-1147734497
syscfg/c2000ware_libraries.cmd.genlibs: build-1147734497
syscfg/c2000ware_libraries.opt: build-1147734497
syscfg/c2000ware_libraries.c: build-1147734497
syscfg/c2000ware_libraries.h: build-1147734497
syscfg/clocktree.h: build-1147734497
syscfg: build-1147734497

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"/Applications/ti/ccs2002/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcrc -Ooff --include_path="/Users/charlie/workspace_ccstheia/try_spi_" --include_path="/Users/charlie/ti/C2000Ware_5_04_00_00" --include_path="/Users/charlie/workspace_ccstheia/try_spi_/device" --include_path="/Users/charlie/ti/C2000Ware_5_04_00_00/driverlib/f28003x/driverlib/" --include_path="/Applications/ti/ccs2002/ccs/tools/compiler/ti-cgt-c2000_22.6.1.LTS/include" --define=DEBUG --define=RAM --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="/Users/charlie/workspace_ccstheia/try_spi_/CPU1_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


