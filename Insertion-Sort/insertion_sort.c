#include<stdio.h>
int size;
void insertion_sort(int array[]);
int main(void)
{
    int index;
    printf("Enter total number of elements : ");
    scanf("%d",&size);
    int array[size];
    printf("Enter the elements of Array : ");
    for( index=0;index<size;index++)
    {
        scanf("%d",&array[index]);
    }
    insertion_sort(array);
    printf("\nArray elements after Sorting : ");
    for(index=0;index<size;index++)
    {
        printf("%d  ",array[index]);
    }
    return 0;
}
void insertion_sort(int array[])
{
    int iterations=0;
    int comparisons=0;
    int select_pos;
    int pos;
    int key;
    for(select_pos=1;select_pos<size;select_pos++)
    {
        key=array[select_pos];
        iterations++;
        pos=select_pos-1;
        while((pos>=0)&&(array[pos]>key) )
        {
            comparisons++;
            array[pos+1]=array[pos];
            pos--;
        }
        array[pos+1]=key;

    }
    printf("\nTotal number of Iterations : %d",iterations);
    
}