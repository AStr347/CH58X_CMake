add_subdirectory(adc)
add_subdirectory(clk)
add_subdirectory(flash)
add_subdirectory(gpio)
add_subdirectory(i2c)
add_subdirectory(pwm)
add_subdirectory(pwr)
add_subdirectory(spi)
add_subdirectory(sys)
add_subdirectory(timer)
add_subdirectory(uart)
add_subdirectory(usbdev)
add_subdirectory(usbhost)

SLIB_INIT(
    SRCS    common/core_riscv.c
    INCLUDE common/include
    PUB_REQ libISP583.a adc clk flash gpio i2c pwm pwr spi sys timer uart usbdev usbhost
)

target_link_directories(StdPeriphDriver PUBLIC common)