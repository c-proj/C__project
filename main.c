#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node node;

struct node
{

    int id;
    int price;
    int med_quantity;
    node *next;
    char *name;
    char *pharm_company;
    char *type;

};
node *top=NULL;
int x;
 FILE *fp;

//prompts the user to get a selection
int Menu(void);

//display the options to the user
void DisplayOptions(void);
int main()
{
   int selection;

    DisplayOptions();

    selection= Menu();

 // ---> Marwa While loops & Getting inputs needed from user to pass it to push

    while(selection != 6)
    {
        if (selection==1)
        {
            printf("ADD MEDECINE\n\n");


            char *a;
            a=(char*)malloc(15);
            char *b;
            b=(char*)malloc(15);
            char *c;
            c=(char*)malloc(15);
            int ID;
            int price;
            int med_quantity;
            fflush(stdin);
            printf("enter the ID: ");
            scanf("%d",&ID);
            printf("please,enter name: ");
            fflush(stdin);
            scanf("%[^\n]s",a);
            printf("please,enter type: ");
            fflush(stdin);
            scanf("%[^\n]s",b);
            printf("please,enter company name: ");
            fflush(stdin);
            scanf("%[^\n]s",c);
            printf("enter the price: ");
            scanf("%d",&price);
            printf("enter the quantity of that medicine: ");
            scanf("%d",&med_quantity);

                        push(ID,a,b,c,price,med_quantity);

        }
        else if(selection==2)
        {
            printf("DELETE\n\n");

            pop();
        }

        else if(selection==3)
        {
            printf("DISPLAY OF INVENTORY\n\n");

            display();
        }
        else if(selection==4)
        {
            printf("RESET ENTIRE INVENTORY\n\n");
            deletestack();
        }
        else if(selection==5)
        {
            printf("SAVING CURRENT INVENTORY TO FILE\n\n");
            SaveInventory();
            //saves to file
        }
        else
        {
            printf("COMMAND NOT RECOGNIZED\n\n");
        }

        printf("\n\n");
        DisplayOptions();
        selection = Menu();
    }

    if (selection==6)
    {
        printf("\nHAVE A NICE DAY!!!\n\n");
    }
    return 0;
}

///////////////////////////

//prompts the user to get a selection
int Menu(void)
{
    int selection;
    printf("\nENTER SELECTION: ");
    scanf("%d", &selection);

    return selection;
}
void push(int value,char*name,char*type,char*pharm_company,int price,int med_quantity)
{

    node *new_node;
    new_node=(node*)malloc(sizeof(node));
    new_node->id=value;
    new_node->name=name;
    new_node->type=type;
    new_node->pharm_company=pharm_company;
    new_node->price=price;
    new_node->med_quantity=med_quantity;
    new_node->next=top;
    top=new_node;
    x++;
}
