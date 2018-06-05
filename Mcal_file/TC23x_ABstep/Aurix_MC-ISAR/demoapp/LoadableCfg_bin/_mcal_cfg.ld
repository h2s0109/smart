OUTPUT_FORMAT("elf32-tricore")
OUTPUT_ARCH(tricore)


__ISTACK_SIZE = DEFINED (__ISTACK_SIZE) ? __ISTACK_SIZE : 8K;
__USTACK_SIZE = DEFINED (__USTACK_SIZE) ? __USTACK_SIZE : 8K;
__HEAP_SIZE = DEFINED (__HEAP_SIZE) ? __HEAP_SIZE : 4K ;
__CSA_SIZE = DEFINED (__CSA_SIZE) ? __CSA_SIZE : 16K ;

__INTTAB_START_ADDR        = 0x800F0000 ;

MEMORY
{

    PMU_PFLASH0_BMI (rx!p): org = 0x80000000, len = 32  /* boot header */
    PMU_STARTUP (rx!p)    : org = 0x80000020, len = 0xE0  /* startup code */
    PMU_TRAPTAB (rx!p): org = 0x80000100, len = 0x300 /* trap vector tables */
    PMU_INTTAB_TC0 (rx!p):  org = 0x800F0000, len = 0x2000 /* interrupt vector table */
    PMU_USER_FUNCS (rx!p):  org = 0x8002E000, len = 0x2000

    PMU_PFLASH0 (rx!p)  : org = 0x80030000, len = 320K /*Program Flash Memory (PFLASH0)*/
                PMU_PFLASH0_CONST (rx!p): org = 0x80080000, len = 128K    
    PMU_PFLASH1 (rx!p)  : org = 0x80200000, len = 2M  /*Program Flash Memory (PFLASH1)*/
    CONFIG_DATA (rx!p): org = 0xA0100000, len = 20K  
    CONFIG_DIO_DATA (rx!p): org = 0xA0140000, len = 512  /*Program Flash Memory (PFLASH1)*/ 
    

    CPU0_PMI_PSPR (wx!p): org = 0x70100000, len = 24K   /*Scratch-Pad RAM (PSPR)*/

    /* 0x100 bytes of DSPR is reserved for sbst_tcx_dspr */
    CPU0_DMI_DSPR (w!xp): org = 0x70000100, len = 72K - 12K /*Local Data RAM (DSPR)*/
    DMI_DSPR (w!xp)     : org = 0xD0019000, len = 12K /*Local Data RAM (DSPR)*/


    /* reserve memory for flash routines */
    FLS_ERASE_PFLASH0 (rx!p): org = 0x80001100, len = 0x200  /*Program Flash Memory (PFLASH0)*/
    FLS_WRITE_PFLASH0 (rx!p): org = 0x80001300, len = 0x200  /*Program Flash Memory (PFLASH0)*/
    FLS_ERASE_SRAM (w!xp):  org = 0x701011C8, len = 0x200  /*Global Scratch-Pad RAM (PSPR)*/
    FLS_WRITE_SRAM (w!xp):  org = 0x70101100, len = 0x200  /*Global Scratch-Pad RAM (PSPR)*/

       
}


SECTIONS
{

  .CONFIGURATION_ECUM_PB 0xa0100000   :
  {
    KEEP(*(.rodata.CPU0.Private.CONFIGURATION_ECUM_PB))          
  }> CONFIG_DATA

  .LIN_LOADABLE_CHANCFG 0xa0100080   :
  {
    KEEP(*(.rodata.CPU0.Private.LIN_LOADABLE_CHANCFG))          
  }> CONFIG_DATA

  .CONFIGURATION_PB 0xa0100200   :
  {
    KEEP(*(.rodata.CPU0.Private.CONFIGURATION_PB))          
  }> CONFIG_DATA

  .DIO_LCFG_RESERVED :
  {
    PROVIDE(DIO_LCFG_RESERVED_START = .);
    . = . + 512;
    PROVIDE(DIO_LCFG_RESERVED_END = .);
  }> CONFIG_DIO_DATA
}

