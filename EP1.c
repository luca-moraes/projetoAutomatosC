#include <stdbool.h>
#include <stdio.h>
// #include <stdlib.h>

typedef struct States State;

struct States {
    char name[10];
    // State *transictionA;
    // struct States *transictionB;
    State *transictions[2];
    bool finalState;
} state;

void mountAutomaton(State *automaton[10], char *word[10], int wordSize){
    int i;
    for(i = 0; i < wordSize; i++){
        State newState;

        *newState.name = *word[0];
        *automaton[i] = newState;
    }
}

int main() {
    char word[10
            // +1
    ];
    // char quantWords[4+1];
    int kQuantWords = 0;
    State automaton[10];

    //TODO: jogar a entrada no buffer com tamanho antes da variavel;
    // fgets(word, sizeof(word)-1, stdin);
    // fgets(quantWords, sizeof(quantWords)-1, stdin);
    // kQuantWords = atoi(quantWords);

    // scanf(fgets(word, 10, stdin), word);
    scanf("%s \n %d", word, &kQuantWords);

    char testWords[kQuantWords][200+1];

    int i;
    for (i = 0; i < kQuantWords; ++i) {
        scanf("%s", testWords[i]);
    }

    printf("Word: %s\nNum: %d\n", word, kQuantWords);

    int j;
    for (j = 0; j < kQuantWords; ++j) {
        printf("Test word %d: %s\n", j, testWords[j]);
    }

    // printf("Hello, World!\n");
    return 0;
}
