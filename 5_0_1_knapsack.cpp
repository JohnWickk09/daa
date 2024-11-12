#include <iostream>
#include <vector>
using namespace std;

vector<int> knapsackSolver(const vector<int> &values, const vector<int> &weights, int W)
{
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Final DP matrix:" << endl;
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

    vector<int> solution(n, 0);
    int w = W;
    int total_weight = 0;
    for (int i = n; i > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            solution[i - 1] = 1;
            w -= weights[i - 1];
            total_weight += weights[i - 1];
        }
    }

    cout << "Total weight in the knapsack: " << total_weight << endl;
    cout << "\nTotal profit: " << dp[n][W] << endl;

    return solution;
}

int main()
{
    int W = 20;
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};

    vector<int> solution = knapsackSolver(values, weights, W);

    cout << "Solution set in 0/1 form: ";
    for (int i = 0; i < solution.size(); i++)
    {
        cout << solution[i] << " ";
    }
    cout << endl;

    return 0;
}