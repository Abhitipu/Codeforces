#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> adj(n);     // {destination, weight}

    for(int i = 0; i < m; i++) {
        ll w;
        int x, y;
        cin >> x >> y >> w;
        x--, y--;
        adj[x].pb({y, w});
        adj[y].pb({x, w});
    }

    auto cmp = [&](const pair<pair<ll, ll>, ll> x, const pair<pair<ll, ll>, ll> y) {
        return x.first.second > y.first.second;
    };

    ll dp[n][4];
    bool vis[n][4];
    memset(vis, false, sizeof(vis));

    priority_queue< pair<pair<ll, ll>, ll>, vector<pair<pair<ll, ll>, ll>>, decltype(cmp)> pq(cmp);   // { {destination, distance} , bitmask}

    pq.push({{0, 0}, 0});

    while(!pq.empty()) {
        auto el = pq.top();
        pq.pop();
        auto cur = el.first;   // {dest, distance}
        ll flag = el.second;

        if(vis[cur.first][flag])
            continue;

        vis[cur.first][flag] = true;
        dp[cur.first][flag] = cur.second;

        ll s1, s2;
        s1 = flag / 2;     // skipped one
        s2 = flag % 2;     // took one twice

        for(ll state = 0; state < 4; state++) {
            ll v1 = state / 2, v2 = state % 2;

            if(v1 < s1 || v2 < s2)    // cant transition
                continue;

            for(auto& p : adj[cur.first]) {
                pq.push({{p.first, cur.second + p.second*(1 - (v1 > s1) + (v2 > s2))}, state});
            }
        }
    }

    for(int i = 1; i < n; i++)
        cout << dp[i][3] << " ";
    cout << '\n';

    return 0;
}
