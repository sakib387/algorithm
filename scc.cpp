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

vector<ll>v[100005],vr[100005];
ll vis[100009];
void init()
{
    for(ll i=0; i<100005; i++)
    {
        vis[i]=0;
        v[i].clear();
        vr[i].clear();
    }
}
stack<ll>st;
void dfs(ll a)
{
    vis[a]=1;
    for(ll i=0; i<v[a].size(); i++)
    {
        if(vis[v[a][i]]==0)
        {
            dfs(v[a][i]);
        }
    }
    st.push(a);
}
void dfs2(ll a)
{
    vis[a]=2;
    for(ll i=0; i<v[a].size(); i++)
    {
        if(vis[v[a][i]]==1)
        {
            dfs2(v[a][i]);
        }
    }
}
int main()
{
    fastIO();
    int t,tn=0;

    cin>>t;
    while(t--)
    {tn++;
        ll a,b,c=0,e,d,i,j,l=0,k=0;
        // while(cin>>a>>b)
        {

            l=0;
            k=0;
            cin>>a>>b;
            if(a==0&&b==0)
            {
                return 0;
            }
            init();
            for(i=1; i<=b; i++)
            {
                cin>>c>>d;
                //if(e==2)
                {
                    v[c].pb(d);
                   // v[d].pb(c);
                    //vr[c].pb(d);
                    vr[d].pb(c);
                }

            }
        }
        for(i=1; i<=a; i++)
        {
            if(vis[i]==0)
            {
                l++;
                dfs(i);
            }
        }
        while(st.size())
        {
           // for(i=1; i<=a; i++)
            {
                    c=st.top();
                if(vis[c]!=2)
                {
                    dfs2(c);
                    k+=1;
                }
            }
            st.pop();
        }


        cout<<"Case "<<tn<<": "<<k<<endl;


    }
    return 0;
}
