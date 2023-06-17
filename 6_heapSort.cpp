#include <bits/stdc++.h>
using namespace std;
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void maxHeapify(int arr[], int n, int ind){
    int larger = ind;
    int left = 2*ind +1;
    int right = 2*ind +2;
    if(left < n && arr[left] > arr[larger])
        larger = left;
    if(right < n && arr[right] > arr[larger])
        larger = right;
    if(larger != ind){
        swap(arr, larger, ind);
        maxHeapify(arr, n, larger);
    }
}
void minHeapify(int arr[], int n, int ind){
    int smaller = ind;
    int left = 2*ind +1;
    int right = 2*ind +2;
    if(left < n && arr[left]<arr[smaller])
        smaller = left;
    if(right <n && arr[right]<arr[smaller])
        smaller = right;
    if(smaller != ind){
        swap(arr, smaller, ind);
        minHeapify(arr, n, smaller);
    }
}
void buildHeap(int arr[], int n){
    for (int i = (n-2)/2; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
        minHeapify(arr, n, i);
    }
}
void maxHeapSort(int arr[], int n){
    buildHeap(arr, n);
    for (int i = n-1; i >= 1; i--)
    {
        swap(arr, i, 0);
        maxHeapify(arr, i, 0);
    }
}
void extractMin(int arr[], int n){               //* For Min-Heapify
    swap(arr, 0, n-1);
    minHeapify(arr, n, 0);
}
void minHeapSort(int arr[], int n){
    buildHeap(arr, n);
    for (int i = n-1; i >= 1; i--)
    {
        swap(arr, i, 0);
        minHeapify(arr, i, 0);
    }
    for (int i = 0; i < n/2; i++)
    {
        swap(arr, i, n-i-1);
    }
}
int main(){
    int arr[] = {9, 4, 5, 7, 2, 3, 1, 8, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    // maxHeapSort(arr, n);
    minHeapSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"  ";
    }cout<<endl;
    extractMin(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"  ";
    }cout<<endl;
    return 0;
}