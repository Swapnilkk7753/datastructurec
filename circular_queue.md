#include<stdio.h>
#include<conio.h>
#define max 5
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
 else if((q->front==max) && (q->rear!=max))
 {
 q->front==0;
 return 0;
 }
 return 0;
}
//isfull
int isfull(queue * q)
{
 if(q->rear==max)
 {
  if(q->front!=0)
  {
   q->rear=0;
   return 0;
  }
  else
   return 1;
 }
 else if(q->front!=0)
 {
  if(q->rear>=q->front)
  return 1;
 }
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
 q->rear++;
 }
}
//removeitem
int removeitem(queue *q)
{
 int  n=-1;
 if(isempty(q)==1)
 printf("\nqueue underflow");
 else
 {
  n=q->front;
  q->front++;
 }
 return n;
}
int main()
{
 queue q;
 int n;
 clrscr();
 initiaque(&q);
 additem(&q,6);
 additem(&q,-2);
 additem(&q,7);
 additem(&q,69);
 additem(&q,9);
 additem(&q,-69);
 additem(&q,-9);
 n=removeitem(&q);
 n=removeitem(&q);
 //additem(&q,77);
 n=removeitem(&q);
 n=removeitem(&q);
 n=removeitem(&q);
 n=removeitem(&q);
 additem(&q,-9);
 n=removeitem(&q);
 printf("\n%d,%d",n,q.front);
 getch();
 return 0;
 }



