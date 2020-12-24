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
    ll tt, i, n, m;
    cin >> n >> m;
    vll a(n);
    vll b(m);

    Ff(i, 0, n)
        cin >> a[i];
    Ff(i, 0, m)
        cin >> b[i];

    ll min_val = *min_element(all(a));

    bool eq = true;
    Ff(i, 1, n) {
        if(a[i] != a[i-1])
            eq = false;
    }

    if(eq) {
        Ff(i, 0, m) {
            cout << a[0]+b[i] << ' ';
        }
        cout << '\n';
        return 0;
    }

    bool flag = true;
    ll val;

    Ff(i, 0, n) {
        if(a[i] != min_val) {
            if(flag) {
                val = a[i]-min_val;
                flag = false;
            }
            else
                val = gcd(val, a[i]-min_val);
        }
    }

    Ff(i, 0, m) {
        ll check = gcd(val, b[i]+min_val);
        cout << check << ' ';
    }
    cout << '\n';

    return 0;
}
