"""
MCAL configuration files automatic copy module.

This module provides easy way to copy the MCAL generated file to project folder.

Available functions:
- auto_copy: Copy the file from source folder to destination folder.
"""
__all__ = ["mcal_fastcopy"]

import shutil
import os
import re


class mcal_fastcopy:
    """Classify the modified files and copy the MCAL configuration files.

    Finds the files which are modified only date comment,
    makes the file list.
    the files on the list only will be copied from source folder to destination folder.

    Public attributes:
    - filecopy: Copy the file from source folder to destination folder.
    """

    def __init__(self):
        print("*" * 70)
        print("Copy procedure start...")
        print("*" * 70)
        return

    def __del__(self):
        print("*" * 70)
        print("Copy procedure end...")
        print("*" * 70)
        return

    def _path_compatibility(self, path):
        # TODO: win 10 eng ver, win 7 eng ver need to check.
        """ Change the path expression for the compatibility

        For the path compatibility, 
        this function will change the diretory seprator symbol
        from '/' to '\\'

        Args: 
            path: Directory path.
        return:
            replace_path: Seprator symbol changed path.
       """
        replace_path = path.replace('/', '\\')
        return replace_path

    def _path_exist_check(self, dir_hc_arg, flag_arg):
        """" Check the path existence.

        According to the flag, code flow is different
        when there is no destination, folder will be created.
        when there is no source, code will be termintae.

        Args:
            dir_hc_arg: h,c file folder path.
                dir_hc_arg[0]: h folder path
                dir_hc_arg[1]: c folder path
            flag_arg: Distingish the dest, src.
                dest_check or src_check
        Returns:
            check_result
        """
        for dir_arg in dir_hc_arg:
            if os.path.exists(dir_arg) != True:
                if flag_arg == 'dest_check':
                    os.makedirs(dir_arg)
                    check_result = True
                elif flag_arg == 'src_check':
                    self.statusBar().showMessage("There are no soure folder.")
                    check_result = False
                else:
                    self.statusBar().showMessage("Something worng")
                    check_result = False
                    # raise ValueError("Wrong argument")
            else:
                check_result = True
            if check_result is True:
                print(dir_arg + " path check complete")
        return check_result

    def _create_folder(self, dir_arg):
        """" Create the folder.

        Create the inc, src folder under the parent path.

        Args:
            dir_arg: parent folder.     
        Returns:
            tmp_dir: created inc, src folder
                tmp_dir[0]: inc folder path
                tmp_dir[1]: src folder path
        """
        tmp_dir = list()
        # .set the .h path
        # tmp_dir.append(dir_arg+'\\inc')
        tmp_dir.append(os.path.join(dir_arg, 'inc'))
        #.set the .c path
        # tmp_dir.append(dir_arg+'\\src')
        tmp_dir.append(os.path.join(dir_arg, 'src'))
        return tmp_dir

    def _gen_hc_dic(self, dir_arg):
        """" Generate the file list.

        Generated the file list is as below:
        [file name:file path]
        {'Can_17_MCanP_Cfg.h':'c:\\D\\Can_17_MCanP_PBCfg.c'}

        Args:
            dir_arg: parent folder.     
        Returns:
            h_dict: header file dictionary
            c_dict: source file dictionary
        """
        for tmp_dir in dir_arg:
            for walk_dir, walk_folder, walk_file in os.walk(tmp_dir):
                split_dir = os.path.split(walk_dir)
                if re.fullmatch('inc', split_dir[1]) is not None:
                    h_dict = dict()
                    h_dict = {key_filename: os.path.join(
                        walk_dir, key_filename) for key_filename in walk_file}
                if re.fullmatch('src', split_dir[1]) is not None:
                    c_dict = dict()
                    c_dict = {key_filename: os.path.join(
                        walk_dir, key_filename) for key_filename in walk_file}
        return h_dict, c_dict

    def _compare_code(self, src_items, dest_itmes, matchitems):
        """ Compare the code line by line

        If file exists in both folders, compare the code line by line.
        In case of DATE comment changes, it will be ignored.
        but if other contents are changed, 
        the corresponding file will be copied to the destination folder.

        Args:
            src_items: source folder item list.
            dest_itmes: destination folder item list.
            matchitems: Items that exist in both folders.
        """
        for tmp_matchitem in matchitems:
            cnt_line = 0
            with open(src_items[tmp_matchitem]) as src_file:
                with open(dest_itmes[tmp_matchitem]) as dest_file:
                    src_contents = src_file.readlines()
                    dest_contents = dest_file.readlines()
                    for line_content in src_contents:
                        if line_content != dest_contents[cnt_line]:
                            if re.search(' DATE', line_content):
                                #print(tmp_matchitem,"line:",cnt_line, line_content)
                                # Skip the simple data change
                                pass
                            else:
                                print(tmp_matchitem, 'other')
                                shutil.copy(
                                    src_items[tmp_matchitem], dest_itmes[tmp_matchitem])
                                break
                        cnt_line = cnt_line + 1
        return

    def _gen_existing(self, src_items, dest_items):
        """Generate the match item list

        Compare the item list each other in source folder and destination folder.
        The compare result is as following:
        {Existing:[items],None:[items]}

        Args:
            src_items: source folder item list.
            dest_items: destination folder item list.

        Return:
            tmp_match_result: sorting result.  
         """
        tmp_match_result = dict()
        tmp_matchlist = list()
        tmp_unmatchlist = list()
        for tmp_src_item in src_items.keys():
            if dest_items.get(tmp_src_item):
                tmp_matchlist.append(tmp_src_item)
            else:
                tmp_unmatchlist.append(tmp_src_item)
        tmp_match_result = {'Existing': tmp_matchlist, 'None': tmp_unmatchlist}
        return tmp_match_result

    def _search_keyword(self, source_folder, keyword):
        """Find "generated" folder

        Args:
            source_folder: Source folder
            keyword: The keyword which wants to find.

        Returns:
            tmp_dir: folder path which includes "generated".
        """
        for tmp_dir, tmp_folder, tmp_file in os.walk(source_folder):
            # Split the path
            # 'C:\\WorkSpace\\sample' ->['C:\\WorkSpace\\', 'sample']
            tmp_dir_split = os.path.split(tmp_dir)
            if re.fullmatch(keyword, tmp_dir_split[1]) is not None:
                # Found the keyword
                return tmp_dir
            else:
                # Next dirctory
                pass
        self.statusBar().showMessage("Can`t find \"generated\" folder")
        return False

    def auto_copy(self, src_dir_arg, dest_dir_arg):
        """copy the file from source to destination

        program procedures ars as followings:
        1. Path compatibility check.
        2. Searching the gnerated folder
        3. Find the source,destination inc,src path.
        4. Create the file list for source, destination
        5. File exisiting check in both folder.
        6. Compare the files line by line on exisiting items.
        6. Copy the files on non-exisiting items.

        Args:
            src_dir_arg: Source directory
            dest_dir_arg: Destination directory
        """
        # Compatibitity check
        src_dir_compatible = self._path_compatibility(src_dir_arg)
        dest_dir_compatible = self._path_compatibility(dest_dir_arg)
        # Search keyword
        src_dir_compatible = self._search_keyword(
            src_dir_compatible, "generated")
        # xxx_dir_hc[0] means h folder
        # xxx_dir_hc[1] means c folder
        if src_dir_compatible is not False and dest_dir_compatible is not '':
            src_dir_hc = self._create_folder(src_dir_compatible)
            dest_dir_hc = self._create_folder(dest_dir_compatible)

            # Check the destination path existence
            self._path_exist_check(dest_dir_hc, 'dest_check')
            # Check the source path existence
            if self._path_exist_check(src_dir_hc, 'src_check'):
                # src_h_items = {'Adc_Cfg.h':'I:/copysour...',''Dem_PBcfg.h':'I:/copysour...'}
                # Generate sorce list
                src_h_items, src_c_items = self._gen_hc_dic(src_dir_hc)
                # Generate destination list
                dest_h_items, dest_c_items = self._gen_hc_dic(dest_dir_hc)

                # print the source files list for Debugging
                # print("\n\r")
                # print("source file list\n\r")
                # from pprint import pprint
                # pprint(src_c_items)
                # pprint(src_h_items)
                # print("\n\r")
                # print("destination file list \n\r")
                # pprint(dest_c_items)
                # pprint(dest_h_items)

                # Seperate exisiting and none exisiting files
                # match_c = {match:['Pwm_17_Gtm_Cfg.c'],unmatch:['test.c']}
                match_c = self._gen_existing(src_c_items, dest_c_items)
                # match_h = {match:['Adc_Cfg.h'],unmatch:['Mcu_Cfg.h']}
                match_h = self._gen_existing(src_h_items, dest_h_items)

                # Compare the file line by line
                # if not same code, copy the code from SRC to Dest
                self._compare_code(src_c_items, dest_c_items,
                                   match_c['Existing'])
                self._compare_code(src_h_items, dest_h_items,
                                   match_h['Existing'])

                # copy the files which are not existing destination folder.
                for tmp_none in match_h['None']:
                    shutil.copy(src_h_items[tmp_none], dest_dir_hc[0])
                for tmp_none in match_c['None']:
                    shutil.copy(src_c_items[tmp_none], dest_dir_hc[1])
                print("Copy process is done succefully")
                # self.statusBar().showMessage("Copy process is done succefully")
            else:
                # raise NotADirectoryError("source path doesn`t exsit")
                # self.statusBar().showMessage("source path doesn`t exsit")
                print("temp")
        else:
            # self.statusBar().showMessage("The directory path has a problem")
            print("temp")
        return None
