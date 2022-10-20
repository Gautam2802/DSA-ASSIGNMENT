/* ANSWER 1
In-place algorithms are a type of algorithm  that do not require additional space for their operation. 
Additional variables that consume a small amount of nonconstant memory are acceptable. This extra 
space should be less than O(log n), however, below O(n) is sometimes allowed. The opposite of an 
in-place algorithm is an out-of-place algorithm, the simplest solution may be to traverse the 
original list in reverse and construct anotherlist using that data.Once the list is fully traversed,
 the new list is constructed.*/

 //ANSWER 2
 //insertion sort using in-place algorithm
 #include <iostream>
 using namespace std;
 //creating insertion sort using void function
 void ip_insertion_sort(int array[],int size){
    int j; 
    for(int i=1;i<size;i++){
        int temp=array[i];
        j=i-1;
        
        //The elements greater than temp variable are moved to one position ahead from their current position
        while(temp<=array[j] && j>=0){
        array[j+1]=array[j];
        j=j-1;
    }

    array[j+1]=temp;
 }
 return;

 }

 //insertion sort using out_place algorithm
 void op_insertion_sort(int array[],int x,int y){
    //x=starting index
    //y=ending index
    if(x==y)
    {
        return;
        }
    int j=x+1;
    int temp=array[j];
    while(x>=0){
        if(array[x]>temp){
            array[x+1]=array[x];
            x--;
        }
        if(x==-1)
        {
            array[0]=temp;
            break;
            }
        if(array[x]<=temp)
        {
            array[x+1]=temp;
        break;
        }
    }
    op_insertion_sort(array,x+1,y);
}

//function to print an array
void printArray(int array[], int size)
{
   for (int i = 0; i < size; i++)
      cout << array[i] << " ";
   cout << endl;
   }

//Main function
int main()
{
    int size;
    cout<<"Enter the size of an array: ";
    cin>>size;

    int array1[size],array2[size]; //Two array with same size and elements
    cout<<"enter array elements ";
    for(int i=0;i<size;i++)
    {
        cin>>array1[i];
        }
        
        for(int i=0;i<size;i++)
        {
            array2[i]=array1[i]; //copying array1 to array2
            }
            cout<<endl;

    // Before sorting
    cout<<"before sorting : ";
    printArray(array1,size);

    //Calling insertion sort using in-place algorithm.
    ip_insertion_sort(array1,size);
    cout<<endl;
    cout<<"in place sorting array: ";
    printArray(array1,size);
    cout<<endl;
    
    //calling insertion sort using out-place algorithm.
    op_insertion_sort(array2,0,size-1);
    cout<<"out place sorting array: ";
    printArray(array1,size);
    cout<<endl;

    return 0;

} 

//ANSWER 3

/* Out_place algorithm has high space complexity 
and easier appliance but in case of in_place algorithm 
appliance is difficult but space complexity is lesser.

out_place_algorithm are used in merge sort.
in_place_algorithm are used in insertion sort,heap sort,bubble sort.

example-if we take an example to reverse an array using out_place we require one extra
array of same size and copy the elements of original array from back to front of new array.
wheras in in_place algorithm swapping of first and last element takes place till the middle 
position of array.
*/
 