#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void startStopwatch();
void displayMenu();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                startStopwatch();
                break;
            case 2:
                printf("Exiting the stopwatch program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Stopwatch Menu ---\n");
    printf("1. Start/Stop Stopwatch\n");
    printf("2. Exit\n");
}

void startStopwatch() {
    int running = 1;
    clock_t start, end;
    double elapsed;
    char input;

    // Start the stopwatch
    printf("Stopwatch started...\n");
    start = clock();

    // Wait for the user to stop it
    while (running) {
        printf("Press 's' to stop the stopwatch: ");
        input = getchar();
        if (input == 's' || input == 'S') {
            end = clock();
            elapsed = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Stopwatch stopped. Time elapsed: %.2f seconds.\n", elapsed);
            running = 0;  // Stop the stopwatch
        }
        // Clear the buffer to avoid issues with `getchar()`
        while (getchar() != '\n');
    }
}
