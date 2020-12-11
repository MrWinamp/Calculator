#include "calculatorservice.h"
using std::cout;

CalculatorService::CalculatorService()
{
    cout << "CalculatorService constructor\n";
    m_operation_factory_interface = nullptr;
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
        QSharedPointer<OperationInterface> ptr; // Можем не беспокоиться об очистке памяти
        ptr = m_operation_factory_interface->createOperationObject(type_name);
        if(!ptr.isNull())
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

void CalculatorService::setOperationFactoryInterface(OperationFactoryInterface * f)
{
    m_operation_factory_interface = f;
}
