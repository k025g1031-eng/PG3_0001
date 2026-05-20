#include <stdio.h>


template <typename Type>
Type Min(Type a, Type b) {

    if (a < b) {
        return static_cast<Type>(a);
    }

    return static_cast<Type>(b);
}


template <>
char Min<char>(char a, char b) {

    printf("数字以外は代入できません\n");

    return 0;
}

int main() {



    printf("int : %d\n", Min<int>(10, 20));
    printf("float : %.1f\n", Min<float>(1.2f, 2.4f));
    printf("double : %.2lf\n", Min<double>(1.23, 1.25));
    printf("char");
    Min("A", "B");

    return 0;
}