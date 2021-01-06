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
    IOS
    // precalc();
    ll tt, i, n, m;
    cin >> tt;

    while(tt--) {
	    cin >> n >> m;
        vvll adj(n);
        Ff(i, 0, m) {
            ll x, y;
            cin >> x >> y;
            x--, y--;
            adj[x].pb(y);
            adj[y].pb(x);
	    }

        vb visited(n, false);
        vll color(n, -1);
        bool pos = true;

        function<void(ll, ll)> dfs = [&](ll idx, int col) {
            visited[idx] = true;
            bool n0 = true;

            if(col != -1) {
                if(col == 1)
                    n0 = false;
            }
            else {
                bool n0 = true;
                for(auto& u: adj[idx]) {
                    if(color[u] == 0)
                        n0 = false;
                }
            }

            if(n0) {
                color[idx] = 0;
                for(auto& u: adj[idx]) {
                    color[u] = 1;
                }

                for(auto& u : adj[idx]) {
                    if(!visited[u])
                        dfs(u, color[u]);
                }
            }
            else {
                color[idx] = 1;
                for(auto& u: adj[idx]) {
                    if(!visited[u])
                        dfs(u, color[u]);
                }
            }
        };

        dfs(0, 0);

        Ff(i, 0, n)
            if(!visited[i])
                pos = false;

        if(pos) {
            vll ans;
            Ff(i, 0, n)
                if(color[i] == 0)
                    ans.pb(i);

            cout << "YES\n" << sz(ans) << '\n';
            for(int i = 0; i < sz(ans); i++)
                cout << ans[i]+1 << ' ';
            cout << '\n';
        }
        else
            cout << "NO\n";

    }
    return 0;
}
