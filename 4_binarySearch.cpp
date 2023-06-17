#include<bits/stdc++.h>
using namespace std;
int binarySearchRec(int arr[], int start, int end, int target){
    if(start > end)
        return -1;
    int mid = start + (end - start)/2;
    if(arr[mid] == target)
        return mid;
    else if(arr[mid] > target)
        return binarySearchRec(arr, start, mid-1, target);
    else    
        return binarySearchRec(arr, mid+1, end, target);
}
int binarySearchIter(int arr[], int start , int end, int target){
    while (start <= end)
    {
        int mid = start + (end - start)/2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            start = mid +1;
        else
            end = mid -1;
    }
    return -1;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 20;
    cout<<binarySearchIter(arr, 0, n-1, target);
    cout<<endl<<binarySearchRec(arr, 0, n-1, target);

    return 0;
}