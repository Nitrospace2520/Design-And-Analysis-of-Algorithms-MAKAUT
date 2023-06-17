#include <bits/stdc++.h>
using namespace std;

int graph[10][10];
int V = 10;
int E = 10;
struct Edge
{
    int src, dest, weight;
};
void readGraph(){
    fstream infile;
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
            if(graph[i][j] != 0){
                count++;
            }
        }
    }
    infile.close();
    E = count;
}
void initial(Edge *edge){
    int count = 0 ;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if(graph[i][j] != 0){
                edge[count].src = i;
                edge[count].dest = j;
                edge[count++].weight = graph[i][j];
            }
        }
        
    }
}
void sortEdges(Edge *edge){
    for (int i = 0; i < E-1; i++)
    {
        int flag = true;
        for (int j = 0; j < E- i -1; j++)
        {
            if (edge[j].weight > edge[j+1].weight )
            {
                Edge temp = edge[j];
                edge[j] = edge[j+1];
                edge[j+1] = temp;
                flag = false;
            }
        }
        if(flag)
            return;
    }
}
int find(int parent[], int index){
    while (parent[index] > 0)
    {
        index = parent[index];
    }
    return index;
}
void unionn(int parent[], int i, int j){
    int u = find(parent, i);
    int v = find(parent, j);
    parent[u] = v;
}
void displaySpanningTree(int spanning[][3], int nEdges){
    for (int i = 0; i < nEdges; i++)
    {
        cout<<(char)(spanning[i][0] + 'A')<<" - "<<(char)(spanning[i][1] + 'A')<<" -> "<<spanning[i][2]<<"\n";
    }
    
}
void kruskalAlgo(Edge *edge){
    sortEdges(edge);
    int parent[V] ;
    int spanning[V][3];
    int nEdges = 0;
    for (int i = 0; i < V; i++)
    {
        parent[i] = -1;
    }
    for (int i = 0; i < E; i++)
    {
        if(find(parent, edge[i].src) != find(parent, edge[i].dest)){
            spanning[nEdges][0] = edge[i].src;
            spanning[nEdges][1] = edge[i].dest;
            spanning[nEdges++][2] = edge[i].weight;
            unionn(parent, edge[i].src, edge[i].dest);
        }
    }
    displaySpanningTree(spanning, nEdges);
}
int main(){
    readGraph();
    Edge *edge = new Edge[E];
    initial(edge);
    kruskalAlgo(edge);
    return 0;
}

/*
#include <iostream>
#include<stdio.h>
using namespace std;

struct Edge{
	int vertex1;
	int vertex2;
	int weight;
};
struct Edge Elist[100];
//struct Edge Elist[9]={{0,1,7},{0,2,8},{1,2,3},{1,3,6},{2,3,4},{2,4,3},{3,5,5},{4,5,2},{3,4,2}};
int nov;
int noe=0;
void readGraph(){
	FILE *fp;
	fp=fopen("Graph.txt","r");
	if(fp==NULL){
		cout<<"file open failed"<<endl;
		return;
	}
	fscanf(fp,"%d",&nov);
	for(int i=0;i<nov;i++){
		for(int j=0;j<=i;j++){
			int x;
			fscanf(fp,"%d",&x);
			if(x!=0){
				Elist[noe].vertex1=j;
				Elist[noe].vertex2=i;
				Elist[noe++].weight=x;
			}
		}
	}
	fclose(fp);
}




void Sort(){
	for(int i=0;i<noe-1;i++){
		for(int j=0;j<noe-i-1;j++){
			if(Elist[j].weight>Elist[j+1].weight){
				struct Edge temp=Elist[j];
				Elist[j]=Elist[j+1];
				Elist[j+1]=temp;
			}
		}
	}
}

void displayGraph(){
	for(int i=0;i<noe;i++){
		printf("(%c,%c)->%d\n",Elist[i].vertex1+'A',Elist[i].vertex2+'A',Elist[i].weight);
	}
}

int parent[100];
int nEdge=0;
int spanning[100][3];

int find(int i){
	while(parent[i]>0)i=parent[i];
	return i;
}

void SimpleUnion(int i,int j){
	int u=find(i);
	int v=find(j);
	parent[u]=v;
}

void displayParent(){
	for(int i=0;i<nov;i++){
		printf("%4d",parent[i]);
	}
	printf("\n");
}

void Kruskal(){
	Sort();
	printf("\n\n");
	displayGraph();
	for(int i=0;i<nov;i++) parent[i]=-1;
	
	for(int i=0;i<noe;i++){
		//displayParent();
		if(find(Elist[i].vertex1)!=find(Elist[i].vertex2)){
			spanning[nEdge][0]=Elist[i].vertex1;
			spanning[nEdge][1]=Elist[i].vertex2;
			spanning[nEdge++][2]=Elist[i].weight;
			SimpleUnion(Elist[i].vertex1,Elist[i].vertex2);			
		}
	}	
}

void displaySpanning(){
	for(int i=0;i<nEdge;i++){
		printf("(%c,%c)->%d\n",spanning[i][0]+'A',spanning[i][1]+'A',spanning[i][2]);
	}
}

int main(){
	readGraph();
	displayGraph();
	Kruskal();
	printf("\n\n");
	displaySpanning();
	return 0;
}

*/