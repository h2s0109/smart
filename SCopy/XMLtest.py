import xml.etree.ElementTree as ET
import os
def indent(elem, level=0):
    i = "\n" + (level-1)*"  "
    j = "\n" + (level-1)*"  "
    if len(elem):
        if not elem.text or not elem.text.strip():
            elem.text = i + "  "
        if not elem.tail or not elem.tail.strip():
            elem.tail = i
        for subelem in elem:
            indent(subelem, level+1)
        if not elem.tail or not elem.tail.strip():
            elem.tail = j
    else:
        if level and (not elem.tail or not elem.tail.strip()):
            elem.tail = j
    return elem 

# tree = ET.parse('.cproject')
# TaskingRoot = tree.getroot()
# print(TaskingRoot.tag)
# m = '{workspace_loc:/${ProjName}/SourceCode/Mcal/McalSW/tricore_general/inc}'
# for option in TaskingRoot.iter('option'):
#     if option.attrib['superClass'] == "com.tasking.ctc.cc.includePaths":
#         for value in option.findall('listOptionValue'):
#             print(value.attrib['value'])
#             option.remove(value)        
#         y = ET.SubElement(option, 'listOptionValue', builtIn="false",value="&quot;$"+m+"&quot;")
#         y = ET.SubElement(option, 'listOptionValue', builtIn="TRue",value="&quot;${workspace_loc:/${ProjName}/SourceCode/Mcal/McalSW/tricore_general/inc}&quot;")
# indent(TaskingRoot)
# tree.write('.1cproject')

def parsing_Tasking(xmlpath, include_path):
    xmlpath = os.path.join(xmlpath,'.cproject')
    tree = ET.parse(xmlpath)
    TaskingRoot = tree.getroot()
    print(TaskingRoot.tag)
    m = '{workspace_loc:/${ProjName}/SourceCode/Mcal/McalSW/tricore_general/inc}'
    for option in TaskingRoot.iter('option'):
        if option.attrib['superClass'] == "com.tasking.ctc.cc.includePaths":
            for value in option.findall('listOptionValue'):
                print(value.attrib['value'])
                option.remove(value)
            for tmp_path in include_path:
                ET.SubElement(option, 'listOptionValue', builtIn="false",value="&quot;$"+tmp_path+"&quot;")        
    indent(TaskingRoot)
    tree.write(xmlpath)
  