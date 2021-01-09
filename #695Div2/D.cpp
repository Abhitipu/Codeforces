#include<bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);

    long long n, k, q;
    cin >> n >> k >> q;

    vector<long long> v1(n);
    for(int i = 0; i < n; i++)
        cin >> v1[i];

    long long dp[n][k+1];

    for(int i = 0; i < n; i++)
        dp[i][0] = 1;

    for(int j = 1; j <= k; j++) {
        for(int i = 0; i < n; i++) {
            dp[i][j] = (i > 0) ? dp[i-1][j-1] : 0ll;
            if(i < n-1)
                dp[i][j] =  (dp[i][j] + dp[i+1][j-1])%mod;
        }
    }

    long long cnt[n] = {0ll};
    long long ans = 0ll;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++)
            cnt[i] = (cnt[i] + (dp[i][j]*dp[i][k-j])%mod)%mod;
        ans = (ans + (cnt[i]*v1[i])%mod)%mod;
    }

    while(q--) {
        int idx, val;
        cin >> idx >> val;
        idx--;
        ans = (ans-(v1[idx]*cnt[idx])%mod + mod)%mod;
        v1[idx] = val;
        ans = (ans+(v1[idx]*cnt[idx])%mod)%mod;
        cout << ans << '\n';
    }
    return 0;
}
