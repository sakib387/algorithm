/*

        بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ
      لَا إِلَٰهَ إِلَّا ٱللَّٰهُ مُحَمَّدٌ رَسُولُ ٱللَّٰهِ

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sort(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define pb push_back
#define fastIO() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define go goto
#define MAX 1000000
#define F first
#define S second

//set_operation

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>mst;


const ll mod=1e9 + 7;
const ll INF = 10000;

int dx[]= {-1,0,0,1,-1,-1,1,1};
int dy[]= {0,-1,1,0,-1,1,-1,1};
int kx[]= {-2,-2,2,2,-1,-1,1,1};
int ky[]= {-1,1,-1,1,-2,2,-2,2};
/*nCr
ll inv[MAX];ll fact[MAX];ll c_inv[MAX];void init(){for(ll i=1; i<=MAX; i++){if(i==1)fact[i]=1;else fact[i]=(fact[i-1]*i)%mod;}inv[1] = 1;for(int i = 2; i <=MAX; ++i)inv[i] = mod - (mod/i) * inv[mod%i] % mod;for(ll i=1; i<=MAX; i++){if(i==1)c_inv[i]=inv[i];else c_inv[i]=(c_inv[i-1]*inv[i])%mod;}c_inv[0]=1;fact[0]=1;}ll nCr(ll n,ll r){init();return (((fact[n]*c_inv[r])%mod)*c_inv[n-r])%mod;}
*/
/*
ll power(ll a,ll b,ll md){if(b == 0){return 1;}ll ans = power(a,b/2,md);ans *= ans;ans %= md;if(b % 2){ans *= a;}return ans % md;}
*/
/*
seiv()
ll are[1000009];vector<ll>sv;void seiv(){ll n=10000007,i,j;;are[1]=1;for(i=4; i<=n; i+=2)are[i]=1;for(i=3; i<=n; i+=2){if(are[i]==0){for(j=i*i; j<=n; j+=i*2)are[j]=1;}}for(i=2; i<=n; i++){if(are[i]==0)sv.pb(i);}}

*/
#define endl "\n"

vector<ll>gr[30005],vx,vy;
ll lca[30008][30];

ll are[2*30006];
ll st[30006];
ll en[30006];

ll N;
void init()
{
    N=1;
    for(ll i=0; i<=30000; i++)
    {
        en[i]=0;
        st[i]=0;
        are[i]=0;
        //ar[i]=0;

        gr[i].clear();
    }
    for(ll i=3000;i<=2*30000;i++)are[i]=0;

}
void skb(ll a,ll p=-1)
{
    //ar[N]=a;
    st[a]=N;
    N++;

    lca[a][0]=p;
    for(int i:gr[a])
    {
        if(i!=p)
        {
            skb(i,a);
        }
    }
    // ar[N]=a;
    en[a]=N;
    N++;


}
bool is_ancestor(int u, int v)
{
    return st[u] <= st[v] && en[u] >= en[v];
}


int LCA(int u, int v,int a)
{
    int l=22;
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i)
    {
        if (!is_ancestor(lca[u][i], v)&&lca[u][i]!=-1)
        {

            u =lca[u][i];
        }
    }
    return lca[u][0];
}

void update(ll indx,ll data)
{
    while(indx<2*30006)
    {
        are[indx]+=data;
        indx+=(indx&(-indx));
    }
}
ll get(ll indx)
{
    int sum=0;
    while(indx>0)
    {
        sum+=are[indx];
        indx-=(indx&(-indx));
    }
    return sum;
}

int main()
{
    fastIO();
    // seiv();
    int t=1,tn=0;
    cin>>t;
    while(t--)
    {
        init();
        memset(lca,-1,sizeof(lca));
        ll a,b,c,d,e=-1,i,j,f= 1,g= 0,h=-1,k=0,r,l=0,an=0;
        vector<ll>v,x;
        cin>>a;
        for(i=1; i<=a; i++)
        {
            cin>>b;
            v.pb(b);
        }
        for(i=1; i<a; i++)
        {
            cin>>c>>d;
            gr[c].pb(d);
            gr[d].pb(c);
        }
        N=1;
        skb(0);
        for(int j=1; j<=22; j++)
        {
            for(int i=0; i<=a; i++)
            {
                if(lca[i][j-1]!=-1)
                {
                    int par=lca[i][j-1];
                    lca[i][j]=lca[par][j-1];
                }
            }
        }



        for(i=0; i<v.size(); i++)
        {
            c=v[i];
           // cout<<i<<" = "<<st[i]<<" "<<en[i]<<endl;
            update(st[i],c);
            update(en[i],-c);

        }
        cin>>b;
        cout<<"Case "<<++tn<<":"<<endl;
        while(b--)
        {
            cin>>c>>d>>e;

            if(c==0)
            {
                an=0;
                l=LCA(d,e,a);
              //  cout<<"L = "<<l<<endl;

                an+=get(st[d]);
                an+=get(st[e]);
                an-=get(st[l]);
                an-=get(st[l]);
                an+=v[l];

              //  cout<<get(st[d])<<" "<<get(st[e])<<" "<<get(st[l])<<" "<<v[l]<<endl;
                // cout<<st[d]<<" g "<<st[e]<<" "<<st[l]<<endl;
                cout<<an<<endl;
            }
            else
            {

                g=e-v[d];

                update(st[d],g);
                update(en[d],-g);
                v[d]=e;

            }
        }


    }

    return 0;
}
