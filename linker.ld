ENTRY(start)

SECTIONS
{
    . = 1M;

    .multiboot :
    {
        KEEP(*(.multiboot))
    }

    .text :
    {
        *(.text)
    }

    .ctors :
    {
        __ctors_start = .;
        KEEP(*(.ctors*))
        __ctors_end = .;
    }

    .rodata :
    {
        *(.rodata*)
    }

    .data :
    {
        *(.data)
    }

    .bss :
    {
        *(COMMON)
        *(.bss)
    }
}
