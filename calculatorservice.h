#ifndef CALCULATORSERVICE_H
#define CALCULATORSERVICE_H

#include "operationfactory.h"

class CalculatorService
{
public:
    CalculatorService();
    /*
    double add(double a, double b, OperationResult * result);
    double subtract(double a, double b, OperationResult * result);
    double divide(double a, double b, OperationResult * result);
    double multiply(double a, double b, OperationResult * result);
    */
    double makeOperation(double a, double b, QString type_name);
    void setOperationFactoryInterface(OperationFactoryInterface * f);
    OperationResult getOperationResult();
private:
    OperationFactoryInterface * m_operation_factory_interface;
    OperationResult m_result;
};

#endif // CALCULATORSERVICE_H
