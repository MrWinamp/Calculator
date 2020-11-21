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
            if(result)
            {
                *result = OperationResult::Ok;
                return a / b;
            }
            else
            {
                printf("Error OperationResult\n");
                return 0;
            }
        }
        else
        {
            if(result)
            {
                printf("Error division by zero\n");
                *result = OperationResult::Error;
                return 0;
            }
            else
            {
                printf("Error OperationResult and division by zero\n");
                return 0;
            }
        }
    }
    ~DivideOperation() {}
};

#endif // DIVIDEOPERATION_H
