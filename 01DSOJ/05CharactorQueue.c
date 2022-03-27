
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

 
void search(const char *str)
{
    int i,j;
    int bool;
    for(i=0; i<strlen(str); i++){
        for(j=0, bool = 0; j<strlen(str); j++){
            if(i!=j && str[i] == str[j]){
                bool = 1;
                break;
            }       
        }
        if(!bool){
            printf("%d\n", i);
            break;
        }
    }
} 

int main()
{
    char str[50];
    scanf("%s", str);
    search(str);
    return 0;
}