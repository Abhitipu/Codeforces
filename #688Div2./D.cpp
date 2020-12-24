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
    return;
}

ll bins(ll val) {
    ll hi = 100;
    ll lo = 1;
    ll best = 1;

    while(hi >= lo) {
        ll mid = (hi+lo)/2;
        ll check = (ll)pow(2, mid+1)-2;   // always typecast pow function
        if(check > val)
            hi = mid-1;
        else {
            best = max(best, mid);
            lo = mid+1;
        }
    }
    return best;
}

int main()
{
    IOS
    // precalc();
    ll tt, i, n, k;
    cin >> tt;
    while(tt--) {
        cin >> k;
        string ans;
        if(k%2 != 0)
            cout << -1 << '\n';
        else {
            while(k > 0) {
                ll q = bins(k);
                string s = "1";
                string s1(q-1, '0');
                s += s1;
                ans += s;
                k -= ((ll)pow(2, q+1)-2);
            }

            n = (ll)ans.size();
            if(n > 2000)
                cout << -1 << '\n';
            else {
                cout << n << '\n';
                Ff(i, 0, n)
                    cout << ans[i] << ' ';
                cout << '\n';
            }
        }
    }
    return 0;
}
