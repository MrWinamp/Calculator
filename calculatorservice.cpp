#include "calculatorservice.h"

CalculatorService::CalculatorService()
{
    m_operation_factory_interface = nullptr;
    m_result = OperationResult::Ok;
}

double CalculatorService::makeOperation(double a, double b, QString type_name, OperationResult * result)
{
    if(m_operation_factory_interface)
    {
        OperationInterface * interface;
        interface = m_operation_factory_interface->createOperationObject(type_name);
        if(interface)
            return interface->makeOperation(a,b,result);
        else
        {
            printf("Error createOperationObject\n");
            *result = OperationResult::Error;
        }
        return 0;
    }
    else
    {
        printf("Error setOperationFactoryInterface\n");
        *result = OperationResult::Error;
    }
    return 0;
}

void CalculatorService::setOperationFactoryInterface(OperationFactoryInterface * f)
{
    m_operation_factory_interface = f;
}
