################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ADC_CH_GAIN_OFFSET.cpp \
../src/ADC_LOGGER.cpp \
../src/ADC_REGISTERS_MAP.cpp \
../src/ADC_USER_CONFIG.cpp \
../src/CHANNEL_BYPASS.cpp \
../src/SIGNAL_SOURCE.cpp \
../src/main.cpp \
../src/testBench.cpp \
../src/tuv_ams_library.cpp 

OBJS += \
./src/ADC_CH_GAIN_OFFSET.o \
./src/ADC_LOGGER.o \
./src/ADC_REGISTERS_MAP.o \
./src/ADC_USER_CONFIG.o \
./src/CHANNEL_BYPASS.o \
./src/SIGNAL_SOURCE.o \
./src/main.o \
./src/testBench.o \
./src/tuv_ams_library.o 

CPP_DEPS += \
./src/ADC_CH_GAIN_OFFSET.d \
./src/ADC_LOGGER.d \
./src/ADC_REGISTERS_MAP.d \
./src/ADC_USER_CONFIG.d \
./src/CHANNEL_BYPASS.d \
./src/SIGNAL_SOURCE.d \
./src/main.d \
./src/testBench.d \
./src/tuv_ams_library.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/systemc231/include -I/usr/local/systemc-ams-2.0/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


