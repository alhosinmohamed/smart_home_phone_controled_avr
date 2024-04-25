################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
smart\ home\ avr.lss \

FLASH_IMAGE += \
smart\ home\ avr.hex \

EEPROM_IMAGE += \
smart\ home\ avr.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: smart\ home\ avr.elf secondary-outputs

# Tool invocations
smart\ home\ avr.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,smart home avr.map -mmcu=atmega32 -o "smart home avr.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

smart\ home\ avr.lss: smart\ home\ avr.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S smart home avr.elf  >"smart home avr.lss"
	@echo 'Finished building: $@'
	@echo ' '

smart\ home\ avr.hex: smart\ home\ avr.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex smart home avr.elf  "smart home avr.hex"
	@echo 'Finished building: $@'
	@echo ' '

smart\ home\ avr.eep: smart\ home\ avr.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex smart home avr.elf  "smart home avr.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: smart\ home\ avr.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 smart home avr.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) "smart home avr.elf"
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
