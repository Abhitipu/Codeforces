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

const ll mod = 1000000007;
const ll mod2 = 998244353;

ll binpow(ll b, ll p) { ll ans = 1; while(p > 0){if(p & 1) ans = (ans * b) % mod; b = (b * b) % mod; p >>= 1;}return ans;}
ll inv(ll x){return binpow(x, mod - 2);}
ll divide(ll x, ll y) {return ((x%mod)*(inv(y)))%mod;}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}

const ll mxn = 1004;
ll facto[mxn];
void precalc() {
    facto[0] = facto[1] = 1;
    ll i;
    Ff(i, 2, mxn)
        facto[i] = (i*facto[i-1])%mod;
    return;
}

ll nCr(ll n, ll r) {
    if(r > n)
        return 0;
    ll num = facto[n];
    ll den = (facto[r]*facto[n-r])%mod;
    num = (num*(inv(den)))%mod;
    return num;
}

int main()
{
    IOS;
    precalc();
    ll tt, i, n, k;
    cin >> tt;
    while(tt--) {
	    cin >> n >> k;
        vll v1(n);
        vll freq(n+1, 0);

        Ff(i, 0, n) {
            cin >> v1[i];
            freq[v1[i]]++;
	    }

        sort(all(v1), greater<ll>());

        ll tochoose = k;
        i = 0;
        while(v1[i] != v1[k-1])
            i++, tochoose--;

        cout << nCr(freq[v1[k-1]], tochoose) << '\n';

    }
    return 0;
}
