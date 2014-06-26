#ifndef CARRIERFILEINITTASK_H
#define CARRIERFILEINITTASK_H

#include <QObject>
#include <QRunnable>
#include <QString>
#include <vector>
#include <QMutex>

#include "CarrierFiles/CarrierFile.h"

using namespace std;

class CarrierFileInitTask : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit CarrierFileInitTask(QString basePath, QString relativePath, vector<CarrierFile*>* fileList, QMutex *fileListMutex, QObject *parent = 0);
    void run();

private:
    QString _basePath;
    QString _relativePath;
    vector<CarrierFile*>* _fileList;
    QMutex* _fileListMutex;

signals:
    void finished();

public slots:
    
};

#endif // CARRIERFILEINITTASK_H
