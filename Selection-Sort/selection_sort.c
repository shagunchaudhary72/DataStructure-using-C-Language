#include<stdio.h>
int selection_sort(int array[],int size);
#define swap(a,b) {int temp=b;b=a;a=temp;};
int main(void)
{
    int index;
    int size;
    printf("Enter size of array :");
    scanf("%d",&size);
    int array[size];
    printf("Enter elements  for sorting : ");
    for( index=0;index<size;index++)
    {
        scanf("%d",&array[index]);
    }
    printf("Array elements before sorting : ");
    for(index=0;index<size;index++)
    {
        printf("%d\t",array[index]);

    }
    selection_sort(array,size);
    printf("\nArray elements after Sorting : ");
    for(index=0;index<size;index++)
    {
        printf("\t%d",array[index]);
    }
    return 0;

}
int selection_sort(int array[],int size)
{
    int iterations=0;
    int comparisons=0;
    int position;
    int select_position;
    
    for(select_position=0;select_position<size-1;select_position++)
    {   iterations++;
        for(position=select_position+1;position<size;position++)
        {
            comparisons++;
            if(array[select_position]>array[position])
            {
                swap(array[select_position],array[position]);
            }
        }

    }
    printf("\nTotal number of iterations : %d ",iterations);
    printf("\nTotal number of Comparisons : %d ",comparisons);
}
