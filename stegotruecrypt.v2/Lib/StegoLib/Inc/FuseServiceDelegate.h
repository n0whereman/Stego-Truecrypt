#ifndef FUSESERVICEDELEGATE_H
#define FUSESERVICEDELEGATE_H

#include <QtCore/QString>

class FuseServiceDelegate
{
public:
    virtual void fuseMounted(bool success) = 0;
    virtual void fuseMountProgress(int stage, int stageCount, QString stageTitle) = 0;
    virtual void fuseUnmounted() = 0;
};

#endif // FUSESERVICEDELEGATE_H
