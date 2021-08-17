
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

int menu(void);
NODE *create_node(int data);
void add_node_at_last_position(int data);
void add_node_at_first_position(int data);
void add_node_at_specific_position(int pos,int data);
void delete_node_from_first_position(void);
void delete_node_from_last_position(void);
void delete_node_from_specific_position(int pos);
void display_list(void);
int count_node(void);


NODE *head=NULL;//creating an empty linked list



enum{EXIT,ADD_FIRST,ADD_LAST,ADD_SPECIFIC,DEL_FIRST,DEL_LAST,DEL_SPECIFIC,DISPLAY_LIST};


int main(void)
{
    int pos;
    int data;
    //menu driven program
    while(1)
    {
        //int choice=menu();
        switch(menu())
        {
            case EXIT:
                exit(0);
             case ADD_FIRST:
                printf("Enter data  : ");
                scanf("%d",&data);
                add_node_at_first_position(data);
                break;
            case ADD_LAST:
                printf("Enter data  : ");
                scanf("%d",&data);
                add_node_at_last_position(data);
                break;
             case ADD_SPECIFIC:
            {
               printf("Enter position : ");
                scanf("%d",&pos);
                if(pos>=1 && pos<=count_node()+1)
                {
                    printf("Enter data : ");
                    scanf("%d",&data);
                    add_node_at_specific_position(pos,data);
                    break;
                }
                else
                printf(" entered position is invalid !!!\n");
            }
            break;
            case DEL_FIRST:
             delete_node_from_first_position();
                break;
            case DEL_LAST:
            delete_node_from_last_position();
                break;
            case DEL_SPECIFIC:
                {
                    printf("Enter Position  :  ");
                    scanf("%d",&pos);
                    if(pos>=1 && pos<=count_node())
                    {
                        delete_node_from_specific_position(pos);
                        break;
                    }
                    else
                    printf(" Entered Position is Invalid !!!\n");
                    }
                break;
            case DISPLAY_LIST:
                display_list();
                break;
                default :
                break;
            
        }
    }
return 0;
     
}

//menu driven prgram
int menu(void)
{
    int choice;
    printf("0. For Exit \n");
    printf("1. For Adding node at First position\n");
    printf("2. For Adding node at Last position \n");
    printf("3. For Adding node at Specific position\n");
    printf("4. For Deletion of node from First Position\n");
    printf("5. For Deletion of node from Last Position\n");
    printf("6. For Deletion of node from Specific Position\n");
    printf("7. For displying the list\n");
    printf("Enter choice  ");
    scanf("%d",&choice);
    return choice;
}


//counting total nodes in list
int count_node(void)
{
    int count=0;
    if(head!=NULL)
    {
        NODE *trav;
        trav=head;
        while(trav!=NULL)
        {
            count++;
            trav=trav->next;
        }
    }
    return count;
}


//display list
void display_list(void)
{
    
 if(head!=NULL)
 {
     NODE *trav;
     trav=head;
     printf("Total number of nodes : %d\n",count_node());
     printf("Nodes inside list :   ");
     printf("head->");
     while(trav!=NULL)
     {
     printf(" %d ->",trav->data,trav->next);
     trav=trav->next;
     }
     printf("null\n");
 }   
 else
 {
     printf("list is empty !!!\n");
 }
 
}

//function for creation of node.
NODE *create_node(int data)
{
    NODE *node;
    node=(NODE *)malloc(sizeof(NODE));
    if(node==NULL)
    {
        printf("malloc() failed !!!\n");
        exit(1);
    }
    node->data=data;
    node->next=NULL;
    return node;

}


//function for addition of node at last position.
void add_node_at_last_position(int data)
{
    NODE *new_node;
    new_node=create_node(data);
    if(head==NULL)
    {
       head=new_node; 
    }
    else
    {
        NODE *trav;
        trav=head;
        while(trav->next!=NULL)
        {
            trav=trav->next;   //move forward
        }
        trav->next=new_node;
    }
printf("SUCCESSFULLY ADDED \n");
}

//function for additon of node at first position.
void add_node_at_first_position(int data)
{
    NODE *new_node;
    new_node=create_node(data);
    if(head==NULL)
    {
        head=new_node;
    }
    else
    {
        new_node->next=head;
        head=new_node;
    }
   printf("SUCCESSFULLY ADDED \n"); 
}


//add node at specific position
void add_node_at_specific_position(int pos,int data)
{
    if(pos==1)
    add_node_at_first_position(data);
    else if(pos==count_node()+1)
    add_node_at_last_position(data);
    else
    {
        NODE *new_node;
        new_node=create_node(data);
        NODE *trav;
        trav=head;
        int i=1;
        while(i<pos-1)
        {
            i++;
            trav=trav->next;
        }
        new_node=trav->next;
        trav->next=new_node;
    }
printf("SUCCESSFULLY ADDED \n");
}


//For deletion of node from First position
void delete_node_from_first_position(void)
{
    if(head!=NULL)
   {
      
           NODE *node;
           node=head;
           head=head->next;
           free(node);
    printf("SUCCESSFULLY DELETED \n");   
    } 
   else
   printf("List is Empty !!!\n");
}


//Delete node from last position
void delete_node_from_last_position(void)
{
    if(head!=NULL)
    {
        if(head->next==NULL)
        {
            free(head);
            head=NULL;
        }
        else
        {
            NODE *trav;
            trav=head;
            while(trav->next->next!=NULL) 
            trav=trav->next;

            free(trav->next);
            trav->next=NULL;
            printf("SUCCESSFULLY DELETED \n");
        }
    }
    else
    printf("List is Empty !!!\n");

}

//Delete node from specific position
void delete_node_from_specific_position(int pos)
{
    if(pos==1)
    delete_node_from_first_position();
    else if(pos==count_node())
    delete_node_from_last_position();
    else
    {
        NODE *trav=head;
        NODE *node=NULL;
        int i=1;
        while(i<pos-1)
        {
            i++;
            trav=trav->next;
        }
        node=trav->next;
        trav->next=trav->next->next;
        free(node);
    }
printf("SUCCESSFULLY DELETED \n");
}











