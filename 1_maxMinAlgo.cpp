#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void max_min(int arr[], int i, int j, int &max, int &min){
    if(i==j){
        max = arr[i];
        min = arr[i];
        return;
    }
    if(i == j-1){
        if(arr[i] > arr[j]){
            max = arr[i];
            min = arr[j];
        }else{
            max = arr[j];
            min = arr[i];
        }
        return;
    }
    else
    {
        int mid = i + (j - i)/2;
        max_min(arr, i, mid, max, min);
        int max1 = max;
        int min1 = min;
        max_min(arr, mid+1, j, max1, min1);
        if(max < max1){
            max = max1;
        }
        if(min > min1){
            min = min1;
        }
    }
    return;
}
int main(){
    int arr[] = {9, 2, 3, 7, 8, 10, 5, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = arr[0];
    int min = arr[0];
    max_min(arr, 0, n-1, max, min);

    cout<<max<<"  "<<min<<endl;
    return 0;
}