
// A STL based C++ program to sort
// a nearly sorted array.

#include <iostream>
#include <queue>
using namespace std;


// Sorting K-sorted/ nearly sorted array
// nLog(k) is the time complexity
// min heap is formed 
void sortK(int arr[],int n,int k)
{
    priority_queue<int,vector<int>, greater<int>> min_heap;
    vector<int> v;
    int j=0;

    for(int i=0;i<n;i++)
    {
        min_heap.push(arr[i]);

        if(min_heap.size()>k)
        {
            arr[j]=min_heap.top();
            min_heap.pop();
            j++;
        }
      
    }

    while(!min_heap.empty())
    {
        arr[j]=min_heap.top();
            min_heap.pop();
            j++;
    }
  
}



void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int k = 3;
    int arr[] = { 29, 6, 3, 12, 56, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Following is original arrayn";
    printArray(arr, n);

    sortK(arr, n, k);
 
    cout << "Following is sorted arrayn";
    printArray(arr, n);
 
    return 0;
}
