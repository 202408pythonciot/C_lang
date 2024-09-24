// 棒倒し法による迷路作成

#include <stdio.h>
#include <time.h>
#include <windows.h>

#define WIDTH (33)		// 5以上の奇数
#define HEIGHT (21)		// 5以上の奇数
#define WAIT (250)

struct {
	int x;
	int y;
} const POLE_VECT[] = {
	{-1,  0},	// LEFT
	{ 1,  0},	// RIGHT
	{ 0,  1},	// DOWN
	{ 0, -1},	// UP
};

int map[HEIGHT][WIDTH];

void clear(void) {
	printf("\x1b[2J");
}

void cursor(int x, int y) {
	printf("\x1b[%d;%dH", y + 1, x + 1);
}

void print_map(void) {
	clear();
	cursor(0, 0);
	for (int y = 0; y < HEIGHT; y += 1) {
		for (int x = 0; x < WIDTH; x += 1) {
			if (map[y][x] == 1) {
				printf("#");
			}
			else if (map[y][x] == 0) {
				printf(" ");
			}
			else {
				printf("%c", map[y][x]);
			}
		}
		printf("\n");
	}
}

void init_map(void) {
	//地図を初期化，周囲だけ壁
	for (int y = 0; y < HEIGHT; y += 1) {
		for (int x = 0; x < WIDTH; x += 1) {
			if((y == 0 || y == HEIGHT - 1)||(x == 0 || x == WIDTH - 1)){
				map[y][x] = 1;
			}
			else {
				map[y][x] = 0;
			}
		}
	}

}

int main(void) {
	// 乱数テーブルを時刻をつかって初期化
	time_t t;
	time(&t);
	srand(t);
	init_map();

	for (int y = 2; y < HEIGHT - 1; y += 2) {
		for (int x = 2; x < WIDTH - 1; x += 2) {
			map[y][x] = 1;

			int r = rand() % 3;
			if (y == 2) { // up方向に棒を倒すのは一番上だけ
				r = rand() % 4;
			}
			map[y + POLE_VECT[r].y][x + POLE_VECT[r].x] = 1;
			print_map();
			Sleep(WAIT);
		}
	}
	print_map();
	return 0;
}
