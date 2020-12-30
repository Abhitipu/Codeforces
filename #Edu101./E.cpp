#include<bits/stdc++.h>
using namespace std;

#define Ff(i,j,n)  for (i = j ; i < n; i++)
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
    ll tt, i, n, k;
    cin >> tt;
    while(tt--) {
        cin >> n >> k;

        string s;
        cin >> s;

        trav(c, s) {
            if(c == '0')
                c = '1';
            else
                c = '0';
        }

        ll mx = min(k, 20*1ll);

        ll check = 0;
        ll z = 0;              // counting prefix zeros is important!
        vb pos(1<<mx, true);   // vll gives TLE... no idea why...

        if(k > 20)
            Ff(i, 0, k-20) {
                if(s[i] == '1')
                    z = 0;
                else
                    z++;
            }

        for(i = max(0ll, k-20); i < k ; i++) {      // 0, 1, 2, ...... , k-1
            check = check*2ll + (s[i]-'0');
        }

        if(z+mx >= k)
            pos[check] = false;

        for(i = k; i < n; i++) {   // O(n)
            // all the end points
            if(s[i-mx] == '1')
                check -= 1ll<<(mx-1), z = 0;
            else
                z++;

            check = check*2ll + (s[i]-'0');
            if(z + mx >= k)
                pos[check] = false;
        }

        ll ans = -1;
        ll d = (1ll<<mx);

        for(i = 0; i < d; i++) {   // 10^6 steps
            if(pos[i]) {
                ans = i;
                break;
            }
        }

        if(ans == -1)
            cout << "NO\n";
        else {
            cout << "YES\n";

            if(k > 20) {
                Ff(i, 0, k-20)
                    cout << 0;
                k = 20;
            }

            for(i = k-1; i >= 0; i--) {
                ll check = (ans>>i)&1;
                cout << check;
            }
            cout << '\n';
        }

    }
    return 0;
}
