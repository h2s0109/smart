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
if sys.platform == "win32":
    base = "Win32GUI"
executables = [
    Executable('SmartCopyMain.py', base=base,
               targetName='Smartcopy.exe', icon='smart.ico')
]
include_files = ['Ico/', 'Database/']
options = {
    'build_exe': {"include_files": include_files}
}
setup(name='Smartcopy',
      version='1.0',
      description='Smartcopycript',
      executables=executables,
      options=options
      )
