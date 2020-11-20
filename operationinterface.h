#ifndef OPERATIONINTERFACE_H
#define OPERATIONINTERFACE_H

#include "operationresult.h"
#include <QString>

class OperationInterface
{
public:
    virtual QString getOperationType() = 0;
    virtual double makeOperation(double a, double b, OperationResult * result) = 0;
    virtual ~OperationInterface() {};
protected:
    OperationResult m_result;
};

#endif // OPERATIONINTERFACE_H
