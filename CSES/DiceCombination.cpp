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
const ll mod = 1000000007;
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

ll solve(ll n, vector<ll> &arr)
{
    if (n == 1 || n == 0)
        return 1;

    if (arr[n] != 0)
        return arr[n];
    ll i;
    fn(i, 1, 7)
    {
        if (i > n)
            break;

        arr[n] = (arr[n] + solve(n - i, arr)) % mod;
    }

    return arr[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> arr(n + 1, 0);
    cout << solve(n, arr) << '\n';

    return 0;
}