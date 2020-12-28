#include <QCoreApplication>
#include "calculatorservice.h"
#include <iostream>
#include <QTextStream>
#include <QString>
#include <QTextCodec>
#include <conio.h>
#include <QPointer>
#include <windows.h>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    double var1, var2, res;
    QTextStream Qcin(stdin);
    QString oper;
    QSharedPointer<OperationFactory> ptr1(new OperationFactory); // Используем умный указатель
    QSharedPointer<CalculatorService> ptr2(new CalculatorService);

    if(ptr1 && ptr2) // Используем QSharedPointer для проверки правильной работы
        ptr2->setOperationFactoryInterface(ptr1);
    else
        return 1;

    //while(true)
    //{
        cout << "\nEnter number 1: "; //Инициализация
        cin >> var1;
        cout << endl;
        cout << "Enter operation: ";
        Qcin >> oper;
        cout << endl;
        cout << "Enter number 2: ";
        cin >> var2;
        cout << endl;

        res = ptr2->makeOperation(var1,var2,oper);
        cout << "\nResult is: " << res << " result status is " << static_cast<int>(ptr2->getOperationResult()) << endl << endl;
        //getch();
        //system("cls");
        /*
        if(static_cast<int>(client.getOperationResult()))
            break;*/
    //}

    //return a.exec();
    return 0;
}
