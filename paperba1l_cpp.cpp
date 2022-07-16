/**
 *  @author:      paperba1l
**/
#include <bits/stdc++.h>
using namespace std;

#define ff          first
#define ss          second
#define pb          push_back
#define pf          push_front
#define mp          make_pair
#define vi          vector<int>
#define vl          vector<ll>
#define pii         pair<int,int>
#define all(v)      (v).begin(),(v).end()
#define sortv(v)    sort(all(v))
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define mset(v, x)  memset(v,x,sizeof(vec))
#define prec(n)     fixed<<setprecision(n)
#define ischar(ch)  (ch>='a' && ch<='z')
#define isChar(ch)  (ch>='A' && ch<='Z')
#define pr(a)       cout<<a<<endl
#define pr2(a,b)    cout<<a<<" "<<b<<endl
#define prY         cout<<"YES"<<endl
#define prN         cout<<"NO"<<endl
#define boostio                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
// Input macros

typedef long long int ll;
typedef unsigned long long ull;

inline int gcd(int a, int b) { return (b ? gcd(b, a % b) : a); }
inline string toString(ll n) {stringstream ss; ss << n;return ss.str();}

const long double EPS   = 1e-9;
const long double PI    = 3.14159265358979;

//int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

const ll mod = 1e9+7;
const ll N = 5000;

void solve(int __tc) {
    int n, m;
    cin >> n >> m;
    
    int a;
    rep(i, 0, n-1) {
        cin>>a;
    }
    
    return;
}

int main() {
    boostio;
    int t = 1;

    // cin>>t;
    while (t--){
        solve(t);
    }
    return 0;
}
