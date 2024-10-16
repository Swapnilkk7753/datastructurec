#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define NULL 0
//node
typedef struct node
{
  int data;
  struct node *next;
}node;
//creare linked list
node * create(node *head)
{
 node *nhead,*temp;
 int i,k;
 for(i=0;i<4;i++)
 {
  printf("enter the value for inserting\n");
  scanf("%d",&k);
  temp=(node *)malloc(sizeof(node));
   temp->data=k;
   temp->next=NULL;
  if(head==NULL)
    {
      head=temp;
      nhead=head;
    }//if ends
  else
    {
     while(nhead->next!=NULL)
     nhead=nhead->next;
     nhead->next=temp
    } //else ends
  }//loop ends
 return head;
}//function ends
void display(node *head)
{
   printf("\nthe inserted element is= ");
    while(head!=NULL)
    {
	printf("%d->",head->data);
	head=head->next;
    }//loop ends
}//function ends
int main()
{
    node *head=NULL;
    int i;
    clrscr();
    head=create(head);
    display(head);
     getch();
    return 0;
}//main ends
