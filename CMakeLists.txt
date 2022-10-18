cmake_minimum_required(VERSION 3.20.0)

# include compiler and linker options
include(CHCompilers.cmake)
# include func for fast static lib creating
include(libbuilder.cmake)

project(CH582M C ASM)
add_executable(${PROJECT_NAME}.elf src/main.c)


add_subdirectory(StdPeriphDriver)
add_subdirectory(Startup)
target_link_libraries(${PROJECT_NAME}.elf Startup CH58XPeriphDriver)

add_custom_target(BIN ALL
    COMMAND ${CMAKE_OBJCOPY_COMPILER} -O ihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
    COMMAND ${CMAKE_SIZE_COMPILER} --format=berkeley ${PROJECT_NAME}.elf
    COMMAND ${CMAKE_OBJDUMP_COMPILER} --source --all-headers --demangle --line-numbers --wide ${PROJECT_NAME}.elf > ${PROJECT_NAME}.lst
    COMMAND ${CMAKE_NM_COMPILER} -n -l -C ${PROJECT_NAME}.elf > symbol.txt
    COMMAND ${CMAKE_READELF_COMPILER} -a ${PROJECT_NAME}.elf > readelf.txt
    DEPENDS ${PROJECT_NAME}.elf
)