#ifndef OPERATIONFACTORYINTERFACE_H
#define OPERATIONFACTORYINTERFACE_H

#include "operationinterface.h"
#include <QString>

class OperationFactoryInterface
{
public:
    virtual OperationInterface * createOperationObject(QString type_name) = 0;
    virtual ~OperationFactoryInterface() {};
};

#endif // OPERATIONFACTORYINTERFACE_H
