#include <stdbool.h>
#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

typedef struct States State;

struct States {
    char name[10+1];
    // State *transictionA;
    // struct States *transictionB;
    State *transictions[2];
    bool finalState;
} state;

void mountAutomaton(State *automaton, char *word, int wordSize){
    int i;
    State *automatonEnd = &automaton[0];

    for(i = 0; i < wordSize+1; i++){
        automaton = &automaton[i];
//        automaton->name.
        if(i == 0){
            strncpy(automaton->name, "eps\0", 4);
        }
        else{
            strncpy(automaton->name, word,i);
            strcpy(&automaton->name[i], "\0");
//            strncpy(automaton->name, strcat(word, "\0"),(i+1));
//            strncat(automaton->name, word,i);
        }

//        if(*word[i] == 'a'){
//            newState.transictions[1] = &newState;
//        }
    }

    int j;
    automaton = automatonEnd;
    for (j = 0; j < wordSize+1; j++) {
        automaton = &automaton[j];
        printf("State name: %s\n", automaton->name);
    }
}

int main() {
    char word[10+1];
//     char quantWords[4+1];
    int kQuantWords = 0;
    State automaton[10+1];

    //TODO: jogar a entrada no buffer com tamanho antes da variavel;

//     fgets(word, sizeof(word)-1, stdin);


//     fgets(quantWords, sizeof(quantWords)-1, stdin);
//     kQuantWords = atoi(quantWords);

    // scanf(fgets(word, 10, stdin), word);
    scanf("%s \n %d", word, &kQuantWords);

//    char testWords[kQuantWords][200+1];
//
//    int i;
//    for (i = 0; i < kQuantWords; ++i) {
//        scanf("%s", testWords[i]);
//    }
//
    printf("Word: %s\nNum: %d\n", word, kQuantWords);

//    int j;
//    for (j = 0; j < kQuantWords; ++j) {
//        printf("Test word %d: %s\n", j, testWords[j]);
//    }

    mountAutomaton(automaton, word, strlen(word));

    // printf("Hello, World!\n");
    return 0;
}
