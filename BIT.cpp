#include<bits/stdc++.h>
using namespace std;
#define pd push_back
int  BIT[1000];
void Buld_BIT(int  a,int b,int sz)
{
    a++;
    while(a<=sz)
    {
        BIT[a]+=b;
        a+=(a&(-a));

    }
}
void Update_BIT(int a,int b,int sz)
{
    a++;
    while(a<=sz)
    {
        BIT[a]+=b;
        a+=(a&(-a));
    }
}
int Get_sum(int a)
{
    a++;
    int sum=0;
    while(a)
    {
        sum+=BIT[a];
        a-=a&(-a);

    }
    return sum;
}
int main()
{

    vector<int>v;
    int a,b,c,d,e,i,j;
    cin>>a;
    for(i=1; i<=a; i++)
    {
        cin>>b;
        v.push_back(b);
    }
    for(i=0; i<v.size(); i++)
    {
        Buld_BIT(i,v[i], a);
    }
    cin>>c;
    while(c--)
    {
        cin>>d;
        if(d==1)
        {
            cin>>b>>d;
            d=d-v[b];
            Update_BIT(b,d,a);
        }
        else
        {
            cin>>b>>d;
            cout<<Get_sum(d)-Get_sum(b-1)<<endl;

        }
    }


    return 0;
}
