################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../._main.c \
../task.c \
../test_main.c \
../thread.c 

OBJS += \
./._main.o \
./task.o \
./test_main.o \
./thread.o 

C_DEPS += \
./._main.d \
./task.d \
./test_main.d \
./thread.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARTIK GCC C Compiler'
	arm-none-eabi-gcc  -D__TINYARA__ -I"C:/ARTIK/SDK/A053/v1.7/libsdk/typical/include" -I"C:/ARTIK/SDK/A053/v1.7/libsdk/typical/include/apps" -I"C:/ARTIK/SDK/A053/v1.7/libsdk/typical/framework_include" -I"C:/ARTIK/SDK/A053/v1.7/libsdk/typical/apps_include" -I"C:/ARTIK/SDK/A053/v1.7/libsdk/typical/apps_include/netutils" -I"C:/ARTIK/SDK/A053/v1.7/libsdk/typical/artik-sdk_include" -I"C:/ARTIK/SDK/A053/v1.7/libsdk/typical/artik-sdk_include/base" -I"C:/ARTIK/SDK/A053/v1.7/libsdk/typical/artik-sdk_include/connectivity" -I"C:/ARTIK/SDK/A053/v1.7/libsdk/typical/artik-sdk_include/systemio" -I"C:/ARTIK/SDK/A053/v1.7/libsdk/typical/artik-sdk_include/wifi" -I"C:/ARTIK/SDK/A053/v1.7/libsdk/typical/artik-sdk_include/lwm2m" -I"C:/ARTIK/SDK/A053/v1.7/libsdk/typical/artik-sdk_include/mqtt" -O0 -ffunction-sections -fdata-sections -fno-builtin -fno-strict-aliasing -fno-strength-reduce -fomit-frame-pointer -Wstrict-prototypes -Wshadow -Wno-implicit-function-declaration -Wno-unused-function -Wno-unused-but-set-variable -DAPP_STACKSIZE=18432 -DAPP_PRIORITY=100 -mcpu=cortex-r4 -mfpu=vfpv3 -g -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


