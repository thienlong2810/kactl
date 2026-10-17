#include <bits/stdc++.h>

using namespace std;

const int maxN = 100000;
const int oo = (int) 1e9+7;
int n, m, mn, mx, root[maxN+5];
long long power[maxN+5];

struct info_1 {
    int l, r, p;
};
struct info_2 {
    long long t, d, a, f;
};
struct pt {
    int l, r, cnt;
    long long sum;
};

vector<pt> st;

vector<info_1> monster;
vector<info_2> queries;
vector<int> v, up[maxN+3], up_erase[maxN+3];

int cs(int x) {
    int l = 0, r = (int) v.size() - 1, p = -1;
    while (l <= r) {
        int mid = (l+r)/2;
        if (v[mid] >= x) {
            p = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return p;
}

int update(int id, int l, int r, int pos, int x, int t) {
    int u = (int) st.size();
    st.push_back(st[id]);
    st[u].cnt += t;
    st[u].sum += 1LL * x * t;

    if (l == r) return u;
    int mid = (l+r)/2;
    if (pos <= mid) {
        int tmp = update(st[u].l, l, mid, pos, x, t);
        st[u].l = tmp;
    } else {
        int tmp = update(st[u].r, mid+1, r, pos, x, t);
        st[u].r = tmp;
    }

    return u;
}

// tong k phan tu nho nhat
long long query(int id, int l, int r, int k) {
    if (id == 0 || k <= 0) return 0;
    if (st[id].cnt <= k) return st[id].sum;      // lay het nut nay
    if (l == r) return 1LL * v[l] * k;           // la co cnt > k: lay k con cung gia tri
    int mid = (l+r)/2;
    int lc = st[st[id].l].cnt;
    if (k <= lc) return query(st[id].l, l, mid, k);
    return st[st[id].l].sum + query(st[id].r, mid+1, r, k - lc);
}

int main() {
    if (fopen("F.INP", "r")) {
        freopen("F.INP", "r", stdin);
        freopen("F.OUT", "w", stdout);
    }
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int l, r, p; cin >> l >> r >> p;
        monster.push_back({l, r, p});
        v.push_back(p);
    }
    for (int i = 1; i <= m; ++i) {
        int t, d, a, f; cin >> t >> d >> a >> f;
        queries.push_back({t, d, a, f});
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    mn = oo, mx = -oo;
    for (int i = 0; i < (int) monster.size(); ++i) {
        int l = monster[i].l, r = monster[i].r;
        mn = min(mn, l);
        mx = max(mx, r);
        up[l].push_back(i);
        up_erase[r+1].push_back(i);
    }

    st.reserve(2 * n * 19 + 10);
    st.push_back({0, 0, 0, 0});

    root[mn-1] = 0;
    for (int t = mn; t <= mx; ++t) {
        root[t] = root[t-1];

        for (int i = 0; i < (int) up[t].size(); ++i) {
            int pos = up[t][i];
            int x = monster[pos].p;
            root[t] = update(root[t], 0, (int) v.size()-1, cs(x), x, 1);
        }
        for (int i = 0; i < (int) up_erase[t].size(); ++i) {
            int pos = up_erase[t][i];
            int x = monster[pos].p;
            root[t] = update(root[t], 0, (int) v.size()-1, cs(x), x, -1);
        }
    }

    power[0] = 1;
    for (int i = 0; i < (int) queries.size(); ++i) {
        int t = queries[i].t, d = queries[i].d, a = queries[i].a, f = queries[i].f;
        long long E = 1 + (1LL*d%f*power[i]%f + a%f)%f;

        power[i+1] = query(root[t], 0, (int) v.size()-1, (int) E);
        cout << power[i+1] << "\n";
    }

    return 0;
}
