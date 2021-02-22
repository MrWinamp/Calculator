#include "operationresult.h"
#include "operationinterface.h"
#include <QString>
#include <iostream>

#ifndef ADDOPERATION_H
#define ADDOPERATION_H

class AddOperation : public OperationInterface
{
public:
    QSharedPointer<OperationInterface> clone();
    AddOperation();
    ~AddOperation();
    virtual QString getOperationType(){return "+";}
    virtual double makeOperation(double a, double b, OperationResult * result);
};

#endif // ADDOPERATION_H
