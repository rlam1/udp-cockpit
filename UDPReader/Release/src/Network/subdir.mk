################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Network/MessageParser.cpp \
../src/Network/NetworkListener.cpp 

OBJS += \
./src/Network/MessageParser.o \
./src/Network/NetworkListener.o 

CPP_DEPS += \
./src/Network/MessageParser.d \
./src/Network/NetworkListener.d 


# Each subdirectory must supply rules for building sources it contributes
src/Network/%.o: ../src/Network/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -UDEBUG -I../src -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


