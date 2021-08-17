#include<stdio.h>
#define swap(a,b) {int temp=b;b=a;a=temp;};
int size;
void bubble_sort(int array[]);
int main()
{
    
    int index;
    printf("Enter total number of elements : ");
    scanf("%d",&size);
    int array[size];
    printf("Enter elements of array : ");
    for(index=0;index<size;index++)
    {
        scanf("%d",&array[index]);
    }
    printf("Array before Sorting : ");
    for(index=0;index<size;index++)
    {
        printf("%d  ",array[index]);

    }
    bubble_sort(array);
    printf("\nElements of array after Sorting : ");
    for(index=0;index<size;index++)
    {
        printf("%d  ",array[index]);
    }
return 0;
}
void bubble_sort(int array[])
{
    int iterations=0;
    int comparisons=0;
    int itr;
    int position;
    int flag=1;
    for(itr=0;(itr<size-1) && (flag==1);itr++)
    {  
        iterations++;
        flag=0; 
        for(position=0;position<size-1-itr;position++)
        { comparisons++;
            if(array[position]>array[position+1])
            {
            swap(array[position],array[position+1]);
            flag=1;
            }
            
        }
    }
    printf("\nTotal number of comparisions : %d",comparisons);
    printf("\nTotal number of iterations : %d",iterations);
}