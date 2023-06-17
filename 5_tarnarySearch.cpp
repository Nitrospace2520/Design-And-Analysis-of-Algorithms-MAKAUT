#include<bits/stdc++.h>
using namespace std;
int ternarySearchRec(int arr[], int start, int end, int target){
    if(start > end)
        return -1;
    int mid1 = start + (end - start)/3;
    int mid2 = end - (end - start)/3;
    if(arr[mid1] == target)
        return mid1;
    else if(arr[mid2] == target)
        return mid2;
    else if(arr[mid1] > target)
        return ternarySearchRec(arr, start, mid1-1, target);
    else if(arr[mid2] < target)
        return ternarySearchRec(arr, mid2+1, end, target);
    else    
        return ternarySearchRec(arr, mid1+1, mid2-1, target);
}
int ternarySearchIter(int arr[], int start , int end, int target){
    while (start <= end)
    {
        int mid1 = start + (end - start)/3;
        int mid2 = end - (end - start)/3;
        if(arr[mid1] == target)
            return mid1;
        if(arr[mid2] == target)
            return mid2;
        else if(arr[mid1] > target)
            end = mid1 -1;
        else if(arr[mid2] < target)
            start = mid2 +1;
        else{
            start = mid1 +1;
            end = mid2 -1;
        }
    }
    return -1;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 7;
    cout<<ternarySearchIter(arr, 0, n-1, target);
    cout<<endl<<ternarySearchRec(arr, 0, n-1, target);

    return 0;
}