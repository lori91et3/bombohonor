################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F0xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
BombHonor.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
BombHonor.list \

OBJCOPY_BIN += \
BombHonor.bin \


# All Target
all: BombHonor.elf secondary-outputs

# Tool invocations
BombHonor.elf: $(OBJS) $(USER_OBJS) D:\git\bombhonor\Firmware\v0\BombHonor\STM32F030F4PX_FLASH.ld
	arm-none-eabi-gcc -o "BombHonor.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m0 -T"D:\git\bombhonor\Firmware\v0\BombHonor\STM32F030F4PX_FLASH.ld" --specs=nosys.specs -Wl,-Map="BombHonor.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

BombHonor.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "BombHonor.list"
	@echo 'Finished building: $@'
	@echo ' '

BombHonor.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "BombHonor.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
