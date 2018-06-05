import re
import os

__all__ = ["Class_comiler_path"]
# def match(pattern, string, flags=0):from start
# def fullmatch(pattern, string, flags=0):
# def search(pattern, string, flags=0)
# def sub(pattern, repl, string, count=0, flags=0):


class Class_comiler_path:
    def __init__(self):
        super().__init__()
        return

    def __del__(self):
        return

    def hierachy_check(self, firstdir, seconddir):
        match_result = [False, False]
        if re.fullmatch(firstdir, seconddir):
            # Fullmatch
            match_result[0] = True
            return match_result
        else:
            # Partial match check
            if re.match(firstdir, seconddir):
                temp_seconddir = re.sub(firstdir, '', seconddir)
                #('C:/Testfolder','C:/Testfolder/add')
                #(/add)
                if re.match('.*/', temp_seconddir):
                    # Partial match, firstdir is above
                    # hierachy_check('C:/Testfolder','C:/Testfolder/add')
                    match_result[0] = True
                    return match_result
                else:
                    # hierachy_check('C:/Testfolder','C:/Testfolderadd')
                    return match_result
            elif re.match(seconddir, firstdir):
                temp_seconddir = re.sub(seconddir, '', firstdir)
                #('C:/Testfolder/add','C:/Testfolder')
                #(/add)
                if re.match('.*/', temp_seconddir):
                    # Partial match, seconddir is above
                    # hierachy_check('C:/Testfolder/add','C:/Testfolder')
                    match_result[1] = True
                    return match_result
                else:
                    # hierachy_check('C:/Testfolder','C:/Testfolderadd')
                    return match_result
            else:
                pass
                # Does not match
                return match_result

    def Compiler_include(self, firstdir, seconddir):
        hierachy_check_result = self.hierachy_check(firstdir, seconddir)
        if hierachy_check_result[0] is True:
            findresult = self._include_path(firstdir, seconddir, True)
        elif hierachy_check_result[1] is True:
            findresult = self._include_path(seconddir, firstdir, True)
        else:
            findresult = self._include_path(firstdir, seconddir, False)
        # DEBUG:
        # print(len(findresult))
        return findresult

    def _include_path(self, firstdir, seconddir, include_inform):
        if include_inform is True:
            findresult = self._include_path_find(firstdir)
        else:
            findresult1 = self._include_path_find(firstdir)
            findresult2 = self._include_path_find(seconddir)
            findresult = findresult1 + findresult2
        return findresult

    def _include_path_find(self, dirpath):
        includelist = list()
        delete_path = os.path.split(dirpath)
        for tmp_dir, tmp_folder, tmp_file in os.walk(dirpath):
            tmp_dir = tmp_dir.replace('\\', '/')
            if len(tmp_file):
                for filelist in tmp_file:
                    # To avoid SchM.c \. is used.
                    if re.match('.*\.h', filelist):
                        # DEBUG:
                        # print('{}{}{}'.format(
                        #     '${workspace_loc:/${ProjName}/{TEMPLETE}/', re.sub(delete_path[0], '', tmp_dir), '}'))
                        includelist.append(
                            '"${workspace_loc:/${ProjName}/{TEMPLETE}' + re.sub(delete_path[0], '', tmp_dir) + '}"')
                        break
        return includelist

    def Compiler_include2(self, dirpath):
        includelist = list()
        dirpath = dirpath.replace('\\', '/')
        for tmp_dir, tmp_folder, tmp_file in os.walk(dirpath):
            tmp_dir = tmp_dir.replace('\\', '/')
            if len(tmp_file):
                for filelist in tmp_file:
                    if re.match('.*\.h', filelist):
                        includelist.append(
                            '"${workspace_loc:/${ProjName}' + re.sub(dirpath, '', tmp_dir) + '}"')
                        break

        return includelist
