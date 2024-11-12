#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int OptimalMergePattern(vector<int>& files)
{
    int cost=0;
    priority_queue<int,vector<int>,greater<int>> minHeap;

    for(int file:files)
    {
        minHeap.push(file);
    }

    while(minHeap.size()>1)
    {
        int f1=minHeap.top();
        minHeap.pop();
        int f2=minHeap.top();
        minHeap.pop();

        cost+=f1+f2;

        minHeap.push(f1+f2);
    }

    return cost;
}

int main()
{
    int n;
    cout<<"enter the number of files: ";
    cin>>n;

    vector<int> files(n);

    cout<<"enter the size of files\n";

    for(int i=0;i<n;i++)
    {
        cout<<"\nfile "<<i+1<<": "; 
        cin>>files[i];
    }

    int res = OptimalMergePattern(files);
    cout<<"the minimum cost to merge all given files is "<<res;

    return 0;
}