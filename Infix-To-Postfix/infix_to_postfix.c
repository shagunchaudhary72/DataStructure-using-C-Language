#include<stdio.h>
#include<stdlib.h>

#define size 10

typedef struct
{
    int arr[size];
    int top;
}stack;

enum{EXIT,PUSH,POP,PEEK,INFIX_TO_POSTFIX};

int menu(void);
int is_stack_full(stack *ps);
void push_into_stack(stack *ps,int element);
int is_stack_empty(stack *ps);
int peek_element(stack *ps);
void pop_element(stack *ps);
void top_in_stack(stack *ps);
void infix_to_postfix(char *infix,char *postfix);
int is_operand(char ch);
int element_priority(char opr);


int main(void)
{
    int n;
    printf("*****INFIX TO POSTFIX CONVERSION*****\n");
    printf("Enter size of INFIX and POSTFIX  : ");
    scanf("%d",&n);
    char infix[n];
    char postfix[n];
    printf("Enter INFIX Expression  :  ");
    scanf("%s",&infix);
    infix_to_postfix(infix,postfix);
    printf("POSTFIX Expression :  %s",postfix);
    return 0;

}

//checking priority of element
int element_priority(char opr)
{
    
    switch(opr)
    {
        case '+':
        case '-':
                return 1;
        case '*':
        case '%':
        case '/':
                return 2;
    }
}

//checking for operand
int is_operand(char ch)
{
    if((ch>64 && ch<91)||(ch>96 && ch<123)||(ch>47 && ch<58))
    return 1;
    else 
    return 0;
}

//infix to postfix expression
void infix_to_postfix(char *infix,char *postfix)
{
    stack s;
    top_in_stack(&s);
    int i;
    int j=0;
    for(i=0;infix[i]!='\0';i++)
    {
        if(is_operand(infix[i]))
        {
            postfix[j]=infix[i];
            j++;
        }
        else
        {
            while((!is_stack_empty(&s))&&(element_priority(peek_element(&s))>=element_priority(infix[i])))
            {
                postfix[j]=peek_element(&s);
                j++;
                pop_element(&s);
            }
            push_into_stack(&s,infix[i]);
        }

    }
    while(!is_stack_empty(&s))
    {
        postfix[j]=peek_element(&s);
        j++;
        pop_element(&s);
    }
    postfix[j]='\0';
}


//in it stack
void top_in_stack(stack *ps)
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