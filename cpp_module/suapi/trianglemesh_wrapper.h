#ifndef SBK_TRIANGLEMESHWRAPPER_H
#define SBK_TRIANGLEMESHWRAPPER_H

#include <model.h>

class TriangleMeshWrapper : public TriangleMesh
{
public:
    TriangleMeshWrapper();
    ~TriangleMeshWrapper();
    void resetPyMethodCache();
private:
    mutable bool m_PyMethodCache[1];
};

#endif // SBK_TRIANGLEMESHWRAPPER_H

