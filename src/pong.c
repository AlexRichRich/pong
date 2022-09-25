#include <stdio.h>

int width = 80; //ширина поля
int height = 25; //величина поля

int xball = 40; // координаты мяча
int yball = 11;

int XdirBall = 1; // направление по оси координат х мяча
int YdirBall = 1; // направление по оси координат у мяча

int rOne = 10; // координата ракеток по у
int rTwo = 10;

int winOne = 0; // счётчики побед
int winTwo = 0;

int move_ball();
int draw();
char move_rackets();

int main() {
    for (int i = 0; winOne != 21 && winTwo != 21; i++) {
        draw();
        move_rackets();
    }
    if (winOne == 21)
        printf("PLAYER 1 WON!\n");
    else if (winTwo == 21)
        printf("PLAYER 2 WON!\n");
}


int draw() {
    printf("\33c\e[3J"); // стриание экрана
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (x == 0 || x == width-1 || y == 0 || y == height - 1) {
                printf("+");
            } else if (y == 3 && ((winOne < 10 && x == 39) || (winTwo < 10 && x == 41))) {
                if (x == 39) printf("%d", winOne);
                if (x == 41) printf("%d", winTwo);
            } else if (y == 3 && ((winOne >= 10 && x == 37) || (winTwo >= 10 && x == 41))) {
                if(x == 37) printf("%d", winOne);
                if(x == 41) printf("%d", winTwo);
                x++;
            } else if ((x == 4 && (rOne == y || rOne + 1 == y || rOne + 2 == y)) || (x == 75 && (rTwo == y || rTwo + 1 == y || rTwo + 2 == y))) {
                printf("H");
            } else if (x == xball && y == yball) {
                printf("0");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

int startnew() {
    if(xball == 1) {
        winTwo++;
        xball = 5;
        yball = 11;
        XdirBall = -XdirBall;
        rOne = 10;
        rTwo = 10;
    } else if (xball == 79) {
        winOne++;
        xball = 74;
        yball = 11;
        XdirBall = -XdirBall;
        rOne = 10;
        rTwo = 10;
    }
    return 0;
}


int move_ball() {
    xball += XdirBall;
    yball += YdirBall;

    if (yball == rOne + 3 && YdirBall == -1 && xball == 5) {
        XdirBall = - XdirBall;
        YdirBall = - YdirBall;
    } else if (xball == 5 && (yball == rOne || yball == rOne + 1 || yball == rOne + 2)) {
        XdirBall = - XdirBall;
    } else if (yball == rOne - 1 && YdirBall == 1 && xball == 5) {
        XdirBall = - XdirBall;
        YdirBall = - YdirBall;
    }

    if (yball == rTwo + 3 && YdirBall == -1 && xball == 74) {
        XdirBall = - XdirBall;
        YdirBall = - YdirBall;
    } else if (xball == 74 && (yball == rTwo || yball == rTwo + 1 || yball == rTwo + 2)) {
        XdirBall = - XdirBall;
    } else if (yball == rTwo - 1 && YdirBall == 1 && xball == 74) {
        XdirBall = - XdirBall;
        YdirBall = - YdirBall;
    }
    if (yball == 1 || yball == 23) {
        YdirBall = - YdirBall;
    }
    startnew();
    return 0;
}


char move_rackets() {
    char up;
    if (scanf("%c", &up)) {
        if (up == 'a') {  // движение вверх правой ракетки
            move_ball();
            if (rOne == 1) {
                return 0;
            }
            rOne += -1;
        } else if (up == 'z') {  // движение вниз правой ракетки
            move_ball();
            if (rOne == 21) {
                return 0;
            }
            rOne += 1;
        } else if (up == 'k') {  // движение вверх левой ракетки
            move_ball();
            if (rTwo == 1) {
                return 0;
            }
            rTwo += -1;
        } else if (up == 'm') {  // движение вниз левой ракетки
            move_ball();
            if (rTwo == 21) {
                return 0;
            }
            rTwo += 1;
        } else if (up == ' ') {  // движение шарика без ракеток
            move_ball();
            return 0;
        }
    }
    return 0;
}
