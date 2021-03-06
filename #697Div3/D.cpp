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
    ll tt, i, n, m, j;
    cin >> tt;
    while(tt--) {
	    cin >> n >> m;

        vll v1(n);
        ll check = 0;
        Ff(i, 0, n)
            cin >> v1[i], check += v1[i];

        vll t1, t2;

        Ff(i, 0, n) {
            ll x;
            cin >> x;
            if(x == 1)
                t1.pb(v1[i]);
            else
                t2.pb(v1[i]);
        }

        if(check < m) {
            cout << -1 << '\n';
            continue;
        }

        sort(all(t1), greater<ll>());
        sort(all(t2), greater<ll>());

        i = 0;
        j = 0;
        ll s1 = sz(t1);
        ll s2 = sz(t2);
        ll ans = LLONG_MAX;
        ll sum = 0;

        while(sum < m && i < s1) {
            // taking only from t1
            sum += t1[i];
            i++;
        }
        while(sum < m) {
            sum += t2[j];
            j++;
        }
        ans = min(i+2*j, ans);
        i--;

        while(i >= 0) {
            sum -= t1[i];
            while(sum < m && j < s2) {
                sum += t2[j];
                j++;
            }
            if(sum < m)
                break;
            ans = min(ans, i+2*j);
            i--;
        }

        cout << ans << '\n';

    }
    return 0;
}
