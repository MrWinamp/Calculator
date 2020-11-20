#include "operationfactory.h"

OperationFactory::OperationFactory()
{

}

OperationInterface * OperationFactory::createOperationObject(QString type_name)
{
    if(type_name == "+")
    {
        AddOperation * add = new AddOperation;
        return add;
    }
    else if(type_name == "-")
    {
        SubtractOperation * sub = new SubtractOperation;
        return sub;
    }
    else if(type_name == "*")
    {
        MultiplyOperation * mul = new MultiplyOperation;
        return mul;
    }
    else if(type_name == "/")
    {
        DivideOperation * div = new DivideOperation;
        return div;
    }
    else
    {
        printf("Incorrect operation\n");
        return nullptr;
    }
}
