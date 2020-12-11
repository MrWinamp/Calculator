#include "addoperation.h"
using std::cout;

AddOperation::AddOperation()
{
    cout << "AddOperation constructor\n";
}

AddOperation::~AddOperation()
{
    cout << "AddOperation destructor\n";
}

double AddOperation::makeOperation(double a, double b, OperationResult * result)
{
    if(result)
    {
        *result = OperationResult::Ok;
        return a + b;
    }
    else
    {
        cout << "Error OperationResult\n";
        return 0;
    }
}
