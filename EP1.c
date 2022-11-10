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

int numberOfEquivalents(char *nextWord, char *stateNameWord){
//    nextWord = "ababa\0";
//    stateNameWord = "abab\0";

    char tempActualWord[sizeof(nextWord)];
    char tempStateNameWord[sizeof (stateNameWord)];

    int k, count = 0, leftSentry = strlen(nextWord) - 1;

    strcpy(&tempActualWord[0], &nextWord[leftSentry]);
    strcpy(&tempActualWord[1], "\0");

    strcpy(&tempStateNameWord[0], &stateNameWord[0]);
    strcpy(&tempStateNameWord[1], "\0");

    for(k = 0; k < strlen(stateNameWord); k++){
        if(strcmp(tempActualWord, tempStateNameWord) == 0){
            count = strlen(tempStateNameWord);
        }

        strncpy(tempStateNameWord, stateNameWord, k + 2);
        strcpy(&tempStateNameWord[k + 2], "\0");

        strncpy(tempActualWord, nextWord + (leftSentry - (k + 1)), (k + 2));
        strcpy(&tempActualWord[k + 2], "\0");
    }

    return count;
}

void mountAutomaton(State *automaton, char *word, int wordSize){
    int i;
    State *firstState = &automaton[0];
    char wordNextTransition[sizeof(word)];

    automaton = firstState;
    for(i = 0; i < wordSize+1; i++){
//        automaton->name.
        if(i == 0){
            strncpy(automaton->name, "eps\0", 4);
            automaton->transictions[0] = word[i] == 'a' ? &automaton[i+1] : &automaton[i];
            automaton->transictions[1] = word[i] == 'b' ? &automaton[i+1] : &automaton[i];
            automaton->finalState = false;
        }else
        if(i == wordSize){
            strncpy(automaton->name, word,i);
            strcpy(&automaton->name[i], "\0");

            automaton->transictions[0] = automaton;
            automaton->transictions[1] = automaton;

            automaton->finalState = true;
        }
        else{
            strncpy(automaton->name, word,i);
            strcpy(&automaton->name[i], "\0");

            strncpy(wordNextTransition, word, i);
            if(word[i] == 'a'){
                strcpy(&wordNextTransition[i], "b\0");
            }else{
                strcpy(&wordNextTransition[i], "a\0");
            }

//            strncpy(wordNextTransition, word, i);
//            strcpy(&wordNextTransition[i+1], "\0");
//
//            sprintf(wordNextTransition,"%s%c%c", wordNextTransition, 'a', "\0");
//
//            wordNextTransition =

            automaton->transictions[0] = word[i] == 'a' ? &automaton[i+1] : &firstState[numberOfEquivalents(wordNextTransition, automaton->name)];
            automaton->transictions[1] = word[i] == 'b' ? &automaton[i+1] : &firstState[numberOfEquivalents(wordNextTransition, automaton->name)];

            automaton->finalState = i == wordSize ? true : false;
//            strncpy(automaton->name, strcat(word, "\0"),(i+1));
//            strncat(automaton->name, word,i);
//            sprintf()
        }
//        if(*word[i] == 'a'){
//            newState.transictions[1] = &newState;
//        }
        automaton = word[i] == 'a' ? automaton->transictions[0] : automaton->transictions[1];
    }

//    int j;
//    automaton = &firstState;
//    for (j = 0; j < wordSize+1; j++) {
//        automaton = &automaton[j];
//        printf("State name: %s, A: %s, B: %s, FINAL: %d\n",
//           automaton->name,
//           automaton->transictions[0]->name,
//           automaton->transictions[1]->name,
//           automaton->finalState
//       );
//    }
}

int main() {
    char word[10+1];
//     char quantWords[4+1];
    int kQuantWords = 0;
    State automaton[(10+1)];

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

//    printf("Diff: %d", numberOfEquivalents(word, word));
    // printf("Hello, World!\n");
    return 0;
}
