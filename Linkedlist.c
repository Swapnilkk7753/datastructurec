#include<stdio.h>
#include<conio.h>
#define NULL 0
typedef struct node  {
int data;
struct node *next;
}node;
node * create(node *head)
{
    node p,*nhead;
    int k;
    nhead=head;
    printf("enter the value for inserting\n");
    scanf("%d",&k);
    if(head==NULL)
    {
      head=&p;
      p.data=k;
      p.next=NULL;
    }
    else{
        while(nhead->next!=NULL)
        {
        nhead=nhead->next;
         }
        p.data=k;
        nhead->next=&p;
        p.next=NULL;
          }
    return head;
}
void display(node *head)
{
    node *p=head;
  printf("he\n");
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
int main()
{
    node *head=NULL;
    int i;
    for(i=0;i<3;i++)
    head=create(head);
    display(head);
    return 0;
}
