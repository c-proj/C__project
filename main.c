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
// --> Mirihan Pop & Delete stack functions

bool isempty(){

return top==NULL;

}

int pop()
{
    int value;
    node *current_node;
    if(isempty())printf("Stack is Empty\n");

    else
    {
        x--;
        current_node=top;
        value=current_node->id;
        top=current_node->next;
        free(current_node);

        return value;

    }

}

void deletestack()
{
    int size=x;
    for(int i=1; i<=size; i++)
    {
        pop();
    }
    x=0;
}
// --> Noura Dispaly & Menu functions 

void display()
{
    node* current_node;

    if(isempty())printf("stack is Empty");

    else
    {
        current_node=top;
        while(current_node!=NULL)
        {
            printf("%d\t\t%s\t\t%s\t\t%s\t\t%dt\t%d\n",current_node->id,current_node->name,current_node->type,current_node->pharm_company,current_node->price,current_node->med_quantity);

            current_node=current_node->next;
        }

    }

}




//--> youstina saveinventory and readfile

//save to file

void SaveInventory(int value,char*name,char*type,char*pharm_company,int price,int med_quantity){

 
  FILE *out;

  if((out=fopen("drugs.txt","a+"))==NULL) {
    printf("cant open file \n");

  }


    else
    {
        
        
           
fprintf(out,"%d %s %s %s %d %d\n",value,name,type,pharm_company,price,med_quantity);

         
      

    }

   fclose(out);
}
//readfile
void readfile(){


    int value=0;
    int price=0;
    char name[50];
    char type[50];
    char company[50];
    int Quan=0;
    char*p;
    char c[1000];
    FILE *fin;
    if((fin=fopen("drugs.txt","r"))==NULL)
        printf("file not found");
         while(fgets(c, sizeof c, fin) !=NULL){
         if ((strlen(c)>0) && (c[strlen (c) - 1] == '\n'))
         c[strlen (c) - 1] = '\0';
         p=strtok(c," ");
         value=atoi(p);
         p=strtok(NULL," ");
         strcpy(name,p);
         p=strtok(NULL," ");
         strcpy(company,p);
         p=strtok(NULL," ");
         strcpy(type,p);
         p=strtok(NULL," ");
         price=atoi(p);
         p=strtok(NULL," ");
         Quan=atoi(p);
         push(value,name,type,company,price,Quan);
      }
      printf("\n");
      fclose(fin);
}
