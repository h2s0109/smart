from lxml import etree as ET
import os


def indent(elem, level=0):
    i = "\n" + (level - 1) * "  "
    j = "\n" + (level - 1) * "  "
    if len(elem):
        if not elem.text or not elem.text.strip():
            elem.text = i + "  "
        if not elem.tail or not elem.tail.strip():
            elem.tail = i
        for subelem in elem:
            indent(subelem, level + 1)
        if not elem.tail or not elem.tail.strip():
            elem.tail = j
    else:
        if level and (not elem.tail or not elem.tail.strip()):
            elem.tail = j
    return elem


def parsing_includeTasking(xmlpath, include_path):
    xmlpath = os.path.join(xmlpath, '.cproject')
    xmlpath = xmlpath.replace('\\', '/')
    tree = ET.parse(xmlpath)
    TaskingRoot = tree.getroot()
    print(TaskingRoot.tag)
    find_option = False
    for option in TaskingRoot.iter('option'):
        if option.attrib['superClass'] == "com.tasking.ctc.cc.includePaths":
            for value in option.findall('listOptionValue'):
                print(value.attrib['value'])
                option.remove(value)
            for tmp_path in include_path:
                # tmp_path = "&quot;" + tmp_path + "&quot;"
                ET.SubElement(option, 'listOptionValue', builtIn="false",
                              value=tmp_path)
            find_option = True
    if find_option == False:
        for option in TaskingRoot.iter('tool'):
            if option.attrib['superClass'] == "com.tasking.ctc.cc.abs.debug":
                for option2 in option.iter('option'):
                    if option2.attrib['superClass'] == "com.tasking.ctc.cc.pr36858":
                        ET.SubElement(option, 'option', id = 'com.tasking.ctc.cc.includePaths.552904157', name="Include paths", superClass="com.tasking.ctc.cc.includePaths", valueType="includePath")
                        break
        for option in TaskingRoot.iter('option'):
            if option.attrib['superClass'] == "com.tasking.ctc.cc.includePaths":
                for value in option.findall('listOptionValue'):
                    print(value.attrib['value'])
                    option.remove(value)
                for tmp_path in include_path:
                    # tmp_path = "&quot;" + tmp_path + "&quot;"
                    ET.SubElement(option, 'listOptionValue', builtIn="false",
                                value=tmp_path)
    indent(TaskingRoot)
    tree.write(xmlpath, encoding="utf-8", xml_declaration=True)
    return
