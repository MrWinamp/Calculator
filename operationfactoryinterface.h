#ifndef OPERATIONFACTORYINTERFACE_H
#define OPERATIONFACTORYINTERFACE_H

#include "operationinterface.h"
#include <QString>
#include <iostream>

class OperationFactoryInterface
{
public:
    OperationFactoryInterface();
    virtual OperationInterface * createOperationObject(QString type_name) = 0;
    virtual ~OperationFactoryInterface();
};

#endif // OPERATIONFACTORYINTERFACE_H
