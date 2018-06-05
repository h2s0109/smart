#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  unsigned long Sync, Sfi, Fid, Plc;
  unsigned long vCrcReg, vCrcPoly, vNextBitCrcReg, vCrcNext;
  unsigned long Header, vNextBitHeader ;
  unsigned int length ;

  if(argc < 5)
  {
    printf("Error: Too few arguments \n");
    printf("Usage: HeaderCRC <SYNC_bit> <SFI_Bit> <FrameId> <PLC> \n", argv[0]);
    return 1 ;
  }
  Sync = atoi(argv[1]) ;
  Sfi = atoi(argv[2]) ; 
  Fid = atoi(argv[3]) ;
  Plc = atoi(argv[4]) ;
  
  Header = (Sync << 19) | ( Sfi << 18) | (Fid << 7) | Plc ;

  vCrcReg = 26 ; /* Initial value for Header CRC */

  vCrcPoly = 901 ;

  /*  printf("Size of unsinged int = %d\n", sizeof(unsigned long)); */

  length = 20 ;

  printf("Header = 0x%x%x \n", (unsigned int)(Header >> 16), Header);
  
  Header = Header << 12 ;
  vCrcReg = vCrcReg << 21 ;

  vCrcPoly = vCrcPoly << 21 ;

  /* printf("MSB, vNextBitHeader, vNextBitCrcReg, vCrcNext, vCrcReg\n"); */
  
  while(length)
  {
    vNextBitHeader = Header & 0x80000000 ;
    vNextBitCrcReg = vCrcReg & 0x80000000 ;
    vCrcNext = vNextBitHeader ^ vNextBitCrcReg ;

    Header = Header << 1 ;
    vCrcReg = vCrcReg << 1 ;

    if(vCrcNext)
    {
      /* printf("      ==> vCrcReg (0x%4x) ^ vCrcPoly (0x%4x) = ",(unsigned int)(vCrcReg >> 21), (unsigned int)(vCrcPoly >> 21)); */
   
      vCrcReg = vCrcReg ^ vCrcPoly ;
      /* printf("%4x \n",(unsigned int)(vCrcReg >> 21)); */
    }
    
    /* 
    printf("%d :", (length - 1)) ;
    printf("%4x, ", (unsigned int)(vNextBitHeader >> 16));
    printf("%4x, ", (unsigned int) (vNextBitCrcReg >> 16));
    printf("%4x, ",    (unsigned int) (vCrcNext >> 16));
    printf("%4x \n",(unsigned int)(vCrcReg >> 21));
    */
    length-- ;
  }

  vCrcReg = vCrcReg >> 21 ;

  printf("HeaderCRC = 0x%x", (unsigned int)vCrcReg);
  
  return 0 ;
}
