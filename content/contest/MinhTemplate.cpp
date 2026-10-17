#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ul;
typedef unsigned long long ull;

#define mask(i) (1LL << (i))
#define getbit(mask, i) (((mask) >> (i)) & 1)
#define all(v) (v).begin(), (v).end()
#define IN "A.INP"
#define OUT "A.OUT"
#define int long long

ll gcd(ll a, ll b){return __gcd(a, b);}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}

ll lastbit(ll mask){return (mask) & (-mask);}
int pop_cnt(ll mask){return __builtin_popcountll(mask);}
int ctz(ull mask){return __builtin_ctzll(mask);}

template <class T1, class T2>
    bool maximize(T1 &a, T2 b){
        if (a < b) {a = b; return true;}
        return false;
    }

template <class T1, class T2>
    bool minimize(T1 &a, T2 b){
        if (a > b) {a = b; return true;}
        return false;
    }

template <class T>
    void printarr(T the_array_itself, string separator = " ", string finish = "\n", ostream &out = cout){
        for(auto item: the_array_itself) out << item << separator;
        out << finish;
    }

template <class T>
    void remove_dup(vector<T> &a){
        sort(all(a));
        a.resize(unique(all(a)) - a.begin());
    }

const long long inf = 1e18, MOD = 1e9+7;

struct Modular{
    ll x;
    Modular(ll _x = 0){
        x = _x % MOD;
        if (x < 0) x += MOD;
    }
    Modular& operator += (Modular y){
        x += y.x;
        if (x >= MOD) x -= MOD;
        return *this;
    }
    Modular operator + (Modular y) {
        Modular tmp = *this;
        return tmp += y;
    }
 
    Modular& operator -= (Modular y){
        x -= y.x;
        if (x < 0) x += MOD;
        return *this;
    }
    Modular operator - (Modular y) {
        Modular tmp = *this;
        return tmp -= y;
    }
 
    Modular& operator *= (Modular y){
        x *= y.x;
        if (x >= MOD) x %= MOD;
        return *this;
    }
    Modular operator * (Modular y) {
        Modular tmp = *this;
        return tmp += y;
    }
 
    // use at your own risk
    bool operator == (Modular y){
        return x == y.x;
    }
    bool operator != (Modular y){
        return x != y.x;
    }
};
ostream& operator << (ostream& out, Modular x){
    out << x.x;
    return out;
}
 
Modular fast_pow(Modular a, int n){
    Modular ans = 1;
    while(n > 0){
        if (n & 1) ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}
Modular inverse(Modular a){return fast_pow(a, MOD - 2);}
 
const int N = 6e5 + 69;
vector<Modular> fact(N), ifact(N);
 
void prepare(){
    fact[0] = 1;
    for(int i = 1; i < N; ++i) fact[i] = fact[i-1] * i;
    ifact[N - 1] = inverse(fact[N-1]);
    for(int i = N-1; i >= 1; --i) ifact[i-1] = ifact[i] * i;
}
 
Modular C(int n, int k){
    if (k < 0 || k > n) return 0;
    return fact[n] * ifact[k] * ifact[n-k];
}
 
Modular Catalan(int n){
    if (n % 2 != 0) return 0;
    return C(n, n / 2) - C(n, n / 2 + 1);
}

// End of the template, let's drink a cup of water before reading:D
// Template use for ONLINE JUDGE

void solve(){
    
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solve();
    cerr << "\nTime elapsed: " << (1.0 * clock() / CLOCKS_PER_SEC) << " s.\n";
    return 0;
}
