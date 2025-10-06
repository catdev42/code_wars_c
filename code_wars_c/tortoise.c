#include <stdlib.h>

int* race(int v1, int v2, int g) {
    int* res = malloc(3*sizeof(int));
    res[0] = res[1] = res[2] = -1;
    if(v1 < v2) {
        long long tmp = 3600*g/(v2 - v1);
        res[0] = tmp / 3600;
        res[1] = (tmp % 3600) / 60;
        res[2] = tmp % 60;
    }
    return res;
}

//ALT

/* #include <stdlib.h>

int* race(int v1, int v2, int g) {
    int *arr = malloc(sizeof(int) * 3);
    arr[0] = -1;
    arr[1] = -1;
    arr[2] = -1;
    double t = (double) g / ((double) v2 - (double) v1);
    if (v1 >= v2) {
      return arr;
    } else {
      arr[0] = (int) t ;
      arr[1] = (int) ((t * 60.0) - arr[0]*60);
      arr[2] = (int) ((t * 3600) - arr[1] * 60 - arr[0]*3600);
      return arr;
    };
    free(arr);
} */