
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
        string s;
        cin >> n;
        cin >> s;
        ll ctr = 0;
        i = n-1;
        while(i >= 0 && s[i] == ')')
            i--, ctr++;

        ll rem = n-ctr;
        // cout << rem << ' ' << ctr << '\n';

        if(ctr > rem)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
