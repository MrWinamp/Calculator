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
    virtual double makeOperation(double a, double b, OperationResult * result)
    {
        if(result)
        {
            *result = OperationResult::Ok;
            return a - b;
        }
        else
        {
            printf("Error OperationResult\n");
            return 0;
        }
    }
};

#endif // SUBTRACTOPERATION_H
