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

int main()
{
    IOS
    // precalc();
    ll tt, i, n;
    cin >> tt;
    while(tt--) {
        cin >> n;
        vector<string> v1(n);

        vll max_h(10), min_h(10), max_v(10), min_v(10);

        Ff(i, 0, 10) {
            max_h[i] = max_v[i] = -1;
            min_v[i] = min_h[i] = n+2;
        }

        Ff(i, 0, n)
            cin >> v1[i];

        ll j;
        Ff(i, 0, n) {
            Ff(j, 0, n) {
                max_h[v1[i][j]-'0'] = max(max_h[v1[i][j]-'0'], i);
                min_h[v1[i][j]-'0'] = min(min_h[v1[i][j]-'0'], i);
            }
        }

        Ff(i, 0, n) {
            Ff(j, 0, n) {
                max_v[v1[j][i]-'0'] = max(max_v[v1[j][i]-'0'], i);
                min_v[v1[j][i]-'0'] = min(min_v[v1[j][i]-'0'], i);
            }
        }

        ll hb_a[10][n];  // actual
        ll hb_v[10][n];  // virtual
        ll vb_v[10][n];
        ll vb_a[10][n];

        Ff(i, 0, 10) {
            Ff(j, 0, n)
                hb_a[i][j] = hb_v[i][j] = vb_a[i][j] = vb_v[i][j] = 0;
        }

        ll k;

        Ff(i, 0, 10) {
            Ff(j, 0, n) {
                ll last_seen = -1;
                Ff(k, 0, n) {
                    if(v1[j][k]-'0' == i) {
                        hb_v[i][j] = max(hb_v[i][j], max(n-k-1, k));
                        if(last_seen == -1) {
                            last_seen = k;
                        }
                        else {
                            hb_a[i][j] = (k-last_seen);
                        }
                    }
                }
            }
        }


        Ff(i, 0, 10) {
            Ff(j, 0, n) {
                ll last_seen = -1;
                Ff(k, 0, n) {
                    if(v1[k][j]-'0' == i) {
                        vb_v[i][j] = max(vb_v[i][j], max(n-k-1, k));
                        if(last_seen == -1) {
                            last_seen = k;
                        }
                        else {
                            vb_a[i][j] = (k-last_seen);
                        }
                    }
                }
            }
        }

        ll best[10];
        fill(best, 0);

        Ff(i, 0, 10) {
            Ff(j, 0, n) {   // horizontal
                // virtual base
                if(max_h[i] != -1) {
                    best[i] = max(best[i], abs(hb_v[i][j]*(j-max_h[i])));
                }
                if(min_h[i] != n+2) {
                    best[i] = max(best[i], abs(hb_v[i][j]*(j-min_h[i])));
                }

                // actual base
                if(hb_v[i][j] != 0) {
                    best[i] = max(best[i], abs(hb_a[i][j]*max(n-j-1, j)));
                }
            }
        }

        // Ff(i, 0, 10) {
        //     cout << max_h[i] << ' ' << min_h[i] << '\n';
        //     cout << max_v[i] << ' ' << min_v[i] << '\n';
        // }

        Ff(i, 0, 10) {
            Ff(j, 0, n) {  // vertical
                // virtual base
                if(max_v[i] != -1) {
                    best[i] = max(best[i], abs(vb_v[i][j]*(j-max_v[i])));
                }
                if(min_v[i] != n+2) {
                    best[i] = max(best[i], abs(vb_v[i][j]*(j-min_v[i])));
                }

                // actual_base
                if(vb_v[i][j] != 0) {
                    best[i] = max(best[i], abs(vb_a[i][j]*max(n-j-1, j)));
                }
            }
        }

        // Ff(i, 0, 10) {
        //     cout << i << '\n';
        //     // cout << "Horizontal\n";
        //     // Ff(j, 0, n) {
        //     //     cout << hb_a[i][j] << ' ' << hb_v[i][j] << '\n';
        //     // }
        //     // cout << i << ' ';
        //     // cout << "Vertical\n";
        //     Ff(j, 0, n) {
        //         cout << vb_a[i][j] << ' ' << vb_v[i][j] << '\n';
        //     }
        // }

        Ff(i, 0, 10)
            cout << best[i] << ' ';
        cout << '\n';

    }
    return 0;
}
