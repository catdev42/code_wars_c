#include <stdio.h>
#include <stdlib.h>

void find_subsets(int *arr, int size, int target, int *current, int curr_size, int start) {
    // Found a valid subset
    int sum = 0;
    for (int i = 0; i < curr_size; i++) {
        sum += current[i];
    }
    
    if (sum == target && curr_size > 0) {
        for (int i = 0; i < curr_size; i++) {
            printf("%d", current[i]);
            if (i < curr_size - 1)
                printf(" ");
        }
        printf("$\n");
        return;
    }
    
    // Try adding more elements
    for (int i = start; i < size; i++) {
        // Skip if adding this number would exceed target
        if (sum + arr[i] > target)
            continue;
            
        current[curr_size] = arr[i];
        find_subsets(arr, size, target, current, curr_size + 1, i + 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        return 1;
    }

    int target = atoi(argv[1]);
    int size = argc - 2;
    
    // Allocate arrays
    int *numbers = malloc(sizeof(int) * size);
    int *current = malloc(sizeof(int) * size);
    
    if (!numbers || !current) {
        if (numbers) free(numbers);
        if (current) free(current);
        return 1;
    }
    
    // Parse input numbers
    for (int i = 0; i < size; i++) {
        numbers[i] = atoi(argv[i + 2]);
    }
    
    // Find all subsets
    find_subsets(numbers, size, target, current, 0, 0);
    
    // Clean up
    free(numbers);
    free(current);
    return 0;
}