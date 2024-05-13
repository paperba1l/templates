/**
 *  @author:      paperba1l
**/
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define pb          push_back
#define pf          push_front
#define mp          make_pair
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define vi          vector<int>
#define vll         vector<ll>
#define vvi         vector<vector<int>>
#define all(v)      (v).begin(),(v).end()
#define rep(i,n)    for(int i=0;i<n;i++)
#define mems(ar,x)  memset(ar,x,sizeof(ar));
#define prec(n)     fixed<<setprecision(n)
#define ischar(ch)  (ch>='a' && ch<='z')
#define isChar(ch)  (ch>='A' && ch<='Z')
#define print1(a)   cout<<a<<'\n';
#define print2(a,b)   cout<<a<<" "<<b<<'\n';
#define print3(a,b,c) cout<<a<<" "<<b<<" "<<c<<'\n';

#define boostio                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

// constants
const long double eps   = 1e-9;
const long double pi    = 3.14159265358979;
const vi month = {31,28,31,30,31,30,31,31,30,31,30,31};
const vvi dir4 = {{0,1},{1,0},{0,-1},{-1,0}}; 
const vvi dir8 = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const vvi dirk = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};

// MOD
ll mod = 1e9+7;

bool inMat(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
void sieve(vi &comp) {
    int n = comp.size();    
    for (int i = 2; i < n; i++) {
        if (comp[i] == 0) {
            for (int j = i * 2; j < n; j += i) {
                comp[j] = 1;
            }
        }
    }
    return;
}


struct BIT {
    vector<ll> f;
    BIT(int n) : f(n) {}
    void insert(int loc, ll val) {
        if (loc == 0) {
            f[loc] += val;
        } else {
            for (int i = loc; i < (int)f.size(); i += i & -i) {
                f[i] += val;
            }
        }
    }
    ll query(int loc) {
        ll res = f[0];
        for (int i = loc; i; i -= i & -i) {
            res += f[i];
        }
        return res;
    }
};

struct ST {
    struct data {
        ll sum , pref , suff , best ;
        data(int _val){
            sum = _val ;
            pref = suff = best = max(0,_val) ;
        }
    };

    ll operation(ll l , ll r) {
        return max(l,r);
        // data new_(0) ;

        // new_.sum = l.sum + r.sum ;
        // new_.suff = max(r.suff, l.suff + r.sum) ;
        // new_.pref = max(l.pref , l.sum + r.pref) ;
        // new_.best =  max({l.best,r.best, r.pref + l.suff}) ;

        // return new_ ;
    }

    int N;
    vector<ll> tree ;
    ST(int n = 1e5) {
        N = n;
        tree.assign(n*4, -1e18); // change this default value
    }
    void reset() {
        tree.assign(N*4, 0);
    }
    void print() {
        print1(tree[0]);
    }

    void buildFromArr(vi &arr, int i, int l, int r) {
        if(l == r) {
            tree[i] = arr[l]; // array value
            // tree[i] = data(arr[l]);
            return;
        }
        int left = (i<<1)+1, right = (i<<1)+2;
        int m = (l+r)/2;
        buildFromArr(arr, left, l, m);
        buildFromArr(arr, right, m+1, r);
        tree[i] = operation(tree[left], tree[right]);
    }

    void buildDefault(int i, int l, int r) {
        if(l == r) {
            tree[i] = 0; // default value
            return;
        }
        int left = (i<<1)+1, right = (i<<1)+2;
        int m = (l+r)/2;
        buildDefault(left, l, m);
        buildDefault(right, m+1, r);
        tree[i] = operation(tree[left], tree[right]);
    }

    void __update(int i, int l, int r, int idx, ll val) {
        if(idx < l or idx > r) return;
        if(l == r) {
            // tree[i] = data(val) ;
            tree[i] = operation(tree[i], val); return;
        }
        int left = (i<<1)+1, right = (i<<1)+2;
        int m = (l+r)/2;
        __update(left, l, m, idx, val);
        __update(right, m+1, r, idx, val);
        tree[i] = operation(tree[left], tree[right]);
        
    }
    void update(int idx, ll val) {
        __update(0, 0, N-1, idx, val);
    }

    ll __query(int i, int l, int r, int ql, int qr) {
        if(ql > r or qr < l) return -1e18;
        if(ql <= l and qr >= r) return tree[i];
        int left = 2*i+1, right = 2*i+2;
        int m = (l+r)/2;
        return operation(
             __query(left, l, m, ql, qr),
             __query(right, m+1, r, ql, qr)
        );
    }
    ll query(int ql, int qr) {
        return __query(0, 0, N-1, ql, qr);
    }
};

struct DSU {
    int num;
    vi par, rank;
    DSU(int size) {
        num = size;
        par = vi(size, -1);
        rank = vi(size, 1);
        iota(all(par), 0);
    }
    int find(int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
        if(par[x] == x) {
            return x;
        }

        par[x] = find(par[x]);
        rank[x] = 1;
        return par[x];
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) {
            return;
        }
        if(rank[x] < rank[y]) swap(x, y); // x is bigger
        rank[x]+=rank[y];
        par[y] = x;
    }
    ll size(int x) {
        return rank[find(x)];
    }
    vector<vector<int>> groups(){
        vector<vector<int>>ret(par.size());
        for(int i=0;i<par.size();i++){
            ret[find(i)].push_back(i);
        }
        return ret;
    }
    void print() {
        auto tmp=groups();
        for(int i=0;i<par.size();i++){
            if(!tmp[i].empty()){
                for(auto z:tmp[i]) {
                    print2(z, ',');
                }
                print1(endl);
            }
        }
    }
};

struct Trie {
    vvi trie;
    vi cnt;
    int N, sz;
    Trie(int n = 1e6) { 
        N = n;
        cnt = vi(n, 0);
        trie = vvi(n, vi(26,0));
        extend();
    }
    
    void extend() {
        for (int i = 0; i < 26; ++i) {
            trie[sz][i] = 0;
        }
        cnt[sz] = 0, sz++;
    }

    int next(int u, int v) {
        if (!trie[u][v]) {
            trie[u][v] = sz;
            extend();
        }
        return trie[u][v];
    }

    void add(string s) {
        int now = 0;
        for (char c : s) {
            now = next(now, c - 'a');
            cnt[now]++;
        }
    }

    void del(string s) {
        int now = 0;
        for (char c : s) {
            now = next(now, c - 'a');
        }
        cnt[now]--;
    }

    void reset() { 
        sz = 0, extend(); 
    }
};

void solve(int __tc) {
    int n;
    cin >> n;


    ll ans = 0;
    rep(i, n) {

    }

    print1(ans);


    
}


int main() {
    boostio;
    int t = 1;
    
    // cin>>t;

    while (t--) {
        solve(t);
    }
    return 0;
}

