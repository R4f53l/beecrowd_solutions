#include <stdio.h>
int main () {
    char s[101], s2[101], s3[101];
    scanf("%[^\n]", s);
    getchar();
    scanf("%[^\n]", s2);
    getchar();
    scanf("%[^\n]", s3);
    getchar();
    printf("%s%s%s\n", s, s2, s3);
    printf("%s%s%s\n", s2, s3, s);
    printf("%s%s%s\n", s3, s, s2);
    printf("%.10s%.10s%.10s\n", s, s2, s3);





    return 0;
}