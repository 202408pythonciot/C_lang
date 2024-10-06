#include <stdio.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0
#define LOOP_DELAY (50)
#define SPEED_INIT (50)
#define SPEED_MAX (5)

enum _KEY {
    KEY_UP = 1,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_DOWN,
    KEY_SPACE,
};

// 色
enum _COLOR {
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

// ブロック
enum BLOCK_TYPE {
    BLOCK_LZ,
    BLOCK_RZ,
    BLOCK_LL,
    BLOCK_RL,
    BLOCK_B,
    BLOCK_T,
    BLOCK_I,
    BLOCK_TYPE_MAX
};
enum BLOCK_STYLE {
    BLOCK_STYLE_R0,
    BLOCK_STYLE_R1,
    BLOCK_STYLE_R2,
    BLOCK_STYLE_R3,
    BLOCK_STYLE_MAX
};

enum _GAME_STATUS {
    GAME_INIT,
    GAME_PLAY,
    GAME_OVER
};
#define BLOCK_AREA 4

const int BLOCK[BLOCK_TYPE_MAX][BLOCK_STYLE_MAX][BLOCK_AREA][BLOCK_AREA] =
{
    {
        {
            {0, 0, 0, 0},
            {RED, RED, 0, 0},
            {0, RED, RED, 0},
            {0, 0, 0, 0}
        },
        {
            {0, RED, 0, 0},
            {RED, RED, 0, 0},
            {RED, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {RED, RED, 0, 0},
            {0, RED, RED, 0},
            {0, 0, 0, 0}
        },
        {
            {0, RED, 0, 0},
            {RED, RED, 0, 0},
            {RED, 0, 0, 0},
            {0, 0, 0, 0}
        }
    },
    {
        {
            {0, 0, 0, 0},
            {0, GREEN, GREEN, 0},
            {GREEN, GREEN, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, GREEN, 0, 0},
            {0, GREEN, GREEN, 0},
            {0, 0, GREEN, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {0, GREEN, GREEN, 0},
            {GREEN, GREEN, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, GREEN, 0, 0},
            {0, GREEN, GREEN, 0},
            {0, 0, GREEN, 0},
            {0, 0, 0, 0}
        }
    },
    {
        {
            {0, 0, BLUE, 0},
            {BLUE, BLUE, BLUE, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, BLUE, 0, 0},
            {0, BLUE, 0, 0},
            {0, BLUE, BLUE, 0},
            {0, 0, 0, 0}
        },
        {
            {BLUE, BLUE, BLUE, 0},
            {BLUE, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, BLUE, BLUE, 0},
            {0, 0, BLUE, 0},
            {0, 0, BLUE, 0},
            {0, 0, 0, 0}
        }
    },
    {
        {
            {0, YELLOW, 0, 0},
            {0, YELLOW, YELLOW, YELLOW},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, YELLOW, YELLOW, 0},
            {0, YELLOW, 0, 0},
            {0, YELLOW, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, YELLOW, YELLOW, YELLOW},
            {0, 0, 0, YELLOW},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, 0, YELLOW, 0},
            {0, 0, YELLOW, 0},
            {0, YELLOW, YELLOW, 0},
            {0, 0, 0, 0}
        }
    },
    {
        {
            {0, YELLOW, YELLOW, 0},
            {0, YELLOW, YELLOW, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, YELLOW, YELLOW, 0},
            {0, YELLOW, YELLOW, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, YELLOW, YELLOW, 0},
            {0, YELLOW, YELLOW, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, YELLOW, YELLOW, 0},
            {0, YELLOW, YELLOW, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        }
    },
    {
        {
            {0, MAGENTA, 0, 0},
            {MAGENTA, MAGENTA, MAGENTA, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, MAGENTA, 0, 0},
            {0, MAGENTA, MAGENTA, 0},
            {0, MAGENTA, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {MAGENTA, MAGENTA, MAGENTA, 0},
            {0, MAGENTA, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, MAGENTA, 0, 0},
            {MAGENTA, MAGENTA, 0, 0},
            {0, MAGENTA, 0, 0},
            {0, 0, 0, 0}
        }
    },
    {
        {
            {0, 0, 0, 0},
            {RED, RED, RED, RED},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, RED, 0, 0},
            {0, RED, 0, 0},
            {0, RED, 0, 0},
            {0, RED, 0, 0}
        },
        {
            {0, 0, 0, 0},
            {RED, RED, RED, RED},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {0, RED, 0, 0},
            {0, RED, 0, 0},
            {0, RED, 0, 0},
            {0, RED, 0, 0}
        }
    }
};


#define FIELD_WIDTH 12
#define FIELD_HEIGHT 22
#define FIELD_MARGINE 3

int GAME_STATUS;
int FIELD[FIELD_HEIGHT][FIELD_WIDTH];
int NEXT_BLOCK;
int CURRENT_BLOCK;
int CURRENT_BLOCK_STYLE;
int CURRENT_BLOCK_X;
int CURRENT_BLOCK_Y;
int SPEED;
int SCORE;
int LEVEL;
int LEVEL_B;
void clear(void) {
    printf("\x1b[2J");
}
void cursor(int x, int y) {
    printf("\x1b[%d;%dH", y + 1, x + 1);
}
void color(int col) {
    printf("\x1b[3%dm", col);
}

int init(void) {
    srand(0);
    GAME_STATUS = GAME_INIT;
    SCORE = 0;
    LEVEL = 1;
    LEVEL_B = 1;
    // フィールドの初期化
    for (int y = 0; y < FIELD_HEIGHT; y += 1) {
        for (int x = 0; x < FIELD_WIDTH; x += 1) {
            if (x == 0 || x == FIELD_WIDTH - 1) {
                FIELD[y][x] = WHITE;
            }
            else if (y == FIELD_HEIGHT - 1) {
                FIELD[y][x] = WHITE;
            }
            else {
                FIELD[y][x] = 0;
            }
        }
    }
    NEXT_BLOCK = rand() % BLOCK_TYPE_MAX;
    CURRENT_BLOCK = -1;
    CURRENT_BLOCK_STYLE = BLOCK_STYLE_R0;
    CURRENT_BLOCK_X = 5;
    CURRENT_BLOCK_Y = 0;
    SPEED = SPEED_INIT;
}

void drawNextBlock(void) {
    for (int y = 0; y < 4; y += 1) {
        for (int x = 0; x < 4; x += 1) {
            cursor(x + 5, y);
            if(BLOCK[NEXT_BLOCK][0][y][x] > 0){
                color(BLOCK[NEXT_BLOCK][0][y][x]);
                printf("■");
            }
        }
    }
}

void drawField(void) {
    for (int y = 0; y < FIELD_HEIGHT; y += 1) {
        for (int x = 0; x < FIELD_WIDTH; x += 1) {
            cursor(x, y + FIELD_MARGINE);
            if(FIELD[y][x] > 0) {
                color(FIELD[y][x]);
                printf("■");
            }
        }
    }

    for (int y = 0; y < 4; y += 1) {
        for (int x = 0; x < 4; x += 1) {
            cursor(CURRENT_BLOCK_X + x, CURRENT_BLOCK_Y + y + FIELD_MARGINE);
            if (BLOCK[CURRENT_BLOCK][CURRENT_BLOCK_STYLE][y][x] > 0) {
                color(BLOCK[CURRENT_BLOCK][CURRENT_BLOCK_STYLE][y][x]);
                printf("■");
            }
        }
    }
}

int isHit(int target_x, int target_y, int target_style) {
    for (int y = 3; y >= 0; y -= 1) {
        for (int x = 3; x >= 0; x -= 1) {
            if ((BLOCK[CURRENT_BLOCK][target_style][y][x] > 0) && (FIELD[target_y + y][target_x + x] > 0)) {
                    return TRUE;
            }
        }
    }
    return FALSE;
}

void execRotateBlock(int target_x, int target_y, int target_style) {
    int next = (target_style + 1) % BLOCK_STYLE_MAX;
    if (!isHit(target_x, target_y, next)) {
        CURRENT_BLOCK_STYLE = next;
    }
    else if ((target_x == 0) && !isHit(target_x + 1, target_y, next)) {
        CURRENT_BLOCK_X = target_x + 1;
        CURRENT_BLOCK_STYLE = next;
    }
    else if ((target_x > 0) && !isHit(target_x - 1, target_y, next)) {
        CURRENT_BLOCK_X = target_x - 1;
        CURRENT_BLOCK_STYLE = next;
    }
}

void update(void) {
    if (isHit(CURRENT_BLOCK_X, CURRENT_BLOCK_Y + 1, CURRENT_BLOCK_STYLE)) {
        for (int y = 0; y < 4; y += 1) {
            for (int x = 0; x < 4; x += 1) {
                if (FIELD[CURRENT_BLOCK_Y + y][CURRENT_BLOCK_X + x] == 0) {
                    FIELD[CURRENT_BLOCK_Y + y][CURRENT_BLOCK_X + x] = BLOCK[CURRENT_BLOCK][CURRENT_BLOCK_STYLE][y][x];
                }
            }
        }
        CURRENT_BLOCK = -1;
        CURRENT_BLOCK_X = 5;
        CURRENT_BLOCK_Y = 0;
    }
    else {
        CURRENT_BLOCK_Y += 1;
    }
    if (CURRENT_BLOCK == -1) {
        CURRENT_BLOCK_Y = 0;
        CURRENT_BLOCK = NEXT_BLOCK;
        CURRENT_BLOCK_STYLE = BLOCK_STYLE_R0;
        NEXT_BLOCK = rand() % BLOCK_TYPE_MAX;
        if (isHit(CURRENT_BLOCK_X, CURRENT_BLOCK_Y + 1, CURRENT_BLOCK_STYLE)) {
            GAME_STATUS = GAME_OVER;
        }
    }
}

int checkKeyInter() {
    int key;
    if (kbhit()) {
        key = getch();
        if (key == 0 || key == 224) {
            switch (getch()) {
            case 72:
                return KEY_UP;
            case 80:
                return KEY_DOWN;
            case 75:
                return KEY_LEFT;
            case 77:
                return KEY_RIGHT;
            }
        }
        else {
            switch (key) {
            case ' ':
                return KEY_SPACE;
            default:
                return 0;
            }
        }
    }
    return 0;
}


void controll(void) {
    switch (checkKeyInter()) {
    case KEY_SPACE:
        if (GAME_STATUS == GAME_INIT) {
            GAME_STATUS = GAME_PLAY;
        }
        else if (GAME_STATUS == GAME_PLAY) {
            execRotateBlock(CURRENT_BLOCK_X, CURRENT_BLOCK_Y, CURRENT_BLOCK_STYLE);
        }
        break;
    case KEY_DOWN:
        if ((GAME_STATUS == GAME_PLAY) &&
            (!isHit(CURRENT_BLOCK_X, CURRENT_BLOCK_Y + 1, CURRENT_BLOCK_STYLE))) {
                CURRENT_BLOCK_Y += 1;
        }
        break;
    case KEY_LEFT:
        if ((GAME_STATUS == GAME_PLAY) &&
            (!isHit(CURRENT_BLOCK_X - 1, CURRENT_BLOCK_Y, CURRENT_BLOCK_STYLE))) {
                CURRENT_BLOCK_X -= 1;
        }
        break;
    case KEY_RIGHT:
        if ((GAME_STATUS == GAME_PLAY) &&
            (!isHit(CURRENT_BLOCK_X + 1, CURRENT_BLOCK_Y, CURRENT_BLOCK_STYLE))) {
                CURRENT_BLOCK_X += 1;
        }
        break;
    }
}

void execLineCheck(void) {
    int flag, lcnt = 0;
    int line[4] = {-1, -1, -1, -1};
    for (int y = 0; y < FIELD_HEIGHT - 1; y += 1) {
        flag = 1;
        for (int x = 1; x < FIELD_WIDTH - 1; x += 1) {
            if (FIELD[y][x] == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            line[lcnt] = y;
            lcnt += 1;
        }
    }
    for (int i = 0; i < 4; i += 1) {
        if (line[i] >= 0) {
            for (int y = line[i] - 1; y >= 0; y -= 1) {
                for (int x = 1; x < FIELD_WIDTH - 1; x += 1) {
                    if (y > 0) {
                        FIELD[y + 1][x] = FIELD[y][x];
                    }
                    else if (y == 0) {
                        FIELD[0][x] = 0;
                    }
                }
            }
        }
    }

    switch (lcnt) {
    case 1:
        SCORE = SCORE + 10;
        break;
    case 2:
        SCORE = SCORE + 20;
        break;
    case 3:
        SCORE = SCORE + 50;
        break;
    case 4:
        SCORE = SCORE + 100;
        break;
    }
    LEVEL = SCORE / 100 + 1;
    if ((LEVEL != LEVEL_B) && (SPEED > SPEED_MAX)) {
        SPEED -= 5;
    }
    if (SPEED < SPEED_MAX) {
        SPEED = SPEED_MAX;
    }
    LEVEL_B = LEVEL;
}

void drawMessage(void) {
    color(WHITE);
    cursor(15, 2);
    switch (GAME_STATUS) {
    case GAME_INIT:
        printf("Press Space if you are ready.");
        break;
    case GAME_PLAY:
        break;
    case GAME_OVER:
        printf("GAME OVER");
        break;
    }
    cursor(15, 4);
    printf("LEVEL: %d", LEVEL);
    cursor(15, 5);
    printf("SCORE: %d", SCORE);
}

// メインループ
void loop(void) {
    int count = 0;
    int linecheck_flag = 0;
    while (1) {
        clear();
        controll();
        if(GAME_STATUS == GAME_PLAY){
            if (!(count % SPEED)){
                update();
                count = 0;
                linecheck_flag = 1;
            }
            else if (linecheck_flag) {
                execLineCheck();
            }
        }
        drawNextBlock();
        drawField();
        drawMessage();
        Sleep(LOOP_DELAY);
        count += 1;
    }
}

int main(void) {
    init();
    loop();
    return 0;
}
