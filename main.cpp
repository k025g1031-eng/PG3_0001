#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <functional>
#include <Windows.h>

void SetTimeout(std::function<void()> func, int second) {

	Sleep(second * 1000);

	func();
}

int main() {

	srand((unsigned int)time(NULL));

	int input = 0;

	printf("半なら1 丁なら0 を入力してください\n");

	scanf_s("%d", &input);

	int dice = rand() % 6 + 1;

	SetTimeout([input, dice]() {

		printf("出目は %d\n", dice);

		if (dice % 2 == input) {
			printf("当たり\n");
		}
		else {
			printf("外れ\n");
		}

		}, 3);

	return 0;
}