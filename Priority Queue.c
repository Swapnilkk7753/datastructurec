#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 3
#define level 2
#define TRUE 1
#define FALSE 0
//queue
typedef struct
{
 int info[max];
 int front;
 int rear;
}queue;
//priority queue
typedef struct
{
 queue pq[level];
}pqueue;
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
 pqueue q;
 char ch='y';
 int c;
 clrscr();
 initiaque(&q.pq[0]);
 initiaque(&q.pq[1]);
 while(ch=='y' ||ch=='Y')
 {
  printf("press 1 for inserting higher priority element in queue\n");
  printf("press 2 for inserting normal item in the queue\n");
  printf("press 3 for removing higher priority element in queue\n");
  printf("press 4 for removing normal element in queue\n");
  printf("press 5 for exit the program\n");
  printf("enter your choice\n");
  scanf("%d",&c);
  switch(c)
  {
   case 1:printf("\nenter the element for inserting in queue: ");
	  scanf("%d",&c);
	  additem(&q.pq[0],c);
	  break;
   case 2:printf("\nenter the element for inserting in queue: ");
	  scanf("%d",&c);
	  additem(&q.pq[1],c);
	  break;
   case 3:c=removeitem(&q.pq[0]);
	  if(c!=-1)
	  printf("poped element from queue is %d",c);
	  break;
   case 4:c=removeitem(&q.pq[1]);
	  if(c!=-1)
	  printf("poped element from queue is %d",c);
	  break;
   case 5:exit(0);
   default:printf("\ninvalid choice");
  }
  printf("\n To continue the program press y or Y otherwise any key\n");
  fflush(stdin);
  scanf("%c",&ch);
 }
 getch();
 return 0;
}
