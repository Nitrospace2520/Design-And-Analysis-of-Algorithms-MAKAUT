#include<bits/stdc++.h>
using namespace std;
int queen[10];
void displayNQueen(int n){
    for (int i = 1; i <= n; i++)
    {
        cout<<queen[i]<<" ";
    }
    cout<<"\n";
}
bool canPlace(int k, int ind){
    for (int j = 1; j <= k-1; j++)
    {
        if (queen[j] == ind || (abs(j - k) == abs(queen[j] - ind)))
        {
            return false;
        }
    }
    return true;
}
void nQueen(int k, int n, int &sol){
    for (int i = 1; i <= n; i++)
    {
        if (canPlace(k, i))
        {
            queen[k] = i;
            if(k == n){
                sol++;
                displayNQueen(n);
            }else
            {
                nQueen(k+1, n, sol);
            }
        }
    }
}

int main(){
    int n=4;
    int sol = 0 ;
    nQueen(1, n, sol);
    cout<<sol<<endl;
    return  0;
}