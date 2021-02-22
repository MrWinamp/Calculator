#include "calculatorservice.h"
using std::cout;

CalculatorService::CalculatorService()
{
    cout << "CalculatorService constructor\n";
    m_operation_factory_interface = QSharedPointer<OperationFactoryInterface>();
    m_result = OperationResult::Ok;
}

CalculatorService::~CalculatorService()
{
    cout << "CalculatorService destructor\n";
}

double CalculatorService::makeOperation(double a, double b, QString type_name)
{
    if(m_operation_factory_interface)
    {
        QSharedPointer<OperationInterface> ptr(m_operation_factory_interface->createOperationObject(type_name)); // Можем не беспокоиться об очистке памяти
        if(ptr)
        {
            return ptr->makeOperation(a,b,&m_result);
        }
        else
        {
            cout << "Error createOperationObject\n";
            m_result = OperationResult::Error;
        }
        return 0;
    }
    else
    {
        cout << "Error setOperationFactoryInterface\n";
        m_result = OperationResult::Error;
    }
    return 0;
}

OperationResult CalculatorService::getOperationResult()
{
    return m_result;
}

void CalculatorService::setOperationFactoryInterface(QSharedPointer<OperationFactoryInterface> f)
{
    m_operation_factory_interface = f;
}
