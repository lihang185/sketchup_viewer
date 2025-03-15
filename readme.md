# 1、介绍

本项目的中文名称是 公输盘(ban)-建筑大师，是一款建筑设计和建模软件，最终目标是打造成为中国产的Google Sketchup平替产品，未来中国市场的容量很大，需要安全性和可选择性。

系统基于小内核和插件设计，并且是只有主从双系统考虑，2种不同的建模方式可以同时工作，是非常不错的CAD类软件的起始代码和开发实验平台，配合最新的建模插件，可在部分领域完全取代Sketchup

![screenshot](https://github.com/lihang185/sketchup_viewer/blob/main/screenshot/view1.png?raw=true)
![screenshot](https://github.com/lihang185/sketchup_viewer/blob/main/screenshot/view2.png?raw=true)

# 2、依赖
软件用python和C++编写，需要：
```
Python3.8 64bit 环境
SketchupAPI 2018 64bit SDK
Pyside2（Qt5.0界面库）
Shiboken2（C++绑定）
PyOpenGL
```

# 3、安装
```
pip install pyopengl
pip install pyside2
```

# 4、运行
```
python sketchup_viewer.py
```
