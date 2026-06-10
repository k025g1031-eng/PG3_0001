#include <stdio.h>


class IShape
{
public:
    virtual void Size() = 0;
    virtual void Draw() = 0;
};

class Circle : public IShape
{
private:
    float radius;
    float area;

public:
    Circle(float r)
    {
        radius = r;
        area = 0.0f;
    }

    void Size() override
    {
        area = 3.14f * radius * radius;
    }

    void Draw() override
    {
        printf("Circle Area = %f\n", area);
    }
};

class Rectangle : public IShape
{
private:
    float width;
    float height;
    float area;

public:
    Rectangle(float w, float h)
    {
        width = w;
        height = h;
        area = 0.0f;
    }

    void Size() override
    {
        area = width * height;
    }

    void Draw() override
    {
        printf("Rectangle Area = %f\n", area);
    }
};

int main()
{
    Circle circle(5.0f);
    Rectangle rect(4.0f, 3.0f);

    circle.Size();
    circle.Draw();

    rect.Size();
    rect.Draw();

    return 0;
}