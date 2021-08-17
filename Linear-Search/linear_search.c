#include<stdio.h>
int linear_search();
int comparisons=0;
int key;
int main(void)
{
        int val=linear_search();
     if(val)
     printf("%d has found \n Total number of comparisions  : %d ",key,comparisons);
     else
     {
         printf("%d has  not found \n total number of comparisons  :%d",key,comparisons );
     }
      
    return 0;
    
}
int linear_search()
{
    int index;
    int size;
    printf("Enter size :");
    scanf("%d",&size);
    int array[size];
    printf("Enter all the numbers : ");
    for(index=0;index<size;index++)
    {
        scanf("%d",&array[index]);
    }

    printf("Enter number for search : ");
    scanf("%d",&key);

    for(int index=0;index<size;index++)
    {
        comparisons++;
        if(array[index]==key)
        {
            return 1;
        }
    }
    return 0;

}