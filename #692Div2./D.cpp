#include<bits/stdc++.h>
using namespace std;

#define Ff(i,j,n)  for (i = j ; i < n; i++)
#define Fb(i,j,n)  for (i = n-1 ; i >= j; i--)
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
ll sz(auto& x){return (ll)x.size();}

void precalc() {
    /*Uncomment precalc() in main*/
    return;
}

int main()
{
    IOS
    // precalc();
    ll n, x, y, q, i, j;
    string s1;
    cin >> s1;
    cin >> x >> y;
    n = sz(s1);

    // fill all q marks with 1s
    // then try all combos with 0s
    // first start filling from the left
    // reverse the string and swap(x, y)
    // then repeat

    ll best = LLONG_MAX;

    Ff(q, 0, 2) {
        string s = s1;

        ll pref[2][n];
        // in 0......i
        ll suff[2][n];
        // in i....n-1

        Ff(i, 0, n) {
            pref[0][i] = (s[i] == '0') + ((i > 0)? pref[0][i-1] : 0);
            pref[1][i] = (s[i] != '0') + ((i > 0)? pref[1][i-1] : 0);
        }

        Fb(i, 0, n) {
            suff[0][i] = (s[i] == '0') + ((i < n-1)? suff[0][i+1] : 0);
            suff[1][i] = (s[i] != '0') + ((i < n-1)? suff[1][i+1] : 0);
        }

        ll val = 0;

        Ff(i, 0, n) {
            // only count for all 1s
            if(s[i] != '0')
                val += ((i > 0)?pref[0][i-1]:0)*x + y*((i < n-1)?suff[0][i+1]:0);
        }
        best = min(best, val);

        // start filling q marks with 0s from the left!
        ll ctr = 0;

        Ff(i, 0, n) {
            if(s[i] != '?')
                continue;
            val -= (((i > 0)?pref[0][i-1]+ctr:0)*x + y*((i < n-1)?suff[0][i+1]:0));
            val += (((i > 0)?pref[1][i-1]-ctr:0)*y + x*((i < n-1)?suff[1][i+1]:0));
            best = min(best, val);
            ctr++;
        }

        swap(x, y);
        reverse(all(s1));
    }

    cout << best << '\n';
    return 0;
}
