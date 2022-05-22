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
#define endl "\n"
#define MAX 10000
vector<ll>v;
ll SPT[MAX][32];
void build_sparse_table(ll a)
{
    ll i,j;
    for(i=0; i<a; i++)
    {
        SPT[i][0]=v[i];
    }
    for(j=1; (1<<j)<=a; j++)
    {
        for(i=0; i+(1<<j)-1<=a; i++)
        {
            SPT[i][j]=min(SPT[i][j-1],SPT[i+(1<<(j-1))][j-1]);
        }
    }

}
ll query(ll l,ll r)
{
  ll j=(r-l)+1;
  j=log2(j);
  cout<<min(SPT[l][j],SPT[r-(1<<j)+1][j])<<endl;
}
void get_input(ll a)
{

    for(ll i=1; i<=a; i++)
    {
        ll c;
        //  c=(rand()%100)+1;
        cin>>c;
        v.pb(c);
    }

}
int main()
{
    ll a,b,c,d,e,i,j,k,l;
    cin>>a;
    get_input(a);
    build_sparse_table(a);
    query(0ll,4ll);
    query(4ll,7ll);
    query(7ll,8ll);
}
