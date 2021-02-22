#include "multiplyoperation.h"
using std::cout;

QSharedPointer<OperationInterface> MultiplyOperation::clone()
{
    return QSharedPointer<OperationInterface>(new MultiplyOperation);
}

MultiplyOperation::MultiplyOperation()
{
    cout << "MultiplyOperation constructor\n";
}

MultiplyOperation::~MultiplyOperation()
{
    cout << "MultiplyOperation destructor\n";
}

double MultiplyOperation::makeOperation(double a, double b, OperationResult * result)
{
    if(result)
    {
        *result = OperationResult::Ok;
        return a * b;
    }
    else
    {
        cout << "Error OperationResult\n";
        return 0;
    }
}
