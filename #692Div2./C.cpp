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
    IOS
    // precalc();
    ll tt, i, n;
    cin >> tt;
    while(tt--) {
        ll m;
        cin >> n >> m;

        vb row(n, false);
        vb col(n, false);
        vpll places(m);
        vll rows(n, -1);
        vll cols(n, -1);

        Ff(i, 0, m) {
            ll x, y;
            cin >> y >> x;
            y--, x--;
            places[i] = {x, y};
            row[x] = true;
            col[y] = true;
            rows[x] = i;
            cols[y] = i;
        }

        vb visited(n, false);
        ll ans = 0;

        auto can = [&](ll ind) {
            return (!col[places[ind].ff] || !row[places[ind].ss]);
        };

        Ff(i, 0, m) {
            if(places[i].ff == places[i].ss || visited[i])
                continue;

            if(can(i)) {
                ans++;
                continue;
            }

            // try to detect a cycle!
            ll ctr = 0;
            ll cur = i;

            bool cycle = true;

            while(!visited[cur] && !can(cur)) {
                ctr++;
                visited[cur] = true;
                cur = cols[places[cur].ff];

                if(can(cur))
                    cycle = false;
            }

            if(!cycle) {
                // cout << "No cycle\n";
                cur = rows[places[i].ss];

                while(!visited[cur] && !can(cur)) {
                    ctr++;
                    visited[cur] = true;
                    cur = rows[places[cur].ss];
                }
                ans += ctr;
            }
            else {
                // cout << "Cycle size " << ctr << '\n';
                ans += (ctr+1);
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
