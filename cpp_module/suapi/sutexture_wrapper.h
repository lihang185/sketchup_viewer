#ifndef SBK_SUTEXTUREWRAPPER_H
#define SBK_SUTEXTUREWRAPPER_H

#include <model.h>

class SUTextureWrapper : public SUTexture
{
public:
    SUTextureWrapper();
    ~SUTextureWrapper();
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

#endif // SBK_SUTEXTUREWRAPPER_H

