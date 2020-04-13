################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../include \
../src


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../main.c \
../src/LCD.c \
../src/PORT.c \
../src/PWM.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
main.o \
src/LCD.o \
src/PORT.o \
src/PWM.o

OBJS_AS_ARGS +=  \
main.o \
src/LCD.o \
src/PORT.o \
src/PWM.o

C_DEPS +=  \
main.d \
src/LCD.d \
src/PORT.d \
src/PWM.d

C_DEPS_AS_ARGS +=  \
main.d \
src/LCD.d \
src/PORT.d \
src/PWM.d

OUTPUT_FILE_PATH +=Robo_Stevey.elf

OUTPUT_FILE_PATH_AS_ARGS +=Robo_Stevey.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Programmes\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Programmes\AtmelStudio\7.0\Packs\atmel\ATmega_DFP\1.3.300\include" -I"../include" -I"../src"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -B "D:\Programmes\AtmelStudio\7.0\Packs\atmel\ATmega_DFP\1.3.300\gcc\dev\atmega328p" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/LCD.o: ../src/LCD.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Programmes\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Programmes\AtmelStudio\7.0\Packs\atmel\ATmega_DFP\1.3.300\include" -I"../include" -I"../src"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -B "D:\Programmes\AtmelStudio\7.0\Packs\atmel\ATmega_DFP\1.3.300\gcc\dev\atmega328p" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/PORT.o: ../src/PORT.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Programmes\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Programmes\AtmelStudio\7.0\Packs\atmel\ATmega_DFP\1.3.300\include" -I"../include" -I"../src"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -B "D:\Programmes\AtmelStudio\7.0\Packs\atmel\ATmega_DFP\1.3.300\gcc\dev\atmega328p" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

src/PWM.o: ../src/PWM.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Programmes\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG  -I"D:\Programmes\AtmelStudio\7.0\Packs\atmel\ATmega_DFP\1.3.300\include" -I"../include" -I"../src"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -g2 -Wall -mmcu=atmega328p -B "D:\Programmes\AtmelStudio\7.0\Packs\atmel\ATmega_DFP\1.3.300\gcc\dev\atmega328p" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)D:\Programmes\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Robo_Stevey.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,--gc-sections -mmcu=atmega328p -B "D:\Programmes\AtmelStudio\7.0\Packs\atmel\ATmega_DFP\1.3.300\gcc\dev\atmega328p"  
	@echo Finished building target: $@
	"D:\Programmes\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Robo_Stevey.elf" "Robo_Stevey.hex"
	"D:\Programmes\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Robo_Stevey.elf" "Robo_Stevey.eep" || exit 0
	"D:\Programmes\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Robo_Stevey.elf" > "Robo_Stevey.lss"
	"D:\Programmes\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Robo_Stevey.elf" "Robo_Stevey.srec"
	"D:\Programmes\AtmelStudio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "Robo_Stevey.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Robo_Stevey.elf" "Robo_Stevey.a" "Robo_Stevey.hex" "Robo_Stevey.lss" "Robo_Stevey.eep" "Robo_Stevey.map" "Robo_Stevey.srec" "Robo_Stevey.usersignatures"
	