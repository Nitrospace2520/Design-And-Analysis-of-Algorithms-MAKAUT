/* #include<bits/stdc++.h>
using namespace std;
int graph[10][10];
int V = 10;
void readGraph(){
    fstream infile;
    infile.open("graph.txt", ios::in);
    if(!infile){
        cout<<"File open failed"<<endl;
        exit(0);
    }
    infile>>V;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            infile>>graph[i][j];
        }
    }
    infile.close();
}
void printGraph(){
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }
}
int extractMin(bool mSet[], int key[]){
    int min_index, min = INT_MAX;
    for (int i = 0; i < V; i++)
    {
        if((mSet[i] == false) && (min > key[i])){
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}
void primAlgo(){
    int key[V] = {INT_MAX};
    bool mSet[V] = {false};
    int parent[V] = {-1};
    parent[0] = -1;
    int res = 0;
    key[0] = 0;
    for (int i = 0; i < V-1; i++)
    {
        int u = extractMin(mSet, key);
        mSet[u] = true;
        res = res + key[u];
        for (int v = 0; v < V; v++)
        {
            if((graph[u][v] != 0) && (!mSet[v]) && (key[v] > graph[u][v])){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    cout<<endl<<endl;
    // for (int i = 0; i < V; i++)
    // {
    //     cout<<key[i]<<"  ";
    // }
    // cout<<endl<<res<<endl;
    for (int i = 1; i < V; i++)
    {
        cout<<parent[i] <<"  "<<i<<"\t"<<graph[i][parent[i]]<<endl;
    }
    

}
int main(){
    readGraph();
    printGraph();
    primAlgo();
    return 0;
} */

#include <bits/stdc++.h>
using namespace std;

int graph[10][10];
int V=10;
void readGraph(){
    fstream infile;
    infile.open("graph.txt", ios:: in);
    if(!infile){
        cout<<"File open operation failed"<<endl;
        return;
    }
    infile>>V;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            infile>>graph[i][j];
        }
    }
    infile.close();
}
void printGraph(){
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout<<graph[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void printMST(int parent[]){
    cout<<"EDGE  \t Weight\n";
    int cost =0;
    for (int i = 1; i < V; i++)
    {
        cout<<parent[i]<<" - "<<i<<" \t "<<graph[i][parent[i]]<<endl;
        cost += graph[i][parent[i]];
    }
    cout<<"Cost : "<<cost;
    cout<<endl;
}
int extractMin(int key[], bool mstSet[]){
    int min_Index, min = INT_MAX;
    for (int i = 0; i < V; i++)
    {
        if(mstSet[i] == false && key[i] < min){
            min = key[i];
            min_Index = i;
        }
    }
    return min_Index;
}
void primsAlgo(){
    int key[V];
    int parent[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mstSet[i] = false;
    }
    parent[0] = -1;
    key[0] = 0;
    for (int i = 0; i < V; i++)
    {
        int u = extractMin(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if(mstSet[v] == false && graph[u][v] != 0 && key[v] > graph[u][v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
        
    }
    printMST(parent);
}
int main(){
    readGraph();
    printGraph();
    primsAlgo();

    return 0;
}