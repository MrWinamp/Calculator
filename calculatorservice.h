#ifndef CALCULATORSERVICE_H
#define CALCULATORSERVICE_H

#include "operationfactory.h"
#include <iostream>
#include <QObject>
#include <QSharedPointer>

class CalculatorService: public QObject
{
    Q_OBJECT
public:
    CalculatorService();
    ~CalculatorService();

    double makeOperation(double a, double b, QString type_name);
    void setOperationFactoryInterface(QSharedPointer<OperationFactoryInterface> f);
    OperationResult getOperationResult();
private:
    QSharedPointer<OperationFactoryInterface> m_operation_factory_interface;
    OperationResult m_result;
};

#endif // CALCULATORSERVICE_H
