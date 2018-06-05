
from compiler import Class_comiler_path
first = 'C:/Testfolder'
second = 'C:/Testfolder/additional'
third = 'C:/Testfolderadditional'
fourth = 'C:/first'
fifth = 'C:/second'
test = Class_comiler_path()
test.hierachy_check(second, first)

import os
from pprint import pprint

THIS_DIR = os.path.dirname(__file__)
# DATABASE_PATH = os.path.realpath("{0}/..".format(THIS_DIR))
SPECIAL_DEST_PATH = os.path.realpath("{0}/Test_1".format(THIS_DIR))
SPECIAL_DEST_PATH2 = os.path.realpath("{0}/Test_1/add".format(THIS_DIR))
SPECIAL_DEST_PATH = SPECIAL_DEST_PATH.replace('\\', '/')
SPECIAL_DEST_PATH2 = SPECIAL_DEST_PATH2.replace('\\', '/')


Temp_Module = SPECIAL_DEST_PATH
Temp_Smodule = SPECIAL_DEST_PATH
result = test.Compiler_include(Temp_Module, Temp_Smodule)
pprint(result)
Temp_Module = SPECIAL_DEST_PATH
Temp_Smodule = SPECIAL_DEST_PATH2
result = test.Compiler_include(Temp_Module, Temp_Smodule)
pprint(result)
