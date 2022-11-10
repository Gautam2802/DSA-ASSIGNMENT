//NAME-Gautam Singal
//SID-21104078
//BRANCH-EE

#include <iostream>
using namespace std;
//PERFORMING BUBBLE SORT
//Swap 2 adjacent elements continously if these are in wrong order
void swap(int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
 
// A function to implement bubble sort
void bubblesort(int array[], int size)
{

    for (int i = 0; i < size - 1; i++)
 
        // Last i elements are already in place
        for (int j = 0; j < size - i - 1; j++)
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
}


int main(){
    int dataset[]={45,5,11,150,2,1};
    int size=sizeof(dataset)/sizeof(dataset[0]);
    bubblesort(dataset,size);
    for (int i = 0; i < size; ++i)
    {
        cout<< "  " <<dataset[i];
    }
    
    
}
