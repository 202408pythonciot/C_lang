#include <stdio.h>
#include <string.h>

typedef struct _Myformat{
	char sur_name[10];
	char last_name[10];
	int  age;
}Myformat;

Myformat setData(char* sur_name, char* last_name, int age) {
	Myformat ret;
	strcpy(&ret.sur_name, sur_name);
	strcpy(&ret.last_name, last_name);
	ret.age = age;
	return ret;
}

int main(void) {
	Myformat a;
	a = setData("neugate", "taro", 30);
	printf("Sur Name:%s\n", a.sur_name);
	printf("Last Name:%s\n", a.last_name);
	printf("age:%d\n", a.age);
	return 0;
}
