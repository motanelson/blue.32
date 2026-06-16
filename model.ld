SECTIONS
{
    .=0x101000
    .text{
        *(.text)


    }
    .bss{
        *(.bss)


    }

    .data{
        *(.data)


    }
    .rodata{
        *(.rodata)


    }


}
