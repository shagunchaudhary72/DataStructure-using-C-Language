#include<stdio.h>
int binary_search(int array[],int size);
int key;
int comparisons=0;
int main(void)
{
    int size;
    printf("Enter counting of numbers : ");
    scanf("%d",&size);
    int array[size];
    printf("Enter all the numbers : ");
    for(int index=0;index<size;index++)
    {
        scanf("%d",&array[index]);
    }
    if(binary_search(array,size))
    printf("%d has found \nTotal number of comparisons : %d",key,comparisons);
    else
    {
        printf("%d has not found \nTotal number of comparisons : %d",key,comparisons);
    }
    
}
int binary_search(int array[],int size)
{
    int left=0;
    int right=size-1;
    printf("Enter number for search : ");
    scanf("%d",&key);
    while(left<=right)
    {
        comparisons++;
        int middle=(left+right)/2;
        if(key==array[middle])
        return 1;
        else if(key>middle)
        {
            left=middle+1;
        }
        else 
        {
            right=middle-1;
        }
        
    }

    
    return 0;
}