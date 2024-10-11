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
 node *nhead;
 int i,k;
 for(i=0;i<4;i++)
 {
  printf("enter the value for inserting\n");
  scanf("%d",&k);
  if(head==NULL)
    {
      head=(node *)malloc(1*sizeof(node));
      head->data=k;
      head->next=NULL;
      nhead=head;
    }//if ends
  else
    {
     while(nhead->next!=NULL)
     nhead=nhead->next;
     nhead->next=(node *)malloc(1*sizeof(node));
     nhead=nhead->next;
     nhead->data=k;
     nhead->next=NULL;
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
