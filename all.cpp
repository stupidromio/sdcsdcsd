#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;
int freq[26];

bool isPossible(int len) {
    if (len == 1) {
        int totalLetters = 0;
        for (int i = 0; i < 26; ++i)
            totalLetters += freq[i];
        return totalLetters >= k;
    }

    int pairsNeeded = len / 2;
    int totalPairs = 0;

    for (int i = 0; i < 26; ++i)
        totalPairs += freq[i] / 2;

    int maxGroups = totalPairs / pairsNeeded;

    if (len % 2 == 0) {
        return maxGroups >= k;
    } else {
        int leftovers = 0;
        for (int i = 0; i < 26; ++i)
            if (freq[i] % 2) leftovers++;

        int extraCenters = (totalPairs - pairsNeeded * k) * 2 + leftovers;
        return maxGroups >= k && extraCenters >= k;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    cin >> s;

    memset(freq, 0, sizeof(freq));
    for (char c: s)
        freq[c - 'a']++;

    int low = 1, high = n;
    int ans = 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}
