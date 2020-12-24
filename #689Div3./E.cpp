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

ll facto[400004];

void precalc() {
    facto[0] = facto[1] = 1;
    ll i = 2;
    while(i < 400004)
        facto[i] = (i*facto[i-1])%mod, i++;

    return;
}

ll ncr(ll n, ll r) {
    if(r > n)
        return 0;
    else {
        ll num = facto[n];
        ll den = (facto[r]*facto[n-r])%mod;
        num = divide(num, den);
        return num;
    }
}

int main()
{
    // IOS
    precalc();
    ll tt, i, n, m, k, x;
    cin >> tt;
    while(tt--) {
        cin >> n >> m >> k;
        vll freq(n, 0);
        vll pref(n, 0);

        Ff(i, 0, n) {
            cin >> x;
            x--;
            freq[x]++;
        }

        Ff(i, 0, n)
            pref[i] = freq[i] + ((i>0)?pref[i-1]:0);
        // disp(pref);

        ll sum = 0;

        for(i = 0; i < n; i++) {
            // forcing i to be the minimum!
            if(freq[i] == 0)
                continue;

            ll check = pref[min(i+k, n-1)]-((i>0)?pref[i-1]:0);

            sum = (sum + ncr(check, m))%mod;
            check -= freq[i];

            sum = (sum-ncr(check, m)+mod)%mod;
        }

        cout << sum << '\n';
    }
    return 0;
}
