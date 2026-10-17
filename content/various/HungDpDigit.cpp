#include <bits/stdc++.h>

#define maxN 100000
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

string a, b;
vector<int> v;

int dp(int i, int checka, int checkb) {
    if (i == sz(b)) {
        fto(i, 0, sz(v)-1) cout << v[i];
        cout << "\n";
        return 0;
    }

    int sd = 0, sc = 9;
    if (checka == 1) sd = (int) a[i] - '0';
    if (checkb == 1) sc = (int) b[i] - '0';

    int ans = 0;
    fto(x, sd, sc) {
        v.pb(x);
        ans = ans + dp(i+1, (x == sd) && (checka == 1), (x == sc) && (checkb == 1));
        v.pop_back();
    }
    return 0;
}

int main() {
    if (fopen("digit.INP", "r")) {
        freopen("digit.INP", "r", stdin);
        freopen("digit.OUT", "w", stdout);
    }

    fastio;
    cin >> a >> b;

    while (sz(a) < sz(b)) a = "0" + a;

    cout << dp(0, 1, 1) << "\n";
    return 0;
}
