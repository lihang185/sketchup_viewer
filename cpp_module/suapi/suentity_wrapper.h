#ifndef SBK_SUENTITYWRAPPER_H
#define SBK_SUENTITYWRAPPER_H

#include <model.h>

class SUEntityWrapper : public SUEntity
{
public:
    SUEntityWrapper();
    ~SUEntityWrapper();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#endif // SBK_SUENTITYWRAPPER_H

