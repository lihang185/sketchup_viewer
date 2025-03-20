
import os, sys
from importlib import import_module

CPP_DIR = os.path.join(os.path.dirname(__file__), "cpp_module" )

try:
    print("suapi path:", CPP_DIR)
    sys.path.append(CPP_DIR)
    suapi = import_module("suapi")
    sys.path.remove(CPP_DIR)
    
except ImportError:
    print ("can't load DLL:suapi.pyd\n")
    sys.exit(1)

EPS = 0.01
EPS2 = EPS*EPS

CVector2D = suapi.CVector2D
CVector3D = suapi.CVector3D
CPlane = suapi.CPlane
CMatrix33 = suapi.CMatrix33
CMatrix = suapi.CMatrix

SUEntity = suapi.SUEntity
SUDrawingElement = suapi.SUDrawingElement
SUVertex = suapi.SUVertex
SUEdge = suapi.SUEdge
SUFace = suapi.SUFace
TriangleMesh = suapi.TriangleMesh
SUComponentInstance = suapi.SUComponentInstance
SUTexture = suapi.SUTexture
SUMaterial = suapi.SUMaterial

SUEntities = suapi.SUEntities
SUEntityIterator = suapi.SUEntityIterator
SUComponentDefinition = suapi.SUComponentDefinition
SUModel = suapi.SUModel



