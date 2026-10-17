#include <bits/stdc++.h>

#define maxN 200000
#define ll long long
#define sz(a) (int) a.size()
#define pb push_back
#define fto(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define fdto(i, a, b) for (int i = (int)(a); i >= (int)(b); --i)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(a) (a).begin(), (a).end()
#define ii pair<int, int>
#define ff first
#define ss second

using namespace std;

template<typename T> void bug(T &&t) {cout << t << "\n";}
template<typename T, typename... U> void bug(T &&t, U &&...u) {
    cout << t << " ";
    bug(u...);
}

void minimize(ll &x, const ll &y) {
    if (x > y) x = y;
}

int n;
ll C, h[maxN+1], f[maxN+1];
const ll oo = (ll) 1e18+7;

struct line {
    ll a, b;
    ll value(ll x) {
        return a*x + b;
    }
};
line st[4*maxN+1];

void init() {
    fto(i, 1, 4*n) st[i] = {0, oo};
    return;
}

void update(int root, int l, int r, line x) {
    if (l == r) {
        if (st[root].value(h[l]) > x.value(h[l])) swap(st[root], x);
        return;
    }
    int mid = (l+r)/2;
    if (x.a < st[root].a) {
        swap(st[root], x);
    }
    if (st[root].value(h[mid]) < x.value(h[mid])) {
        update(root*2, l, mid, x);
    } else {
        swap(st[root], x);
        update(root*2+1, mid+1, r, x);
    }
}

ll query(int root, int l, int r, int i, int j, ll x) {
    if (l == r) return st[root].value(x);
    int mid = (l+r)/2;
    if (x <= h[mid]) return min(st[root].value(x), query(root*2, l, mid, i, j, x));
    return min(st[root].value(x), query(root*2+1, mid+1, r, i, j, x));
}

int main() {
    if (fopen("FROG3.INP", "r")) {
        freopen("FROG3.INP", "r", stdin);
        freopen("FROG3.OUT", "w", stdout);
    }

    fastio;

    cin >> n >> C;
    fto(i, 1, n) cin >> h[i];

    fto(i, 1, n) f[i] = oo;

    f[1] = 0;
    init();
    update(1, 1, n, {-2*h[1], h[1]*h[1]});

    //bug(-2*h[1], h[1]*h[1]);

    fto(i, 2, n) {
        ll tam = query(1, 1, n, 1, i-1, h[i]);
        f[i] = tam + C + h[i]*h[i];
        //bug(i, tam, f[i]);
        update(1, 1, n, {-2*h[i], h[i]*h[i] + f[i]});
        //bug(-2*h[i], h[i]*h[i] + f[i]);
    }

    cout << f[n] << "\n";
    return 0;
}
