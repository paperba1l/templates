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
#define vii         vector<pii>
#define vll         vector<ll>
#define all(v)      (v).begin(),(v).end()
#define sortv(v)    sort(all(v));
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

class SegTree {
    struct data{
        ll sum , pref , suff , best ;
        data(int _val){
            sum = _val ;
            pref = suff = best = max(0,_val) ;
        }
    };
    vector<data> tree ;

    public :
    SegTree(int n = 1e5){
        tree.assign(n*4,data(0)) ;
    }

    void currbest(){
        cout << tree[1].best << endl ;
    }

    void update(int node, int index , int st, int sp , int value){
        if(st > index || sp < index )  return ;
        if(st == sp){
            tree[node] = data(value) ;
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1) ;

            update(lft,index,st,mid,value) ;
            update(rght,index,mid+1,sp,value) ;
            tree[node] = operation(tree[lft],tree[rght]) ;
        }
    }

    void build(const vector<int> &v , int node , int st , int sp ){
        if(st == sp){
            tree[node] = data(v[st]) ;
        }
        else{
            int lft = (node << 1) ;
            int rght = lft + 1;
            int mid = st + ((sp-st)>>1) ;

            build(v,lft,st,mid) ;
            build(v,rght,mid+1,sp) ;
            tree[node] = operation(tree[lft],tree[rght]) ;
        }
    }

    data operation(data l , data r){
        data new_(0) ;

        new_.sum = l.sum + r.sum ;
        new_.suff = max(r.suff, l.suff + r.sum) ;
        new_.pref = max(l.pref , l.sum + r.pref) ;
        new_.best =  max({l.best,r.best, r.pref + l.suff}) ;

        return new_ ;
    }
};

struct DSU {
    vector<ll> data;
    ll num;
    DSU(ll size) {
        data = vector<ll>(size, -1);
        iota(all(data), 0);
        num = size;
    }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
            if (data[y] < data[x]) {
                swap(x, y);
            }
            data[x] += data[y]; data[y] = x;
            num--;
        }
        return x != y;
    }
    bool find(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] == x ? x : data[x] = root(data[x]);
    }
    ll size(int x) {
        return -data[root(x)];
    }
    vector<vector<int>>groups(){
        vector<vector<int>>ret(data.size());
        for(int i=0;i<data.size();i++){
            ret[root(i)].push_back(i);
        }
        return ret;
    }
    void print() {
        auto tmp=groups();
        for(int i=0;i<data.size();i++){
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
