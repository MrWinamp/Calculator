#include <QtTest>
#include <QString>
#include <calculatorservice.h>

class CalculatorServiceTest : public QObject
{
    Q_OBJECT

private slots:
    void add_data();
    void sub_data();
    void mul_data();
    void div_data();

    void add();
    void sub();
    void mul();
    void div();
};

void CalculatorServiceTest::add_data()
{
    QTest::addColumn<double>("var1"); // Добавляем столбцы в таблицу данных
    QTest::addColumn<double>("var2");
    QTest::addColumn<double>("result");
    QString row;

    for(int i = -100; i < 100; i++)
        for(int j = -100; j < 100; j++)
        {
            row = "add_test[";
            row.append(QString::number(i)).append("][").append(QString::number(j)).append("]");
            QTest::newRow(row.toStdString().data()) << (double)i << (double)j << (double)i+(double)j; // Добавляем строки в таблицу данных
        }
}

void CalculatorServiceTest::add()
{
    CalculatorService client; // Начинаем инициализацию с клиента
    OperationFactory fac; // Создаем фабрику
    client.setOperationFactoryInterface(&fac); // Устанавливаем интерфейс

    QFETCH(double, var1); // Создаем локальные переменные
    QFETCH(double, var2);
    QFETCH(double, result);

    QCOMPARE(client.makeOperation(var1, var2, "+"), result); // Сравниваем полученный и ожидаемый результаты
}

void CalculatorServiceTest::sub_data()
{
    QTest::addColumn<double>("var1"); // Добавляем столбцы в таблицу данных
    QTest::addColumn<double>("var2");
    QTest::addColumn<double>("result");
    QString row;

    for(int i = -100; i < 100; i++)
        for(int j = -100; j < 100; j++)
        {
            row = "sub_test[";
            row.append(QString::number(i)).append("][").append(QString::number(j)).append("]");
            QTest::newRow(row.toStdString().data()) << (double)i << (double)j << (double)i-(double)j; // Добавляем строки в таблицу данных
        }
}

void CalculatorServiceTest::sub()
{
    CalculatorService client; // Начинаем инициализацию с клиента
    OperationFactory fac; // Создаем фабрику
    client.setOperationFactoryInterface(&fac); // Устанавливаем интерфейс

    QFETCH(double, var1); // Создаем локальные переменные
    QFETCH(double, var2);
    QFETCH(double, result);

    QCOMPARE(client.makeOperation(var1, var2, "-"), result); // Сравниваем полученный и ожидаемый результаты
}

void CalculatorServiceTest::mul_data()
{
    QTest::addColumn<double>("var1"); // Добавляем столбцы в таблицу данных
    QTest::addColumn<double>("var2");
    QTest::addColumn<double>("result");
    QString row;

    for(int i = -100; i < 100; i++)
        for(int j = -100; j < 100; j++)
        {
            row = "mul_test[";
            row.append(QString::number(i)).append("][").append(QString::number(j)).append("]");
            QTest::newRow(row.toStdString().data()) << (double)i << (double)j << (double)i*(double)j; // Добавляем строки в таблицу данных
        }
}

void CalculatorServiceTest::mul()
{
    CalculatorService client; // Начинаем инициализацию с клиента
    OperationFactory fac; // Создаем фабрику
    client.setOperationFactoryInterface(&fac); // Устанавливаем интерфейс

    QFETCH(double, var1); // Создаем локальные переменные
    QFETCH(double, var2);
    QFETCH(double, result);

    QCOMPARE(client.makeOperation(var1, var2, "*"), result); // Сравниваем полученный и ожидаемый результаты
}

void CalculatorServiceTest::div_data()
{
    QTest::addColumn<double>("var1"); // Добавляем столбцы в таблицу данных
    QTest::addColumn<double>("var2");
    QTest::addColumn<double>("result");
    QString row;
    int i, j;

    for(i = -100; i < 100; i++)
        for(j = -100; j < 0; j++)
        {
            row = "div_test[";
            row.append(QString::number(i)).append("][").append(QString::number(j)).append("]");
            QTest::newRow(row.toStdString().data()) << (double)i << (double)j << (double)i/(double)j; // Добавляем строки в таблицу данных
        }

    for(i = -100; i < 100; i++)
        for(j = 1; j < 100; j++)
        {
            row = "div_test[";
            row.append(QString::number(i)).append("][").append(QString::number(j)).append("]");
            QTest::newRow(row.toStdString().data()) << (double)i << (double)j << (double)i/(double)j; // Добавляем строки в таблицу данных
        }
    row = "div_test[";
    row.append(QString::number(i)).append("][").append(QString::number(j)).append("]");
    QTest::newRow(row.toStdString().data()) << (double)i << (double)0 << (double)0; // Деление на ноль
}

void CalculatorServiceTest::div()
{
    CalculatorService client; // Начинаем инициализацию с клиента
    OperationFactory fac; // Создаем фабрику
    client.setOperationFactoryInterface(&fac); // Устанавливаем интерфейс

    QFETCH(double, var1); // Создаем локальные переменные
    QFETCH(double, var2);
    QFETCH(double, result);

    QCOMPARE(client.makeOperation(var1, var2, "/"), result); // Сравниваем полученный и ожидаемый результаты
}

QTEST_MAIN(CalculatorServiceTest)
#include "calculatorservicetest.moc"

