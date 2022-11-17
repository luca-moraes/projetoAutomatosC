#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct States State;

struct States {
    char name[10+1];
    State *transictions[2];
    bool finalState;
};

int numberOfEquivalents(char *nextWord, char *stateNameWord){
    char tempActualWord[strlen(nextWord)];
    char tempStateNameWord[strlen(stateNameWord)];

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
    char wordWrongTransition[strlen(word)];

    automaton = firstState;
    for(i = 0; i < wordSize+1; i++){
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

            strncpy(wordWrongTransition, word, i);
            if(word[i] == 'a'){
                strcpy(&wordWrongTransition[i], "b\0");
            }else{
                strcpy(&wordWrongTransition[i], "a\0");
            }

            automaton->transictions[0] = word[i] == 'a' ? &firstState[i+1] : &firstState[numberOfEquivalents(wordWrongTransition, automaton->name)];
            automaton->transictions[1] = word[i] == 'b' ? &firstState[i+1] : &firstState[numberOfEquivalents(wordWrongTransition, automaton->name)];

            automaton->finalState = i == wordSize ? true : false;
        }

        automaton = word[i] == 'a' ? automaton->transictions[0] : automaton->transictions[1];
    }
}

void printAutomaton(State *automaton, char *word, int wordSize){
    int j;
    State *firstState = &automaton[0];
    automaton = firstState;

    for (j = 0; j < wordSize + 1; j++) {
        printf("%s %s %s\n",
               automaton->name,
               automaton->transictions[0]->name,
               automaton->transictions[1]->name
        );
        automaton = word[j] == 'a' ? automaton->transictions[0] : automaton->transictions[1];
    }
}

bool checkWordValidity(State *automaton, char *testWord, int testWordSize){
    int k;
    State *firstState = &automaton[0];
    automaton = firstState;

    for(k = 0; k < testWordSize; k++){
        automaton = testWord[k] == 'a' ? automaton->transictions[0] : automaton->transictions[1];
    }

    return automaton->finalState;
}

int main() {
    char word[10+1];
    int kQuantWords = 0;
    State automaton[(10+1)];

    scanf("%s \n %d", word, &kQuantWords);

    char testWords[kQuantWords][200+1];
    int i;

    for (i = 0; i < kQuantWords; ++i) {
        scanf("%s", testWords[i]);
    }

    mountAutomaton(automaton, word, strlen(word));
    printAutomaton(automaton, word, strlen(word));
    for(i = 0; i < kQuantWords; i++) {
        checkWordValidity(automaton, testWords[i], strlen(testWords[i])) ? printf("1\n") : printf("0\n");
    }
    return 0;
}
