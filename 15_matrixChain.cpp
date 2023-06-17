#include<bits/stdc++.h>
using namespace std;
// int n = 10;
// int p[10] ;
int M[20][20] = {0};
int S[20][20] = {0};
void matrixChainMultipication(int p[], int n){
    n = n-1;
    for (int i = 1; i <= n; i++)
    {
        M[i][i] = 0;
    }
    
    for(int len = 2; len <= n; len++){
        for(int i=1; i<= n -len +1; i++){
            int j= i +len -1;
            M[i][j] = INT_MAX;
            for (int k = i; k <= j -1 ; k++)
            {
                int cost = M[i][k] + M[k+1][j] + (p[i-1] * p[j] * p[k]);
                if(cost < M[i][j]){
                    M[i][j] = cost;
                    S[i][j] = k;
                }
            }
        }
    }
    cout<<"S - table"<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout<<S[i][j]<<"  ";
        }
        cout<<"\n";
    }
    cout<<endl;
}
void printOptimalParentiss(int i, int j){
    if(i == j){
        cout<<" A"<<i;
    }else {
        cout<<"( ";
        printOptimalParentiss(i, S[i][j]);
        printOptimalParentiss(S[i][j] +1, j);
        cout<<" )";
    }
}
int main(){
    int n = 8;
    int p[n] = {2, 3, 5, 2, 4, 3, 5, 2};
    matrixChainMultipication(p, n);
    printOptimalParentiss(1, n-1);

    return 0;

}