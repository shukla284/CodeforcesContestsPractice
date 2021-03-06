
/*
   Author: Shivam Shukla
*/
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pair<ll,ll> > vpll;
 
const int MOD=1e9+7;
const int MAX=1e5+5;
const double PI= acos(-1.0);
const long double EPS=1e-70;
const int64_t INF=1e18+10;
 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(0), cout.tie(0)
#define trace(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define vi vector<int>
#define vl vector<ll>
#define vs vector<str>
#define vc(x) vector<x>
#define mapll map<ll,ll>
#define mapib map<int,bool>
#define mapiv map<int,vector>
#define mapsi map<string,int>
#define rep(i,j,k) for(ll i=j;i<k;i++)
#define down(i,j,k) for(ll i=j;i>=k;i--)
#define repa(i,n) for(ll i=0;i<n;i++)
#define dowa(i,n) for(ll i=n;i>=0;i--)
#define reps(i,j,k,s) for(ll i=j;i<k;i+=s)
#define downs(i,j,k,s) for(ll i=j;i>=k;i-=s)
#define trv(i,x) for(auto i:x)
#define pb push_back
#define eb emplace_back
#define sz(x) (int)x.size()
#define ff first
#define ss second
#define str string 
#define dub double
#define pqmax priority_queue<ll>
#define pqmin priority_queue<ll,vl,greater<ll> >
 
template<typename t> t lcm(t a, t b) {return (a*b)/__gcd(a,b);}
template<typename t> t gcd(t a, t b) {return __gcd(a,b);}
template<typename t> t mul_mod(t a, t b, t m){t res=((a%m)*(b%m)%m); return res;}
template<typename t> t add_mod(t a, t b, t m){t res=((a%m)+(b%m))%m; return res;}
template<typename t> t pow_mod(t a,t b,t m) {t res=1;while(b){if(b&1) res=mul_mod(res,a,m);a=mul_mod(a,a,m), b>>=1;} return res%m;}
template<typename t> vc(t) num_vec(t num) {t res; while (num) res.pb(num%10), num/=10; return res;}
template<typename t> t vec_num(t vec) {t res=0; ll mul=1; repa(i,sz(vec)) res=vec[i]*mul, mul*=10; return res;}
 

int32_t main(int argc,char** argv){
	fastio();
	auto tstart= clock();
 
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif   

    int n; cin >> n;
    vpll v(n); repa(i, n) cin >> v[i].ff >> v[i].ss;
    
    vector<pair<long double, int>> theta(n);
    repa(i, n)  {
       
       long double ang = atan((long double) v[i].ss /(long double) v[i].ff);
       
       if (v[i].ff >= 0 && v[i].ss < 0)
       	   ang += (2 * PI);

       else if (v[i].ff < 0 && v[i].ss >= 0)
       	   ang += PI;

       else if (v[i].ff < 0 && v[i].ss < 0)
           ang += PI; 

       
       theta[i].ff = ang;
       theta[i].ss = i;
    }
    

    sort(all(theta));

    long double mnd = numeric_limits<double>::max();
    auto ans = make_pair(-1, -1);
 
    rep(i, 1, sz(theta)) {
    	long double diff = abs(theta[i].ff - theta[i - 1].ff);
        
        diff = min(diff, (2 * PI - diff));
    	if (mnd - diff > EPS) {
    		 ans.ff = theta[i - 1].ss, ans.ss = theta[i].ss;
    		 mnd = min(mnd, diff);
        }
    }
    
    long double diff = abs(theta[0].ff - theta[sz(theta) - 1].ff);
    diff = min(diff, (2 * PI - diff));
    if (mnd - diff >= EPS){
    	ans.ff = theta[sz(theta) - 1].ss, ans.ss = theta[0].ss;
    	mnd = min(mnd, diff);
    }

    cout << ans.ff + 1 << " " << ans.ss + 1 << endl;

    cerr<<setprecision(2)<<fixed<<"Time elapsed: "<<(double)(clock() - tstart)/CLOCKS_PER_SEC<<endl; 
    return 0; 
}