#include "calculatorservice.h"

CalculatorService::CalculatorService()
{
    m_operation_factory_interface = nullptr;
    m_result = OperationResult::Ok;
}

CalculatorService::~CalculatorService()
{
    std::cout << "CalculatorService destructor\n";
}

double CalculatorService::makeOperation(double a, double b, QString type_name)
{
    if(m_operation_factory_interface)
    {
        OperationInterface * interface;
        interface = m_operation_factory_interface->createOperationObject(type_name);
        QSharedPointer<OperationInterface> ptr(interface); // Можем не беспокоиться об очистке памяти
        if(!ptr.isNull())
        {
            return ptr->makeOperation(a,b,&m_result);
        }
        else
        {
            printf("Error createOperationObject\n");
            m_result = OperationResult::Error;
        }
        return 0;
    }
    else
    {
        printf("Error setOperationFactoryInterface\n");
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
