#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)
#define RE(i, a, b) for (int i = a; i <= b; i++)
#define int long long
#define ll long long
#define vi vector<int>
#define sorte(a) sort(a.begin(), a.end())

const int MOD = 1e9 + 7;

int MAX = 200005;

const int N = 1e6 + 5;
vector<int> sumDiv(N, 1);
vector<int> proDiv(N, 1);
vector<int> countDiv(N, 1);

void preComputeProDiv()
{
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            proDiv[j] *= i;
        }
    }
}

void precomputeSumDivisors()
{
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            sumDiv[j] += i;
        }
    }
}

void precomputeCountDivisors()
{
    for (int i = 2; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            countDiv[j]++;
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    int value = 1;
    while (n--)
    {
        int x, k;
        cin >> x >> k;
        k %= MOD;
        value *= pow(x, k);
        value %= MOD;
    }

    cout << countDiv[value]%MOD << " " << sumDiv[value]%MOD << " " << proDiv[value]%MOD << endl;
}

int32_t main()
{

    // int t;
    // cin >> t;
    // while (t--)
    // {

    //     solve();
    // }
    precomputeCountDivisors();
    preComputeProDiv();
    precomputeSumDivisors();
    solve();

    // cout<<"Hello World"<<endl;

    return 0;
}
