#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll seg [4*100009];
ll lazy [4*100009];
void pop(ll a,ll l,ll h){
lazy[a*2]+=lazy[a];
lazy[a*2+1]+=lazy[a];
ll mid=(l+h)/2;
seg[a*2]+=(mid-l+1)*lazy[a];
seg[a*2+1]+=(h-mid)*lazy[a];
lazy[a]=0;
return;
}
void update(ll a,ll low,ll hig,ll l,ll r,ll val)
{

    if(low>r||hig<l)return;
    else if(low>=l&&hig<=r)
    {
        seg[a]+=(hig-low+1)*val;

            lazy[a]+=val;


        return;
    }
    ll mid=(low+hig)/2;
    if(lazy[a])pop(a,low,hig);
    update(a*2,low,mid,l,r,val);
    update(a*2+1,mid+1,hig,l,r,val);
    seg[a]=seg[a*2]+seg[a*2+1];
}
ll queary(ll a,ll low,ll hig,ll l,ll r)
{

    if(low>r||hig<l)return 0;
    if(low>=l&&hig<=r)return  seg[a];
    ll mid=(low+hig)/2;
    if(lazy[a])pop(a,low,hig);
    return queary(a*2,low,mid,l,r)+queary(a*2+1,mid+1,hig,l,r);

}
int main()
{
    ll t;
    cin>>t;
    for(ll x=1; x<=t; x++)
    {
        ll a,b,c,d,e,i,j,k,l;
        cin>>a>>b;
        for(i=1;i<=a*4;i++){lazy[i]=seg[i]=0;}
        cout<<"Case "<<x<<":\n";
        for(i=1; i<=b; i++)
        {
            cin>>c;
            if(c==0)
            {
                cin>>c>>d>>e;
                c++;
                d++;
                update(1,1,a,c,d,e);
            }
            else
            {
                cin>>c>>d;
                c++;
                d++;
                cout<< queary(1,1,a,c,d)<<endl;
            }
        }
    }
    return 0;
}
