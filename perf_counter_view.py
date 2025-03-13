from PySide2.QtCore import Qt
from PySide2.QtGui import QPen,  QColor

from time import perf_counter

class PerformanceCounter:
    MAX_PC = 6
    STICK_WIDTH = 10
    STICK_SCALE = 4.0
    
    def __init__(self):
        self.counter = [0, 0, 0, 0, 0, 0]
        pass
        
    def start(self,  i):
        self.counter[i] = perf_counter()
    def end(self, i):
        self.counter[i] = (perf_counter() - self.counter[i]) * 1000
        
    def GetColor(index):
        if index == 0:
            return Qt.GlobalColor.red
        elif index==1:
            return Qt.GlobalColor.darkGreen
        elif index==2:
            return Qt.GlobalColor.darkBlue
        elif index==3:
            return QColor(0, 128, 128)
        elif index==4:
            return Qt.GlobalColor.darkMagenta
        else:
            return Qt.GlobalColor.gray
            
        
    def Draw(self,  painter):
        self.WIDTH = self.rect.width()
        self.HEIGHT = self.rect.height()
        
        for i in range(self.MAX_PC):
            x = (i * 2 + 1) * self.STICK_WIDTH
            
            v = self.counter[i]
            py = int(v * self.STICK_SCALE)
            
            #if py > self.HEIGHT:
            #    py = self.HEIGHT;
            
            color = PerformanceCounter.GetColor(i)
            #painter.setPen(Qt.NoPen)
            painter.setBrush(color)
            
            painter.drawRect(x, self.HEIGHT-py,  self.STICK_WIDTH,  py)
        
        self.DrawText(painter)
        self.DrawFrame(painter)
        
    def DrawText(self, painter):
        font=painter.font()
        font.setPointSize(8)
        font.setBold(False)
        painter.setFont(font)
        painter.setPen(QColor(Qt.GlobalColor.black))
        painter.drawText(-60,self.HEIGHT-1,"time: %2.0f ms"%(self.counter[4]))
        
    def DrawFrame(self, painter):
        #######################
        # 绘制边框
        #######################    
        pen = QPen(Qt.GlobalColor.black)
        painter.setPen(pen)
        painter.drawLine(0, 0,    5,  0)
        painter.drawLine(0, 0,    0,  self.HEIGHT-1)
        
        for y in range(0, self.HEIGHT,  20):
            if y == 0: continue
            py = self.HEIGHT-y
            painter.drawLine(0, py,  -3,  py)
            text = "%d"%int(y/self.STICK_SCALE)
            painter.drawText(-15, py+4,text)
