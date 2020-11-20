#include <QCoreApplication>
#include "calculatorservice.h"
#include <iostream>
#include <QTextStream>
#include <QString>
#include <QTextCodec>
#include <conio.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CalculatorService client;
    OperationResult result = OperationResult::Ok;
    double var1, var2, res;
    QTextStream Qcin(stdin);
    QString oper;
    OperationFactory fac; // Создаем фабрику
    client.setOperationFactoryInterface(&fac);

    while(true)
    {
        printf("Enter numeber 1: "); //Инициализация
        cin >> var1;
        cout << endl;
        cout << "Enter operation: ";
        Qcin >> oper;
        cout << endl;
        cout << "Enter number 2: ";
        cin >> var2;
        cout << endl;

        res = client.makeOperation(var1,var2,oper,&result);
        cout << "Result is: " << res << " result status is " << static_cast<int>(result) << endl;
        getch();
        system("cls");
    }

    return a.exec();
}
