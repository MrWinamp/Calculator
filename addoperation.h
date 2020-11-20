#ifndef ADDOPERATION_H
#define ADDOPERATION_H

#include "operationresult.h"
#include "operationinterface.h"
#include <QString>

class AddOperation: public OperationInterface
{
public:
    AddOperation();
    virtual QString getOperationType(){return "Add";}
    virtual void makeOperation(double a, double b, OperationResult * result)
    {
        m_result = OperationResult::Ok;
        result = &m_result;
    }
    ~AddOperation() {}
};

#endif // ADDOPERATION_H
