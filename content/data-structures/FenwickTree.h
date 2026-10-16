#define lastbit(x) ((x) & (-x))
struct Fenwick{
    int n;
    vector<ll> bit;
    Fenwick(int _n){
        n = _n;
        bit.assign(n + 1 , 0);
    }
    void add(int id , ll x){
        for(; id <= n ; id += lastbit(id)) bit[id] += x;
    }
    ll getPre(int id){
        ll sum = 0;
        for(; id > 0 ; id -= lastbit(id)) sum += bit[id];
        return sum;
    }
    ll query(int l , int r){
        return getPre(r) - getPre(l - 1);
    }
    int upperBound(ll target){ // return the first index which prefix > target
        int pos = 0;
        ll sum = 0;
        for(int sz = (1 << 25) ; sz > 0 ; sz /= 2){
            if(pos + sz <= n && sum + bit[pos + sz] <= target){
                sum += bit[pos + sz];
                pos += sz;
            }
        }
        return pos + 1; // return n + 1 if total <= target
    }
};
