#include <bits/stdc++.h>
using namespace std;
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
// Lamuto's Partition:-
int paritition1(int arr[], int start, int end){
    int pivot = arr[end];
    int left = start -1;
    for (int i = start; i <= end; i++)
    {
        if(arr[i] < pivot){
            left++;
            swap(arr, left, i);
        }
    }
    left++;
    swap(arr, left, end);
    return left;
}

// Hoare's Partition:-
int paritition2(int arr[], int start, int end){
    int pivot = arr[start];
    int left = start -1;
    int right = end + 1;
    while (true)
    {
        do
        {
            left++; 
        } while (arr[left] < pivot);
        do
        {
            right--;
        } while (arr[right] > pivot);
        if(left >= right)
            return right;
        
        swap(arr, left, right);
    }
    //return right;
}
// Randomised Pivotindex :-
int partition3(int arr[], int start, int end){
    // srand(time(NULL));
    int pivotInd = start + ( rand() % (end - start));
    swap(arr, start, pivotInd);
    return paritition2(arr, start, end); // calling hoare's partition
}

// For Lamuto's Partition:-
void quickSort1(int arr[], int start, int end){
    if(start < end){
        int pivotIndex = paritition1(arr, start, end);
        quickSort1(arr, start, pivotIndex-1);
        quickSort1(arr, pivotIndex +1, end);
    }
}

// For Hoare's Partition:-
void quickSort2(int arr[], int start, int end){
    if(start < end){
        int pivotIndex = paritition2(arr, start, end);
        quickSort2(arr, start, pivotIndex);
        quickSort2(arr, pivotIndex +1, end);
    }
}

// For Randomised selected Pivot-Index:-
void quickSort3(int arr[], int start, int end){
    if(start < end){
        int pivotIndex = partition3(arr, start, end);
        quickSort3(arr, start, pivotIndex);
        quickSort3(arr, pivotIndex +1, end);
    }
}

int main(){
    int n;
    cout<<"Enter the size of the arrary: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int choice;
    cout<<"Enter 1 for Lamuto Partition"<<endl;
    cout<<"Enter 2 for Hoare Partition"<<endl;
    cout<<"Enter 3 for Random selected Pivot Index"<<endl;
    cout<<"Enter the choice for Quick Sort: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        quickSort1(arr, 0, n-1);
        break;
    case 2:
        quickSort2(arr, 0, n-1);
        break;
    case 3:
        quickSort3(arr, 0, n-1);
        break;
    default:
        break;
    }   
    
    cout<<"After quick sort implementation, the sorted array will be:"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    return 0;    
}