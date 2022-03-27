#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50

/*顺序栈的应用之括号匹配*/
typedef struct
{
    char  data[MAXSIZE];
    int top;

}*sqStack,sepStack;

sqStack initStack()//栈的初始化
{
    sqStack s;
    s=(sqStack)malloc(sizeof(sepStack));//为栈顶元素动态分配空间
    if(!s)
      return NULL;//如果分配空间失败，返回空
    s->top=0;

    return s;
}


int push(sqStack s,char x)//入栈
{
    if(s->top==MAXSIZE-1)//栈满时
        return 0;

    s->data[s->top++]=x;

    return 1;


}


int pop(sqStack s,char *x)//出栈
{
    if(s->top==0)//当s->top==0时,说明栈为空
        return 0;

    *x=s->data[--s->top];

    return 1;
}

int getTops(sqStack s1,char ch)//从栈顶得到一个括号
{
    while(s1->top!=0)
    {
        pop(s1,&ch);

        if(ch=='('||ch=='['||ch=='{')
            //printf("%d\n",1);

            return 1;
    }
    return 0;

}



int match(char ch1,char ch2)//检测左括号是否与右括号匹配
{
    if((ch1=='('&&ch2==')')||(ch1=='{'&&ch2=='}')||(ch1=='['&&ch2==']'))
        return 1;
    else
        return 0;
}


int isEmpty(sqStack s)
{
    if(s->top==0)
        return 1;
    else
        return 0;
}


int parenthesisMatch(sqStack s)//检测括号是否匹配,匹配返回1，否则返回0
{
    char str[100];
    int i=0;
    // printf("Please input a string:\n");
    scanf("%s",str);
    char a;
    char ch;

    for(i=0; str[i]!=0; i++)
    {
        switch(str[i])//挨个对字符串中的每个字符进行判定
        {
        case '{':
        case '[':
        case '('://当前字符如果为左括号,则左括号入栈
            push(s,str[i]);

            break;
        case '}':
        case ']':
        case ')'://当前字符为右括号时

            if(isEmpty(s)==1)
            {
            	printf("0 \n");
           	    return 0;//如果栈为空，括号不匹配
            }
               
            getTops(s,ch);//如果栈不为空，从栈顶获取一个左括号
            if(match(ch,str[i]))//看获取的左括号是否与当前右括号匹配
            {
                pop(s,&a);//如果匹配,则左括号出栈
            }
          

        }
    }
    if(isEmpty(s)==1)//当栈顶元素为空时,括号匹配
    {
          printf("1 \n");
        return 1;
    }
    else
    {
          printf("0 \n");
        return 0;
    }
}



int main()
{

    sqStack s;

    s= initStack();
    parenthesisMatch(s) ;

    return 0;
}

