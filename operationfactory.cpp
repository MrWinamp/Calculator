#include "operationfactory.h"
using std::cout;

OperationFactory::OperationFactory()
{
    cout << "OperationFactory constructor\n";
}

OperationFactory::~OperationFactory()
{
    cout << "OperationFactory destructor\n";
}

QSharedPointer<OperationInterface> OperationFactory::createOperationObject(QString type_name)
{
    if(type_name == "+")
    {
        AddOperation * add = new AddOperation;
        QSharedPointer<OperationInterface> ptr(add);
        return ptr;
    }
    else if(type_name == "-")
    {
        SubtractOperation * sub = new SubtractOperation;
        QSharedPointer<OperationInterface> ptr(sub);
        return ptr;
    }
    else if(type_name == "*")
    {
        MultiplyOperation * mul = new MultiplyOperation;
        QSharedPointer<OperationInterface> ptr(mul);
        return ptr;
    }
    else if(type_name == "/")
    {
        DivideOperation * div = new DivideOperation;
        QSharedPointer<OperationInterface> ptr(div);
        return ptr;
    }
    else
    {
        cout << "Incorrect operation\n";
        return nullptr;
    }
}
