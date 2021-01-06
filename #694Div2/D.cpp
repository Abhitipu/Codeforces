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

const ll mxn = 1000007;

ll prime[mxn] = {0};
ll minv[mxn] = {0};

void sieve() {
    ll i;
    Ff(i, 0, mxn)
        minv[i] = i;

    Ff(i, 2, mxn) {
        if(prime[i] == 0) {
            for(ll j = i; j < mxn; j += i) {
                prime[j] = 1;

                while(minv[j]%(i*i) == 0)
                    minv[j] /= i*i;
            }
        }
    }
}

int main()
{
    IOS
    // precalc();
    ll tt, i, n;
    cin >> tt;
    sieve();
    while(tt--) {
	    cin >> n;
        vll v1(n);
        unordered_map<ll, ll> m1;

        Ff(i, 0, n) {
            cin >> v1[i];
            m1[minv[v1[i]]]++;
	    }

        ll max_val = 0;
        ll sum = 0;
        for(auto it: m1) {
            max_val = max(max_val, it.ss);
            if(it.ss%2 == 0 || it.ff == 1)
                sum += it.ss;
        }

        ll q;
        cin >> q;
        while(q--) {
            ll w;
            cin >> w;
            if(w == 0)
                cout << max_val << '\n';
            else
                cout << max(sum, max_val) << '\n';
        }

    }
    return 0;
}
