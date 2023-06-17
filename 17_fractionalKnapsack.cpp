#include<bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
    double ratio;
};
void sortItem(Item *item, int n){
    for (int i = 0; i < n-1; i++)
    {
        bool flag = true;
        for (int j = 0; j < n -i -1; j++)
        {
            if(item[j].ratio < item[j+1].ratio){
                Item temp = item[j];
                item[j] = item[j+1];
                item[j+1] = temp;
                flag = false;
            }
        }
        if(flag)
            return;
    }
}
double fractionalKnapsack(Item *item, int n, int Weight){
    sortItem(item, n);    //? It will sort the item with (profit / weight) ratio
    double maxProfit = 0.0 ;
    for (int i = 0; i < n; i++)
    {
        if(item[i].weight <= Weight){
            maxProfit += item[i].value;
            Weight -= item[i].weight;
            continue;
        }
        maxProfit += Weight*item[i].ratio;
        break;
    }
    return maxProfit;
}
int main(int argc, char const *argv[])
{
    int value[] = {100, 60, 120};
    int weight[] = {20, 10, 30};
    int weightOfBag = 50;
    int n = sizeof(value)/sizeof(value[0]);
    Item *item= new Item[n];
    for (int i = 0; i < n; i++)
    {
        item[i].value = value[i];
        item[i].weight = weight[i];
        item[i].ratio = (double)value[i]/weight[i];
    }
    cout<<fractionalKnapsack(item, n, weightOfBag)<<endl;
    return 0;
}
