#include <bits/stdc++.h>
using namespace std;
int graph[10][10];
int V = 10;
int E = 10;
struct Edge{
    int src, dest, weight;
};

struct Graph{
    Edge *edge;
    Graph(){
        this->edge = new Edge[E];
    }
    void intialised(){
        int count = 0 ;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if(graph[i][j] != 0){
                    edge[count].src = i;
                    edge[count].dest = j;
                    edge[count].weight = graph[i][j];
                    count++;
                }
            }
        }
    }
};
void readGraph(){
    fstream infile;
    infile.open("graph.txt", ios::in);
    if (!infile)
    {
        cout<<"File opened operation failed\n";
        exit(0);
    }
    infile>>V;
    int count = 0 ;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            infile>>graph[i][j];
            if(graph[i][j] != 0)
                count++;
        }
    }
    infile.close();
    E = count;
}
void printGraph(){
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout<<graph[i][j]<<"  ";
            if(graph[i][j] != 0){
            }
        }
        cout<<"\n";
    }
    cout<<endl;
}
void printDist(int dist[]){
    for (int i = 0; i < V; i++)
    {
        cout<<(char)(i +'A')<<" distance from source "<<dist[i]<<"\n";
    }
}

void bellmanFordAlgorithm(Graph *g, int src){
    int dist[V] ;
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    for (int i = 1; i  <= V-1; i++)
    {
        for (int j = 0; j < E ; j++)
        {
            int u = g->edge[j].src;
            int v = g->edge[j].dest;
            int w = g->edge[j].weight;
            if(dist[u] != INT_MAX && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
            }
        }
    }
    for (int i = 0; i < E; i++)
    {
        int u = g->edge[i].src;
        int v = g->edge[i].dest;
        int w = g->edge[i].weight;
        if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
            cout<<"Graph contains negative weight cycle\n";
        }
    }
    
    printDist(dist);
}
int main(){
    readGraph();
    // Edge** edge = new Edge*[E];
    printGraph();
    Graph *g = new Graph();
    g->intialised();
    bellmanFordAlgorithm(g, 0);
    return 0;
}

/* 
void printMST(int parent[]){
    for (int i = 1; i < V; i++)
    {
        cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]]<<"\n";
    }
}
void printDist(int dist[]){
    for (int i = 0; i < V; i++)
    {
        cout<<i<<" distance from source "<<dist[i]<<"\n";
    }
}

int minKey(int key[], bool mstSet[]){
    int min_index = -1, min = INT_MAX;
    for (int i = 0; i < V; i++)
    {
        if(mstSet[i] == false && min>key[i]){
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}
void dijkstraAlgo(int src){
    int dist[V];
    bool sptSet[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int i = 0; i < V; i++)
    {
        int u = minKey(dist, sptSet);
        sptSet[u] = true;
        for (int j = 0; j < V; j++)
        {
            if (sptSet[j] == false && graph[u][j] != 0 && (dist[j] > dist[u] + graph[u][j]))
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
    printDist(dist);
}
void primsAlgo(){
    int key[V], parent[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        parent[i] = -1;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V; count++)
    {
        int u = minKey(key, mstSet);
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
} */