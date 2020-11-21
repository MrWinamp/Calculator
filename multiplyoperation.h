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
        if(result)
        {
            *result = OperationResult::Ok;
            return a * b;
        }
        else
        {
            printf("Error OperationResult\n");
            return 0;
        }
    }
    ~MultiplyOperation() {}
};

#endif // MULTIPLYOPERATION_H
