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

void call() {
    cout << "Im here\n";
}
void precalc() {
    return;
}

vb visited;
vvll adj2;

void dfs(ll ind) {
    visited[ind] = true;
    for(auto&u : adj2[ind]) {
        if(!visited[u])
            dfs(u);
    }
}

int main()
{
    IOS
    // precalc();
    ll n, m, i, j;
    ll v1, v2;
    cin >> n >> m;
    adj2 = vvll(n);

    Ff(i, 0, m) {
        ll x, y;
        cin >> x >> y;
        x--, y--;
        adj2[x].pb(y);
        adj2[y].pb(x);
    }

    // connected or not ?
    bool pos = true;
    visited.assign(n, false);
    dfs(0);
    Ff(i, 0, n) {
        if(!visited[i])
            pos = false;
    }

    if(pos) {
        // exactly 3 distinct types of adj lists reqd..
        map<vll, vll> m1;
        map<vll, ll> m2;
        ll ctr = 1;
        Ff(i, 0, n) {
            sort(all(adj2[i]));
            m1[adj2[i]].pb(i);
            if(m1[adj2[i]].size() == 1)
                m2[adj2[i]] = ctr, ctr++;
        }

        if(m1.size() != 3) {
            cout << -1;
        }
        else {
            vll ans(n, 0);
            ll sz[3];
            fill(sz, 0);
            Ff(i, 0, n)
                ans[i] = m2[adj2[i]], sz[ans[i]-1]++;

            ll sum = 0;
            Ff(i, 0, 3)
                Ff(j, i+1, 3)
                    sum += sz[i]*sz[j];

            if(sum == m) {
                Ff(i, 0, n)
                    cout << ans[i] << ' ';
            }
            else
                cout << -1;
        }
    }
    else
        cout << -1;

    cout << '\n';

    return 0;
}
