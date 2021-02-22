#include "operationresult.h"
#include "operationinterface.h"
#include <QString>
#include <iostream>

#ifndef MULTIPLYOPERATION_H
#define MULTIPLYOPERATION_H


class MultiplyOperation : public OperationInterface
{
public:
    QSharedPointer<OperationInterface> clone();
    MultiplyOperation();
    virtual QString getOperationType(){return "*";}
    virtual double makeOperation(double a, double b, OperationResult * result);
    ~MultiplyOperation();
};

#endif // MULTIPLYOPERATION_H
