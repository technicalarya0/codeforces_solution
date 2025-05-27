#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RE(i, a, b) for (int i = a; i <= b; i++)
#define int long long
#define vi vector<int>
#define sorte(a) sort(a.begin(), a.end())

const int N = 1e5 + 7;
const string VOWELS = "aeiou";
const int MOD = 1e9 + 7;
map<int, int> mp;

int MAX = 200005;

long long calculateArea(const vector<pair<long long, long long>> &positions)
{
    if (positions.empty())
        return 0;

    long long min_x = positions[0].first, max_x = positions[0].first;
    long long min_y = positions[0].second, max_y = positions[0].second;

    for (const auto &pos : positions)
    {
        min_x = min(min_x, pos.first);
        max_x = max(max_x, pos.first);
        min_y = min(min_y, pos.second);
        max_y = max(max_y, pos.second);
    }

    return (max_x - min_x + 1) * (max_y - min_y + 1);
}

void solve()
{
    int n;
    cin >> n;

    vector<pair<long long, long long>> monsters(n);
    set<pair<long long, long long>> occupied;

    for (int i = 0; i < n; i++)
    {
        cin >> monsters[i].first >> monsters[i].second;
        occupied.insert(monsters[i]);
    }

    // Handle special case for single monster
    if (n == 1)
    {
        cout << "1\n";
        return;
    }

    long long minCost = calculateArea(monsters);

    // Try moving each monster
    for (int i = 0; i < n; i++)
    {
        auto original = monsters[i];
        occupied.erase(original);

        // Collect all unique x and y coordinates from other monsters
        set<long long> x_coords, y_coords;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                x_coords.insert(monsters[j].first);
                y_coords.insert(monsters[j].second);
            }
        }

        // Try strategic positions: combinations of existing coordinates
        for (long long x : x_coords)
        {
            for (long long y : y_coords)
            {
                if (occupied.find({x, y}) == occupied.end())
                {
                    monsters[i] = {x, y};
                    minCost = min(minCost, calculateArea(monsters));
                }
            }
        }

        // Try corner positions of the bounding box
        if (n > 1)
        {
            long long min_x = LLONG_MAX, max_x = LLONG_MIN;
            long long min_y = LLONG_MAX, max_y = LLONG_MIN;

            for (int j = 0; j < n; j++)
            {
                if (i != j)
                {
                    min_x = min(min_x, monsters[j].first);
                    max_x = max(max_x, monsters[j].first);
                    min_y = min(min_y, monsters[j].second);
                    max_y = max(max_y, monsters[j].second);
                }
            }

            // Try the four corners of the bounding box
            vector<pair<long long, long long>> candidates = {
                {min_x, min_y}, {min_x, max_y}, {max_x, min_y}, {max_x, max_y}};

            for (const auto &candidate : candidates)
            {
                if (occupied.find(candidate) == occupied.end())
                {
                    monsters[i] = candidate;
                    minCost = min(minCost, calculateArea(monsters));
                }
            }
        }

        // Restore original position for next iteration
        monsters[i] = original;
        occupied.insert(original);
    }

    cout << minCost << "\n";
}

int32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    // solve();

    // cout<<"Hello World"<<endl;

    return 0;
}
