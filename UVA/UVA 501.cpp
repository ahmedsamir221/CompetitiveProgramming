/*
   first we will comprised the numbers then use binary search , it's function will return
   number of element that less than our mid ,and we can do that using segment tree
*/
#include<queue>
#include<map>
#include <string>
#include<bits/stdc++.h>
#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
//#define x real()
//#define y imag()
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
//typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)
const int N=210,M=20500;

int n,m,a[600010],q[600010],cas,mn,k,l,r,b[600010],recom[600010];
vector<int>val[5000000];
string s;
void bulid(int s=1,int e=n,int p=1)
{
    if(s==e)
    {
        val[p].clear();
        val[p].push_back(a[s]);
        return;
    }
    int mid=(s+e)/2;
    bulid(s,mid,p*2);
    bulid(mid+1,e,p*2+1);
    val[p].resize(val[p*2].size()+val[p*2+1].size());
    merge (val[p*2].begin(),val[p*2].end(),val[p*2+1].begin(),val[p*2+1].end(),val[p].begin());
}

int get(int s=1,int e=n,int p=1)
{
    if(s>=l&&e<=r)
    {
        auto it=lower_bound(val[p].begin(),val[p].end(),k);
        return it-val[p].begin();
    }
    int mid=(s+e)/2;
    if(r<=mid) return get(s,mid,p*2);
    else if(l>mid) return get(mid+1,e,p*2+1);
    else return get(s,mid,p*2)+get(mid+1,e,p*2+1);
}
 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
//input;
int t;
scanf("%d",&t);
while(t--)
{
    scanf("%d%d",&n,&m);
    forr(i,1,n)
    {
      scanf("%d",&a[i]);
      b[i]=a[i];
    }
    sort(b+1,b+1+n);
    int c=0;
    map<int,int>com;
    forr(i,1,n)
    {
      if(i!=1&&b[i]==b[i-1])continue;
      com[b[i]]=++c;
      recom[c]=b[i];
    }

    forr(i,1,n)a[i]=com[a[i]];

    forr(i,1,m)scanf("%d",&q[i]);
    bulid();
    if(cas++)printf("\n");
    mn=0;
    forr(i,1,m)
    {
        l=1,r=q[i];
        mn++;
        int lo=1,hi=60010,mid;
        while(lo<hi)
        {
            mid=(lo+hi+1)/2;
            k=mid;
            int g=get();
            if(g>=mn)hi=mid-1;
            else lo=mid;
        }
        printf("%d\n",recom[lo]);
    }
}
return 0;
}
