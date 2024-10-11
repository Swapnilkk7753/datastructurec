#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 3
#define TRUE 1
#define FALSE 0
//queue
typedef struct
{
 int info[max];
 int front;
 int rear;
}queue;
//initialize
void initiaque(queue *q)
{
 q->front=0;
 q->rear=0;
}
//isempty
int isempty(queue * q)
{
 if(q->front==q->rear)
 return 1;
 return 0;
}
//isfull
int isfull(queue * q)
{
 if((q->rear+1)%max==q->front)
 return 1;
 return 0;
}
//additem
void additem(queue *q,int value)
{
 if(isfull(q)==1)
 printf("\nqueue overflow");
 else
 {
 q->info[q->rear]=value;
 q->rear=(q->rear+1)%max;
 }
}
//removeitem
int removeitem(queue *q)
{
 int n=-1;
 if(isempty(q)==1)
 printf("\nqueue underflow");
 else
 {
  n=q->info[q->front];
  q->front=(q->front+1)%max;
 }
 return n;
}
int main()
{
 queue q;
 char ch='y';
 int c;
 clrscr();
 initiaque(&q);
 while(ch=='y' ||ch=='Y')
 {
  printf("press 1 for additem in queue\n");
  printf("press 2 for remove item in the queue\n");
  printf("press 3 for exit the program\n");
  printf("enter your choice\n");
  scanf("%d",&c);
  switch(c)
  {
   case 1:printf("\nenter the element for inserting in queue: ");
	  scanf("%d",&c);
	  additem(&q,c);
	  break;
   case 2:c=removeitem(&q);
	  if(c!=-1)
	  printf("poped element from queue is %d",c);
	  break;
   case 3:exit(0);
   default:printf("\ninvalid choice");
  }
  printf("\n To continue the program press y or Y otherwise any key\n");
  fflush(stdin);
  scanf("%c",&ch);
 }
 getch();
 return 0;
}




