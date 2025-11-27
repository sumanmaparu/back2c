#include<stdio.h>

char buf[1000] = {0};
int choice;
int nwords = 0;
int inword = 0;
int maxlen = 0;
int list_of_wordlen[1000] = {0};

void find_max_word_len() {
    for(int i = 0; i < nwords; i++) {
        if(list_of_wordlen[i] > maxlen) {
            maxlen = list_of_wordlen[i];
        }
    }
    printf("Number of words with maximum length: %d\n", maxlen);
}

void count_words(char *buf) {
    int i=0;
    int wordlen = 0;
    printf("\n Entered line is: %s", buf);
    while (buf[i] != '\0' && buf[i] != '\n') {
        if ((buf[i] != ' ' && buf[i] != '\t')) {
            wordlen++;
            inword = 1;
        } else if(inword == 1) {
            inword = 0;
            list_of_wordlen[nwords] = wordlen;
            // if (list_of_wordlen[nwords] > maxlen) {
            //     maxlen = list_of_wordlen[nwords];
            // }
            find_max_word_len();
            wordlen = 0;
            nwords++;
        }
        i++;
    }
    if(inword == 1) {
        list_of_wordlen[nwords] = wordlen;
        // if (list_of_wordlen[nwords] > maxlen) {
        //     maxlen = list_of_wordlen[nwords];
        // }
        find_max_word_len();
        nwords++;
    }
}

void print_horizontal_histogram() {
    printf("\nHorizontal Histogram:\n");
    for(int i = 0; i < nwords; i++) {
        for(int j = 0 ; j < list_of_wordlen[i]; j++) {
            printf("*  ");
        }
        printf("\n");
    }
}

void print_vertical_histogram() {
    printf("\nVertical Histogram:\n");
    printf("\nMax word length: %d\n", maxlen);
    for(int i = 0; i < maxlen; i++) {
        for (int j = 0; j < nwords; j++) {
            if (list_of_wordlen[j] >= maxlen - i) {
                printf("*  ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }
}

void print_both_histograms() {
    print_horizontal_histogram();
    print_vertical_histogram();
}

int main() {
    printf("Read line: ");
    if(fgets(buf, sizeof buf, stdin) != NULL) {
        printf("\nYou entered: %s", buf);
    }

    do {
        printf("\nEnter your choice for histogram (1-3): ");
        printf("\n----------------------------------------");
        printf("\n1. Horizontal Histogram");
        printf("\n2. Vertical Histogram");
        printf("\n3. Both Horizontal & Vertical Histogram\n");
        scanf("%d", &choice);
    
        switch (choice) {
            case 1:
                printf("\nYou chose option %d: Horizontal Histogram\n", choice);
                count_words(buf);
                printf("Total words: %d\n", nwords);
                printf("Max word length: %d\n", maxlen);
                print_horizontal_histogram();
                break;
            case 2:
                printf("\nYou chose option %d: Vertical Histogram\n", choice);
                count_words(buf);
                printf("Total words: %d\n", nwords);
                printf("Max word length: %d\n", maxlen);
                print_vertical_histogram();
                break;
            case 3:
                printf("\nYou chose option %d: Both Horizontal & Vertical Histogram\n", choice);
                count_words(buf);
                printf("Total words: %d\n", nwords);
                printf("Max word length: %d\n", maxlen);
                print_both_histograms();
                break;
            default:
                printf("\nInvalid choice -> %d. Please select 1 - 3.\n", choice);
                break;
        }
    } while (choice < 1 || choice > 3);

    return 0;
}