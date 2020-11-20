#include "operationresult.h"
#include "operationinterface.h"
#include <QString>

#ifndef SUBTRACTOPERATION_H
#define SUBTRACTOPERATION_H

class SubtractOperation : public OperationInterface
{
public:
    SubtractOperation();
    virtual QString getOperationType(){return "-";}
    virtual double makeOperation(double a, double b, OperationResult * result)
    {
        *result = OperationResult::Ok;
        return a - b;
    }
    ~SubtractOperation() {}
};

#endif // SUBTRACTOPERATION_H
