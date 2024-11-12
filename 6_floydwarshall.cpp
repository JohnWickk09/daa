#include <iostream>
using namespace std;
#define V 4

void printmatrix(int graph[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {

            if (graph[i][j] == 999)
            {
                cout << "infinity\t";
            }
            else
            {
                cout << graph[i][j] << "\t\t";
            }
        }
        cout << endl;
    }
}

void floydwarshall(int graph[][V])
{
    for(int k=0;k<V;k++)
    {
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if((graph[i][k]+graph[k][j])< graph [i][j] && graph[i][k]!=999 && graph[k][j]!=999)
                {
                    graph[i][j]=graph[k][j]+graph[i][k];
                }
            }
        }

        cout<<"\nmatrix with "<<k+1<<" as intermediate node: \n";
        printmatrix(graph);
    }
}


int main()
{

    int graph[V][V];

    cout<<"enter weight of edges (enter 999 if no edge exists)\n";

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<"\nweight between nodes "<<i+1<<" and "<<j+1<<": ";
            cin>>graph[i][j];
        }
    }
    cout<<endl;
    cout<<"initial matrix\n";
    printmatrix(graph);

    floydwarshall(graph);
    cout<<"\nfinal matrix\n";
    printmatrix(graph);

    return 0;
}