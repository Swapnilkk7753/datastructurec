#include<stdio.h>
#include<conio.h>
#define NULL 0
typedef struct node
{
 int data;
 struct node *next;
}node;
node * create(node *head)
{
 node *temp,*p;
 int k;
 char ch='y';
 while(ch=='y')
 {
  temp=(node*)malloc(sizeof(node));
  printf("\nenter the integer element: ");
  scanf("%d",&k);
  temp->data=k;
  temp->next=NULL;
  if(head==NULL)
  head=p=temp;
  else
  {
   while(p->next!=NULL)
   p=p->next;
   p->next=temp;
  }
  printf("\npress y for continue inserting: ");
  fflush(stdin);
  scanf("%c",&ch);
 }
 return head;
}
void display(node* head)
{
 node *p=head;
 printf("\n");
 while(p!=NULL)
 {
  printf("%d->",p->data);
  p=p->next;
 }
}
node* deleterandom(node*head,int k)
{
 node *p=head,*temp;
 int flag=0;
 while(p!=NULL)
 {
  if(p->data==k)
  {
   flag=1;
   break;
  }
  p=p->next;
 }
 if(flag==0)
 printf("\nkey not found");
 else
 {
  if(head->next==NULL||head->data==k)
  {
   temp=head;
   head=head->next;
   free(temp);
  }
  else
  {
   p=head;
   while(p!=NULL)
   {
    if(p->next->data==k)
    {
     temp=p->next;
     p->next=temp->next;
     free(temp);
     break;
    }
    p=p->next;
   }
  }
 }
  return head;
 }
int main()
{
 node *head=NULL;
 int key;
 clrscr();
 head=create(head);
 display(head);
 printf("\nenter the key: ");
 scanf("%d",&key);
 head=deleterandom(head,key);
 display(head);
 getch();
 return 0;
}

