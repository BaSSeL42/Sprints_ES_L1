################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/DIO/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/Button/subdir.mk
-include App/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
sprints_LED_V1.lss \

FLASH_IMAGE += \
sprints_LED_V1.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: sprints_LED_V1.elf secondary-outputs

# Tool invocations
sprints_LED_V1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,sprints_LED_V1.map -mmcu=atmega32 -o "sprints_LED_V1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

sprints_LED_V1.lss: sprints_LED_V1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S sprints_LED_V1.elf  >"sprints_LED_V1.lss"
	@echo 'Finished building: $@'
	@echo ' '

sprints_LED_V1.hex: sprints_LED_V1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex sprints_LED_V1.elf  "sprints_LED_V1.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: sprints_LED_V1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 sprints_LED_V1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) sprints_LED_V1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
