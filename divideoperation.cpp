#include "divideoperation.h"
using std::cout;

QSharedPointer<OperationInterface> DivideOperation::clone()
{
    return QSharedPointer<OperationInterface>(new DivideOperation);
}

DivideOperation::DivideOperation()
{
    cout << "DivideOperation constructor\n";
}

DivideOperation::~DivideOperation()
{
    cout << "DivideOperation destructor\n";
}

double DivideOperation::makeOperation(double a, double b, OperationResult * result)
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
            cout << "Error OperationResult\n";
            return 0;
        }
    }
    else
    {
        if(result)
        {
            cout << "Error division by zero\n";
            *result = OperationResult::Error;
            return 0;
        }
        else
        {
            cout << "Error OperationResult and division by zero\n";
            return 0;
        }
    }
}
