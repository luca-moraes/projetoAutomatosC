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

        char stateName[i+1];

        if(i == 0){
            *stateName = 'e';
        }
        else{
            *stateName = *word[i];
        }

        *newState.name = stateName;

//        if(*word[i] == 'a'){
//            newState.transictions[1] = &newState;
//        }

        automaton[i] = &newState;
    }

    int j;
    for (j; j < wordSize; j++) {
        printf("State name: %s\n", *automaton[j]->name);
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

//    char testWords[kQuantWords][200+1];
//
//    int i;
//    for (i = 0; i < kQuantWords; ++i) {
//        scanf("%s", testWords[i]);
//    }
//
//    printf("Word: %s\nNum: %d\n", word, kQuantWords);

//    int j;
//    for (j = 0; j < kQuantWords; ++j) {
//        printf("Test word %d: %s\n", j, testWords[j]);
//    }

    mountAutomaton(automaton, word, 4);

    // printf("Hello, World!\n");
    return 0;
}
