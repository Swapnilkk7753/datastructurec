#define NULL 0
#include<stdio.h>
#include<conio.h>
typedef struct node
{
 int data;
 struct node *next;
}node;
typedef struct
{
 node *head;
}stack;
void initstack(stack *s)
{
 s->head=NULL;
}
int isempty(stack *s)
{
 if(s->head==NULL)
 return 1;
 return 0;
}
node* push(stack *s,int k)
{
 node *p=s->head,*temp;
 temp=(node*)malloc(sizeof(node));
 temp->data=k;
 temp->next=NULL;
 if(s->head==NULL)
 s->head=temp;
 else
 {
  while(p->next!=NULL)
  p=p->next;
  p->next=temp;
 }
 return s->head;
}
int pop(stack *s)
{
 node *p=s->head,*temp;
 int n=-1;
 if(isempty(s))
 printf("\nstack underflow");
 else if(p->next==NULL)
 {
  n=p->data;
  s->head=NULL;
  free(p);
 }
 else
 {
  while(p->next->next!=NULL)
  p=p->next;
  temp=p->next;
  n=temp->data;
  p->next=temp->next;
  free(temp);
 }
 return n;
}
void main()
{
 stack s;
 char ch='y';
 int k;
 clrscr();
 while(ch=='y')
 {
  printf("\npress 1 for pushing the value on stack");
  printf("\npress 2 for poping the value from stack");
  printf("\npress 3 for exit the program");
  printf("\nenter your choice");
  scanf("%d",&k);
  switch(k)
  {
   case 1:printf("\nenter the integer element");
	  scanf("%d",&k);
	  s.head=push(&s,k);
	  break;
   case 2:k=pop(&s);
	  if(k!=-1)
	  printf("\npopped element is %d",k);
	  break;
   case 3:exit(0);
   default:printf("\ninvalid choice");
  }
  printf("\npress y for continue the operation");
  fflush(stdin);
  scanf("%c",&ch);
 }
 getch();
 }
