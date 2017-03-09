/*
* @Subject: 
* @Model:
* @Compile-cmd: gcc -Wall 
* 
* @Author:    LiuKun
* @Date:      2017-02-15 14:09:30
* @Email:     liukun@antiy.cn
* @File Path: /Users/liukun/FloatingGuyBlog/blog/source/include/code/int5_5_3.c
* @Create Time: 2017-02-15 14:09:30
* @Last Modified by:   FloatingGuy
* @Last Modified time: 2017-02-15 15:26:56
* @Reference: 
*
* 5.5.3  转换错误
*
* 64bit x86064设备上
*  int -> size_t 
*  有符号 转无符号
*  4字节 到8字节
*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ARRAY_SIZE 500

//int -> size_t
//-1
void initalize_array(int size) {
    if (size < MAX_ARRAY_SIZE) {   //[1]
    	size_t len = (size_t)size;   //最大的 8字节无符号数
    	printf("sizeof size_t = %lu\n", sizeof(len));
    	printf("size_t:%zu, 0x%8zx\n", len, len);
        // array = malloc(size);       //bug
        // free(array);
    }
    else {
    	printf("poc error\n");
    }
}

//size_t -> unsigned short
void cut_off_error(size_t size, char* str1, char* str2) {
	unsigned short int total;
	total = size;
	printf("LONG_MAX  %ld\n", LONG_MAX);	//9223372036854775807
	printf("USHRT_MAX %d\n", USHRT_MAX);	//65535
	printf("%d, 0x%x\n", total, total);  //1 , 0x1
	char* buf = (char*)malloc(total);
    strcpy(buf, str1);       //vul
    strcpy(buf, str2);       //vul
    free(buf);
}


// '0xffff ffff ffff ffffL'
// '0x1 0000 0000 0000 0000L'
int main(int argc, char const *argv[])
{
	/* code */
	int a = -1;
	printf("sizeof int = %lu\n", sizeof(a));
	printf("int:%d, 0x%8x\n",a, a );
	// initalize_array(a);
	printf("long size:%d\n", sizeof(long));
	cut_off_error(65537, "", "");
	return 0;
}
/*
sizeof int = 4
int:-1, 0xffffffff
sizeof size_t = 8
size_t:18446744073709551615, 0xffffffff
*/