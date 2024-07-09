#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n;
char productionSet[10][10];
char subResult[20];
char result[20];

void follow(char *result, char c);
void first(char *result, char c);
void addToResultSet(char result[], char val);

int main() {
    int i;
    char choice;
    char c;
    
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    
    printf("Enter %d productions\nProductions with multiple terms should be given as separate productions\n", n);
    for (i = 0; i < n; i++) {
        scanf("%s", productionSet[i]);
    }
    
    do {
        printf("Find FOLLOW of: ");
        scanf(" %c", &c);
        follow(result, c);
        
        printf("FOLLOW(%c) = { ", c);
        for (i = 0; result[i] != '\0'; i++) {
            printf("%c ", result[i]);
        }
        printf("}\n");
        
        printf("Press 'y' to continue: ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}

void follow(char *result, char c) {
    int i, j, k;
    subResult[0] = '\0';
    result[0] = '\0';
    
    if (productionSet[0][0] == c) {
        addToResultSet(result, '$');
    }
    
    for (i = 0; i < n; i++) {
        for (j = 2; j < strlen(productionSet[i]); j++) {
            if (productionSet[i][j] == c) {
                if (productionSet[i][j + 1] != '\0') {
                    first(subResult, productionSet[i][j + 1]);
                }
                if (productionSet[i][j + 1] == '\0' && c != productionSet[i][0]) {
                    follow(subResult, productionSet[i][0]);
                }
                for (k = 0; subResult[k] != '\0'; k++) {
                    addToResultSet(result, subResult[k]);
                }
            }
        }
    }
}

void first(char *result, char c) {
    int i;
    if (!(isupper(c))) {
        addToResultSet(result, c);
        return;
    }
    
    for (i = 0; i < n; i++) {
        if (productionSet[i][0] == c) {
            if (productionSet[i][2] == '#') {
                follow(result, productionSet[i][0]);
            } else if (!isupper(productionSet[i][2])) {
                addToResultSet(result, productionSet[i][2]);
            } else {
                first(result, productionSet[i][2]);
            }
        }
    }
}

void addToResultSet(char result[], char val) {
    int k;
    for (k = 0; result[k] != '\0'; k++) {
        if (result[k] == val) {
            return;
        }
    }
    result[k] = val;
    result[k + 1] = '\0';
}
