#include "operationresult.h"
#include "operationinterface.h"
#include <QString>
#include <iostream>

#ifndef DIVIDEOPERATION_H
#define DIVIDEOPERATION_H


class DivideOperation : public OperationInterface
{
public:
    QSharedPointer<OperationInterface> clone();
    DivideOperation();
    virtual QString getOperationType(){return "/";}
    virtual double makeOperation(double a, double b, OperationResult * result);
    ~DivideOperation();
};

#endif // DIVIDEOPERATION_H
