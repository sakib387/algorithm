/*

        بِسْمِ اللَّهِ الرَّحْمَٰنِ الرَّحِيمِ
      لَا إِلَٰهَ إِلَّا ٱللَّٰهُ مُحَمَّدٌ رَسُولُ ٱللَّٰهِ

*/
#include<bits/stdc++.h>
using namespace std;
#define ll int
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
const ll INF = 1e18;

int dx[]= {-1,0,0,1,-1,-1,1,1};
int dy[]= {0,-1,1,0,-1,1,-1,1};
int kx[]= {-2,-2,2,2,-1,-1,1,1};
int ky[]= {-1,1,-1,1,-2,2,-2,2};
/*nCr
ll inv[MAX];ll fact[MAX];ll c_inv[MAX];void init(){for(ll i=1; i<=MAX; i++){if(i==1)fact[i]=1;else fact[i]=(fact[i-1]*i)%mod;}inv[1] = 1;for(int i = 2; i <=MAX; ++i)inv[i] = mod - (mod/i) * inv[mod%i] % mod;for(ll i=1; i<=MAX; i++){if(i==1)c_inv[i]=inv[i];else c_inv[i]=(c_inv[i-1]*inv[i])%mod;}c_inv[0]=1;}ll nCr(ll n,ll r){init();return (((fact[n]*c_inv[r])%mod)*c_inv[n-r])%mod;}
*/
/*
ll power(ll a,ll b,ll md){if(b == 0){return 1;}ll ans = power(a,b/2,md);ans *= ans;ans %= md;if(b % 2){ans *= a;}return ans % md;}
*/

/*seiv
ll are[1000009];vector<ll>sv;void seiv(){ll n=100000,i,j;are[1]=1;for(i=4; i<=n; i+=2)are[i]=1;for(i=3; i<=n; i+=2){if(are[i]==0){for(j=i*i; j<=n; j+=i*2)are[j]=1;}}for(i=2; i<=n; i++){if(are[i]==0)sv.pb(i);}}
*/

#define endl "\n"

struct tri
{
    tri* ar[10];
    int   cn;

    tri()
    {
        for(int i=0; i<=9; i++)ar[i]=NULL;

        cn=0;
    }
};
ll ans=0;

void insert(string s,tri *root)
{
    tri *tmp=root;
    for(int i=0; i<s.size(); i++)
    {
        int c=s[i]-'0';
        if(tmp->cn==1)
        {
            ans=1;
        }
        if(tmp->ar[c]!=NULL)
        {
            tmp=tmp->ar[c];

            ans=max((i+1)*tmp->cn,ans);
        }
        else
        {
            tmp->ar[c]=new tri();
            tmp=tmp->ar[c];

            ans=max((i+1)*tmp->cn,ans);
        }
        if(tmp->cn==1)
        {
            ans=1;
        }
    }
    if(tmp->cn==1)
    {
        ans=1;
    }
    tmp->cn=1;
}
void delete_(tri *root)
{
    for(int i=0; i<=9; i++)
    {
        if(root->ar[i]!=NULL)
        {
            delete_(root->ar[i]);
        }
    }
    delete(root);
}
int main()
{
    fastIO();
    //seiv();
    int t=1,tn=0;
    cin>>t;
    while(t--)
    {
        tri *root=new tri();
        ll a,b,c,d,e=0,i,j,f= 1,g= 0,h=-1,k=0,r,l=0,an=0;
        // memset(dp,-1,sizeof(dp));
        cin>>a;
        ans=0;
        string s;
        vector<string>v;
        for(i=0; i<a; i++)
        {
            cin>>s;
            v.pb(s);
          //  insert(s,root);
            // cout<<ans<<endl;
        }
        sort(v);
        for(i=0;i<v.size();i++){
			insert(v[i],root);
        }
        cout<<"Case "<<++tn<<": ";
        if(ans)
        cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        delete_(root);
        ans=0;
    }

    return 0;
}
