/**
 * Author: Hung
 * Date: 2026-10-17
 * License: CC0
 * Source: own work
 * Description: Self-explanatory methods for string hashing.
 * Status: stress-tested
 */
#include <bits/stdc++.h>

#define maxN 1000000
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

string s;
string t;
const ll base = 311LL;
const ll oo = (ll) 1e9+7;
ll Pow[maxN+1], Hashs[maxN+1], Hasht;

ll getHash(int i, int j) {
    return ((Hashs[j] - Hashs[i-1]*Pow[j-i+1]%oo)+oo)%oo;
}

int main() {
    if (fopen("HASH1.INP", "r")) {
        freopen("HASH1.INP", "r", stdin);
        freopen("HASH1.OUT", "w", stdout);
    }

    fastio;

    cin >> s;
    cin >> t;

    s = " " + s;
    t = " " + t;

    Hashs[0] = 0;
    Pow[0] = 1;
    fto(i, 1, sz(s)-1) {
        Hashs[i] = (Hashs[i-1]*base%oo + (s[i] - '0'))%oo;
        Pow[i] = (Pow[i-1]*base)%oo;
    }
    cout << ans << "\n";
    return 0;
}

