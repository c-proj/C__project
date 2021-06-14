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


//////////
int main()
{
   int selection;


    DisplayOptions();

    selection= Menu();

    while(selection != 7)
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
        }/*
        else if(selection==4)
        {
            printf("SAVING CURRENT INVENTORY TO FILE\n\n");
            SaveInventory(entry, &size);
            //saves to file
        }*/
        else if(selection==5)
        {
            printf("RESET ENTIRE INVENTORY\n\n");
            deletestack();
        }/*
        else if(selection==6)
        {
            printf("LOADING SALES RECORDS FROM FILE\n\n");
            LoadSalesRecords(entry, &size);
        }*/
        else
        {
            printf("COMMAND NOT RECOGNIZED\n\n");
        }

        printf("\n\n");
        DisplayOptions();

        //clears buffer
        //scanf("%c", &trash);

        selection = Menu();
    }

    if (selection==7)
    {
        printf("\nHAVE A NICE DAY!!!\n\n");
    }
    return 0;
}

///////////////////////////



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
    puts("A new medicine has been added to the inventory.")
    fp = fopen("drugs.txt","a");
    fprintf(fp,"Medicine ID: %d, Medicine name: %s, Medicine type: %s, Pharmacutical Co.: %s, Medicine price: %d, Quantity: %d\n",value,name,type,pharm_company,price,med_quantity);
    fclose(fp);
}
bool isempty()
{
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


void display()
{
    node* current_node;

    if(isempty())printf("stack is Empty");

    else
    {
        current_node=top;
        while(current_node!=NULL)
        {
            printf("%d\t\t%s\t\t%s\t\t%dt\t%d\n",current_node->id,current_node->name,current_node->type,current_node->pharm_company,current_node->price,current_node->med_quantity);

            current_node=current_node->next;
        }

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

////////////////////

//display the options to the user
void DisplayOptions(void)
{
    printf("HELLO, WELCOME TO THE INVENTORY PROGRAM.\n");
    printf("THIS PROGRAM HOLDS INVENORY FOR PHARMACUTICAL COMPANIES ALONG WITH THEIR NAME,ID,PRICE,\n");
    printf("*********************************************\n\n");
    printf("HERE ARE YOUR OPTIONS\n");
    printf("1--ADD A NEW MEDECINE\n");
    printf("2--DELETE AN MEDECINE \n");
    printf("3--DISPLAY THE INVENTORY\n");
    printf("4--SAVE CURRENT INVENTORY TO FILE\n");
    printf("5--RESET THE ENTIRE INVENTORY\n");
    printf("6--LOAD SALES RECORD FROM FILE\n");
    printf("7--QUIT\n");
}

//prompts the user to get a selection
int Menu(void)
{
    int selection;
    printf("\nENTER SELECTION: ");
    scanf("%d", &selection);

    return selection;
}

//nagy => files
    Student record;
    Linked student;
    Login user = { "admin","admin" }, userCheck;
    int choice;
    //if the file exist, Linked will read the file else it will do nothing beacuse it's first time
    FILE* fptr = fopen("students.dat","rb");
    createLinked(&student);
    //to read the file data alwaya in the beginning and make it easy to deal with the data
    if (fptr != NULL) {
        readFile(fptr, &student,&user, insert);
        fclose(fptr);
    }
    puts("\t\t\t\tWELCOME TO YOUR STUDENTS DATABASE");
    puts("\ntip,the default userName is \"admin\", default password is \"admin\"\nLOGIN");
    printf("%s", "username: ");
    gets(userCheck.userName);
    printf("%s", "password: ");
    gets(userCheck.password);
    //to check for password correctness
    while ((strcmp(user.userName,userCheck.userName))!=0 || (strcmp(user.password,userCheck.password))!=0 ) {
        puts("wrong user name or password,please try login again");
        printf("%s", "username: ");
        gets(userCheck.userName);
        printf("%s", "password: ");
        gets(userCheck.password);
    }
    system("clear");
    instructions();
    enterChoice(&choice);
     while(choice !=11){
        puts("\t\t\t\t***********");
         switch (choice) {
         }
    return 0;
}
