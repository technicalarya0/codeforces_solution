#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    int result = 0;
    while (!freq.empty()) {
        int curr = freq.begin()->first;
        // Start a new sequence
        result++;
        while (true) {
            if (freq[curr] > 0) {
                freq[curr]--;
                if (freq[curr] == 0)
                    freq.erase(curr);
                curr++;
            } else {
                break;
            }
        }
    }

    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
