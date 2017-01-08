################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Network/Internal/DATA_message.cpp 

OBJS += \
./src/Network/Internal/DATA_message.o 

CPP_DEPS += \
./src/Network/Internal/DATA_message.d 


# Each subdirectory must supply rules for building sources it contributes
src/Network/Internal/%.o: ../src/Network/Internal/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -I../src -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


