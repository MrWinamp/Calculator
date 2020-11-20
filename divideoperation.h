#include "operationresult.h"
#include "operationinterface.h"
#include <QString>

#ifndef DIVIDEOPERATION_H
#define DIVIDEOPERATION_H


class DivideOperation : public OperationInterface
{
public:
    DivideOperation();
    virtual QString getOperationType(){return "/";}
    virtual double makeOperation(double a, double b, OperationResult * result)
    {
        if(b)
        {
            *result = OperationResult::Ok;
            return a / b;
        }
        else
        {
            printf("Error division by zero\n");
            *result = OperationResult::Error;
            return 0;
        }
    }
    ~DivideOperation() {}
};

#endif // DIVIDEOPERATION_H
