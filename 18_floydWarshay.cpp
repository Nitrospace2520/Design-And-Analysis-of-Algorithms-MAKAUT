// #include <bits/stdc++.h>
#include <iostream>
#include<fstream>
using namespace std;

int graph[10][10];
int V = 10;
int E = 10;

void readGraph(){
    fstream infile ;
    infile.open("graph.txt", ios::in);
    if (!infile)
    {
        cout<<"File open operation failed\n";
        exit(0);
    }
    infile>>V;
    int count = 0;
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
int dist[10][10];
int pred[10][10];
void floyd(){
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = graph[i][j];
            if(dist[i][j] == 0 && dist[i][j] == 999){
                pred[i][j] = -1;
            }else{
                pred[i][j] = i;
            }
        }
    }
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] != 999 && dist[k][j] != 999)
                {
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        pred[i][j] = pred[k][j];
                    }
                }
            }
        }
    }
}
void APSP(int i, int j){
    if(i == j)
        cout<<"  "<<(i+1);
    else if(pred[i][j] == -1)
        cout<<"No Path"<<endl;
    else
    {
        APSP(i, pred[i][j]);
        cout<<"  "<<(j+1);
    }
}
int main(){
    readGraph();
    floyd();
    APSP(1, V-1);

    return 0;
}

/*
 *
#include<iostream>
using namespace std;
int w[4][4]={0,999,-2,999,
            4,0,3,999,
            999,999,0,2,
            999,-1,999,0
            };
int n=4;

int dist[10][10];
int pred[10][10];
void Floyd(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=w[i][j];
            if(w[i][j]==0||w[i][j]==999){
                pred[i][j]=-1;
            }
            else pred[i][j]=i;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dist[i][k]!=999 && dist[k][j]!=999){
                    if(dist[i][k]+dist[k][j]<dist[i][j]){
                        dist[i][j]=dist[i][k]+dist[k][j];
                        pred[i][j]=pred[k][j];
                    }
                }
            }
        }
    }
}


void APSP(int i,int j){
    if(i==j) cout<<"    "<<i+1;
    else if(pred[i][j]==-1) cout<<"NO PATH"<<endl;
    else{
        APSP(i,pred[i][j]);
        cout<<"    "<<j+1;
    }
}



int main(){
    Floyd();
    APSP(1,3);
    return 0;
}
*/