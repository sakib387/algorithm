#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sort(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define pb push_back
#define fastIO() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define go goto
#define MAX 1000000
//set_operation
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>mst;

ll mod=998244353;
ll ceil(ll a, ll b)
{
    return a % b == 0 ? a / b : a / b + 1;
}

///nCr
ll inv[MAX];
ll fact[MAX];
ll c_inv[MAX];
ll nCr(ll n,ll r)
{
    for(ll i=1; i<=MAX; i++)
    {
        if(i==1)
            fact[i]=1;
        else
            fact[i]=(fact[i-1]*i)%mod;
    }
    inv[1] = 1;
    for(int i = 2; i <=MAX; ++i)
        inv[i] = mod - (mod/i) * inv[mod%i] % mod;
    for(ll i=1; i<=MAX; i++)
    {
        if(i==1)
            c_inv[i]=inv[i];
        else
            c_inv[i]=(c_inv[i-1]*inv[i])%mod;
    }
    c_inv[0]=1;
    return (((fact[n]*c_inv[r])%mod)*c_inv[n-r])%mod;
}
///
ll power(ll a,ll b,ll mod)
{
    if(b == 0)
    {
        return 1;
    }
    ll ans = power(a,b/2,mod);
    ans *= ans;
    ans %= mod;
    if(b % 2)
    {
        ans *= a;
    }
    return ans % mod;
}
ll ar[1000009];
vector<ll>sv;
void seiv()
{
    ll n=1000000,i,j;
    ar[1]=1;
    for(i=4; i<=n; i+=2)
        ar[i]=1;
    for(i=3; i<=n; i+=2)
    {
        if(ar[i]==0)
        {
            for(j=i*i; j<=n; j+=i*2)
                ar[j]=1;
        }
    }
    for(i=2; i<=n; i++)
    {
        if(ar[i]==0)
            sv.pb(i);
    }
}

        ll pi[1000009]= {0};
int main()
{
    fastIO();
    int t,tn=0;
//    seiv();
    cin>>t;
    while(t--)
    {
        ll  a,b,c,d,i,j;
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        pi[0]=0;
        for(i=1,j=0; i<pat.size();)
        {
            if(pat[i]==pat[j])
            {
                j++;
                pi[i]=j;
                i++;
            }
            else
            {
                if(j==0)i++;
                else j=pi[j-1];
            }
        }
        vector<ll>v;
        j=0;
        for(i=0; i<s.size();)
        {
            if(s[i]==pat[j])
            {
                i++;
                j++;
                if(j==pat.size()){
                    v.pb(i-j+1);j=pi[j-1];
                }
            }
            else
            {
                if(j==0)i++;
                else j=pi[j-1];
            }
        }
        if(v.size()>0){
            cout<<v.size()<<endl;
            for(i=0;i<v.size();i++){
                cout<<v[i]<<" ";
            }cout<<endl;
        }
        else cout<<"Not Found"<<endl;
        for(i=0;i<pat.size();i++){
            pi[i]=0;
        }

    }
    return 0;
}
