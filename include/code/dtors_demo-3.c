#include <stdio.h>
#include <stdlib.h>

// 模板:
// 创建 ELF .init_array段。

static void create(void) __attribute__ ((constructor));
static void destroy(void) __attribute__ ((destructor));



int main(int argc, char const *argv[])
{
	printf("create fptr: %p. \n", create);
	printf("destroy fptr: %p. \n", destroy);
	return 0;
}

static void create(void) {
	puts("create called.");
}

static void destroy(void) {
	puts("destroy called.");
}

static void crack(void) {
	puts("crack called.");
}
