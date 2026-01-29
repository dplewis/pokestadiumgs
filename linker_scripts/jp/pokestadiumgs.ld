SECTIONS
{
    __romPos = 0;
    _gp = 0x0;
    header_ROM_START = __romPos;
    header_VRAM = ADDR(.header);
    .header 0x0 : AT(header_ROM_START) SUBALIGN(16)
    {
        FILL(0x00000000);
        header_DATA_START = .;
        header = .;
        build/asm/jp/header.o(.data);
        header_DATA_END = .;
        header_DATA_SIZE = ABSOLUTE(header_DATA_END - header_DATA_START);
    }
    __romPos += SIZEOF(.header);
    header_ROM_END = __romPos;
    header_VRAM_END = .;

    boot_ROM_START = __romPos;
    boot_VRAM = ADDR(.boot);
    .boot 0xA4000040 : AT(boot_ROM_START) SUBALIGN(16)
    {
        FILL(0x00000000);
        boot_TEXT_START = .;
        build/asm/jp/boot.o(.text);
        boot_TEXT_END = .;
        boot_TEXT_SIZE = ABSOLUTE(boot_TEXT_END - boot_TEXT_START);
        boot_DATA_START = .;
        boot = .;
        build/asm/jp/boot.o(.data);
        bootcode_font = .;
        build/assets/jp/bootcode_font.o(.data);
        boot_DATA_END = .;
        boot_DATA_SIZE = ABSOLUTE(boot_DATA_END - boot_DATA_START);
        boot_RODATA_START = .;
        build/asm/jp/boot.o(.rodata);
        boot_RODATA_END = .;
        boot_RODATA_SIZE = ABSOLUTE(boot_RODATA_END - boot_RODATA_START);
    }
    boot_bss_VRAM = ADDR(.boot_bss);
    .boot_bss (NOLOAD) : SUBALIGN(16)
    {
        FILL(0x00000000);
        boot_BSS_START = .;
        build/asm/jp/boot.o(.bss);
        boot_BSS_END = .;
        boot_BSS_SIZE = ABSOLUTE(boot_BSS_END - boot_BSS_START);
    }
    __romPos += SIZEOF(.boot);
    boot_ROM_END = __romPos;
    boot_VRAM_END = .;
    __romPos = ALIGN(__romPos, 16);
    . = ALIGN(., 16);

    text_ROM_START = __romPos;
    text_VRAM = ADDR(.text);
    .text 0x80000400 : AT(text_ROM_START) SUBALIGN(16)
    {
        FILL(0x00000000);
        text_TEXT_START = .;
        build/asm/jp/entry.o(.text);
        build/asm/jp/pre_main.o(.text);
        text_TEXT_END = .;
        text_TEXT_SIZE = ABSOLUTE(text_TEXT_END - text_TEXT_START);
        text_DATA_START = .;
        entry = .;
        build/asm/jp/entry.o(.data);
        pre_main = .;
        build/asm/jp/pre_main.o(.data);
        _2060 = .;
        build/assets/jp/2060.o(.data);
        text_DATA_END = .;
        text_DATA_SIZE = ABSOLUTE(text_DATA_END - text_DATA_START);
        text_RODATA_START = .;
        build/asm/jp/entry.o(.rodata);
        build/asm/jp/pre_main.o(.rodata);
        text_RODATA_END = .;
        text_RODATA_SIZE = ABSOLUTE(text_RODATA_END - text_RODATA_START);
    }
    text_bss_VRAM = ADDR(.text_bss);
    .text_bss (NOLOAD) : SUBALIGN(16)
    {
        FILL(0x00000000);
        text_BSS_START = .;
        build/asm/jp/entry.o(.bss);
        build/asm/jp/pre_main.o(.bss);
        text_BSS_END = .;
        text_BSS_SIZE = ABSOLUTE(text_BSS_END - text_BSS_START);
    }
    __romPos += SIZEOF(.text);
    text_ROM_END = __romPos;
    text_VRAM_END = .;
    __romPos = ALIGN(__romPos, 16);
    . = ALIGN(., 16);

    /DISCARD/ :
    {
        *(*);
    }
}
