#include <stdio.h>

void paint();
void moveRocket();
void moveball();
void score();

int scoreA = 0;
int scoreB = 0;
int yroketka1 = 13;
int yroketka2 = 13;

int borderUp = 0;
int borderDown = 25;
int borderLeft = 0;
int borderRight = 80;

int bollX = 39;
int bollY = 13;
int vectorX = -1;
int vectorY = -1;

int victory = 21;
char c1;
int winner;

int main() {
    paint();
    while (1) {
        scanf("%c", &c1);
        if ((c1 == 'z' || c1 == 'Z') ||
        (c1 == 'a' || c1 == 'A') ||
        (c1 == 'm' || c1 == 'M') ||
        (c1 == 'k' || c1 == 'K') ||
        (c1 == ' ')) {
            printf("\033[0d\033[2J");
            paint();
            if (scoreA == victory || scoreB == victory) {
                if (scoreA > scoreB) winner = 1;
                else
                winner = 2;
                printf("\nPlayer %d is WIN!!!!\nСongratulations!!!!\n", winner);
                break;
            }
        }
    }

    return 0;
}

void paint() {
    moveRocket();
    moveball();
    for (int y = 0; y < borderDown; y++) {
        for (int x = 0; x < borderRight; x++) {
            if (x == bollX && y == bollY) {
                printf("*");
            } else if (y == borderUp || y == borderDown - 1) {
                printf("-");
            } else if (x == borderLeft || x == borderRight - 1) {
                printf("|");
            } else if ((y == yroketka1 || y == yroketka1 - 1||
            y == yroketka1 - 2) && (x == borderLeft + 1)) {
                printf("|");
            } else if ((y == yroketka2 || y == yroketka2 - 1 ||
            y == yroketka2 - 2) &&
                       (x == borderRight - 2)) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    score();
    printf("\nPlayer 1: %d\nPlayer 2: %d\n", scoreA, scoreB);
}
void moveball() {
    if ((bollY == borderDown - 1 && yroketka2 + 1 == borderDown - 1 &&
        bollX == borderRight - 3)||  // проверка в углах
    (bollY == borderUp && yroketka2 - 2 == borderUp + 1
    && bollX == borderRight - 3) ||
    (bollY == borderDown - 1 && yroketka1 + 1 == borderDown - 1 &&
    bollX == borderLeft + 2) ||
    (bollY == borderUp && yroketka1 - 2 == borderUp + 1 &&
    bollX == borderLeft + 2)) {
        vectorX = -vectorX;
        vectorY = -vectorY;
    } else if (bollY == borderUp || bollY == borderDown - 1) {
        vectorY = -vectorY;
    } else if (((bollY == yroketka2 || bollY == yroketka2 - 1 ||
    bollY == yroketka2 - 2) && bollX == borderRight - 3) ||
    ((bollY == yroketka1 || bollY == yroketka1 -1 || bollY == yroketka1 - 2)
    && bollX == borderLeft + 2)) {
         vectorX = -vectorX;
    }
    bollX += vectorX;
    bollY += vectorY;
}
void score() {
    if (bollX == borderLeft) {
        scoreB++;
        yroketka1 = 13;
        yroketka2 = 13;
        bollX = 39;
        bollY = 13;
        vectorX = -1;
        vectorY = 1;
    }
    if (bollX == borderRight - 1) {
        scoreA++;
        yroketka1 = 13;
        yroketka2 = 13;
        bollX = 39;
        bollY = 13;
        vectorX = 1;
        vectorY = 1;
    }
}

void moveRocket() {
    if ((c1 == 'z' || c1 == 'Z') && yroketka1 < borderDown - 2) yroketka1++;
    else if ((c1 == 'a' || c1 == 'A') && yroketka1 > borderUp + 3) yroketka1--;
    else if ((c1 == 'm' || c1 == 'M') && yroketka2 < borderDown - 2)yroketka2++;
    else if ((c1 == 'k' || c1 == 'K') && yroketka2 > borderUp + 3) yroketka2--;
}
