#include "operationresult.h"
#include "operationinterface.h"
#include <QString>
#include <iostream>

#ifndef SUBTRACTOPERATION_H
#define SUBTRACTOPERATION_H

class SubtractOperation : public OperationInterface
{
public:
    SubtractOperation();
    ~SubtractOperation();
    virtual QString getOperationType(){return "-";}
    virtual double makeOperation(double a, double b, OperationResult * result);
};

#endif // SUBTRACTOPERATION_H
