#ifndef CALCULATORSERVICE_H
#define CALCULATORSERVICE_H

#include "operationfactoryinterface.h"

class CalculatorService
{
public:
    CalculatorService();
    double add(double a, double b, OperationResult * result);
    double subtract(double a, double b, OperationResult * result);
    double divide(double a, double b, OperationResult * result);
    double multiply(double a, double b, OperationResult * result);
    void setOperationFactoryInterface(OperationFactoryInterface * f);
private:
    OperationFactoryInterface * m_operation_factory_interface;
};

#endif // CALCULATORSERVICE_H
