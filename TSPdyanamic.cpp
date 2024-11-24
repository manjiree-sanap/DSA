#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

const int INF = INT_MAX;

// Function to find the minimum cost of visiting all cities and returning to the start
int tsp(int mask, int pos, vector<vector<int>>& dp, vector<vector<int>>& graph, int n) {
    if (mask == (1 << n) - 1) {
        return graph[pos][0]; // Return to starting city
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) { // If the city is not visited
            int newAns = graph[pos][city] + tsp(mask | (1 << city), city, dp, graph, n);
            ans = min(ans, newAns);
        }
    }

    dp[mask][pos] = ans;
    return ans;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<vector<int>> dp(1 << n, vector<int>(n, -1));

    int minCost = tsp(1, 0, dp, graph, n);

    cout << "The minimum cost of visiting all cities is: " << minCost << endl;
    return 0;
}

