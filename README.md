# CH58X CMake

## Instruments

* CMake 3.25.0
* MounRiver Studio Community toolchain
  * RISC-V Embedded GCC (riscv gcc 8.2.0)
  * OpenOCD
* VSCode Extensions
  * C/C++
  * CMake
  * CMake Tools
  * Native Debug

## Flash/Debug

For flashing and debuging set self paths into '.vscode/settings.json'

## Build

Add to 'cmake-tool-kits.json' all parts of compiler like this:

(for windows path: 'C:\Users\\%username%\AppData\Local\CMakeTools\cmake-tools-kits.json')

```json
{
    "name": "GCC 8.2.0 riscv-none-embed",
    "compilers": {
        "C": "...RISC-V Embedded GCC/bin/riscv-none-embed-gcc.exe",
        "CXX": "...RISC-V Embedded GCC/bin/riscv-none-embed-g++.exe",
        "LINKER": "...RISC-V Embedded GCC/bin/riscv-none-embed-ld.exe",
        "ASM": "...RISC-V Embedded GCC/bin/riscv-none-embed-gcc.exe",
        "OBJCOPY": "...RISC-V Embedded GCC/bin/riscv-none-embed-objcopy.exe",
        "OBJDUMP": "...RISC-V Embedded GCC/bin/riscv-none-embed-objdump.exe",
        "SIZE": "...RISC-V Embedded GCC/bin/riscv-none-embed-size.exe",
        "READELF": "...RISC-V Embedded GCC/bin/riscv-none-embed-readelf.exe",
        "ADDR2LINE": "...RISC-V Embedded GCC/bin/riscv-none-embed-addr2line.exe",
        "AR": "...RISC-V Embedded GCC/bin/riscv-none-embed-ar.exe",
        "NM": "...RISC-V Embedded GCC/bin/riscv-none-embed-nm.exe"
    }
}
```

Configure and build project throught 'CMake Tools' extension
