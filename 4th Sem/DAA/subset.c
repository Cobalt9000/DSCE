#include<stdio.h>

int w[10], x[10], i, n, r = 0, d, count = 0, flag = 1;

void subset(int s, int k, int r) {
    x[k] = 1;
    if (s + w[k] == d) {
        printf("\n Subset %d -->", ++count);
        for (i = 0; i <= k; i++) {
            if (x[i] == 1) {
                printf("\t %d", w[i]);
            }
        }
    } else {
        if ((s + w[k] + w[k + 1]) <= d) {
            subset(s + w[k], k + 1, r - w[k]);
        }
    }
    if (((s + r - w[k]) >= d) && (s + w[k + 1] <= d)) {
        x[k] = 0;
        subset(s, k + 1, r - w[k]);
    }
}

int main() {
    printf("\n Enter n value : ");
    scanf("%d", &n);
    printf("\n Enter the elements of the sets in ascending order : \n ");
    for (i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        x[i] = 0;
        r += w[i];
    }
    printf("\n Enter the d value : ");
    scanf("%d", &d);
    subset(0, 0, r);
    if (flag == 1 && count == 0) {
        printf("\n Subset Not Possible");
    }
    return 0; // Added a return statement
}

