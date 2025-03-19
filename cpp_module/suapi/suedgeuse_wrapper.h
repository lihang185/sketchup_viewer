#ifndef SBK_SUEDGEUSEWRAPPER_H
#define SBK_SUEDGEUSEWRAPPER_H

#include <model.h>

class SUEdgeUseWrapper : public SUEdgeUse
{
public:
    SUEdgeUseWrapper();
    ~SUEdgeUseWrapper();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

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

#endif // SBK_SUEDGEUSEWRAPPER_H

