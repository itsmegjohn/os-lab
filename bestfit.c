#include <stdio.h>

int main() {
    int fragment[20], b[20], p[20], barray[20] = {0}, parray[20] = {0};
    int i, j, nb, np, temp, lowest;

    printf("Enter the number of Blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of Processes: ");
    scanf("%d", &np);

    printf("Enter the Size of Blocks:\n");
    for (i = 1; i <= nb; i++) {
        printf("Block Number %d: ", i);
        scanf("%d", &b[i]);
    }

    printf("Enter the Size of Processes:\n");
    for (i = 1; i <= np; i++) {
        printf("Process Number %d: ", i);
        scanf("%d", &p[i]);
    }

    for (i = 1; i <= np; i++) {
        lowest = 9999; // Initialize lowest for each process
        
        for (j = 1; j <= nb; j++) {
            if (barray[j] == 0) {
                temp = b[j] - p[i];
                if (temp >= 0 && temp < lowest) {
                    parray[i] = j;
                    lowest = temp;
                }
            }
        }
        
        if (parray[i] != 0) {
            fragment[i] = lowest;
            barray[parray[i]] = 1;
        }
    }

    printf("\n\tProcessNo\tProcessSize\tBlockNo\t\tBlockSize\tFragment\n");
    for (i = 1; i <= np; i++) {
        if (parray[i] != 0) {
            printf("\n\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", i, p[i], parray[i], b[parray[i]], fragment[i]);
        }
    }

    return 0;
}

