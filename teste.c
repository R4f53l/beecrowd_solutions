#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char p[40], c1, c2;

    while (scanf("%s%c", p, &c2)) {
        char i = tolower(p[0]);
        int valid = 1;

        if(p[0] == '*')break;
        if(c2!='\n')
            while (scanf("%s%c", p, &c1)) {
                if (tolower(p[0]) != i) {
                    valid = 0;
                }
                if(c1 == '\n')break;
            }

        if (valid) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
    }

    return 0;
}