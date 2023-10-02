#include <stdio.h>

#define WIDTH_SCRING 82
#define HEIGHT_SCRING 27
#define ROCKET1_DEFAULT_X 2
#define ROCKET2_DEFAULT_X 79
#define BALL_START_X (WIDTH_SCRING / 2)
#define BALL_START_Y (HEIGHT_SCRING / 2)
int main() {
    int ball_y = BALL_START_Y;
    int ball_x = BALL_START_X;
    int rocket_1_X = ROCKET1_DEFAULT_X;
    int rocket_2_X = ROCKET2_DEFAULT_X;
    int rocket_1 = 12;
    int rocket_2 = 12;
    int vector_x = -1;
    int vector_y = 1;
    int win = 21;
    int player1 = 0;
    int player2 = 0;
    char input;

    while (1) {
        printf("Player one: %d \nPlayer two: %d \n---Press \'Control + C\' to exit\n", player1, player2);
        for (int y = 0; y < HEIGHT_SCRING; ++y) {
            for (int x = 0; x < WIDTH_SCRING; ++x) {
                if ((x == ROCKET1_DEFAULT_X && (y == rocket_1 - 1 || y == rocket_1 || y == rocket_1 + 1)) ||
                    (x == ROCKET2_DEFAULT_X && (y == rocket_2 - 1 || y == rocket_2 || y == rocket_2 + 1))) {
                    printf("|");
                } else if (x == ball_x && y == ball_y) {
                    printf("o");
                } else if ((y == 0 && x != 0 && x != WIDTH_SCRING - 1) ||
                           (y == HEIGHT_SCRING - 1 && x != 0 && x != WIDTH_SCRING - 1)) {
                    printf("-");
                } else if ((x == 0 && y != 0 && y != HEIGHT_SCRING - 1) ||
                           (x == WIDTH_SCRING - 1 && y != 0 && y != HEIGHT_SCRING - 1)) {
                    printf("|");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        if (ball_y == 1 || ball_y == HEIGHT_SCRING - 2) {
            vector_y = -vector_y;
        }
        if (ball_x == rocket_1_X + 1 &&
            (ball_y == rocket_1 - 1 || ball_y == rocket_1 || ball_y == rocket_1 + 1)) {
            vector_x = -vector_x;
        }
        if (ball_x == rocket_2_X - 1 &&
            (ball_y == rocket_2 - 1 || ball_y == rocket_2 || ball_y == rocket_2 + 1)) {
            vector_x = -vector_x;
        }
        ball_y += vector_y;
        ball_x += vector_x;

        if (ball_x < 2) {
            player2 += 1;
            ball_x = BALL_START_X;
            ball_y = BALL_START_Y;
        }
        if (ball_x > WIDTH_SCRING - 1) {
            player1 += 1;
            ball_x = BALL_START_X;
            ball_y = BALL_START_Y;
        }
        if (player1 == win) {
            printf("######### Win player number I #########\n");
            break;
        } else if (player2 == win) {
            printf("$$$$$$$$$$ Win player number II $$$$$$$$$$\n");
            break;
        }

        scanf("%c", &input);
        if ((input == 'a' || input == 'A') && (rocket_1 - 2 != 0)) {
            rocket_1--;
        } else if ((input == 'z' || input == 'Z') && (rocket_1 + 2 != HEIGHT_SCRING - 1)) {
            rocket_1++;
        } else if ((input == 'k' || input == 'K') && (rocket_2 - 2 != 0)) {
            rocket_2--;
        } else if ((input == 'm' || input == 'M') && (rocket_2 + 2 != HEIGHT_SCRING - 1)) {
            rocket_2++;
        } 
        printf("\33[0d\33[2J");
    }
    return 0;
}