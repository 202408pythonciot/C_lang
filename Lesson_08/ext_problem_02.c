#include <stdio.h>

void my_func(void) {
    static int counter = 0;
    counter += 1;
    printf("This function is called %d time(s).\n", counter);
}
int main(void) {
    my_func(); // This function is called 1 time(s).
    my_func(); // This function is called 2 time(s).
    my_func(); // This function is called 3 time(s).
    my_func(); // This function is called 4 time(s).
    my_func(); // This function is called 5 time(s).

	return 0;
}
