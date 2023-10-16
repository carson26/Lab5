#include <stdio.h>
#include <stdbool.h>

void possibleCombos(int totalScore) {
    int count = 0;
    int scoreCombos[10000][5];
    int score;
    bool noneFound = false;
    while (noneFound == false) {
        for (int i = totalScore / 8; i >= 0; i--) {
            score = 0;
            if (totalScore % 8 > 0) {
                scoreCombos[count][0] = i;
                score += i * 8;
                for (int j = totalScore / 7; i >= 0; j--) {
                    if ((totalScore - score) % 7 > 0) {
                        scoreCombos[count][1] = j;
                        score += j * 7;
                        for (int k = totalScore / 6; k >= 0; k--) {
                            if ((totalScore - score) % 6 > 0) {
                                scoreCombos[count][2] = k;
                                score += k * 6;
                                for (int l = totalScore / 3; l >= 0; l--) {
                                    if ((totalScore - score) % 3 > 0) {
                                        scoreCombos[count][3] = l;
                                        score += l * 3;
                                        for (int p = totalScore / 2; p >= 0; p--) {
                                            if ((totalScore - score) % 2 > 0) {
                                                scoreCombos[count][4] = p;
                                                score += p * 2;
                                            }
                                            count += 1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if ((scoreCombos[count-1][0] == 0) && (scoreCombos[count-1][1] == 0) && (scoreCombos[count-1][2] == 0) && (scoreCombos[count-1][3] == 0) && (scoreCombos[count-1][4] == 0)) {
            noneFound == true;
        }
    }

    for (int i = 0; i <= count; i++) {
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", scoreCombos[i][0], scoreCombos[i][1], scoreCombos[i][2], scoreCombos[i][3], scoreCombos[i][4]);
    }
}

int main() {
    int userNum = 10;
    while (userNum > 1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &userNum);
        if (userNum > 1) {
            possibleCombos(userNum);
        }
    }
    return 0;
}
main();