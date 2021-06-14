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
