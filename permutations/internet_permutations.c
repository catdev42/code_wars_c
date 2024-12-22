#include <stdio.h>
#include <stdlib.h>

void swap (int *i, int *j) {
    int temp = *i;
    *i = *j;
    *j = temp;
}

void permute(int index, int* arr, int n) {
   if (index == n-1) {
       for (int k = 0; k < n; ++k) {
            printf ("%d ", arr[k]);
       }
       printf ("\n");
       return;
   }
   for (int i = index; i < n; i++) {
       swap (arr + index, arr + i);
       permute (index+1, arr, n);
       swap (arr + i, arr + index);
   }
   return;
}

int main()
{
   int n = 5;
//    if (scanf("%d",&n) != 1) exit (1);
   int arr[6];
   for (int i = 0; i < n; ++i) arr[i] = i+1;
   permute(0, arr, n);
   return 0;
}