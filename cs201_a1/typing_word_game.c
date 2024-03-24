/*

    Reid Luttrell - CS 201
    Assignment 1
    due: 4/14/2020

*/

#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include <string.h>

/* in C there is no standard generic swap algorithm, so i made this specific one */
void swap(char** arr, int to, int from) {
    char* tmp;

    tmp = arr[to];
    arr[to] = arr[from];
    arr[from] = tmp;
}

void shuffle_words(char** words, int idx) {
    int new_index;

    if (!idx)
        return;

    new_index = rand() % idx;

    swap(words, new_index, idx);

    shuffle_words(words, --idx);
}

/* recursively display word and check validity of input */
void handle_word(char** words, int len, int idx) {
    char attempt[10];
    
    if (idx >= len)
        return;

    printf("word #%d is %s: ", idx + 1, words[idx]);
    scanf("%10s", attempt);
    
    while(getchar() != '\n');

    if (strcmp(words[idx], attempt) != 0) {
        printf("Incorrect. Try again.\n");
        handle_word(words, len, idx); /* don't update index to display again */
        return;
    }

    handle_word(words, len, ++idx);
}

int main() {
    int i, j, len;
    struct timeval seed, time_0, time_1, net;

    /* the only way to do this with no malloc I believe */
    char* words[10] = {
        "The",
        "quick",
        "brown",
        "fox",
        "jumps",
        "over",
        "the",
        "lazy",
        "dog",
    };

    printf("This is a game that tests typing speed.\n");
    printf("Type the following words\n");

    len = 9;

    gettimeofday(&seed, NULL);    
    srand(seed.tv_usec);

    i = len - 1;
    shuffle_words(words, i);

    gettimeofday(&time_0, NULL);

    j = 0;
    handle_word(words, len, j);

    gettimeofday(&time_1, NULL);

    timersub(&time_1, &time_0, &net);

    printf("Correct! Your time is: %3d seconds %6d useconds.\n",
           (int)net.tv_sec, (int)net.tv_usec);

    return 0;
}
