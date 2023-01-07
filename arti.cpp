#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sort(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define pb push_back
#define fastIO() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define go goto
//#define endl "\n"
#define MAX 1000000
ll mod=1000000007;
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

vector<ll>g[100010];
ll low[100010],st[100010],art[100010],vis[100010],tim;
vector<pair<ll,ll>>vp;
void init()
{
    tim=1;
    for(ll i=0; i<=100000; i++)
    {
        g[i].clear();
        low[i]=st[i]=art[i]= vis[i]=0;
    }
    vp.clear();
}
void  dfs(ll v,ll p=-1)
{
    vis[v]=1;
    st[v]=low[v]=tim++;
    int chl=0;
    for(ll u : g[v])
    {
        if(u!=p)
        {
            if(vis[u]==0)
            {
                dfs(u,v);
                low[v]=min(low[v],low[u]);
                if(low[u]>st[v])
                {
                    art[v]=1;
                    if(v<u)
                    vp.pb({v,u});
                    else vp.pb({u,v});
                }
                chl++;
            }
            else low[v]=min(low[v],st[u]);
        }
    }

}
int main()
{
    fastIO();
    int t,tn=0;

//    cin>>t;
//    while(t--)
    {
        ll a,b,c,d,e,i,j,k,l;
        while(cin>>a)
        {
            init();
            for(int x=0; x<a; x++)
            {
                char ch;
                cin>>b>>ch>>c>>ch;
                for(i=0; i<c; i++)
                {
                    cin>>d;
                    g[b].pb(d);
                }

            }
            for(i=0; i<a; i++)
            {
                if(vis[i]==0)
                {
                    dfs(i);
                }
            }
            sort(vp);
            cout<<vp.size()<<" critical links"<<endl;
            for(i=0;i<vp.size();i++){
                cout<<vp[i].first<<" - "<<vp[i].second<<endl;
            }
            cout<<endl;
        }

    }
    return 0;
}
