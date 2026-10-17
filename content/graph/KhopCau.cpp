#include <bits/stdc++.h>

#define maxN 10000
#define fto(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define fdto(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define sz(a) (int)a.size()
#define pb push_back
#define ff first
#define ss second
#define ii pair<int, int>
#define ll long long
#define all(a) (a).begin(), (a).end()
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int n, m, low[maxN+1], num[maxN+1], t, khop, cau, dd[maxN+1];
vector<int> ke[maxN+1];

void dfs(int u, int p) {
    low[u] = num[u] = ++t;
    int child = 0;
    fto(i, 0, sz(ke[u])-1) {
        int v = ke[u][i];
        if (v == p) continue;
        if (num[v] == 0) {
            dfs(v, u);
            ++child;
            low[u] = min(low[u], low[v]);
            if (num[v] == low[v]) ++cau;
            if (p == -1) {
                if (child > 1) dd[u] = 1;
            } else if (low[v] >= num[u]) dd[u] = 1;
        } else {
            low[u] = min(low[u], num[v]);
        }
    }
    return;
}

int main() {
    if (fopen("KHOPCAU.INP", "r")) {
        freopen("KHOPCAU.INP", "r", stdin);
        freopen("KHOPCAU.OUT", "w", stdout);
    }

    fastio;
    cin >> n >> m;

    fto(i, 1, m) {
        int u, v; cin >> u >> v;
        ke[u].pb(v); ke[v].pb(u);
    }

    khop = 0, cau = 0;
    fto(i, 1, n) if (num[i] == 0) dfs(i, -1);
    fto(i, 1, n) if (dd[i]) ++khop;
    cout << khop << " " << cau << "\n";
    return 0;
}
