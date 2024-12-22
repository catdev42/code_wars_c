#include <stdio.h>
#include <string.h>

// Function to print an array
void printArray(char *str, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

// Function to generate permutations iteratively
void generatePermutations(char *str) {
    int n = strlen(str);
    int c[n]; // Control array for tracking swaps
    for (int i = 0; i < n; i++) {
        c[i] = 0; // Initialize control array
    }

    printArray(str, n); // Print the initial permutation

    int i = 0; // Start with the first element
    while (i < n) {
        if (c[i] < i) {
            // If i is even, swap str[0] and str[i]
            // If i is odd, swap str[c[i]] and str[i]
            if (i % 2 == 0) {
                char temp = str[0];
                str[0] = str[i];
                str[i] = temp;
            } else {
                char temp = str[c[i]];
                str[c[i]] = str[i];
                str[i] = temp;
            }

            printArray(str, n); // Print current permutation
            c[i]++; // Increase control array value for current position
            i = 0; // Reset position to 0
        } else {
            c[i] = 0; // Reset control array value for current position
            i++; // Move to the next position
        }
    }
}

int main() {
	char	input[100] = "012345";
    // printf("Enter a string to generate permutations: ");
    // scanf("%s", input);

    printf("Permutations of %s:\n", input);
    generatePermutations(input);
    return 0;
}
