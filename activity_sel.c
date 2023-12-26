#include <stdio.h>
#include <stdlib.h>

// Structure to represent an activity with start and finish times
struct Activity {
    int start;
    int finish;
};

// Function to find and print the maximum number of activities
void printMaxActivities(struct Activity activity[], int n) {
    // Custom bubble sort by start times
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (activity[j].finish > activity[j + 1].finish){
                struct Activity temp = activity[j];
                activity[j] = activity[j + 1];
                activity[j + 1] = temp;
            }
        }
    }

    int i = 0;
    printf("Selected activities: %d ", i);

    // Consider the rest of the activities
    for (int j = 1; j < n; j++) {
        if (activity[j].start >= activity[i].finish) {
            printf("%d ", j);
            i = j;
        }
    }
}

int main() {
    int n;

    // Input the number of activities
    printf("Enter the number of activities: ");
    scanf("%d", &n);

    struct Activity activity[n];

    // Input activity data
    for (int i = 0; i < n; i++) {
        printf("Enter start time for activity %d: ", i);
        scanf("%d", &activity[i].start);
        printf("Enter finish time for activity %d: ", i);
        scanf("%d", &activity[i].finish);
    }

    printf("Activities:\n");
    for (int i = 0; i < n; i++) {
        printf("Activity %d: Start = %d, Finish = %d\n", i, activity[i].start, activity[i].finish);
    }

    printf("Maximum set of activities that can be executed by a single person: ");
    printMaxActivities(activity, n);

    return 0;
}
