# from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import QFile, Qt
from PyQt5.QtGui import QStandardItem, QStandardItemModel

__all__ = ["Class_Treebuild"]
class Class_Treebuild:

    def __init__(self):
        super().__init__()
        return

    def left_item_construct(self, module, key):
        item_module = QStandardItem(key)
        item_module.setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
        item_module.setCheckState(Qt.Unchecked)
        self.child_tree_build(item_module,module[key])
        return item_module
    def child_tree_build(self, item_perent, child_elements):
        childcount = 0
        for childTmp in child_elements:
            item_child = QStandardItem(childTmp)
            item_child.setCheckState(Qt.Unchecked)
            item_perent.setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
            item_perent.setChild(childcount, item_child)
            childcount += 1
        return
    def left_item_construct_special(self, module, key):
        item_module = QStandardItem(key)
        moduleitem = len(module[key])
        item_dict =dict()
        for tempItem in module[key]:
            if module[key][tempItem] =='check':
                moduleitem-=1
                item_dict[tempItem]={'checkvalue':Qt.Checked}
                item_dict[tempItem].update(option=Qt.ItemIsUserCheckable)
            else:
                item_module.setCheckState(Qt.Unchecked)
                item_dict[tempItem]={'checkvalue':Qt.Unchecked}
                item_dict[tempItem].update(option=Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
        if moduleitem == 0:
            item_module.setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
            item_module.setCheckState(Qt.Checked)
            self.child_tree_build_special(item_module, item_dict)
        else:
            item_module.setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
            item_module.setCheckState(Qt.Unchecked)
            self.child_tree_build_special(item_module,item_dict,flag=True)
        return item_module

    def child_tree_build_special(self, item_perent, child_elements, flag=False):
        childcount = 0
        for childTmp in child_elements.keys():
            item_child = QStandardItem(childTmp)
            item_child.setCheckState(child_elements[childTmp]['checkvalue'])
            if flag==True:
                item_child.setFlags(child_elements[childTmp]['option'])
            else:
                item_child.setFlags(Qt.ItemIsUserCheckable)
            item_perent.setChild(childcount, item_child)
            childcount += 1
        return

    def model_status_eval(self, parent):
        try:
            #체크박스가 클릭되면 무조건 이안으로 들어오게 된다.
            total =parent.rowCount()
            checkItemNull = False
            for cnt1 in range(0, parent.rowCount()):                
                level1 = self.item_info_get(parent, cnt1)
                if not parent.hasChildren(level1['idx']):
                    level1['item'].setFlags(Qt.ItemIsTristate)
                    total-=1
                    if total == 0:
                        checkItemNull = True
                else:
                    if level1['item'].checkState() == Qt.Checked:                
                        for cnt2 in range(0, level1['childcnts']):
                            level2 = self.item_info_get(parent, cnt2, level1['idx'])
                            level2['item'].setCheckState(Qt.Checked)
                            level2['item'].setFlags(Qt.ItemIsTristate)
                    if level1['item'].checkState() == Qt.Unchecked:
                        for cnt2 in range(0, level1['childcnts']):
                            level2 = self.item_info_get(parent, cnt2, level1['idx']) 
                            level2['item'].setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
        except:
            print("Error:left_item_model_gen")
        return checkItemNull

    def item_info_get(self, model, cnt = None, indx_up = None,item = None):
        item_info = dict()
        child = list()
        if indx_up is not None:
            item_info['idx'] = model.index(cnt,0,indx_up)
        elif item is not None:
            item_info['idx'] = model.indexFromItem(item)            
        else:
            item_info['idx'] = model.index(cnt, 0)
        item_info['item'] = model.itemFromIndex(item_info['idx'])
        item_info['parents'] = item_info['item'].parent()
        item_info['rownum'] = item_info['item'].row()
        item_info['data'] = model.data(item_info['idx'])
        item_info['text'] = item_info['item'].text()
        item_info['hasChildren'] = item_info['item'].hasChildren()  
        if item_info['hasChildren'] == True:
            item_info['childcnts'] = model.rowCount(item_info['idx'])
            item_info['childcnts2'] = item_info['item'].rowCount()
            for tmp in range(0, item_info['childcnts']):
                child.append(item_info['item'].child(tmp, 0).text())
        else:
            item_info['childcnts'] = 0
        item_info['childlist'] =  child
        return item_info


    def model_Analyzation(self, parent, copylist = None):
            
        """Generate the selected item dictionary on left side
            It also generate the rightside tree based on leftsidetree selection.
            
            Args:
            parent: Leftside item model.

        Returns:
            dict(): selected module on leftside
        Module_Selected:{BASIC_MODULE:['port','ecum'...],SRV_MODULE:['integration','irq']
                        ,USER_MODULE:['dsadc','gpt'...]}
        """
        copymodel = QStandardItemModel()
        for cnt1 in range(0, parent.rowCount()):                
            level1 = self.item_info_get(parent, cnt1)
            
            copymodel.appendRow(level1['item'].clone())
            level1_copy = self.item_info_get(copymodel, cnt1)
            print(level1_copy['data'])
            level2_checked = list()
            check_cnt = 0
            for cnt2 in range(0, level1['childcnts']):
                level2 = self.item_info_get(parent, cnt2, level1['idx'])
                if level1['item'].checkState() | level2['item'].checkState() == Qt.Checked:                                           
                    level2_checked.append(level2['data'])
                    level1_copy['item'].appendRow(level2['item'].clone())
                    level2_copy = self.item_info_get(copymodel, check_cnt, level1_copy['idx'])                    
                    check_cnt += 1
                    print(level2_copy['data'])
                elif level2['item'].checkState() == Qt.Unchecked:
                    if copylist is not None:
                        copylist[level1['data']].pop(level2['data'])
        return copymodel

    def FindChildrenItem(self, parent, finditem):
        
        """Generate the selected item dictionary on left side
            It also generate the rightside tree based on leftsidetree selection.
            
            Args:
            parent: Leftside item model.

        Returns:
            dict(): selected module on leftside
        Module_Selected:{BASIC_MODULE:['port','ecum'...],SRV_MODULE:['integration','irq']
                        ,USER_MODULE:['dsadc','gpt'...]}
        """
        Module_Selected = dict()
        itemvalue = parent.findItems(finditem)
        level1 = self.item_info_get(parent,item = itemvalue[0])
        level2_checked = list()
        for cnt2 in range(0, level1['childcnts']):
            level2 = self.item_info_get(parent, cnt2, level1['idx'])      
            level2_checked.append(level2['data'])               
        Module_Selected[level1['data']] = level2_checked
        return Module_Selected[level1['data']]
