#include <stdio.h>

template <typename T1, typename T2>
class MinClass {
public:

    T1 value1;
    T2 value2;

    MinClass(T1 value1, T2 value2)
        : value1(value1), value2(value2) {
    }

    T1 Min() {
        if (value1 < value2) {
            return value1;
        }

        return (T1)value2;
    }
};

int main() {

    MinClass<int, int> m1(10, 20);
    MinClass<int, float> m2(10, 20.5f);
    MinClass<int, double> m3(10, 20.8);

    MinClass<float, float> m4(3.5f, 2.1f);
    MinClass<float, double> m5(3.5f, 2.8);

    MinClass<double, double> m6(5.6, 8.9);

    printf("%d\n", m1.Min());
    printf("%d\n", m2.Min());
    printf("%d\n", m3.Min());

    printf("%f\n", m4.Min());
    printf("%f\n", m5.Min());

    printf("%lf\n", m6.Min());

    return 0;
}