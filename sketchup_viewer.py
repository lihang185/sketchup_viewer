from PySide2.QtCore import Slot
from PySide2 import QtWidgets
from Ui_sketchup_viewer import Ui_MainWindow
from importlib import import_module
import os

from su_model import SketchupModel

START_FILE = "test2_box"
START_FILE_optional = "ren", "test1_triangle"
START_FILE_NAME = START_FILE + ".skp"


work_dir = os.path.join(os.path.dirname(__file__), "data" )
os.chdir(work_dir)
print("work_dir:", work_dir)
class SketchupViewer(QtWidgets.QMainWindow, Ui_MainWindow):
    """SketchupViewer
    
    this is main window
    """
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.view.mainWindow = self
        
        self.model = None
        self.loaded_tools = {}
        
        self.enable_input =False
        self.value_input = ""

    #################
    # Show Event
    # 启动完成
    # 载入初始模型
    #################
    def showEvent(self, event):
        model = SketchupModel()
        ok = model.load(START_FILE_NAME)
        if ok:
            self.model = model
            self.view.model = model

    #################
    # Menu Action
    # 菜单操作
    #################
    @Slot()
    def on_actionOpen_triggered(self):
        print( "on_actionOpen_triggered" )
        file_name, ext = QtWidgets.QFileDialog.getOpenFileName(caption="Open SketchUp File", filter="SketchUp Files(2018) (*.skp)")
        
        if file_name:
            print( "load: ", file_name)
            self.model = None
            self.view.model = None
            #gc.collect()
            
            model = SketchupModel()
            ok = model.load(file_name)
            if ok:
                self.model = model
                self.view.model = model

        else:
            print("no select file")
            
        self.view.repaint()

    #################
    # Toolbar Action
    # 工具栏操作
    #################
    @Slot()
    def on_actionselect_triggered(self):
        print("use tool: Select")


    def load_tool(self, file_name, class_name):
        if class_name in self.loaded_tools:
            return self.loaded_tools[class_name]
        
        try:
            module = import_module(file_name)
        except ImportError:
            print ("can't load module file:", file_name)
            return None
        
        try:
            tool_class = getattr(module, class_name)
        except AttributeError:
            print ("can't get class:", class_name)
            return None

        tool = tool_class(self.view)
        self.loaded_tools[class_name] = tool
        return tool


    #################
    # Debug Action
    # 调试命令
    #################
    @Slot()
    def on_actionTest1_triggered(self):
        print("ok")
    @Slot()
    def on_actionTest2_triggered(self):
        print("ok")
    @Slot()
    def on_actionTest3_triggered(self):
        print("ok")
    @Slot()
    def on_actionTest4_triggered(self):
        print("ok")
    @Slot()
    def on_actionTest5_triggered(self):
        print("ok")

    #################
    # Key Event
    # 键盘事件
    #################
    def clearKeyInput(self):
        self.value_input = ""
        
    def keyPressEvent(self, event):
        key = event.key()
        #
        if key > 255:
            if key == 0x1000021:
                #==============
                # Ctrl
                self.view.ctrlKeyPress()
                
            elif key == 0x1000020:
                #==============
                # Shift
                self.view.shiftKeyPress()
        
        if self.enable_input == False:
            return
        
        valid_key = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '-']
        
        if key < 255:
            if chr(key) in valid_key:
                self.value_input += chr(key)
                self.statusBar.showMessage(f"Input {self.value_input}")
            #print("key:", chr(key))
        else:
            if key == 0x1000005:
                # Enter
                try:
                    value = float(self.value_input)
                except:
                    print("Invalid input value:", self.value_input)
                    return

                print(value)
                #self.view.current_tool.enterValue(value)
                    
                self.statusBar.showMessage("")
                self.value_input = ""
                
                self.view.repaint()
            elif key == 0x1000003:
                self.value_input = self.value_input[:len(self.value_input)-1]
                self.statusBar.showMessage(f"Input: {self.value_input}")
            else:
                print("alt key:", hex(key))

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    
    MainWindow = SketchupViewer()
    MainWindow.show()
    sys.exit(app.exec_())
