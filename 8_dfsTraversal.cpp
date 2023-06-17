#include<bits/stdc++.h>
using namespace std;
int graph[10][10];
int V =10;
class Stack{
    int tp, size, CAP, *stack;
    public:
    Stack(){
        tp = -1;
        size =0;
        CAP = V;
        stack = new int[V];
    }
    ~Stack(){
        delete [] stack;
    }
    bool isEmpty(){
        return size == 0;
    }
    void push(int val){
        if(size == CAP-1)
            return;
        size++;
        tp++;
        stack[tp] = val;
    }
    void pop(){
        if(size == 0)
            return;
        tp--;
        size--;
    }
    int top(){
        if(size == 0)
            return 999;
        return stack[tp];
    }
};

void readGraph(){
    fstream infile;
    infile.open("graph.txt", ios::in);
    if(!infile){
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
        cout<<endl;
    }
    cout<<endl;
}

void dfsRec(bool visited[], int src){
    visited[src] = true;
    cout<<src<<"  ";
    for (int i = 0; i < V; i++)
    {
        if(graph[src][i] != 0 && visited[i] == false){
            dfsRec(visited, i);
        }
    }
}

void dfsIter(bool visited[], int src){
    Stack *st = new Stack();
    visited[src] = true;
    st->push(src);
    while (!st->isEmpty())
    {
        int u = st->top();
        st->pop();
        cout<<u<<"  ";
        for (int i = 0; i < V; i++)
        {
            if(visited[i] == false && graph[u][i] != 0){
                visited[i] = true;
                st->push(i);
            }
        }
        
    }
    
}

int main(){
    readGraph();
    printGraph();
    bool visited[V] ;
    fill(visited, visited+V, false);
    // dfsRec(visited, 0);
    dfsIter(visited, 0);
    return 0;
}