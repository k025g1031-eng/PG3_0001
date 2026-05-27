#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

typedef void (*PFunc)(int*);

void DispResult(int* result) {

    if (*result == 1) {
        printf("正解です！\n");
    }
    else {
        printf("不正解です！\n");
    }
}

void setTimeout(PFunc p, int second, int* result) {

    printf("---------------\n");

    Sleep(second * 1000);

    p(result);
}

int main() {

    srand((unsigned int)time(NULL));

    int userChoice;

    printf("丁半ゲーム\n");
    printf("奇数なら 1 を入力\n");
    printf("偶数なら 0 を入力\n");

    scanf_s("%d", &userChoice);


    int dice = rand() % 6 + 1;

    printf("サイコロを振ります\n");

    int result = 0;

    if ((userChoice == 0 && dice % 2 == 0) ||
        (userChoice == 1 && dice % 2 == 1)) {

        result = 1;
    }

    PFunc p;

    p = DispResult;

    setTimeout(p, 3, &result);

    printf("出目は %d\n", dice);

    return 0;
}