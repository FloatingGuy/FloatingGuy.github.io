#include "stdio.h"
#include "limits.h"

// 无符号数 安全

void check_no_wrap()
{
	unsigned i, j, sum;
	sum = UINT_MAX;
	i = j = 1;

	if (sum + i > UINT_MAX)
		printf("too big\n");
	else
		printf("ok\n");

}

void check_yes_wrap()
{
	unsigned i, j, sum;
	sum = UINT_MAX;
	i = j = 1;

	if (i > UINT_MAX - sum)
		printf("too big\n");
	else
		printf("ok\n");
}

void simple_test()
{
	unsigned int ui;
	ui = UINT_MAX;  //0xffff ffff
	ui++;
	printf("ui = %u\n", ui);
	ui = 0;
	ui--;
	printf("ui = %u\n", ui);
}

int main(int argc, char const *argv[])
{
	/* code */
	printf("错误检测 wrap 回绕\n");
	check_no_wrap();
	printf("正确检测 wrap 回绕\n");
	check_yes_wrap();
	return 0;
}