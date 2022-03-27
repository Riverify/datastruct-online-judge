#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void fun(char str[100])
{
	char *p=str;
	int i=0;
	while(*p)
	{
		if(*p!=' ')
			str[i++]=*p;
		p++;
	}
	str[i]='\0';
}

int main()
{
  // char c[100] = "(A (B (C, D), E ( , F)) )";
  // fun(c);
  // int i = 0;
  //  while (c[i] != '\0') {
  //    printf("%c", c[i]);
  //    i++;
  //  }

   char gLists[100];
    scanf( "%[^\n]", gLists )   ;
   fun(gLists);
   int i = 0;
    while (gLists[i] != '\0') {
     printf("%c", gLists[i]);
     i++;

   }
}
