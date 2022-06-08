#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked // faster char input
#define fon(i, n) for (i = 0; i < n; i++)
#define fn(i, j, n) for (i = j; i < n; i++)
#define fr(i, n) for (i = n - 1; i >= 0; i--)
#define ll long long int
#define pb push_back
#define mp make_pair // making pair
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define sv(v) sort(v.begin(), v.end());
#define svd(v) sort(v.begin(), v.end(), greater<int>()); // sort vector decending
#define svp(v, fun) sort(v.begin(), v.end(), fun);       // sort vector in a particular order
#define sa(arr) sort(arr, arr + sizeof(arr) / sizeof(arr[0]));
#define sad(arr) sort(arr, arr + sizeof(arr) / sizeof(arr[0]), greater<int>()); // sort arr decending
const int mod = 1000000007;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

void showArray(ll a[], ll array_size)
{
    ll i;
    fon(i, array_size) cout << a[i] << ' ';
    cout << endl;
}
void showVector(vl v)
{
    for (ll x : v)
        cout << x << ' ';
    cout << endl;
}
int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

bool compareInterval(pl i1, pl i2) // function sort in a particular order
{
    return (i1.first < i2.first);
}

// int dp[5001][5001];

// ll solve(int n, int m, string s1, string s2)
// {
//     if (n == (int)s1.length() || m == (int)s2.length())
//         return max((int)s1.length() - n, (int)s2.length() - m);

//     if (dp[n][m] != -1)
//         return dp[n][m];

//     int ans;
//     if (s1[n] == s2[m])
//         ans = solve(n + 1, m + 1, s1, s2);
//     else
//     {
//         int a = 1 + solve(n + 1, m, s1, s2);     // delete
//         int b = 1 + solve(n + 1, m + 1, s1, s2); // replace
//         int c = 1 + solve(n, m + 1, s1, s2);     // insert
//         ans = min(a, min(b, c));
//     }

//     return dp[n][m] = ans;
// }

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    int i, j;
    fon(i, n + 1) fon(j, m + 1)
    {
        if (i == 0)
            dp[i][j] = j;
        else if (j == 0)
            dp[i][j] = i;

        else if (str1[i - 1] == str2[j - 1])
            dp[i][j] = dp[i - 1][j - 1];
        else

            dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
    }

    cout << dp[n][m] << '\n';

    return 0;
}