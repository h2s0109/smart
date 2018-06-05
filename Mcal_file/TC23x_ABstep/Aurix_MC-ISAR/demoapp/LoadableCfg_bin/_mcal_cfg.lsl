
// Include the CPU specific .lsl file
// The CPU is specified by the __CPU__ macro
#ifndef __CPU__
# error No CPU defined, please link with -D__CPU__=<cpu>
#endif

#define __QUOTE_ME2(x) #x
#define __QUOTE_ME(x) __QUOTE_ME2(x)
#define CPULSL_FILE __QUOTE_ME(__CPU__.lsl)
#define __LINKONLY__

#include CPULSL_FILE

// Define default external memory
// These memory definitions can be replaced by the Debug Target Configuration Wizard

#ifndef HAS_ON_CHIP_FLASH       // On-chip flash is located at 0x[8a]0000000
memory xrom_a (tag="External ROM",tag="dtc")
{
        mau = 8;
        size = 1M;
        type = rom;
         map     cached (dest=bus:sri, dest_offset=0x80000000,           size=1M);
         map not_cached (dest=bus:sri, dest_offset=0xa0000000, reserved, size=1M);
}
#endif

/* trap tab is on the reset address of BTV (cached area) */
#define IFXTRAPTAB 0x80000100	/* this is the default address (only cached area) of BTV after reset */

section_layout :tc0:linear
{
  "_lc_u_trap_tab" = (IFXTRAPTAB);
  "_lc_u_trap_tab_tc0" = (IFXTRAPTAB);

              // trapvector table for CPU0
  group (ordered, contiguous, align = 1<<5, run_addr=(IFXTRAPTAB)+0x0000)
  {
    select ".text.CPU0_TRAP_HANDLER_CODE_ROM";
  }
}

section_layout mpe:tc0:linear
{
	group  (ordered, run_addr=0xa0100000)
	{
		select ".rodata.CPU0.Private.CONFIGURATION_ECUM_PB";
	}
}

section_layout mpe:tc0:linear
{
	group  (ordered, contiguous, run_addr=0xa0100080, align = 4)
	{
		select ".rodata.CPU0.Private.LIN_LOADABLE_CHANCFG";
	}
}

section_layout mpe:tc0:linear
{
	group  (ordered, contiguous, run_addr=0xa0100200, align = 4)
	{
		select ".rodata.CPU0.Private.CONFIGURATION_PB";
	}
}

section_layout mpe:tc0:linear
{
	group DIO_LCFG_RESERVE (ordered, contiguous, run_addr = 0xa0140000)
	{
		reserved "DIO_LCFG_RESERVE" (alloc_allowed = absolute, size = 512);
	}
}

