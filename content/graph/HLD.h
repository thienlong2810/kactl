/**
 * Author: Hung
 * Date: 2026-10-17
 * License: CC0
 * Source: https://codeforces.com/blog/entry/53170, https://github.com/bqi343/USACO/blob/master/Implementations/content/graphs%20(12)/Trees%20(10)/HLD%20(10.3).h
 * Description: Decomposes a tree into vertex disjoint heavy paths and light
 * edges such that the path from any leaf to the root contains at most log(n)
 * light edges. Code does additive modifications and max queries, but can
 * support commutative segtree modifications/queries on paths and subtrees.
 * Takes as input the full adjacency list. VALS\_EDGES being true means that
 * values are stored in the edges, as opposed to the nodes. All values
 * initialized to the segtree default. Root must be 1.
 * Time: O((\log N)^2)
 */
#include <bits/stdc++.h>
 
#define maxN 200000
#define pb push_back
#define pf push_front
#define sz(a) (int) a.size()
#define ff first
#define ss second
#define ll long long
#define fto(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define fdto(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define ii pair<int, int>
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
 
using namespace std;
 
int n, q, Sz[maxN+1], depth[maxN+1], arr[maxN+1], curpos, pos[maxN+1], par[maxN+1], chainhead[maxN+1];
int a[maxN+1], f[4*maxN+1];
vector<int> ke[maxN+1];
mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
 
void input() {
    cin >> n >> q;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, n-1) {
        int u, v; cin >> u >> v;
        ke[u].pb(v); ke[v].pb(u);
    }
    return;
}
 
void dfs_hld(int u) {
    Sz[u] = 1;
    fto(i, 0, sz(ke[u])-1) {
        int v = ke[u][i];
        if (v == par[u]) continue;
        par[v] = u;
        depth[v] = depth[u] + 1;
        dfs_hld(v);
        Sz[u] += Sz[v];
    }
    return;
}
 
void hld(int u, int p) {
    pos[u] = ++curpos;
    arr[curpos] = u;
    chainhead[u] = p;
    int nxt = 0;
    fto(i, 0, sz(ke[u])-1) {
        int v = ke[u][i];
        if (v == par[u]) continue;
        if (nxt == 0 || Sz[nxt] < Sz[v]) nxt = v;
    }
    if (nxt != 0) hld(nxt, p);
    fto(i, 0, sz(ke[u])-1) {
        int v = ke[u][i];
        if (v == par[u] || v == nxt) continue;
        hld(v, v);
    }
    return;
}
 
void prepare() {
    par[1] = 1;
    depth[1] = 1;
    curpos = 0;
    dfs_hld(1);
    hld(1, 1);
    return;
}
 
void init(int root, int l, int r) {
    if (l == r) {
        f[root] = a[arr[l]];
        return;
    }
    int mid = (l+r)/2;
    init(root*2, l, mid);
    init(root*2+1, mid+1, r);
    f[root] = max(f[root*2], f[root*2+1]);
    return;
}
 
void update(int root, int l, int r, int i, int x) {
    if (r < i || i < l) return;
    if (l == r) {
        if (l == i) f[root] = x;
        return;
    }
    int mid = (l+r)/2;
    update(root*2, l, mid, i, x);
    update(root*2+1, mid+1, r, i, x);
    f[root] = max(f[root*2], f[root*2+1]);
}
 
int query(int root, int l, int r, int i, int j) {
    if (r < i || j < l) return 0;
    if (i <= l && r <= j) return f[root];
    int mid = (l+r)/2;
    int x = query(root*2, l, mid, i, j);
    int y = query(root*2+1, mid+1, r, i, j);
    return max(x, y);
}
 
int lca(int u, int v) {
    while (chainhead[u] != chainhead[v]) {
        if (depth[chainhead[u]] < depth[chainhead[v]]) swap(u, v);
        u = par[chainhead[u]];
    }
    if (depth[v] < depth[u]) swap(u, v);
    return u;
}
 
int query_max(int u, int v) {
    int ans = 0;
    while (chainhead[u] != chainhead[v]) {
        if (depth[chainhead[u]] < depth[chainhead[v]]) swap(u, v);
        ans = max(ans, query(1, 1, curpos, pos[chainhead[u]], pos[u]));
        u = par[chainhead[u]];
    }
    if (depth[u] > depth[v]) swap(u, v);
    ans = max(ans, query(1, 1, curpos, pos[u], pos[v]));
    return ans;
}
 
void solve() {
    prepare();
    init(1, 1, curpos);
 
    while (q--) {
        int t, u, v, x; cin >> t;
        if (t == 1) {
            cin >> u >> x;
            update(1, 1, curpos, pos[u], x);
        } else {
            cin >> u >> v;
            cout << query_max(u, v) << " ";
        }
    }
    return;
}
 
int main() {
    if (fopen("HLD.INP", "r")) {
        freopen("HLD.INP", "r", stdin);
        freopen("HLD.OUT", "w", stdout);
    }
 
    fastio;
 
    input();
 
    solve();
 
    return 0;
}
