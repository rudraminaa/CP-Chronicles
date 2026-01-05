/*

Problem : Rudolf and Snowflakes 1846E2

Approach : sum = 1+k+k2+k3+...kd  : ki = k^i
                so we need to find a pair of k,d for n such {sum = n}
                2^60>1e18 so we can iterate for each d and using binary search we can also find k;

Time Complexity : O(nlogn)
Space Complexity : O(n)

Submission Link : https://codeforces.com/problemset/submission/1846/356008118
*/
#include <bits/stdc++.h>
using namespace std;
 
#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr);
#define int long long
#define ull unsigned long long
#define ld long double
 
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vs vector<string>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vpi vector<pii>
#define vpl vector<pll>
#define vvi vector<vi>
#define vvll vector<vll>
#define mii map<int, int>
#define mll map<long long, long long>
#define si set<int>
#define sll set<long long>
 
#define loop(i, n) for (int i = 0; i < n; i++)
#define rloop(i, n) for (int i = n - 1; i >= 0; i--)
#define loop1(i, a, b) for (int i = a; i <= b; i++)
#define rloop1(i, a, b) for (int i = a; i >= b; i--)
 
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define endl '\n'
#define print1 cout<<"YES"<<endl
#define print0 cout<<"NO"<<endl
 
const int MOD = 1e18;
const int INF = 1e18;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
 
template <typename T> void _print(const T &x) { cerr << x; }
 
template <typename T, typename U> void _print(const pair<T, U> &p) {
    cerr << "("; _print(p.first); cerr << ", "; _print(p.second); cerr << ")";
}
 
template <typename T> void _print(const vector<T> &v) {
    cerr << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        _print(v[i]);
        if (i != v.size() - 1) cerr << ", ";
    }
    cerr << "]";
}
 
template <typename T> void _print(const set<T> &s) {
    cerr << "{";
    for (auto it = s.begin(); it != s.end(); ++it) {
        _print(*it);
        if (next(it) != s.end()) cerr << ", ";
    }
    cerr << "}";
}
 
template <typename T, typename U> void _print(const map<T, U> &m) {
    cerr << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        _print(it->first); cerr << ": "; _print(it->second);
        if (next(it) != m.end()) cerr << ", ";
    }
    cerr << "}";
}
 
#else
#define debug(x)
#endif
 
 
int binpow(int a, int n) {
    int result = 1;
    a %= MOD;
    while (n > 0) {
        if (n & 1)
            result = (result * a);
        a = (a * a);
        n >>= 1;
    }
    return result;
}

/*

s(k) = [k^(d+1) - 1]/[k-1]

*/

int cal(int k, int d, int n){
    int sum = 1, term = 1;
    loop(i,d){
        if(term>n/k || sum>n) return 2;
        term *= k;
        sum += term;
    }
    if(sum == n) return 0;
    return 1;
}
 
void solve(){
    int n;
    cin>>n;
 
    if(n<7) {print0; return;}

    loop1(d,2,60){
        int l = 2, h = n;
        while (l <= h)
        {
            int k = l + (h-l)/2;
            int res = cal(k,d,n);
            if (res==0){
                print1;
                return;
            }
            else if (res==1) l = k + 1;
            else h = k - 1;
        }
    }
    print0;
}
 
int32_t main() {
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}