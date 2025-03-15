#ifndef SBK_SUVERTEXWRAPPER_H
#define SBK_SUVERTEXWRAPPER_H

#include <model.h>

class SUVertexWrapper : public SUVertex
{
public:
    SUVertexWrapper();
    ~SUVertexWrapper();
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

#endif // SBK_SUVERTEXWRAPPER_H

