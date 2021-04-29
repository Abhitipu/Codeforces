#include<bits/stdc++.h>
using namespace std;

#define Ff(i,j,n)  for (i = j ; i < n; i++)
#define Fb(i,j,n)  for (i = n-1 ; i >= j; i--)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define pi 3.14159265358979323846
#define trav(i,x) for(auto& i: x)
#define fill(x,y) memset(x,y,sizeof(x))
#define all(x) x.begin(), x.end()
#define disp(x) for(auto& i:x){ cout << i << ' ';} cout << endl;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define lb lower_bound
#define ub upper_bound
#define sz(x) (ll)x.size()

typedef vector<long long> vll;
typedef pair<long long, long long> pll;
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

ll dp[5001][5001];

int main()
{
    IOS;
    // precalc();
    ll tt, i, n;
    cin >> n;
    vll a(n), b(n);

    Ff(i, 0, n)
        cin >> a[i];

    Ff(i, 0, n)
        cin >> b[i];

    ll ans = 0;

    Ff(i, 0, n)
        ans += a[i]*b[i];

    // greedy : max with max.. but how ??
    // reverse only a ?

    // can iterate over all end points!
    // but multiplication would take a long time
    // optimize the multiplication!

    // dp[i][j] -> result if i...j is flipped

    Ff(i, 0, n)
        dp[i][i] = 0;

    ll chk = ans;

    Ff(i, 0, n-1) {
        dp[i][i+1] = (a[i+1] - a[i])*(b[i] - b[i+1]);
        // cout << dp[i][i+1] << " ";
        ans = max(ans, chk + dp[i][i+1]);
    }

    for(int len = 3; len <= n; len++) {
        for(int i = 0; i + len <= n; i++) {
            // cout << i << " " << len << '\n';
            dp[i][i+len-1] = dp[i+1][i+len-2] + (a[i+len-1] - a[i])*(b[i] - b[i+len-1]);
            ans = max(ans, chk + dp[i][i+len-1]);
        }
    }

    cout << ans << '\n';
    return 0;
}
