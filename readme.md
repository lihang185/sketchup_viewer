# 1、介绍

本项目是智绘大师 （https://aidim3d.com)  的OpenCAD开源项目。智绘大师的开发核心概念是AI（人工智能建模）、DIM（设计信息模型化）、3D（三维软件），核心强调未来的设计流程是设计信息模型化的工程，从设计开始，信息模型贯穿整个生命周期，输出创新的*.DIM格式，打破传统BIM的信息孤岛，特别是BIM主要应用在施工阶段而忽略设计端的问题。

智绘大师致力于打造一款全专业跨行业全品类设计师三维建模软件，最终目标是打造成为中国产的Google SketchUp平替产品，打破三维设计软件长期被欧美企业垄断的局面。中国市场的容量庞大，更需要数字资产的安全性和三维设计工具软件的可选择性。

智绘大师-OpenCAD的开源系统基于小内核和插件设计，架构上具有主从双系统考虑，通过两种不同的建模方式即可进行协同工作，是非常不错的CAD（计算机辅助设计）类软件的起始代码和开发实验平台，您可以在OpenCAD的开源系统上进行各类的插件和功能开发，比如曲面功能、布尔运算、模型渲染、信息统计、管道设计、场景交互......，即可在部分领域完全取代SketchUp。

我们热诚欢迎广大三维开发者以及高等院校相关师生们加入我们的智绘大师-OpenCAD开源项目中来！

本开源项目的图标设计为独立跨界建筑师设计师：陈宇晖 。

您有任何二次开发需求和想法，可以直接联系我们：info@aidim3d.com

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
