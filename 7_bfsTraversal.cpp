/*
#include<iostream>
#include<fstream>
#include<limits.h>
using namespace std;
const int V = 6;
/* class Queue
{
public:
    int *arr;
    int size;
    int front, rear;
    Queue(int size){
        this->size = size;
        this->arr = new int[size];
        front = -1;
        rear = -1;
    }
    ~Queue(){
        delete [] arr;
    }
    bool empty(){
        return (rear == front && front == -1);
    }
    int front(){
        if(front != -1){
            return arr[front];
        }
        return INT_MIN;
    }
    void pop(){
        if(front == -1)
            return;
        front = front+1;
        return ;
    }
    void push(int val){
        if(size == rear -1){
            return;
        }
        rear = rear +1;
        arr[rear] = val;
        if(front == -1)
            front = 0 ;
        return;
    }
};
 **
void bfs(int adjM[][V], int start){
    bool visited[V] = {false};
    /*  //?  ERROR!
    Queue *q = new Queue(V+1);
    q->push(adjM[0][0]);
    visited[0] = true;
    while (!q->empty())
    {
        int u = q->front();
        q->pop();
        for (int i=0; i< u; i++ )
        {
            if(visited[] == false){
                visited[]
            }
        }
        
    } **
    int queue[V+1], rear = -1, front = -1;
    visited[start] = true;
    front++;
    queue[++rear] = start;
    while (front <= rear)
    {
        start = queue[front++];
        cout<<start<<"  ";
        for (int i = 0; i < V; i++)
        {
            if(adjM[start][i] == 1 && visited[i] == false){
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}
int main(){
    fstream infile;
    infile.open("graph.txt", ios::in);
    if (!infile)
    {
        cout<<"File open operation failed\n";
        return 0;
    }
    // infile>>V;
    int adjM[V][V] = {{0}};
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            infile>>adjM[i][j];
        }
    }
    bfs(adjM, 0);
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int graph[10][10];
int V= 10;
class Queue
{
private:
    int frnt, rear, *queue, size, CAP;
public:
    Queue();
    ~Queue();
    void enQueue(int val){
        if(rear == CAP-1)
            return ;
        rear++;
        size++;
        if(frnt == -1)
            frnt = 0;
        queue[rear] = val;
    }
    void deQueue(){
        if(frnt == -1)
            return;
        frnt++;
        size--;
    }
    bool isEmpty(){
        return (size == 0);
    }
    int front(){
        if(frnt == -1)
            return -999;
        return queue[frnt];
    }
};
Queue::Queue()
{
    this->size = 0;
    this->CAP = V+1;
    this->frnt = -1;
    this->rear = -1;
    this->queue = new int[V+1];
}
Queue::~Queue()
{
    delete []  queue;
}

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

void bfsIter(int src){
    bool visited[V+1] ;
    fill(visited, visited+V+1, false);
    Queue *qu = new Queue();
    qu->enQueue(src);
    visited[src] = true;
    while (!qu->isEmpty())
    {
        int u1 = qu->front();
        qu->deQueue();
        cout<<u1<<"  ";
        for (int v = 0; v < V; v++)
        {
            if (visited[v] == false && graph[u1][v] > 0)  
            {
                visited[v] = true;
                qu->enQueue(v);
            }
        }
    }
}
int main(){
    readGraph();
    printGraph();
    bfsIter(1);
    return 0;
}