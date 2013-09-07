################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Class.cpp \
../src/L002HelloCPP.cpp \
../src/Man.cpp \
../src/People.cpp 

OBJS += \
./src/Class.o \
./src/L002HelloCPP.o \
./src/Man.o \
./src/People.o 

CPP_DEPS += \
./src/Class.d \
./src/L002HelloCPP.d \
./src/Man.d \
./src/People.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


