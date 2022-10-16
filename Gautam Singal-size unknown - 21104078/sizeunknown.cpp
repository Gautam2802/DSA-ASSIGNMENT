#include <iostream>
using namespace std;

int simple_binarySearch(int arr[], int left, int right, int num)
{
    //mid= Middle element
    //left= Starting index 
    //right= Ending index
    if (right >= left)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == num)
            return mid;
        if (arr[mid] > num)
            return simple_binarySearch(arr, left, mid - 1, num);
        return simple_binarySearch(arr, mid + 1, right, num);
    }
    return -1;
    return -1; //-1 When element is not present
}
//Binary search function with unknown length
int unknown_binarysearch(int arr[], int num)
{
    // giving left and right index of an array
    int left = 0, right = 1;

    int count = arr[0];

    while (count < num)
    {
        left = right;
        right = right * 2;
        count = arr[right];
    }

    return simple_binarySearch(arr, left, right, num);
}

int main()
{
    int x;    //Taking size of an array
    cin >> x;

    int arr[x];
    //cout<<"ENTER THE SORTED ARRAY ONLY"<<endl;
    for (int i = 0; i < x; i++)
    {
        cin >> arr[i];
    }

    int num;  //taking input of number that to be found
    cin >> num;

    unknown_binarysearch(arr, num);  //passing array and number without size of an array

    int output = unknown_binarysearch(arr, num);
    if (output == -1)
        cout << "NO match found ";
    else
        cout << "Match found at index position is : " << output;
    return 0;
}