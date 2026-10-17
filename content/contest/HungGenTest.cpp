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

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());

ll n, m, t, a[maxN+1];

ll Rand(ll l, ll r) {
    return l + rd() % (r-l+1);
}

void maketest() {
    ofstream cout("$(danghunghst2).INP");
    n = Rand(1, 1000);
    cout << n << "\n";
    return;
}

int main() {
    srand(time(nullptr));
    fastio;


    int T = 100;
    fto(i, 1, T) {
        maketest();
        system("$(danghunghst2)_LOW.exe");
        system("$(danghunghst2).exe");
        if (system("fc /w $(danghunghst2).OUT $(danghunghst2).ANS") != 0) {
            cout << "Test: " << i << " " << "SAI ROI HUNG OII\n";
            break;
        }
        cout << "Test: " << i << " " << "DUNG ROI HUNG OII\n";
    }

    return 0;
}
