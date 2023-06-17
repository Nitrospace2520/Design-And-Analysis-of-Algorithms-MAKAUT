#include<bits/stdc++.h>
using namespace std;
int graph[10][10];
int V = 10;
void readGraph(){
    fstream infile;
    infile.open("graph.txt", ios::in);
    if (!infile)
    {
        cout<<"File open operation failed\n";
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
        cout<<"\n";
    }
    cout<<endl;
}
void printDistFromSource(int dist[]){
    for (int i = 0; i < V; i++)
    {
        cout<<i<<" distance from source "<<dist[i]<<"\n";
    }
}
int minKey(int dist[], bool sptSet[]){
    int min_index = -1, min = INT_MAX;
    for (int i = 0; i < V; i++)
    {
        if(sptSet[i] == false && dist[i] <= min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}
void djikstraAlgo(int s){
    bool sptSet[V]; // shortest path tree
    int dist[V];
    for (int i = 0; i < V; i++)
    {   
        sptSet[i] = false;
        dist[i] = INT_MAX;
    }
    dist[s] = 0;
    for (int i = 0; i < V-1; i++)
    {
        int u = minKey(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if(sptSet[v] == false && graph[u][v] != 0 && (dist[u] != INT_MAX) && (dist[v] > (dist[u] + graph[u][v]))){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printDistFromSource(dist);
}
int main(){
    readGraph();
    printGraph();
    djikstraAlgo(0);
    return 0;
}