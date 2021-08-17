#include<stdio.h>
int array_sum(int size);
int main(void)
{
    int size;
    printf("How many numbers : ");
    scanf("%d",&size);
    printf("Sum of numbers:  %d",array_sum(size));
    return 0;

}
int array_sum(int size)
{
    int array[size];
    int sum=0;
    int index;
    printf("Enter numbers : ");
    for(index=0;index<size;index++)
    {
        scanf("%d",&array[index]);
    }
    for(index=0;index<size;index++)
    {
        sum+=array[index];
    }
    return sum;
}