//Infix to postfix conversion 
#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#define max 20
typedef struct
{
 char info[max];
 int top;
}stack;

void initialize(stack *a)
 {
  a->info[0]='\0';
  a->top=1;
 }

int isempty(stack *a)
 {
  if(a->top==0)
  return 1;
  return 0;
 }

int isfull(stack *a)
 {
  if(a->top==max)
  return 1;
  return 0;
 }

void push(stack *a,char ch)
 {
  if(isfull(a)==1)
  printf("\nstack overflow");
  else
  {
   a->info[a->top]=ch;
   a->top++;
  }
 }

char pop(stack *a)
 {
  char n='-1';
  if(isempty(a)==1)
  printf("\nstack underflow");
  else
  {
   a->top--;
   n=a->info[a->top];
  }
  return n;
 }

int isoperend(char a)
 {
  if(isdigit(a)||isalpha(a))
  return 1;
  return 0;
 }

int icp(char a)
 {
  switch(a)
  {
   case '(':return 5;
   case '*':
   case '/':
   case '%':return 4;
   case '+':
   case '-':return 3;
   case ')':return 2;
  }
 }

int isp(stack *a)
 {
  char c;
  c=a->info[a->top-1];
  switch(c)
  {
   case '*':
   case '/':
   case '%':return 4;
   case '+':
   case '-':return 3;
   case '(':return 1;
   case '\0':return 0;
  }
 }

void infixtopostfix(char a[],char b[])
 {
  int i=0,c=0;
  stack s;
  initialize(&s);
  while(a[i]!='\0')
  {
   if(isoperend(a[i]))
    b[c++]=a[i];
   else
   {
    if(icp(a[i])>isp(&s))
    push(&s,a[i]);
    else
    {
     while(isp(&s)>=icp(a[i]))
     b[c++]=pop(&s);
     if(')'==a[i])
     pop(&s);
     else
     push(&s,a[i]);
    }
   }
  i++;
  }
  while(!isempty(&s))
  b[c++]=pop(&s);
 }

int main()
{
 char infix[50],postfix[50];
 clrscr();
 printf("\nenter the infix expression:");
 fflush(stdin);
 gets(infix);
 infixtopostfix(infix,postfix);
 printf("\nthe postfix expression is:");
 puts(postfix);
 getch();
 return 0;
}

