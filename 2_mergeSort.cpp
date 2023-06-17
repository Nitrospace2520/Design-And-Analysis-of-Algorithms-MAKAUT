#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end){
    /* //*Method : 01 
    int n = end - start +1;
    int *temp = new int[n];
    int i = start;
    int j = mid+1;
    int k=0;
    while (i<= mid && j<= end)
    {
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= end)
    {
        temp[k++] = arr[j++];
    }
    for ( i = 0, j = start; i < n; i++, j++)
    {
        arr[j] = temp[i];
    }
    delete [] temp;
    */
    //* Method: 02
    int n1 = mid - start +1;
    int n2 = end - mid;
    int *temp1 = new int[n1];
    int *temp2 = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        temp1[i] = arr[start +i];
    }
    for (int i = 0; i < n2; i++)
    {
        temp2[i] = arr[mid+1 +i];
    }
    int i = 0;
    int j = 0;
    int k = start;
    while (i<n1 && j<n2)
    {
        if(temp1[i] <= temp2[j]){
            arr[k++] = temp1[i++];
        }else{
            arr[k++] = temp2[j++];
        }
    }
    while (i<n1)
    {
        arr[k++] = temp1[i++];
    }
    while (j < n2)
    {
        arr[k++] = temp2[j++];
    }
    
    delete [] temp1;
    delete [] temp2;
}

void mergeSort(int arr[], int start, int end){
    if(start < end){
        int mid = start + (end - start)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}
int main(){
    int arr[] = {9, 2, 3, 10, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<"  ";
    }cout<<endl;
    
    return 0;
}