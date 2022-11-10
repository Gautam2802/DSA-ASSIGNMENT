//NAME-Gautam Singal
//SID-21104078
//BRANCH-EE

#include<iostream>
using namespace std;

//PERFORMING SELECTION SORT
 
//Swap function
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
void selectionsort(int arr[], int size)
{

    // One by one move boundary of unsorted subarray
    for (int i = 0; i < size-1; i++)
    {
       
        // Find the minimum element in unsorted array
        int min = i;
        for (int j = i+1; j < size; j++)
        if (arr[j] < arr[min])
            min = j;
 
        // Swap the found minimum element with the first element
        if(min !=i)
            swap(&arr[min], &arr[i]);
            }
            }


int main(){
    int dataset[]={56,8,11,150,2,1};
    int size=sizeof(dataset)/sizeof(dataset[0]);
    selectionsort(dataset,size);
    for (int i = 0; i < size; i++)
    {
        cout<<" "<<dataset[i];
    }
    
    
}