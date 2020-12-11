#include "subtractoperation.h"
using std::cout;

SubtractOperation::SubtractOperation()
{
    cout << "SubstractOperation constructor\n";
}

SubtractOperation::~SubtractOperation()
{
    cout << "SubstractOperation destructor\n";
}

double SubtractOperation::makeOperation(double a, double b, OperationResult * result)
{
    if(result)
    {
        *result = OperationResult::Ok;
        return a - b;
    }
    else
    {
        cout << "Error OperationResult\n";
        return 0;
    }
}
