SECTIONS
{
  . = 0x0;
  .text : {
    bbb = .;
    *(.text)
    *(.text.r0)
    *(.text.r1)
    *(.text.r2)
  }
  .data : { *(.data) }
  .bss : { *(.bss) }
}
