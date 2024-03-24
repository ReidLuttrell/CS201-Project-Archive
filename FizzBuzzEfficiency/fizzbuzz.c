#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

// the normal fizzbuzz algorithm utilizing if statements

void FizzBuzzNormal(int itr) {
    int i;
    for (i = 1; i <= itr; ++i) {
        if (i % 15 == 0) { // divisible by 3 and 5
            printf("FizzBuzz\n");
        } else if (i % 3 == 0) { // divisible by 3
            printf("Fizz ");
        } else if (i % 5 == 0) { // divisible by 5
            printf("Buzz ");
        } else {
            printf("%d ", i); // none
        }
    }
}

// the fizzbuzz algorithm utilizing switch statements

void FizzBuzzSwitch(int itr) {
    int i;
    for (i = 1; i <= itr; ++i) {
        switch (i % 15) {
            default:
                printf("%d ", i); // this is most likely so it goes first
                break;
            case 3: // multiple of 3 remaining
            case 6:
            case 9:
            case 12:
                printf("Fizz ");
                break;
            case 5: // multiple of 5 remaining
            case 10:
                printf("Buzz ");
                break;
            case 0: // divisible by 15
                printf("FizzBuzz\n");
                break;
        }
    }
}

// this is taking advantage of the fact that there will always be a predictable pattern in the fizz and buzzes
// this is hypothetically a lot faster than anything else I've done, however, since we don't have knowledge of what
// the number of iterations will be, we must manually check whether or not we will go too far for numbers that aren't
// divisible by 15 for every output we do. This sort of defeats the purpose but is an interesting option nonetheless.

void FizzBuzzUnrolled(int itr) {
    int i;
    for (i = 0; i < itr; i += 15) {
        printf("%d ", i + 1);
        if (i + 1 == itr) break;
        printf("%d ", i + 2);
        if (i + 2 == itr) break;
        printf("Fizz ");
        if (i + 3 == itr) break;
        printf("%d ", i + 4);
        if (i + 4 == itr) break;
        printf("Buzz ");
        if (i + 5 == itr) break;
        printf("Fizz ");
        if (i + 6 == itr) break;
        printf("%d ", i + 7);
        if (i + 7 == itr) break;
        printf("%d ", i + 8);
        if (i + 8 == itr) break;
        printf("Fizz "); 
        if (i + 9 == itr) break;
        printf("Buzz ");
        if (i + 10 == itr) break;
        printf("%d ", i + 11);
        if (i + 11 == itr) break;
        printf("Fizz ");
        if (i + 12 == itr) break;
        printf("%d ", i + 13); 
        if (i + 13 == itr) break;
        printf("%d ", i + 14); 
        if (i + 14 == itr) break;
        printf("FizzBuzz\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
       printf("\n\nNot enough arguments.\n");
       printf("Algorithm options: (1) Normal Fizz Buzz, (2) Switch Fizz Buzz, (3) Unrolled Fizz Buzz\n");
       printf("Usage: ./a.out number_iterations algorithm_number\n");
       return 1;
    }
    struct timeval tf, ti, net;

    gettimeofday(&ti, NULL);

    int itr;
    itr = atoi(argv[1]);
    int option;
    option = atoi(argv[2]);
    
    if (option == 1)
        FizzBuzzNormal(itr);
    else if (option == 2)
        FizzBuzzSwitch(itr);
    else if (option == 3)
        FizzBuzzUnrolled(itr);
    else {
        printf("Algorithm number not recognized, exiting.\n");
        return 1;
    }

    gettimeofday(&tf, NULL);

    timersub(&tf, &ti, &net);

    printf("\n\nExecution time: %lu\n us", (long unsigned)net.tv_usec);
    return 0;
}
