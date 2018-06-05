# -*- coding: utf-8 -*-

""" This file is created for tesing sort.py """
import os
#For the debugging
from copy import deepcopy
#For the performance test
import time
from sort import import_data, gen_c_h_dic, export_data, copy_mcalmodule, gen_sort

#User should set the module key value here "MODULE":[] in isort.json
THIS_DIR = os.path.dirname(__file__) 
DATABASE_PATH = os.path.realpath("{0}/Database/isort.json".format(THIS_DIR))
SPECIAL_DEST_PATH = os.path.realpath("{0}/TestResult".format(THIS_DIR))
DEST_PATH = os.path.realpath("{0}/TestResult".format(THIS_DIR))

#Go up to the dir
UPPER_DIR = os.path.realpath("{0}/../..".format(THIS_DIR))
FILE_PATH = os.path.realpath("{0}/Mcal_file".format(UPPER_DIR))

sort_data = import_data(DATABASE_PATH, "SORTING")
module_data = import_data(DATABASE_PATH, "MODULE")
sorkey_datas = import_data(DATABASE_PATH, "SORTINGKEY")
bmodule_data = import_data(DATABASE_PATH, "BASICMODULE")
smodule_data = import_data(DATABASE_PATH, "SERVICEMODULE")

# a=dict()
# a.update({"MODULEDATA":{"BASICMODULE":bmodule_data,"SERVICEMODULE":smodule_data}})
module_sort_result = gen_c_h_dic(FILE_PATH, sort_data, module_data)
smodule_sort_result = gen_c_h_dic(FILE_PATH, sort_data, smodule_data, True)
smodule_sort_resultcopy = deepcopy(smodule_sort_result)

#Test the sorting time
start_time = time.time()
refine_result = gen_sort(module_sort_result, smodule_sort_resultcopy, sorkey_datas)
end_time = time.time() - start_time
print("--- %s seconds ---" % (end_time))

#Generate the sorting result
export_data('sort_result1.json', module_sort_result)
export_data('sort_result2.json', smodule_sort_result)
export_data('sort_result3.json', smodule_sort_resultcopy)
export_data('sort_result4.json', refine_result)

copy_mcalmodule(module_sort_result, DEST_PATH)
copy_mcalmodule(refine_result, SPECIAL_DEST_PATH, smodule=1)
