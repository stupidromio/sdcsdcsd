#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
int n, k;
vector<long long> cost;
vector<vector<int>> combine;
vector<bool> isFree;
vector<long long> memo;
vector<bool> visited;

long long getCost(int i) {
    if (memo[i] != -1) return memo[i];
    if (isFree[i]) return memo[i] = 0;
    long long minCost = cost[i];
    if (!combine[i].empty()) {
        long long comboCost = 0;
        for (int child : combine[i]) {
            comboCost += getCost(child);
        }
        minCost = min(minCost, comboCost);
    }
    return memo[i] = minCost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    cost.resize(n);
    combine.resize(n);
    isFree.assign(n, false);
    memo.assign(n, -1);
    for (int i = 0; i < n; ++i) cin >> cost[i];
    for (int i = 0; i < k; ++i) {
        int r; cin >> r;
        isFree[r - 1] = true;  
    }
    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        for (int j = 0; j < m; ++j) {
            int x; cin >> x;
            combine[i].push_back(x - 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << getCost(i) << " ";
    }
    cout << "\n";
    return 0;
}
