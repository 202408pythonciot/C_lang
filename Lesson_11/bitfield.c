#include <stdio.h>
typedef struct _bit8 {
	unsigned char _b0 : 1;
	unsigned char _b1 : 1;
	unsigned char _b2 : 1;
	unsigned char _b3 : 1;
	unsigned char _b4 : 1;
	unsigned char _b5 : 1;
	unsigned char _b6 : 1;
	unsigned char _b7 : 1;
}bit8;
typedef union _si8t {
	signed char byte;
	bit8 bits;
} si8t;

int main(void) {
	si8t a;
	printf("整数(-128～127)を入力してください\n");
	scanf("%hhd", &a.byte);
	printf("10進数:%hhd, 16進数:0x%02hhx, \n", a.byte, a.byte);
	for (int i = 0; i < 8; i += 1) {
		printf(" %d", i);
	}
	printf("\n");
	printf(" %d", a.bits._b7);
	printf(" %d", a.bits._b6);
	printf(" %d", a.bits._b5);
	printf(" %d", a.bits._b4);
	printf(" %d", a.bits._b3);
	printf(" %d", a.bits._b2);
	printf(" %d", a.bits._b1);
	printf(" %d", a.bits._b0);

	return 0;
}
