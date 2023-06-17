#include <bits/stdc++.h>
using namespace std;
int graph[10][10];
int V = 10;
int E = 10;
struct Edge
{
    int src, dest, weight;
};
void initial(Edge *edge){
    int count = 0;
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
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
void readGraph(){
    fstream infile;
    infile.open("graph.txt", ios::in);
    if (!infile)
    {
        cout<<"File open operation failed\n";
        exit(0);
    }
    infile>>V;
    int count =0;
    for (int i = 1; i <= V; i++)
    {
        for (int j = 1; j <= V; j++)
        {
            infile>>graph[i][j];
            if(graph[i][j] != 0)
                count++;
        }
    }
    infile.close();
    E = count;
}
void printColors(int color[]){
    for (int i = 1; i <= V; i++)
    {
        cout<<"C"<<color[i]<<"  ";
    }
    cout<<endl;
}
void nextValue(int color[], int col, int index){
    while (true)
    {
        color[index] = (color[index] +1)%(col +1);
        if(color[index] == 0)
            return;
        int i=1;
        for (i=1; i <= index -1; i++)
        {
            if(graph[i][index] == 1 && color[i] == color[index])
                break;
        }
        if(i == index)
            return;
    }
}
void mColoring(int index, int col, int color[], int &solution){
    while (true)
    {
        nextValue(color, col, index);
        if(color[index] == 0)
            return;
        if(index == V){
            solution++;
            printColors(color);
        }
        else{
            mColoring(index+1, col, color, solution);
        }
    }
}
int main(){
    readGraph();
    int col = 2;
    Edge *edge = new Edge[E];
    initial(edge);
    int index = 1;
    int color[V] ;
    for (int i = 1; i <= V; i++)
    {
        color[i] = 0;
    }
    int solution = 0;
    mColoring(index, col, color, solution);
    cout<<endl<<"The no of solution :"<<solution;
    return 0;
}

/*
9 
0 4 8 0 0 0 0 0 0
4 0 11 8 0 0 0 0 0
8 11 0 0 7 1 0 0 0
0 8 0 0 2 0 7 4 0
0 0 7 2 0 6 0 0 0
0 0 1 0 6 0 0 2 0
0 0 0 7 0 0 0 14 9
0 0 0 4 0 2 14 0 10
0 0 0 0 0 0 9 10 0

* */
/* 
#include<bits/stdc++.h>
using namespace std;

int x[10];
/*
int n=4,col=2;
int G[5][5]={ 0, 0, 0, 0, 0,
						0, 0, 1, 0, 1,
						0, 1, 0, 1, 0,
						0, 0, 1, 0, 1,
						0, 1, 0, 1, 0};

*

int n,col;
int G[10][10];

void readGraph() {
	FILE *fp;
	fp=fopen("graph.txt","r");
	if(fp==NULL) {
		cout<<"File openning error"<<endl;
		return ;
	}
	fscanf(fp,"%d",&n);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			fscanf(fp,"%d",&G[i][j]);
		}
	}
}

void displayGraph() {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			printf("%-3d",G[i][j]);
		}
		cout<<endl;
	}
}

void displaySoln(int x[]) {
	for(int i=1;i<=n;i++)
		cout<<"C"<<x[i]<<"  ";
	cout<<endl;
}

void nextValue(int k) {
	int j;
	while(true) {
		x[k]=(x[k]+1)%(col+1);
		if(x[k]==0)
			return;
		for(j=1;j<=k-1;j++) {
			if(G[j][k]==1 && x[j]==x[k])
				break;
		}
		if(j==k)
			return;
	}
}
int c=0;
void mColoring(int k) {
	while(true) {
		nextValue(k);
		if(x[k]==0)
			return;
		if(k==n) {
			c++;
			displaySoln(x);
		}
		else 
			mColoring(k+1);
	}
}

int main() {
	readGraph();
	cout<<"Graph = "<<endl;
	displayGraph();
	cout<<"Enter the number of colors = ";
	cin>>col;
	mColoring(1);
	cout<<"Number of solutions = "<<c<<endl;
	return 0;
}
 */