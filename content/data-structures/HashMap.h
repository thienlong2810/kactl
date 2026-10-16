#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct custom_hash{
    size_t operator() (uint64_t x) const{
        uint64_t R = rng() | 1;
        return __builtin_bswap64(x * R);
    }
};
template<typename T1 , typename T2>
using Umap = gp_hash_table<T1 , T2 , custom_hash>;
template<typename T>
using Uset = gp_hash_table<T , null_type , custom_hash>;
