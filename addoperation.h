#include "operationresult.h"
#include "operationinterface.h"
#include <QString>
#include <iostream>

#ifndef ADDOPERATION_H
#define ADDOPERATION_H

class AddOperation : public OperationInterface
{
public:
    AddOperation();
    ~AddOperation();
    virtual QString getOperationType(){return "+";}
    virtual double makeOperation(double a, double b, OperationResult * result)
    {
        if(result)
        {
            *result = OperationResult::Ok;
            return a + b;
        }
        else
        {
            printf("Error OperationResult\n");
            return 0;
        }
    }
};

#endif // ADDOPERATION_H
