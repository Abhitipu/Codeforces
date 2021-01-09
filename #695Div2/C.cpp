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
    ll a, b, c, i, tt, q, n;
    cin >> a >> b >> c;
    vector<ll> s1(a), s2(b), s3(c);
    ll sum1, sum2, sum3, ans;
    sum1 = sum2 = sum3 = ans = 0;

    Ff(i, 0, a)
        cin >> s1[i], sum1 += s1[i];
    Ff(i, 0, b)
        cin >> s2[i], sum2 += s2[i];
    Ff(i, 0, c)
        cin >> s3[i], sum3 += s3[i];

    ans = max(ans, sum1 + sum2 - sum3);
    ans = max(ans, sum1 + sum3 - sum2);
    ans = max(ans, sum2 + sum3 - sum1);

    sort(all(s1)), sort(all(s2)), sort(all(s3));

    vll mins(3);
    mins[0] = *s1.begin();
    mins[1] = *s2.begin();
    mins[2] = *s3.begin();

    sort(all(mins));

    ans = max(ans, sum1 + sum2 + sum3 - 2*(mins[0] + mins[1]));

    cout << ans << '\n';
    return 0;
}
