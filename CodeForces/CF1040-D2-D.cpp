// https://codeforces.com/blog/entry/61668
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

ll n,k;
string x;
 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
input;
srand(0);
cin>>n>>k;
ll l=1,r=n,mid;
while(1)
{
    int sz=r-l+1;
    int t=rand()%sz;
    cout<<l+t<<" "<<l+t<<endl;
    fflush(stdout);
    cin>>x;
    if(x=="Yes")exit(0);

    l=max((ll)1,l-k);
    r=min(r+k,n);
    mid=(l+r)/2;
    cout<<l<<" "<<mid<<endl;
    fflush(stdout);
    cin>>x;
    if(x=="Bad")exit(0);
    if(x=="Yes")
    {
        if(l==mid)exit(0);
        else
        {
            l=max((ll)1,l-k);
            r=min(mid+k,n);
        }
    }
    else
    {
        l=max((ll)1,mid+1-k);
        r=min(r+k,n);
    }
}
return 0;
}
