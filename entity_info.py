from PySide2 import QtWidgets
from Ui_entityinfo import Ui_EntityInfo

class EntityInfo(QtWidgets.QWidget, Ui_EntityInfo):
    def __init__(self, parent):
        super().__init__(parent)
        self.setupUi(self)

