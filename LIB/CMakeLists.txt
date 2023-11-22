SLIB_INIT(
    SRCS bogus.c
    INCLUDE include
    PUB_REQ libCH58xBLE.a
)

target_link_directories(LIB PUBLIC raw)