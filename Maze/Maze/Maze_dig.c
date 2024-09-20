// 穴掘り法による迷路作成

#include <stdio.h>
#include <time.h>
#include <windows.h>

#define WIDTH (33)
#define HEIGHT (21)
#define WAIT (250)

struct {
	int x;
	int y;
} const DIG_VECT[] = {
	{ 0, -1},	// UP
	{ 0,  1},	// DOWN
	{-1,  0},	// LEFT
	{ 1,  0}	// RIGHT
};

int map[HEIGHT][WIDTH];

void clear(void) {
	printf("\x1b[2J");
}
void cursor(int x, int y) {
	printf("\x1b[%d;%dH", y + 1, x + 1);
}
void init_map(void) {
	//地図を初期化，すべて壁で埋める
	for (int y = 0; y < HEIGHT; y += 1) {
		for (int x = 0; x < WIDTH; x += 1) {
			map[y][x] = 1;
		}
	}
	// 乱数テーブルを時刻をつかって初期化
	time_t t;
	time(&t);
	srand(t);
}

void print_map(void) {
	clear();
	cursor(0, 0);
	for (int y = 0; y < HEIGHT; y += 1) {
		for (int x = 0; x < WIDTH; x += 1) {
			if (map[y][x] == 1) {
				printf("#");
			}else if(map[y][x] == 0) {
				printf(" ");
			}
			else {
				printf("%c", map[y][x]);
			}
		}
		printf("\n");
	}
}

void dig(x, y) {
	int d = rand() % 4;
	int dd = d;

	print_map();
	Sleep(WAIT);
	for (;;) {
		int px = x + DIG_VECT[d].x * 2;
		int py = y + DIG_VECT[d].y * 2;

		if (px < 0 || px >= WIDTH || py < 0 || py >= HEIGHT || map[py][px] == 0) {
			d++;
			if (d == 4)
				d = 0;
			if (d == dd)
				return;
		}
		else {
			map[y + DIG_VECT[d].y][x + DIG_VECT[d].x] = 0;
			map[py][px] = 0;
			dig(px, py);
			d = dd = rand() % 4;
		}
	}
}

int rand_odd(int max) {
	return ((rand() % ((max + 1) / 2)) + 1) * 2 - 1;
}

int main(void) {
	init_map();
	int x = rand_odd(WIDTH - 2);
	int y = rand_odd(HEIGHT - 2);
	dig(x, y);
	// 入口を掘る
	map[1][0] = 0;
	// 出口を掘る
	map[HEIGHT - 1 - 1][WIDTH - 1] = 0;
	print_map();
	return 0;
}
