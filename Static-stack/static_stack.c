#include<stdio.h>
#include<stdlib.h>

#define size 5

typedef struct
{
    int arr[size];
    int top;
}stack;

enum{EXIT,PUSH,POP,PEEK};

int menu(void);
int is_stack_full(stack *ps);
void push_into_stack(stack *ps,int element);
int is_stack_empty(stack *ps);
int peek_element(stack *ps);
void pop_element(stack *ps);
void in_it_stack(stack *ps);

int main(void)
{
    stack s;
    int ele;
    int choice;
    in_it_stack(&s);
    printf("****STATIC STACK****\n");
    do
    {
        choice=menu();
        switch(choice)
        {
            case EXIT:
                break;
            case PUSH:
                if(is_stack_full(&s))
                {
                    printf("Enter Element : ");
                    scanf("%d",&ele);
                    push_into_stack(&s,ele);
                }
                else
                {
                    printf("*****Stack OverFlow !!!*****\n");
                }
                break;
            case POP:
                if(is_stack_empty(&s))
                {
                    printf("****Stack UnderFlow !!!****\n");
                }
                else
                {
                    ele=peek_element(&s);
                    pop_element(&s);
                    printf("POPPED Element is : %d\n",ele);
                }
                break;
            case PEEK:
                if(is_stack_empty(&s))
                {
                    printf("****Stack Underflow****\n");
                }
                else
                {
                    ele=peek_element(&s);
                    printf("Top Element : %d\n",ele);
                }
                break;
                default:
                break;

        }
    } while (choice!=0);
    
}

//menu
int menu(void)
{   
    int choice;
    printf(" 0. EXIT\n 1. PUSH\n 2. POP\n 3. PEEK\n");
    printf("Enter choice : ");
    scanf("%d",&choice);
    return choice;
}

//in it stack
void in_it_stack(stack *ps)
{
    ps->top=-1;
}

//is stack full
int is_stack_full(stack *ps)
{
    if(ps->top==size-1)
    {
        return 0;
    }
    else
    return 1;
}

//push element into stack
void push_into_stack(stack *ps ,int element)
{
    ps->top++;
    ps->arr[ps->top]=element;
    printf("Element PUSHED Successfully \n");

}

//is stack empty
int is_stack_empty(stack *ps)
{
    if(ps->top==-1)
    {
        return 1; 
    }
    return 0;
}

//peek element
int peek_element(stack *ps)
{
    return ps->arr[ps->top];
}

//pop element
void pop_element(stack *ps)
{
    ps->top--;
    
}