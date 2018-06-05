
from compiler import Class_comiler_path
first = 'C:/Testfolder'
second = 'C:/Testfolder/additional'
third = 'C:/Testfolderadditional'
fourth = 'C:/first'
fifth = 'C:/second'
test = Class_comiler_path()
test.hierachy_check(second,first)

Temp_Module ='E:/WorkSpace/회사업무/Git/SmartCopy/Test2'
Temp_Smodule ='E:/WorkSpace/회사업무/Git/SmartCopy/Test2'
test.Compiler_include(Temp_Module, Temp_Smodule)
Temp_Module ='E:/WorkSpace/회사업무/Git/SmartCopy/Test4'
Temp_Smodule ='E:/WorkSpace/회사업무/Git/SmartCopy/Test4/add'
test.Compiler_include(Temp_Module, Temp_Smodule)
Temp_Module ='E:/WorkSpace/회사업무/Git/SmartCopy/Test2'
Temp_Smodule ='E:/WorkSpace/회사업무/Git/SmartCopy/Test2'
test.Compiler_include(Temp_Module, Temp_Smodule)
Temp_Module ='E:/WorkSpace/회사업무/Git/SmartCopy/Test4'
Temp_Smodule ='E:/WorkSpace/회사업무/Git/SmartCopy/Test4/add'
test.Compiler_include(Temp_Smodule, Temp_Module)