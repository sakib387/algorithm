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
//set_operation
#define inf 1000000000000000
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>mst;


ll mod=1000000007;
ll mod2=1000000009;

int dx[]= {-1,0,0,1,-1,-1,1,1};
int dy[]= {0,-1,1,0,-1,1,-1,1};
/*//nCr
ll inv[MAX];ll fact[MAX];ll c_inv[MAX];
ll nCr(ll n,ll r)
{

    return (((fact[n]*c_inv[r])%mod)*c_inv[n-r])%mod;
}
void init()
{
    for(ll i=1; i<=MAX; i++){if(i==1)fact[i]=1;else fact[i]=(fact[i-1]*i)%mod;}inv[1] = 1;for(int i = 2; i <=MAX; ++i)inv[i] = mod - (mod/i) * inv[mod%i] % mod;for(ll i=1; i<=MAX; i++){if(i==1)c_inv[i]=inv[i];else c_inv[i]=(c_inv[i-1]*inv[i])%mod;}c_inv[0]=1;
}
*/

ll power(ll a,ll b,ll md)
{
    if(b == 0)
    {
        return 1;
    }
    ll ans = power(a,b/2,md);
    ans *= ans;
    ans %= md;
    if(b % 2)
    {
        ans *= a;
    }
    return ans % md;
}

/*
ll are[1000009];vector<ll>sv;
void seiv()
{
	ll n=1000000,i,j;are[1]=1;for(i=4; i<=n; i+=2)are[i]=1;for(i=3; i<=n; i+=2){if(are[i]==0){for(j=i*i; j<=n; j+=i*2)are[j]=1;}}for(i=2; i<=n; i++){if(are[i]==0)sv.pb(i);}
}
*/

#define endl "\n"

ll pw[1000005];
ll bl[1000005];
ll pw2[1000005];
ll bl2[1000005];
void hash_1(string s)
{
    pw[0]=1;
    bl[0]=s[0]-'a'+1;
    ll base=31;
    for(ll i=1; i<s.size(); i++)
    {
        bl[i]=(bl[i-1]+((s[i]-'a'+1)*base)%mod)%mod;
        pw[i]=base;
        base=base*31;
        base%=mod;

    }
}
void hash_2(string s)
{
    pw2[0]=1;
    bl2[0]=s[0]-'a'+1;
    ll base=29;
    for(ll i=1; i<s.size(); i++)
    {
        bl2[i]=(bl2[i-1]+((s[i]-'a'+1)*base)%mod2)%mod2;
        pw2[i]=base;
        base=base*29;
        base%=mod2;

    }
}
int main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        ll a,b,c,d,e=0,i,j,f=0,g=0,h=0,k=0,r,l,an=0;
        //memset(dp,-1,sizeof(dp));
        string s;
        cin>>a>>b>>s;
        hash_1(s);
        hash_2(s);
        set<pair<ll,ll>>st,st1;
        for(i=0,k=b-1; k<s.size(); k++,i++)
        {
            if(i==0)
            {
                c=bl[k];
                d=bl2[k];
            }
            else
            {
                c=(bl[k]-bl[i-1]+mod)%mod;
                d=(bl2[k]-bl2[i-1]+mod2)%mod2;
                c=(c*(power(pw[i],mod-2,mod)))%mod;
                d=(d*(power(pw2[i],mod2-2,mod2)))%mod2;

            }
           // cout<<c<<" "<<d<<endl;
            st.insert({c,d});
        }
        cout<<st.size()<<endl;



    }
    return 0;
}
