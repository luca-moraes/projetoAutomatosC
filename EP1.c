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

int numberOfEquivalents(){
    char w1[6] = "ababa\0";
    char w2[6] = "abab\0";

    char tempW1[6];
    char tempW2[6];

    int k, count = 0, leftSentry = strlen(w1)-1;

    strcpy(&tempW1[0], &w1[leftSentry]);
    strcpy(&tempW1[1], "\0");

    strcpy(&tempW2[0], &w2[0]);
    strcpy(&tempW2[1], "\0");

    for(k = 0; k < strlen(w2); k++){
        if(strcmp(tempW1, tempW2) == 0){
            count = strlen(tempW2);
        }

        strncpy(tempW2, w2, k+2);
        strcpy(&tempW2[k+2], "\0");

        strncpy(tempW1, w1+(leftSentry-(k+1)), (k+2));
        strcpy(&tempW1[k+2], "\0");
    }

    return count;
}

void mountAutomaton(State *automaton, char *word, int wordSize){
    int i;
    State *firstState = &automaton[0];

    for(i = 0; i < wordSize+1; i++){
        automaton = &automaton[i];
//        automaton->name.
        if(i == 0){
            strncpy(automaton->name, "eps\0", 4);
            automaton->transictions[0] = word[i] == 'a' ? &automaton[i+1] : &automaton[i];
            automaton->transictions[1] = word[i] == 'b' ? &automaton[i+1] : &automaton[i];
            automaton->finalState = false;
        }
        else{
            strncpy(automaton->name, word,i);
            strcpy(&automaton->name[i], "\0");

            automaton->transictions[0] = word[i] == 'a' ? &automaton[i+1] : firstState;
            automaton->transictions[1] = word[i] == 'b' ? &automaton[i+1] : firstState;

            automaton->finalState = i == wordSize ? true : false;
//            strncpy(automaton->name, strcat(word, "\0"),(i+1));
//            strncat(automaton->name, word,i);
        }
//        if(*word[i] == 'a'){
//            newState.transictions[1] = &newState;
//        }
    }

    int j;
    automaton = firstState;
    for (j = 0; j < wordSize+1; j++) {
        automaton = &automaton[j];
        printf("State name: %s, A: %s, B: %s, FINAL: %d\n",
           automaton->name,
           automaton->transictions[0]->name,
           automaton->transictions[1]->name,
           automaton->finalState
       );
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

    printf("Diff: %d", numberOfEquivalents());
    // printf("Hello, World!\n");
    return 0;
}
