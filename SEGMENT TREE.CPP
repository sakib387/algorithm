#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll seg[4*200008];
ll ar[200009];
void build(ll n,ll low,ll hig)
{
    if(low==hig)
    {
        seg[n]=ar[low];
        return ;
    }
    ll mid=(low+hig)/2;
    build( n*2, low, mid);
    build(n*2+1, mid+1, hig);
    seg[n]=(seg[n*2]+seg[n*2+1]);

}

void update(ll n,ll low,ll hig,ll ind,ll val)
{
    if(low==hig&&low==ind)
    {
        seg[n]+=val;
        ar[low]+=val;
        return ;
    }
    if(low>ind||hig<ind)return;
    ll mid=(low+hig)/2;
    update( n*2, low, mid,ind,val);
    update(n*2+1, mid+1, hig,ind,val);
    seg[n]=(seg[n*2]+seg[n*2+1]);

}
ll quary(ll a,ll low,ll high,ll l, ll r)
{

    if(low>=l&&high<=r)return seg[a];
    else if(low>r||high<l)return 0;
    ll mid=(low+high)/2;
    return (quary( a*2, low, mid, l,  r)+quary( a*2+1, mid+1, high, l,  r));
}
int main()
{
    ll t,n=1;

        ll a,b,c,d,e,i,j,k,l;

        cin>>a>>b;
        for(ll j=1; j<=a*4; j++)
        {
            ar[j]=seg[j]=0;
        }

        for(i=1; i<=a; i++)
        {
            cin>>ar[i];
        }
        build(1,1,a);
        for(i=1; i<=b; i++ )
        {
            ll s;
            cin>>s;
            if(s==2)
            {
                cin>>c>>d;c++;
                cout<<quary(1,1,a,c,d)<<endl;
            }

            else
            {
                cin>>c>>d;c++;
                update(1,1,a,c,d-ar[c]);
            }
        }
    return 0;

}
