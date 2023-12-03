#include <stdio.h>
#include <stdbool.h>

// Function for FIFO page replacement
void fifo(int frames, int pages, int incomingStream[]) {
    int frame[frames];
    int i, j;
    int pageFaults = 0;
    int hits = 0;
    int misses = 0;

    for (i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    printf("Incoming \t");

    for (i = 1; i <= frames; i++) {
        printf("Frame %d \t", i);
    }

    for (i = 0; i < pages; i++) {
        bool isPageFault = true;

        for (j = 0; j < frames; j++) {
            if (frame[j] == incomingStream[i]) {
                isPageFault = false;
                hits++;
                break;
            }
        }

        if (isPageFault) {
            frame[pageFaults % frames] = incomingStream[i];
            pageFaults++;
            misses++;
        }

        printf("\n%d\t\t\t", incomingStream[i]);

        for (j = 0; j < frames; j++) {
            if (frame[j] != -1) {
                printf(" %d\t\t\t", frame[j]);
            } else {
                printf(" - \t\t\t");
            }
        }
    }

    double pageHitRatio = (double)hits / pages;

    printf("\nTotal Page Hits (FIFO):\t%d\n", hits);
    printf("Total Page Misses (FIFO):\t%d\n", misses);
    printf("Page Hit Ratio (FIFO):\t%.2f\n", pageHitRatio);
}

// Function for LRU page replacement
void lru(int frames, int pages, int incomingStream[]) {
    int frame[frames];
    int counter[frames];
    int i, j, k;
    int pageFaults = 0;
    int hits = 0;
    int misses = 0;

    for (i = 0; i < frames; i++) {
        frame[i] = -1;
        counter[i] = 0;
    }

    printf("Incoming \t");

    for (i = 1; i <= frames; i++) {
        printf("Frame %d \t", i);
    }

    for (i = 0; i < pages; i++) {
        bool isPageFault = true;

        for (j = 0; j < frames; j++) {
            if (frame[j] == incomingStream[i]) {
                counter[j] = i;
                hits++;
                isPageFault = false;
            }
        }

        if (isPageFault) {
            int min = counter[0];
            int replaceIndex = 0;

            for (k = 1; k < frames; k++) {
                if (counter[k] < min) {
                    min = counter[k];
                    replaceIndex = k;
                }
            }

            frame[replaceIndex] = incomingStream[i];
            counter[replaceIndex] = i;
            pageFaults++;
            misses++;
        }

        printf("\n%d\t\t\t", incomingStream[i]);

        for (j = 0; j < frames; j++) {
            if (frame[j] != -1) {
                printf(" %d\t\t\t", frame[j]);
            } else {
                printf(" - \t\t\t");
            }
        }
    }

    double pageHitRatio = (double)hits / pages;

    printf("\nTotal Page Hits (LRU):\t%d\n", hits);
    printf("Total Page Misses (LRU):\t%d\n", misses);
    printf("Page Hit Ratio (LRU):\t%.2f\n", pageHitRatio);
}

// Function for Optimal page replacement
void optimal(int frames, int pages, int incomingStream[]) {
    int frame[frames];
    int i, j, k;
    int pageFaults = 0;
    int hits = 0;
    int misses = 0;

    for (i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    printf("Incoming \t");

    for (i = 1; i <= frames; i++) {
        printf("Frame %d \t", i);
    }

    for (i = 0; i < pages; i++) {
        bool isPageFault = true;

        for (j = 0; j < frames; j++) {
            if (frame[j] == incomingStream[i]) {
                isPageFault = false;
                hits++;
                break;
            }
        }

        if (isPageFault) {
            int pageToReplace = -1;
            int farthestUse = -1;

            for (j = 0; j < frames; j++) {
                int nextPageUse = 0;

                for (k = i + 1; k < pages; k++) {
                    if (incomingStream[k] == frame[j]) {
                        nextPageUse = k;
                        break;
                    }
                }

                if (nextPageUse == 0) {
                    pageToReplace = j;
                    break;
                }

                if (nextPageUse > farthestUse) {
                    farthestUse = nextPageUse;
                    pageToReplace = j;
                }
            }

            frame[pageToReplace] = incomingStream[i];
            pageFaults++;
            misses++;
        }

        printf("\n%d\t\t\t", incomingStream[i]);

        for (j = 0; j < frames; j++) {
            if (frame[j] != -1) {
                printf(" %d\t\t\t", frame[j]);
            } else {
                printf(" - \t\t\t");
            }
        }
    }

    double pageHitRatio = (double)hits / pages;

    printf("\nTotal Page Hits (Optimal):\t%d\n", hits);
    printf("Total Page Misses (Optimal):\t%d\n", misses);
    printf("Page Hit Ratio (Optimal):\t%.2f\n", pageHitRatio);
}

// Function for MRU page replacement
void mru(int frames, int pages, int incomingStream[]) {
    int frame[frames];
    int i, j;
    int pageFaults = 0;
    int hits = 0;
    int misses = 0;

    for (i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    printf("Incoming \t");

    for (i = 1; i <= frames; i++) {
        printf("Frame %d \t", i);
    }

    for (i = 0; i < pages; i++) {
        bool isPageFault = true;

        for (j = 0; j < frames; j++) {
            if (frame[j] == incomingStream[i]) {
                isPageFault = false;
                hits++;
                int temp = frame[j];
                for (int k = j; k > 0; k--) {
               
           frame[k] = frame[k-1];
                }
                frame[0] = temp;
                break;
            }
        }

        if (isPageFault) {
            for (j = frames - 1; j > 0; j--) {
                frame[j] = frame[j - 1];
            }
            frame[0] = incomingStream[i];
            pageFaults++;
            misses++;
        }

        printf("\n%d\t\t\t", incomingStream[i]);

        for (j = 0; j < frames; j++) {
            if (frame[j] != -1) {
                printf(" %d\t\t\t", frame[j]);
            } else {
                printf(" - \t\t\t");
            }
        }
    }

    double pageHitRatio = (double)hits / pages;

    printf("\nTotal Page Hits (MRU):\t%d\n", hits);
    printf("Total Page Misses (MRU):\t%d\n", misses);
    printf("Page Hit Ratio (MRU):\t%.2f\n", pageHitRatio);
}

int main() {
    int frames, pages;

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    printf("Enter the number of elements in the incoming page reference stream: ");
    scanf("%d", &pages);

    int incomingStream[pages];

    printf("Enter the elements in the incoming page reference stream:\n");
    for (int m = 0; m < pages; m++) {
        scanf("%d", &incomingStream[m]);
    }

    int choice;

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. FIFO\n");
        printf("2. LRU\n");
        printf("3. Optimal\n");
        printf("4. MRU\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fifo(frames, pages, incomingStream);
                break;
            case 2:
                lru(frames, pages, incomingStream);
                break;
            case 3:
                optimal(frames, pages, incomingStream);
                break;
            case 4:
                mru(frames, pages, incomingStream);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
