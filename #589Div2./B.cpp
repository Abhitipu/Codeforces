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
    ll tt, i, n, h, w, j;
    cin >> h >> w;

    vll rows(h), cols(w);

    Ff(i, 0, h)
        cin >> rows[i];
    Ff(i, 0, w)
        cin >> cols[i];

    ll board[h][w];

    Ff(i, 0, h) {
        Ff(j, 0, w)
            board[i][j] = -1;
    }

    ll ans = 1;

    Ff(i,0,h) {
        ll check = rows[i];
        j = 0;
        while(j < check){
            board[i][j] = 1;
            j++;
        }
        if(j < w)
            board[i][j] = 0;
    }

    Ff(i,0,w) {
        ll check = cols[i];
        j = 0;
        while(j < check){
            if(board[j][i] == 0)
                ans = 0;
            board[j][i] = 1;
            j++;
        }
        if(j < h) {
            if(board[j][i] == -1 || board[j][i]==0)
                board[j][i] = 0;
            else
                ans = 0;
        }
    }

    Ff(i, 0, h) {
        Ff(j, 0, w) {
            if(board[i][j] == -1) {
                ans = (ans*2)%mod;
            }
        }
    }

    cout << ans << '\n';
    return 0;
}
