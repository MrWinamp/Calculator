#include "operationresult.h"
#include "operationinterface.h"
#include <QString>

#ifndef ADDOPERATION_H
#define ADDOPERATION_H

class AddOperation : public OperationInterface
{
public:
    AddOperation();
    virtual QString getOperationType(){return "+";}
    virtual double makeOperation(double a, double b, OperationResult * result)
    {
        *result = OperationResult::Ok;
        return a + b;
    }
    ~AddOperation() {}
};

#endif // ADDOPERATION_H
