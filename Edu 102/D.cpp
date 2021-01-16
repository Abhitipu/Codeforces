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
        string s;
        cin >> s;

        vll prefmax(n), prefmin(n), suffmax(n), suffmin(n);
        ll cur = 0;
        vll delta(n);

        Ff(i, 0, n) {
            delta[i] = (s[i] == '+') - (s[i] == '-');
            cur += delta[i];

            prefmax[i] = max(cur, 0ll);
            prefmin[i] = min(cur, 0ll);

            if(i == 0)
                continue;

            delta[i] += delta[i-1];
            prefmax[i] = max(cur, prefmax[i-1]);
            prefmin[i] = min(cur, prefmin[i-1]);
        }

        cur = (s[n-1] == '+') - (s[n-1] == '-');
        suffmax[n-1] = max(cur, 0ll);
        suffmin[n-1] = min(cur, 0ll);

        Fb(i, 0, n-1) {
            cur = (s[i] == '+') - (s[i] == '-');
            suffmax[i] = max(cur, max(cur + suffmax[i+1], 0ll));
            suffmin[i] = min(cur, min(cur + suffmin[i+1], 0ll));
        }

        Ff(i, 0, m) {
            ll left, right;
            cin >> left >> right;
            left -= 2;
            ll mx, mn, del;
            mx = mn = del = 0;

            if(left >= 0)
                mn = prefmin[left], mx = prefmax[left], del = delta[left];

            if(right <= n-1)
                mx = max(mx, del + suffmax[right]), mn = min(mn, del + suffmin[right]);

            cout << mx - mn + 1 << '\n';
        }

    }
    return 0;
}
