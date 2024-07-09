#include <stdio.h>

int main() {
    char com[100];
    int i = 2, a = 0;

    printf("Enter comment: ");
    scanf(" %[^\n]s", com);

    if (com[0] == '/') {
        if (com[1] == '/') {
            printf("It is a comment\n");
        } else if (com[1] == '*') {
            for (i = 2; com[i] != '\0'; i++) {
                if (com[i] == '*' && com[i + 1] == '/') {
                    printf("It is a comment\n");
                    a = 1;
                    break;
                }
            }
            if (a == 0) {
                printf("It is not a comment\n");
            }
        } else {
            printf("It is not a comment\n");
        }
    } else {
        printf("It is not a comment\n");
    }

    return 0;
}
