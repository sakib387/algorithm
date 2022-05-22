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
#define MAX 1000003
//set_operation
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>mst;
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
ll a[MAX],M=1e9+7;
int main()
{
    fastIO();
    ll n;
    cin>>n;
    a[0]=1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=6;j++)
        {
            if(i-j>=0) a[i]=(a[i]+a[i-j])%M;
        }
    }
    cout<<a[n]<<"\n";
    return 0;
}

