#include <stdio.h>

class Employee
{
public:
    virtual void Work()
    {
        printf("Work\n");
    }
};

class Programmer : public Employee
{
public:
    void Work() override
    {
        printf("Programming\n");
    }
};

class Designer : public Employee
{
public:
    void Work() override
    {
        printf("Designing\n");
    }
};

int main()
{
    Employee* e1 = new Programmer();
    Employee* e2 = new Designer();

    e1->Work();
    e2->Work();

    delete e1;
    delete e2;

    return 0;
}