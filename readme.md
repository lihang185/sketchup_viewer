# 1、介绍

本项目是 公输盘(ban)-建筑大师 的开源版本，目的是打造成为Google Sketchup的一个可选的平替软件，开源部分是软件的基础框架，是非常不错的CAD类软件的起始代码和开发实验平台，配合最新的建模插件，可在部分领域完全取代Sketchup

![设备](https://github.com/lihang185/sketchup_viewer/blob/main/screenshot/view1.png?raw=true)

# 2、依赖
项目用python和C++编写，需要：
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
