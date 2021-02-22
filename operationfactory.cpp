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
    QSharedPointer<OperationInterface> o = m_operations_hash.value(type_name, QSharedPointer<OperationInterface>());
    Q_ASSERT(o);

    if(o)
    {
        return o->clone();
    }

    cout << "Incorrect operation\n";
    return QSharedPointer<OperationInterface>();
}

void OperationFactory::registerOperationInterface(QSharedPointer<OperationInterface> operation_interface)
{
    QString operation_name = operation_interface->getOperationType();
    m_operations_hash.insert(operation_name, operation_interface);
}
