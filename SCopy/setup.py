# -*- coding: utf-8 -*-

# A very simple setup script to create a single executable
#
# hello.py is a very simple 'Hello, world' type script which also displays the
# environment in which the script runs
#
# Run the build process by running the command 'python setup.py build'
#
# If everything works well you should find a subdirectory in the build
# subdirectory that contains the files needed to run the script without Python

from cx_Freeze import setup, Executable
import sys
base = None
import os
import re
exe_path =dict()
exe_path['main'] ='SmartCopyMain.py'
exe_path['Ico'] = 'Ico\\smart.ico'
inc_path = ['Ico', 'Database']

current_path= os.getcwd()
current_path_check = os.path.split(current_path)
count = 0
if re.match('SCopy', current_path_check[1]):
    print("do nothing")
else:
    for exe_path_temp in exe_path:
        exe_path[exe_path_temp] = 'scopy\\'+ exe_path[exe_path_temp]
    for temp_inc_path in inc_path:
        inc_path[count] = 'scopy\\'+temp_inc_path
        count+=1

if sys.platform == "win32":
    base = "Win32GUI"
executables = [
    Executable(exe_path['main'], base=base,
               targetName='Smartcopy.exe', icon=exe_path['Ico'])
]

options = {
    'build_exe': {'build_exe':'Output',"include_files": inc_path,"packages": ['lxml', 'gzip'],"excludes": ['html','http','email','unittest','pydoc_data']}
}

setup(name='Smartcopy',
      version='2.0',
      description='Smartcopycript',
      executables=executables,
      options=options
      )
