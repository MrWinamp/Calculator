#ifndef CALCULATORSERVICE_H
#define CALCULATORSERVICE_H

#include "operationfactory.h"
#include <iostream>

class CalculatorService
{
public:
    CalculatorService();
    ~CalculatorService();

    double makeOperation(double a, double b, QString type_name);
    void setOperationFactoryInterface(OperationFactoryInterface * f);
    OperationResult getOperationResult();
private:
    OperationFactoryInterface * m_operation_factory_interface;
    OperationResult m_result;
};

#endif // CALCULATORSERVICE_H
