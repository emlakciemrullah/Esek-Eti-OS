ENTRY(start)

SECTIONS
{
    /* Start the kernel at 1MB */
    . = 1M;

    /* Multiboot header must be within the first 8KB */
    .multiboot :
    {
        KEEP(*(.multiboot))
    }

    /* Code */
    .text :
    {
        *(.text)
    }

    /* Global constructors */
    .ctors :
    {
        __ctors_start = .;
        KEEP(*(.ctors*))
        __ctors_end = .;
    }

    /* Read-only data */
    .rodata :
    {
        *(.rodata*)
    }

    /* Initialized data */
    .data :
    {
        *(.data)
    }

    /* Uninitialized data (zeroed by boot code or manually) */
    .bss :
    {
        *(COMMON)
        *(.bss)
    }
}
