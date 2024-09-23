#include <stdio.h>

int main() {

    int n = 4;
    int t = 0;

    int a[] = { 1, 2, 3, 4, 5 };
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-1-i; j++)
            t=a[j], a[j]=a[j+1], a[j+1]=t;

    for (int i = 0; i < 5; i++) {
        printf("%d ",a[i]);
    }

    return 0;
}