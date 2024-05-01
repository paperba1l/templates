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
#define vvi         vector<vector<int>>
#define vll         vector<ll>
#define all(v)      (v).begin(),(v).end()
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define mset(ar,x)  memset(ar,x,sizeof(ar));
#define prec(n)     fixed<<setprecision(n)
#define ischar(ch)  (ch>='a' && ch<='z')
#define isChar(ch)  (ch>='A' && ch<='Z')
#define println(a)      cout<< a <<endl;
#define println2(a,b)   cout<<a<<" "<<b<<endl;
#define println3(a,b,c) cout<<a<<" "<<b<<" "<<c<<endl;

#define boostio                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

// constants
const long double eps   = 1e-9;
const long double pi    = 3.14159265358979;
const ll mod            = 1e9+7;

vi month = {31,28,31,30,31,30,31,31,30,31,30,31};
vvi dir4 = {{0,1},{1,0},{0,-1},{-1,0}}; 
vvi dir8 = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
vvi dirk = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
bool inGrid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
//
struct BIT {
    vector<ll> f;
    BIT(int n) : f(n) {}
    void insert(int loc, int val) {
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

class ST {
    struct data{
        ll sum , pref , suff , best ;
        data(int _val){
            sum = _val ;
            pref = suff = best = max(0,_val) ;
        }
    };
    vector<int> tree ;

public :
    ST(int n = 1e5){
        tree.assign(n*4, 0); // change this default value
    }

    void currbest(){
        cout << tree[0] << endl ;
    }

    void build(vi &arr, int i, int l, int r){
        if(l == r){
            tree[i] = arr[l];
            // tree[i] = data(arr[l]);
            return;
        }
        int left = 2*i + 1, right = 2*i + 2;
        int m = (l+r)/2;
        build(arr, left, l, m);
        build(arr, right, m+1, r);
        tree[i] = (tree[left] + tree[right]);
    }

    void update(int i, int l, int r, int idx, int val){
        if(idx < l or idx > r)  return;
        if(l == r){
            // tree[i] = data(val) ;
            tree[i] = val;
            return;
        }
        int left = 2*i + 1, right = 2*i + 2;
        int m = (l+r)/2;
        update(left, l, m, idx, val);
        update(right, m+1, r, idx, val);
        tree[i] = (tree[left] + tree[right]);
    }

    int query(int i, int l, int r, int ql, int qr){
        if(ql > r or qr < l) return 0;
        if(ql <= l and qr >= r) return tree[i];
        int left = 2*i + 1, right = 2*i + 2;
        int m = (l+r)/2;
        return query(left, l, m, ql, qr) + query(right, m+1, r, ql, qr);
    }


    int operation(int l , int r) {
        return l + r;
        // data new_(0) ;

        // new_.sum = l.sum + r.sum ;
        // new_.suff = max(r.suff, l.suff + r.sum) ;
        // new_.pref = max(l.pref , l.sum + r.pref) ;
        // new_.best =  max({l.best,r.best, r.pref + l.suff}) ;

        // return new_ ;
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
    vector<vector<int>>groups(){
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
                    cout<<z<<",";
                }
                cout<<endl;
            }
        }
    }
};




const ll n = 1e6+10;


void solve(int __tc) {
    int n;
    cin >> n;

    vi arr(n);
    for(auto &x : arr) {
        cin >> x;
    }

    ST st(n);
    st.build(arr, 0, 0, n-1);

    
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
