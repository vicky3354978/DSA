#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *next;
}node;
void push(node **s,int x)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("stcak overflow \n");
        return;
    }
    temp->info=x;
    temp->next=*s;
    *s=temp;
    printf("item is pushed in stack \n");
}
void pop(node **s)
{
    if(*s==NULL)
    {
        printf("underflow\n ");
        return;
    }
    node *temp;
    temp=*s;
    *s=temp->next;
    int x=temp->info;
    free(temp);
    printf("the poped istem is %d ",x);
}
int main()
{
    int x;
    node *s=NULL;
    int choice;
    while(choice)
    {
        printf("\npress\n");
        printf("1: for push the item \n");
        printf("2: for pop the item \n");
        printf("3: for exit the program \n ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        printf("enter the item which you to push in stack \n");
        scanf("%d",&x);
        push(&s,x);
        break;
        case 2:
        pop(&s);
        break;
        case 3:
        return 0;
        default :
        printf("invalid ");
        break;
        }

    }

    return 0;

}