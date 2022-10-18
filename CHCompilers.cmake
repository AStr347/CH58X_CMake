# flags for not try 'test project build'
set(CMAKE_ASM_COMPILER_FORCED true)
set(CMAKE_C_COMPILER_FORCED true)
set(CMAKE_CXX_COMPILER_FORCED true)

# for disable '-Wl,--major-image-version,0,--minor-image-version,0'
set(CMAKE_SYSTEM_NAME Generic)

# linker options - ok
set(CMAKE_EXE_LINKER_FLAGS "-g -T\"${CMAKE_SOURCE_DIR}/Ld/Link.ld\" -nostartfiles -Xlinker --gc-sections -static --specs=nano.specs --specs=nosys.specs")
# compiler options may be can some clear
add_compile_options(-march=rv32imac -mabi=ilp32 -mcmodel=medany -msmall-data-limit=8 -Os -fsigned-char)
add_compile_options(-ffunction-sections -fdata-sections -fpack-struct -fshort-enums -flto)
add_compile_options(-fmessage-length=0 -fomit-frame-pointer -fno-strict-aliasing -fshort-wchar -fuse-ld=bfd)
add_compile_options(-Wall -Wno-nonnull-compare -Wextra -Wshadow -Werror)