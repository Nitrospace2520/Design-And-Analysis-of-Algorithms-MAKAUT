#include<bits/stdc++.h>
using namespace std;
int n = 7;
struct Job
{
    int profit, deadline;
};
void sortJobs(Job *job){
    for (int i = 0; i < n-1; i++)
    {
        bool flag = true;
        for (int j = 0; j < n -i -1; j++)
        {
            if(job[j].profit < job[j+1].profit){        //* sort the Jobs by decreasing order of profit
                Job temp = job[j];
                job[j] = job[j+1];
                job[j+1] = temp;
                flag = false;
            }
        }
        if (flag)
        {
            return ;
        }
    }
}
int maxDeadline(int deadline[]){
    int maxDead = deadline[0];
    for (int i = 1; i < n; i++)
    {
        maxDead = max(maxDead, deadline[i]);
    }
    return maxDead;
}
int maximumProfit(Job *job, int *chart,int len){
    sortJobs(job);       //* sort via profit decreasing order
    int job_profit = 0, count_job =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = job[i].deadline; j > 0; j--)
        {
            if(chart[j] == -1){
                chart[j]= i;
                count_job++;
                job_profit += job[i].profit;
                break;
            }
        }
    }
    cout<<count_job<<endl;
    return job_profit;
}
int main(int argc, char const *argv[])
{
    int profit[] = {3, 5, 20, 18, 1, 6, 30};
    int deadline[] = {1, 3, 4, 3, 2, 1, 2};
    n = sizeof(profit)/sizeof(profit[0]);
    Job *job = new Job[n];
    int len = maxDeadline(deadline);
    int *chart = new int[len+1];
    for(int i=0; i<n; i++){
        job[i].profit = profit[i];
        job[i].deadline = deadline[i];
    }
    for (int i = 0; i <= len; i++)
    {
        chart[i] = -1;
    }
    int maxProfit = maximumProfit(job, chart, len);
    cout<<maxProfit<<endl;
    delete [] job;
    delete [] chart;
    return 0;
}