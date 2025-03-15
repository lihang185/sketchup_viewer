#ifndef SBK_SUENTITYITERATORWRAPPER_H
#define SBK_SUENTITYITERATORWRAPPER_H

#include <model.h>

class SUEntityIteratorWrapper : public SUEntityIterator
{
public:
    SUEntityIteratorWrapper();
    ~SUEntityIteratorWrapper();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#endif // SBK_SUENTITYITERATORWRAPPER_H

