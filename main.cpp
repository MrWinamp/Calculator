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
    CalculatorService * client;
    client = new CalculatorService;
    double var1, var2, res;
    QTextStream Qcin(stdin);
    QString oper;
    OperationFactory * fac; // Создаем фабрику
    fac = new OperationFactory;
    QPointer<OperationFactory> ptr1(fac); // Используем защищенный указатель
    QPointer<CalculatorService> ptr2(client);

    if(!ptr1.isNull() && !ptr2.isNull()) // Используем QPointer для проверки правильной работы
        ptr2->setOperationFactoryInterface(ptr1.data());
    else
        return 1;

    //while(true)
    //{
        printf("Enter number 1: "); //Инициализация
        cin >> var1;
        cout << endl;
        cout << "Enter operation: ";
        Qcin >> oper;
        cout << endl;
        cout << "Enter number 2: ";
        cin >> var2;
        cout << endl;

        res = ptr2->makeOperation(var1,var2,oper);
        cout << "Result is: " << res << " result status is " << static_cast<int>(ptr2->getOperationResult()) << endl;
        //getch();
        //system("cls");
        /*
        if(static_cast<int>(client.getOperationResult()))
            break;*/
    //}

    //return a.exec();
    delete  fac;
    if(ptr1.isNull())
        cout << "OperationFactory QPointer is NULL" << endl;
    else
        cout << "OperationFactory QPointer isn't NULL" << endl;

    delete client;
    if(ptr2.isNull())
        cout << "CalculatorService QPointer is NULL" << endl;
    else
        cout << "CalculatorService QPointer isn't NULL" << endl;
    return 0;
}
