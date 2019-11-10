__version__ = '1.0.0'
__all__ = ['import_data', 'export_data', 'gen_c_h_dic',
           'copy_mcalmodule', 'gen_sort', 'moduledatashow']

import json
from pprint import pprint
import shutil
import os
from re import search, sub, match
from distutils.file_util import copy_file
import pathcheck


def import_data(filepath_arg, datatype_arg):
    """Importing the json data"""
    with open(filepath_arg) as data_file:
        data = json.load(data_file)
    sorting_data = data[datatype_arg]
    return sorting_data


def export_data(filepath_arg, data_arg):
    """Exporting the json data"""
    with open(filepath_arg, 'w') as data_file:
        json.dump(data_arg, data_file, indent=1)
    return


def gen_c_h_dic(dir_arg, sort_data, module_data, smodule=False):
    """Generate the dictionary including
        {include:[file name,file path],source:[file name,file path]}"""
    search_result = dict()
    module_whole = list()
    ex_classify_result = _sort_classify(
        sort_data['EX_AND'], sort_data['EX_OR'])
    inc_classify_result = _sort_classify(
        sort_data['INC_AND'], sort_data['INC_OR'])
    for tmp_dir, tmp_folder, tmp_file in os.walk(dir_arg):
        tmp_dir = tmp_dir.replace('\\', '/')
        ex_flag = _folder_check(tmp_dir, ex_classify_result, sort_data, 'EX')
        if ex_flag is True:
            # When the directory path has excluded folder, skip the directory path quickly.
            tmp_folder[:] = [
                remove_i for remove_i in tmp_folder if remove_i not in tmp_folder]
        else:
            inc_flag = _folder_check(
                tmp_dir, inc_classify_result, sort_data, 'INC')
            if inc_flag is True:
                # Find the target directory path!!!!
                # Classify procedure will be processed
                tmp_result = dict()
                for module_name in module_data:
                    module_whole.append(tmp_dir)
                    sort_key = sub('^.*/', '', tmp_dir)
                    if tmp_dir.find('/' + module_name) is not -1:
                        if smodule is False:
                            if match('general', module_name):
                                sort_key = sub(
                                    '^.*' + module_name + '.*?/', '', tmp_dir)
                            tmppath = _gen_dirpath(tmp_dir, sort_key)
                        elif smodule is True:
                            tmp_file.sort()
                            tmppath = _gen_filefullpath(
                                tmp_dir, tmp_file, sort_key)
                        tmp_result.update({module_name: tmppath})
                        break
                search_result = _concate_dic(search_result, tmp_result)
    return search_result


def moduledatashow(dir_arg, sort_data, module_data, *pjname):
    """Generate the dictionary including
        {include:[file name,file path],source:[file name,file path]}"""
    # UPDATE:
    data_creation_success = False
    module_whole = list()
    ex_classify_result = _sort_classify(
        sort_data['EX_AND'], sort_data['EX_OR'])
    inc_classify_result = _sort_classify(
        sort_data['INC_AND'], sort_data['INC_OR'])
    for tmp_dir, tmp_folder, _ in os.walk(dir_arg):
        tmp_dir = tmp_dir.replace('\\', '/')
        ex_flag = _folder_check(tmp_dir, ex_classify_result, sort_data, 'EX')
        if ex_flag is True:
            # When the directory path has excluded folder, skip the directory path quickly.
            tmp_folder[:] = [
                remove_i for remove_i in tmp_folder if remove_i not in tmp_folder]
        else:
            inc_flag = _folder_check(
                tmp_dir, inc_classify_result, sort_data, 'INC')
            # Find the target directory path!!!!
            # Classify procedure will be processed
            if inc_flag is True:
                module_whole.append(tmp_dir)
    # if there is installed module.
    if len(module_whole)is not 0:
        if not pjname:
            data_creation_success = _no_moduledata(
            module_whole, module_data)
            _installed_mcalfolder_print(module_whole)
        else:
            data_creation_success = _no_moduledata(
                module_whole, module_data, pjname[0])
            _installed_mcalfolder_print(module_whole, pjname[0])      
    return data_creation_success


def _installed_mcalfolder_print(USER_MODULE, *pjname):
    # To remove the duplicated folder name.
    USER_MODULE = set(USER_MODULE)
    USER_MODULE = list(USER_MODULE)
    USER_MODULE.sort()
    print("-" * 50, "sorting result", "-" * 50, "\n\r")
    # pprint(USER_MODULE)
    if not pjname:
        export_data('jmodule_whole.json', USER_MODULE)
    else:
        userpath = pathcheck.windowinstallpathini(pjname[0])
        userpath = os.path.join(userpath, 'jmodule_whole.json')
        export_data(userpath, USER_MODULE)
    return


def windowinstallpath(pjname):
    # To remove the duplicated folder name.
    userpath = os.path.join(os.environ['USERPROFILE'], "AppData", "Local")
    userpath = os.path.join(userpath, pjname)
    return userpath


def _no_moduledata(whole_module_list, module_data, *pjname):
    """Generating the installed module list.
    Through the function, user can easily check installed package
    For the purpose to check the installed module,
    do not configure module name on purpose.
    """
    #'~TC23x_ABstep/Aurix_MC-ISAR/adc_infineon_tricore/ssc/inc'
    # To find the path which includes Mcal module '~TC23x_ABstep/Aurix_MC-ISAR/'
    no_mdulepath = [j for j in whole_module_list if search(
        '^.*(?=adc)', j) is not None]
    no_mdulepath = search('^.*(?=adc)', no_mdulepath[0]).group()
    tmp_whole_module_list = [sub(no_mdulepath, '', k)
                             for k in whole_module_list]
    tmp2_whole_module_list = [search('^.*?(?=/)', m).group()
                              for m in tmp_whole_module_list]
    tmp3_whole_module_list = [sub('_infineon.*$', '', j)
                              for j in tmp2_whole_module_list]
    tmp3_whole_module_list = set(tmp3_whole_module_list)
    refine_whole_module_list = list(tmp3_whole_module_list)
    refine_whole_module_list.sort()
    module_data["MODULEDATA"]["USER_MODULE"] = refine_whole_module_list
    if not pjname:
        THIS_DIR = os.getcwd()
        THIS_DIR = os.path.realpath(
            "{0}/Database/data_key.json".format(THIS_DIR))
        export_data(THIS_DIR, module_data)
    else:
        userpath = windowinstallpath(pjname[0])
        userpath = os.path.join(userpath, 'Database', 'data_key.json')
        export_data(userpath, module_data)
    return True


def _gen_filefullpath(dir_arg, files_arg, sort_key_arg):
    """ Generating the file path which has
    {sort_key_arg: [directory name\\file path]}"""
    tmp_path = dict()
    for tmp_file_key in files_arg:
        tmp_path.update({tmp_file_key: os.path.join(
            dir_arg, tmp_file_key).replace('\\', '/')})
    filepath_ret = {sort_key_arg: tmp_path}
    return filepath_ret


def _gen_dirpath(dir_arg, sort_key_arg):
    """ Generating the file path which has
    {sort_key_arg: [directory name]}"""
    filepath_ret = {sort_key_arg: dir_arg}
    return filepath_ret


def _gen_filepath(files_arg, sort_key_arg):
    """ Generating the file path which has
    {sort_key_arg: [file path]}"""
    tmp_path = list()
    for tmp_file_key in files_arg:
        tmp_path.append(tmp_file_key)
    filepath_ret = dict({sort_key_arg: tmp_path})
    return filepath_ret


def _concate_dic(dic1_arg, dic2_arg):
    """Update the dic with same module key"""
    for key_value in dic2_arg.keys():
        dic1_arg.setdefault(key_value, {})
        dic1_arg[key_value].update(dic2_arg[key_value])
    return dic1_arg


def _sort_classify(sort_data_and, sort_data_or):
    """Set the sorting condition"""
    if len(sort_data_and) > 0:
        if len(sort_data_or) > 0:
            sort_case = 'SORT_AND_OR'
        else:
            sort_case = 'SORT_AND'
    else:
        sort_case = 'SORT_OR'
    return sort_case


def _sort_or(tmp_dir, sort_data_or):
    """Sorting the directory using OR condition"""
    for item_or in sort_data_or:
        if search(item_or + '$', tmp_dir):
            exist_flag = True
            break
        else:
            exist_flag = False
    return exist_flag


def _sort_and(tmp_dir, sort_data_or):
    """Sorting the directory using AND condition"""
    for item_and in sort_data_or:
        if search(item_and + '$', tmp_dir):
            exist_flag = True
        else:
            exist_flag = False
            break
    return exist_flag


def _sort_andor(tmp_dir, sort_data_and, sort_data_or):
    """Sorting the directory using AND and OR condition"""
    for item_and in sort_data_and:
        if search(item_and, tmp_dir):
            for item_or in sort_data_or:
                if search(item_or + '$', tmp_dir):
                    exist_flag = True
                    break
                else:
                    exist_flag = False
        else:
            exist_flag = False
    return exist_flag


def _folder_check(tmp_dir, ex_classify_result, sort_data, sortname):
    sort_and = sortname + '_AND'
    sort_or = sortname + '_OR'
    if ex_classify_result == 'SORT_AND_OR':
        ex_flag_a = _sort_andor(
            tmp_dir, sort_data[sort_and], sort_data[sort_or])
    elif ex_classify_result == 'SORT_OR':
        ex_flag_a = _sort_or(tmp_dir, sort_data[sort_or])
    else:
        ex_flag_a = _sort_and(tmp_dir, sort_data[sort_and])
    return ex_flag_a


def copy_mcalmodule(src_result, dest_result, smodule=False):
    """Mcal module copy to user designated folder"""
    src_result_keys = list(src_result.keys())
    for module in src_result_keys:
        src_module_keys = src_result[module].keys()
        for k in src_module_keys:
            dest_path = os.path.join(dest_result, module, k).replace('\\', '/')
            if smodule is False:
                shutil.copytree(src_result[module][k], dest_path)
                print('{}:{} copy is done'.format(k, module))
                if match('tricore_general', module) and match('src', k):
                    print(module)
            else:
                os.makedirs(dest_path)
                for pathfinal2 in src_result[module][k].values():
                    copy_file(pathfinal2, dest_path, update=0)
    return None

# for test


def copy_mcal2(src_result, dest_result):
    """copy Mcal module to user designated folder"""
    src = src_result
    copy_file(src, dest_result, update=1)
    return None

def Srv_SortKye_Gen(module_checked, sorkey_datas):
    """To remove the unrelated module, the sorting key of modules that are selected by the user will be generated.
        
        Args:
            module_checked: module which is selected by user
            sorkey_datas: module sort keys for service module

        Returns:
            sortkey_list: selected module sortkey
    """
    import itertools
    sortkey_list = [sorkey_datas[k] for k in module_checked]
    #Remove the unused items
    sortkey_list = list(filter(None, sortkey_list))
    #Convert the 2 dimensional array to 1 dimensional array
    sortkey_list = list(itertools.chain(*sortkey_list))
    sortkey_list = list(set(sortkey_list))
    sortkey_list.sort()
    return sortkey_list

def gen_sort(Srv_file_whole, SrvModule_SortKey):
    """Regenerate Srv_file_whole.
    Remove the unsed item.
        Args:
            Srv_file_whole: whole service file
            SrvModule_SortKey: Selected module sortkey for service

        Returns:
            Srv_file_filtered: selected module service file
    """
    Srv_file_filtered = dict()
    for j in Srv_file_whole:
        Srv_file_filtered.setdefault(j, {})
        for k in Srv_file_whole[j]:
            tmplist = dict()
            Srv_file_filtered[j].setdefault(k, {})
            for sortkey_j2 in SrvModule_SortKey:
                super_sort(sortkey_j2, Srv_file_whole[j][k], tmplist)
            Srv_file_filtered[j].update({k: tmplist})
    # pprint(Srv_file_filtered)
    return Srv_file_filtered


def super_sort(sortkey_j_arg, unsorted_arg, tmplist_arg):
    """Recursive function
    If unsorted_arg match with sortkey_j_arg,
    remove the match item in unsorted_arg and
    make the match list to tmplist_arg"""
    for unsorted_arg_j in unsorted_arg:
        if search(sortkey_j_arg, unsorted_arg_j) is not None:
            tmplist_arg.update({unsorted_arg_j: unsorted_arg[unsorted_arg_j]})
            unsorted_arg.pop(unsorted_arg_j)
            if len(unsorted_arg) is not 0:
                super_sort(sortkey_j_arg, unsorted_arg, tmplist_arg)
                break
            else:
                break
            # super_sort(sortkey_j_arg, unsorted_arg, tmplist_arg)
            # break
    return