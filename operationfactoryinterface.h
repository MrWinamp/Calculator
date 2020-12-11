#ifndef OPERATIONFACTORYINTERFACE_H
#define OPERATIONFACTORYINTERFACE_H

#include "operationinterface.h"
#include <QString>
#include <iostream>
#include <QObject>

class OperationFactoryInterface: public QObject
{
    Q_OBJECT
public:
    OperationFactoryInterface();
    virtual QSharedPointer<OperationInterface> createOperationObject(QString type_name) = 0;
    virtual ~OperationFactoryInterface();
};

#endif // OPERATIONFACTORYINTERFACE_H
