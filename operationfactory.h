#include "operationfactoryinterface.h"
#include "addoperation.h"
#include "subtractoperation.h"
#include "multiplyoperation.h"
#include "divideoperation.h"

#ifndef OPERATIONFACTORY_H
#define OPERATIONFACTORY_H

class OperationFactory : public OperationFactoryInterface
{
public:
    OperationFactory();
    OperationInterface * createOperationObject(QString type_name);
    ~OperationFactory() {}
};

#endif // OPERATIONFACTORY_H
