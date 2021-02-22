#include "operationfactoryinterface.h"
#include "addoperation.h"
#include "subtractoperation.h"
#include "multiplyoperation.h"
#include "divideoperation.h"
#include <iostream>
#include <QSharedPointer>

#ifndef OPERATIONFACTORY_H
#define OPERATIONFACTORY_H

class OperationFactory : public OperationFactoryInterface
{
public:
    OperationFactory();
    QSharedPointer<OperationInterface> createOperationObject(QString type_name);
    void registerOperationInterface(QSharedPointer<OperationInterface> operation_intarface);
    ~OperationFactory();
private:
    QHash<QString, QSharedPointer<OperationInterface>> m_operations_hash;
};

#endif // OPERATIONFACTORY_H
