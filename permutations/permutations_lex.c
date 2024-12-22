#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Function to swap two characters
void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Function to reverse a part of the string
void reverse(char *str, int start, int end) {
    while (start < end) {
        swap(&str[start], &str[end]);
        start++;
        end--;
    }
}


/*

This sorts the array so the next time the function is called it is called on the newewr array...

 */
// Function to find the next lexicographical permutation
bool next_permutation(char *str, int n) {
    // Step 1: Find the largest index k such that str[k] < str[k + 1]
    int k = -1;
    for (int i = 0; i < n - 1; i++) {
        if (str[i] < str[i + 1]) {
            k = i;
        }
    }

    // If no such index exists, we are at the last permutation
    if (k == -1) {
        return false;
    }

    // Step 2: Find the largest index l greater than k such that str[k] < str[l]
    int l = -1;
    for (int i = k + 1; i < n; i++) {
        if (str[k] < str[i]) {
            l = i;
        }
    }

    // Step 3: Swap str[k] and str[l]
    swap(&str[k], &str[l]);

    // Step 4: Reverse the sequence from str[k + 1] to the end
    reverse(str, k + 1, n - 1);

    return true;
}

int main() {
   	char	input[100] = "012345";


    // Sort the input string to ensure permutations start in lexicographical order
    int n = strlen(input);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (input[i] > input[j]) {
                swap(&input[i], &input[j]);
            }
        }
    }

    printf("Permutations of %s in lexicographical order:\n", input);

    do {
        printf("%s\n", input);
    } while (next_permutation(input, n));

    return 0;
}



/*

Explanation:
Sorting:

Before generating permutations, the input string is sorted. This ensures that the permutations start in lexicographical order.
Next Permutation Algorithm:

Step 1: Find the largest index k where str[k] < str[k + 1].
Step 2: Find the largest index l greater than k where str[k] < str[l].
Step 3: Swap str[k] and str[l].
Step 4: Reverse the substring from str[k + 1] to the end.
Termination:

When k cannot be found (i.e., the string is in descending order), the function terminates as it has reached the last permutation.
Output:

The next_permutation function is called repeatedly until it returns false, printing each permutation in lexicographical order.
*/