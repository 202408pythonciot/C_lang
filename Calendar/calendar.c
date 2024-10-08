#include <stdio.h>

#define WDAYS  (7)
const char *W[WDAYS] = {"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"};
// グレゴリオ暦の年をいれるとうるう年であれば「1」を，それ以外は「0」を返す関数
int check_leap_year(int year){
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
        return 1;
    }
    return 0;
}

// グレゴリオ暦での曜日判定(日：0，月：1，〜，土：6)
int get_weekday(int year, int month, int day){
    if(month < 3){
        year  = year - 1;
        month = month + 12;
    }
    return (year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + day) % 7;
}

// グレゴリオ暦で月の最終日を求める
int get_month_lastday(int year, int month){
    int d = 30;
    if(month == 1 || month == 3 || month == 5  || month == 7  || month == 8  || month == 10  || month == 12){
        d = d + 1;
    }else if(month == 2){
        d = 28 + check_leap_year(year);
    }
    return d;
}

void print_cal(int year, int month){
    printf("       %d-%d\n", year, month);
    int day = 0;
    for(int wd = 0; wd < WDAYS ; wd += 1){
        printf(" %s", W[wd]);
    }
    printf("\n");
    for(int week = 0; week < 5; week += 1){
        for(int wd = 0; wd < WDAYS ; wd += 1){
            if ((week == 0 && wd >= get_weekday(year, month, 1))||((day >= 1)&&(day < get_month_lastday(year, month)))){
                day += 1;
                printf(" %2d", day);
            }else{
                printf("   ");
                
            }
        }
        printf("\n");
    }
}

int main(void){
     print_cal(2024, 2);
    return 0;
}
