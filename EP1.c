#include <stdio.h>

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
        printf("Test word: %s\n", testWords[j]);
    }

    //printf("Hello, World!\n");
    return 0;
}
