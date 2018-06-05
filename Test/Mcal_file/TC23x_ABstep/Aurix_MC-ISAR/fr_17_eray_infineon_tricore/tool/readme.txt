How to use HeaderCRC.exe?
--------------------------
- Open DOS window
- Type 
    HeaderCRC <SYNC_bit> <SFI_Bit> <FrameId> <PLC> 
  Example: HeaderCRC 1 1 3 4
  
  For example input, you will see following output
  Header = c184
  HeaderCRC = 7c7

- Use HeaderCRC value in the manual configuration  