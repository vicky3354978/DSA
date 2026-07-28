#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int item;
    struct node *next;
}node;
void insertatstart(node **s,int info)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("insuffecient memory");
        return;
    }
    temp->item=info;
    temp->next=*s;
    *s=temp;
}
void insertatend(node **s, int info)
{
    node *current,*temp;
    temp = (node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("insuffecient memory");
        return;
    }
    temp->item=info;
    temp->next=NULL;
    if(*s==NULL)
    {
        *s=temp;
        return;
    }
    for(current=*s; current->next!=NULL; current=current->next);
    current->next=temp;
    
}
void insertatbetween(node **s,int info,int pos)
{
node *current, *temp;
    temp = (node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("insuffecient memory");
        return;
    }
    current=*s;
    for(int i=1; i<pos-1; i++)
    {
        current=current->next;
    }
    temp->item=info;
    temp->next=current->next;
    current->next=temp;

}
void deleteatstart(node **s)
{
    if(*s==NULL)
    {
        printf("linked kist is empty \n");
        return;
    }
    node *temp;
    temp=*s;
    *s=temp->next;
    int n=temp->item;
    free(temp);
    printf("deleted item is %d  ",n);
}
void deleteatend(node **s)
{
    if(*s==NULL)
    {
        printf("linked kist is empty \n");
        return;
    }
    if((*s)->next==NULL)
    {
        int n=(*s)->item;
        free(*s);
        printf("deleted item id %d ",n);
        return;

    }
    node *back,*current;
    for(back=NULL,current=*s; current->next!=NULL; current=current->next)
    {
        back=current;
    }
    node *temp;
    temp=current;
    back->next=NULL;
    int n=temp->item;
    free(temp);
    printf("the deleted item is : %d ",n);
}
void deletebetween(node **s,int pos)
{
    if(*s==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    node *current,*back;
    current=*s;
    back=NULL;

    for(int i=1;i<pos;i++)
    {
        back=current;
        current=current->next;
        if(current==NULL)
        {
            printf("Invalid position\n");
            return;
        }
    }

    if(back==NULL)
    {
        *s=current->next;
    }
    else
    {
        back->next=current->next;
    }

    int n=current->item;

    free(current);

    printf("The deleted item is : %d\n",n);
}

void display(node **s)
{ 
    node *d;
    if(*s==NULL)
    {
        printf("linked list is empty ");
        return;
    }
    printf("the info are : \n");
    for(d=*s; d!=NULL; d=d->next)
    {
        printf("%5d",d->item);
    }
}

int main()
{
    int value;
    node *s=NULL;
    int choice;
    int pos;
    while(1)
    {
        printf("\n main menu \n");
        printf("\nenter 1 for insert at start \n");
        printf("\nenter 2 insert at end \n");
        printf("\nenter 3 for insert at between \n");
        printf("\nenter 4 for display all  node infomation \n");
        printf("\nenter 5 delete the starting node \n");
        printf("\nenter 6 delete the end node \n ");
        printf("\nenter 7 for delete the node between the linked list \n");
        printf("\nenter 8 for exit the program");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter the value \n");
            scanf("%d",&value);
            insertatstart(&s,value);
            break;
            case 2:
            printf("enter the value \n");
            scanf("%d",&value);
            insertatend(&s,value);
            break;
            case 3:
            printf("enter the value \n");
            scanf("%d",&value);
            printf("enter the position \n");
            scanf("%d",&pos);
            insertatbetween(&s,value,pos);
            break;
            case 4:
            display(&s);
            break;
            case 5:
            deleteatstart(&s);
            break;
            case 6:
            deleteatend(&s);
            break;
            case 7:
            printf("enter the position \n");
            scanf("%d",&pos);
            deletebetween(&s,pos);
            break;
            case 8:
            return 0;


        }
    }
    return 0;
}