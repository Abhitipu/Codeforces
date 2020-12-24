#include<bits/stdc++.h>
using namespace std;

#define Ff(i,j,n)  for (i = j ; i < n; i++)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pll pair<long long, long long>
#define pi 3.14159265358979323846
#define trav(i,x) for(auto& i: x)
#define fill(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(), x.end()
#define disp(x) for(auto& i:x){ cout << i << ' ';} cout << endl;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define lb lower_bound
#define ub upper_bound

typedef vector<long long> vll;
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vll> vvll;
typedef vector<vi> vvi;
typedef vector<pll> vpll;
typedef long double ld;
typedef priority_queue <ll, vll, greater<ll>> mipq;

const ll mod = 1e9+7;
const ll mod2 = 998244353;

ll binpow(ll b, ll p) { ll ans = 1; while(p > 0){if(p & 1) ans = (ans * b) % mod; b = (b * b) % mod; p >>= 1;}return ans;}
ll inv(ll x){return binpow(x, mod - 2);}
ll divide(ll x, ll y) {return ((x%mod)*(inv(y)))%mod;}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}

void precalc() {
    /*Uncomment precalc() in main*/
    return;
}

int main()
{
    IOS;
    // precalc();
    ll tt, n;
    cin >> n;
    ll sum = 0;

    vll a(n);
    vll b(n);

    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i], sum += b[i];

    // relate to knapsack!
    // Take Win, Wout and W = (Win+Wout)
    // Lim-> max limit
    // ans = Win+Wout/2 = W/2 + Win/2
    // do a dp...ew....

    ll mxn = 100*n+1;
    ll dp[n+1][mxn];

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < mxn; j++)
            dp[i][j] = -1;
    }

    dp[0][0] = 0;   // base case

    for(int i = 0; i < n; i++) {
        for(int j = i; j >= 0; j--) {       // Go back to avoid taking the same value again n again
            for(int k = 0; k < mxn; k++) {
                if(dp[j][k] == -1)
                    continue;
                dp[j+1][k+a[i]] = max(dp[j+1][k+a[i]], dp[j][k]+b[i]);    // k+a[i] -> total available volume
            }
        }
    }

    // cout << fixed << setprecision(12);

    for(int i = 1; i <= n; i++) {
        ld ans = 0;
        for(int k = 0; k < mxn; k++) {
            if(dp[i][k] == -1)
                continue;
            ans = max(ans, min((ld)k, (ld)(sum+dp[i][k])/2));
        }
        cout << ans << ' ';
    }
    cout << '\n';
    return 0;
}
