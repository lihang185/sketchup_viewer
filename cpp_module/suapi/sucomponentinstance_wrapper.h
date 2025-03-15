#ifndef SBK_SUCOMPONENTINSTANCEWRAPPER_H
#define SBK_SUCOMPONENTINSTANCEWRAPPER_H

#include <model.h>

class SUComponentInstanceWrapper : public SUComponentInstance
{
public:
    SUComponentInstanceWrapper();
    ~SUComponentInstanceWrapper();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  ifndef SBK_SUDRAWINGELEMENTWRAPPER_H
#  define SBK_SUDRAWINGELEMENTWRAPPER_H

// Inherited base class:
class SUDrawingElementWrapper : public SUDrawingElement
{
public:
    SUDrawingElementWrapper();
    ~SUDrawingElementWrapper();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  endif // SBK_SUDRAWINGELEMENTWRAPPER_H

#  ifndef SBK_SUENTITYWRAPPER_H
#  define SBK_SUENTITYWRAPPER_H

// Inherited base class:
class SUEntityWrapper : public SUEntity
{
public:
    SUEntityWrapper();
    ~SUEntityWrapper();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#  endif // SBK_SUENTITYWRAPPER_H

#endif // SBK_SUCOMPONENTINSTANCEWRAPPER_H

