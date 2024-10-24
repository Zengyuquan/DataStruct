#include<stdio.h>

int main()
{
    long long A, B;

    if(scanf("%lld %lld", &A, &B) != 2)
    {
        return 1;
    }

    if(A < 1 || A > 50000|| B < 1 || B > 50000)
    {
        return 1;
    }

    long long result = A * B;
    printf("%lld\n", result);
    return 0;

}