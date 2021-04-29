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

int main()
{
    IOS;
    // precalc();
    ll tt, i, n, m, k;
    cin >> tt;
    while(tt--) {
        cin >> n;
        vvll adj(n);
        vll u(n);
        vll s(n);

        ll mx = 0;

        Ff(i, 0, n) {
            cin >> u[i];
        }

        Ff(i, 0, n) {
            cin >> s[i];
            u[i]--;
            adj[u[i]].pb(s[i]);
            mx = max(mx , 1ll*sz(adj[u[i]]));
        }

        Ff(i, 0, n)
            sort(all(adj[i]), greater<ll>());

        sort(all(adj), [](const vll& x, const vll& y) {return x.size() > y.size();});

        vvll pref(n);

        Ff(i, 0, n) {
            ll u = 0;
            for(auto val: adj[i]) {
                u += val;
                pref[i].pb(u);
            }
        }

        Ff(k, 1, n+1) {     // amortized ?
            ll ans = 0;
            Ff(i, 0, n) {
                if(sz(adj[i]) < k)
                    break;
                else {
                    // do in O(1)
                    ll siz = sz(adj[i]);
                    ll toRemove = siz%k;
                    ans += pref[i][siz-1-toRemove];
                }
                // cout << ans << ' ';
            }
            cout << ans << " ";
        }
        cout << '\n';
    }
    return 0;
}
