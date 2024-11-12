#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item
{
    int weight;
    int value;
};

bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &items)
{
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;               
    vector<pair<int, double>> solutionSet;

    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].weight <= W)
        {
            W -= items[i].weight;
            totalValue += items[i].value;
            solutionSet.push_back({i, 1.0}); 
        }
        else
        {
            double fraction = (double)W / items[i].weight;
            totalValue += items[i].value * fraction;
            solutionSet.push_back({i, fraction}); 
            break;                               
        }
    }

    cout << "Solution Set (Item Index, Fraction of Item Included):" << endl;
    for (auto &sol : solutionSet)
    {
        cout << "Item " << sol.first << ": " << sol.second * 100 << "%" << endl;
    }

    return totalValue;
}

int main()
{
    int W = 50; 
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};

    double maxValue = fractionalKnapsack(W, items);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
