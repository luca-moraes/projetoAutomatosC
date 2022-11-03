#include <stdio.h>
#include <stdbool.h>

typedef struct States State;

struct States{
    char name[10];
    State *transictionA;
    struct States *transictionB;
    bool finalState;
} state;

int main() {
    char word[10];
    int kQuantWords = 0;

    scanf("%s \n %d", word, &kQuantWords);

    char testWords[kQuantWords][200];

    int i;
    for (i = 0; i < kQuantWords; ++i) {
        scanf("%s", testWords[i]);
    }

    printf("Word: %s\nNum: %d\n", word, kQuantWords);

    int j;
    for (j = 0; j < kQuantWords; ++j) {
        printf("Test word %d: %s\n", j, testWords[j]);
    }

    //printf("Hello, World!\n");
    return 0;
}
