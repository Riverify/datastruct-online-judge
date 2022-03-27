#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() 
{
    int n;
    long temp;
    long a1 = 0;
    long a2 = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        temp = a1;
        a1 = a2;
        a2 = a2 + temp;
    }
    printf("%ld \n", a1);
}
