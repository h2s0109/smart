# from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtGui import QStandardItemModel, QStandardItem
from PyQt5.QtCore import Qt, QFile
__all__ = ["Class_Treebuild"]
class Class_Treebuild:

    def __init__(self):
        super().__init__()
        return

    def right_tree_init(self, elements):
        righttree = dict()
        for module in elements:            
            righttree[module] = []
        return righttree

    def left_item_model_construct(self, ItemModel, elements):
        basemodule = ['BASIC_MODULE', 'SRV_MODULE']
        for module in elements:
            item_module = QStandardItem(module)
            item_module.setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
            if module in basemodule:
                item_module.setCheckState(Qt.Checked)
                checkvalue = Qt.Checked
                option = Qt.ItemIsUserCheckable
            else:
                item_module.setCheckState(Qt.Unchecked)
                checkvalue = Qt.Unchecked
                option = Qt.ItemIsUserCheckable | Qt.ItemIsEnabled
            self.child_tree_build(item_module, elements[module], checkvalue, option)
            ItemModel.appendRow(item_module)
        return

    def child_tree_build(self, item_perent, child_elements, checkstate, flag):
        childcount = 0
        for childTmp in child_elements:
            item_child = QStandardItem(childTmp)
            item_child.setCheckState(checkstate)
            item_child.setFlags(flag)
            item_perent.setChild(childcount, item_child)
            childcount += 1
        return

    def right_item_model_construct(self, parent, elements, previous_state):
        parent.clear()
        module_inform = dict()
        for module in elements:
            module_inform[module] = {'indexnum': 0}
            item_module = QStandardItem(module)
            item_module.setFlags(Qt.ItemIsUserCheckable)
            item_module.setCheckState(Qt.Unchecked)
            if len(elements[module]):
                item_module.setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
                item_module.setCheckState(Qt.Checked)
                checkvalue = Qt.Checked
                option = Qt.ItemIsUserCheckable | Qt.ItemIsEnabled
                self.child_tree_build(item_module, elements[module], checkvalue, option)
            parent.appendRow(item_module)
            module_inform[module]['indexnum'] = parent.rowCount() - 1            
            previous_state[module] =  item_module.checkState()
        return module_inform

    def right_item_model_construct_copy(self, parent, elements, previous_state, leftModel):
        parent.clear()
        # module_inform = dict()
        # for module in elements:
        #     module_inform[module] = {'indexnum': 0}
        #     item_module = QStandardItem(module)
        #     item_module.setFlags(Qt.ItemIsUserCheckable)
        #     item_module.setCheckState(Qt.Unchecked)
        #     if len(elements[module]):
        #         item_module.setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
        #         item_module.setCheckState(Qt.Checked)
        #         checkvalue = Qt.Checked
        #         option = Qt.ItemIsUserCheckable | Qt.ItemIsEnabled
        #         self.child_tree_build(item_module, elements[module], checkvalue, option)
        #     parent.appendRow(item_module)
        #     module_inform[module]['indexnum'] = parent.rowCount() - 1            
        #     previous_state[module] =  item_module.checkState()
        # parent.setModel(leftModel)
        return

    def right_checkbox_click(self, parent, tree_inform, previous_state):
        #체크박스가 클릭되면 무조건 이안으로 들어오게 된다.
        for j_basemodule in tree_inform:
            level1_cnt = tree_inform[j_basemodule]['indexnum']
            level1 = self.item_info_get(parent, level1_cnt)   
            count_value = level1['childcnts']
            if previous_state[j_basemodule] == level1['item'].checkState():
                if level1['item'].checkState() == Qt.Unchecked:
                    for level2_cnt in range(0, level1['childcnts']):
                        level2 = self.item_info_get(parent, level2_cnt, level1['idx'])                         
                        level2['item'].setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
                        # child_item.setFlags(Qt.NoItemFlags)
                elif level1['item'].checkState() == Qt.Checked:                    
                    for level2_cnt in range(0, level1['childcnts']):
                        level2 = self.item_info_get(parent, level2_cnt, level1['idx']) 
                        level2['item'].setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
                        if level2['item'].checkState() == Qt.Unchecked:
                            count_value = count_value - 1
                if count_value is 0:
                    print(level1['data'])
                    level1['item'].setCheckState(Qt.Unchecked)
            else:
                if level1['item'].checkState() == Qt.Unchecked:
                    for level2_cnt in range(0, level1['childcnts']):
                        level2 = self.item_info_get(parent, level2_cnt, level1['idx'])                        
                        level2['item'].setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
                        level2['item'].setCheckState(Qt.Unchecked)
                elif level1['item'].checkState() == Qt.Checked:
                    for level2_cnt in range(0, level1['childcnts']):
                        level2 = self.item_info_get(parent, level2_cnt, level1['idx'])  
                        level2['item'].setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
                        level2['item'].setCheckState(Qt.Checked)
            previous_state[j_basemodule] = level1['item'].checkState()
        return

    def left_item_model_gen(self, level1):
        try:
            for cnt in range(0, level1.rowCount()):
                #DEBUG:
                # print(level1.item(cnt,0).text())
                if level1.item(cnt,0).checkState() == Qt.Unchecked:
                    flag = Qt.ItemIsUserCheckable | Qt.ItemIsEnabled                
                elif level1.item(cnt,0).checkState() == Qt.Checked:                
                    flag = Qt.NoItemFlags
                level2 = level1.item(cnt,0)
                for level2_cnt in range(0,  level2.rowCount()):
                    level2.child(level2_cnt,0).setFlags(flag)
                    #DEBUG:
                    #print(check = level2.child(level2_cnt,0).text())
        except:
            print("Error:left_item_model_gen")
        return

    def LeftTreeAnalyze(self, parent):
        
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
        for cnt1 in range(0, parent.rowCount()):                
            level1 = self.item_info_get(parent, cnt1)
            level2_checked = list()
            for cnt2 in range(0, level1['childcnts']):
                level2 = self.item_info_get(parent, cnt2, level1['idx'])      
                if level1['item'].checkState() | level2['item'].checkState() == Qt.Checked:                        
                    level2_checked.append(level2['data'])
                print('level_1_data:',level1['data'],'level_2_data:',level2['data'])                 
            Module_Selected[level1['data']] = level2_checked
        return Module_Selected
    
    def LeftTreeAnalyze_copy(self, parent):
            
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
        copymodel = QStandardItemModel()
        for cnt1 in range(0, parent.rowCount()):                
            level1 = self.item_info_get(parent, cnt1)
            
            copymodel.appendRow(level1['item'].clone())
            level1_copy = self.item_info_get(copymodel, cnt1)
            print(level1_copy['data'])
            level2_checked = list()
            check_cnt = 0
            for cnt2 in range(0, level1['childcnts']):
                level2 = self.item_info_get(parent, cnt2, level1['idx'],cnt1)
                if level1['item'].checkState() | level2['item'].checkState() == Qt.Checked:                                           
                    level2_checked.append(level2['data'])
                    
                    level1_copy['item'].appendRow(level2['item'].clone())
                    level2_copy = self.item_info_get(copymodel, check_cnt, level1_copy['idx'], cnt1)                    
                    check_cnt += 1
                    print(level2_copy['data'])
                    
            Module_Selected[level1['data']] = level2_checked
        return Module_Selected, copymodel

    def item_info_get(self, model, cnt, indx_up = None, cnt_up = 0):
        item_info = dict()
        child = list()
        if(indx_up is not None):
            item_info['idx'] = model.index(cnt,0,indx_up)
        else:
            item_info['idx'] = model.index(cnt, 0)
            item_info['item1'] = model.item(cnt_up,0)
        item_info['rownum'] = cnt
        item_info['item'] = model.itemFromIndex(item_info['idx'])
        item_info['data'] = model.data(item_info['idx'])
        item_info['text'] = item_info['item'].text()
        item_info['hasChildren'] = item_info['item'].hasChildren()  
        if item_info['hasChildren'] == True:
            item_info['childcnts'] = model.rowCount(item_info['idx'])
            item_info['childcnts2'] = item_info['item'].rowCount()
            for tmp in range(0, item_info['childcnts']):
                child.append(item_info['item'].child(tmp, 0).text())
        item_info['childlist'] =  child
        return item_info

    def collect_uncheck_item(self, item, cnt, removelist, database):
        for database_item in database:
            if item['data'] in database[database_item]:
                database[database_item].pop(item['data'])
                removelist.append(cnt)
                removelist.sort(reverse=True)
                return removelist

    def item_remove(self, right_parent, unchecked_item):
        for key in unchecked_item:
            if len(unchecked_item[key]):
                for idx in unchecked_item[key]:
                    right_parent.removeRow(idx,key)
        return

    def tristate_view(self, right_parent):
        parentCount = right_parent.rowCount()
        tempCount = 0
        checkItemNull = False            
        for k_num in range(0, parentCount):
            level1 = self.item_info_get(right_parent, k_num)
            if not right_parent.hasChildren(level1['idx']):
                print("Debug",level1['data'])
                level1['item'].setCheckState(Qt.Unchecked)
                level1['item'].setFlags(Qt.ItemIsTristate)                
                tempCount+=1
                # if all module is selected, no more copy process can progresses
        if tempCount is parentCount:
            checkItemNull = True
        return checkItemNull

    def TreeFindUnchecked(self,right_parent, copylist):
        unchecked_item = dict()
        level_1_rowcnts = right_parent.rowCount()
        for level1_cnt in range(0, level_1_rowcnts):                
            uncheck_list = list()              
            level1 = self.item_info_get(right_parent, level1_cnt)
            #DEBUG:
            print(level1['data'],"here",level1_cnt)
            #if Leve_1 checked, whole item will be removed
            if level1['item'].checkState() == Qt.Unchecked:
                #DEBUG:
                print(level1['data'],"will be removed")
                level1['item'].setCheckState(Qt.Checked)
                level1['item'].setFlags(Qt.ItemIsTristate)                                               
                for tmplevels_2_cnt in range(0,level1['childcnts']):        
                    templevel2 = self.item_info_get(right_parent, tmplevels_2_cnt, level1['idx'])
                    uncheck_list = self.collect_uncheck_item(templevel2, tmplevels_2_cnt, uncheck_list, copylist)
                unchecked_item[level1['idx']] = uncheck_list
            else:
                print(level1['data'])                    
                for level2_cnt in range(0,level1['childcnts']):
                    level2 = self.item_info_get(right_parent, level2_cnt, level1['idx'])
                    #DEBUG:
                    print(level1['data'], level2['data'], level1['childcnts'], level2_cnt)
                    #if Leve_2 checked only selected item wil be removed
                    if level2['item'].checkState() == Qt.Unchecked:
                        #DEBUG:
                        print(level2['data'],"will be removed")   
                        uncheck_list = self.collect_uncheck_item(level2, level2_cnt,  uncheck_list, copylist)                     
                        unchecked_item[level1['idx']] = uncheck_list     
        return unchecked_item

    def TreeFindUnchecked_copy(self,right_parent, copylist, LeftItemSel2):
        unchecked_item = dict()
        level_1_rowcnts = right_parent.rowCount()
        for level1_cnt in range(0, level_1_rowcnts):                
            uncheck_list = list()              
            level1 = self.item_info_get(right_parent, level1_cnt)
            if level1['item'].checkState() == Qt.Unchecked:
                #DEBUG:
                print(level1['data'],"will be removed")
                level1['item'].setCheckState(Qt.Checked)
                level1['item'].setFlags(Qt.ItemIsTristate)                                               
                for tmplevels_2_cnt in range(0,level1['childcnts']):        
                    templevel2 = self.item_info_get(right_parent, tmplevels_2_cnt, level1['idx'])
                    uncheck_list = self.collect_uncheck_item(templevel2, tmplevels_2_cnt, uncheck_list, copylist)
                unchecked_item[level1['idx']] = uncheck_list
            else:
                print(level1['data'])                    
                for level2_cnt in range(0,level1['childcnts']):
                    level2 = self.item_info_get(right_parent, level2_cnt, level1['idx'])
                    #DEBUG:
                    print(level1['data'], level2['data'], level1['childcnts'], level2_cnt)
                    #if Leve_2 checked only selected item wil be removed
                    if level2['item'].checkState() == Qt.Unchecked:
                        #DEBUG:
                        print(level2['data'],"will be removed")   
                        uncheck_list = self.collect_uncheck_item(level2, level2_cnt,  uncheck_list, copylist)                     
                        unchecked_item[level1['idx']] = uncheck_list     
        return unchecked_item
#TODO:
    def RightTreeAnalyze(self, parent, copylist):
            
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
                level2 = self.item_info_get(parent, cnt2, level1['idx'],cnt1)
                if level1['item'].checkState() | level2['item'].checkState() == Qt.Checked:                                           
                    level2_checked.append(level2['data'])
                    
                    level1_copy['item'].appendRow(level2['item'].clone())
                    level2_copy = self.item_info_get(copymodel, check_cnt, level1_copy['idx'], cnt1)                    
                    check_cnt += 1
                    print(level2_copy['data'])
                    
        return copymodel