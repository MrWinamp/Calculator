#include "operationresult.h"
#include "operationinterface.h"
#include <QString>

#ifndef MULTIPLYOPERATION_H
#define MULTIPLYOPERATION_H


class MultiplyOperation : public OperationInterface
{
public:
    MultiplyOperation();
    virtual QString getOperationType(){return "*";}
    virtual double makeOperation(double a, double b, OperationResult * result)
    {
        *result = OperationResult::Ok;
        return a * b;
    }
    ~MultiplyOperation() {}
};

#endif // MULTIPLYOPERATION_H
