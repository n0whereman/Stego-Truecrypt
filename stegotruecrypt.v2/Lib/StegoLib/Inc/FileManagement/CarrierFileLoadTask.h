#ifndef CARRIERFILELOADTASK_H
#define CARRIERFILELOADTASK_H

#include <QObject>
#include <QRunnable>
#include "CarrierFiles/CarrierFile.h"

class CarrierFileLoadTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit CarrierFileLoadTask(CarrierFile* fileToLoad, QObject *parent = 0);
    void run();

private:
    CarrierFile* _fileToLoad;

signals:
    void finished();

public slots:
    
};

#endif // CARRIERFILELOADTASK_H
