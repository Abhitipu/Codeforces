#include<bits/stdc++.h>
using namespace std;

#define Ff(i,j,n)  for (i = j ; i < n; i++)
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

int main()
{
    IOS;
    // precalc();
    ll tt, i, n;
    cin >> tt;
    while(tt--) {
        cin >> n;
        vpll ans;

        if(n <= 8) {
            Ff(i, 0, n-3)
                ans.pb({i+3, n});

            ll check = n;
            while(check != 1) {
                ans.pb({n, 2});
                check = (check+1)/2;
            }
        }
        else {
            Ff(i, 3, 8)
                ans.pb({i, n});

            Ff(i, 9, n)
                ans.pb({i, n});

            ll check = n;

            while(check!=1) {
                ans.pb({n, 8});
                check = (check+7)/8;
            }

            Ff(i, 0, 3)
                ans.pb({8, 2});
        }

        n = sz(ans);

        cout << n << '\n';
        Ff(i, 0, n) {
            cout << ans[i].ff << ' ' << ans[i].ss << '\n';
        }
    }
    return 0;
}
