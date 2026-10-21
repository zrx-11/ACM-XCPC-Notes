#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<vector>
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
#define rep(i,a,b) for(int i=(a),i##_end_=(b);i<=i##_end_;i++)
#define dwn(i,a,b) for(int i=(a),i##_end_=(b);i>=i##_end_;i--)
using namespace std;
inline int read() {
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    return x*f;
}
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=66000;
const int MOD=998244353;
const int inv2=499122177;
void fwt(ll* x,int len,int mode) {
    for(int i=2;i<=len;i<<=1) {
        int step=i>>1;
        for(int j=0;j<len;j+=i)
            for(int k=j;k<j+step;k++) {
                ll a=x[k],b=x[k+step];
                x[k]=(a+b)%MOD;x[k+step]=(a-b+MOD)%MOD;
                if(mode==-1) (x[k]*=inv2)%=MOD,(x[k+step]*=inv2)%=MOD;
            }
    }
}
char word[10010];
typedef long long LL;
const int mod=100000000;
struct bignum
{
    LL num[3010];
    void init()
    {
        memset(num,0,sizeof num);
    }

    void operator /= (const LL &a)
    {
        for(int i=num[0];i>1;--i)
        {
            num[i-1]+=(num[i]%a*mod);
            num[i]/=a;
        }
        num[1]/=a;
        while(num[0]>0&&num[num[0]]<=0) --num[0];
    }
	ll calc() {
		ll s=0;
		dwn(i,num[0],1) {
			s=((ll)s*mod+num[i])%MOD;
		}
		return s;
	}
    void read()
    {
        scanf("%s",word);
        int len=strlen(word);
        for(int i=0;i<len;++i)
            num[(len-i-1)/8+1]=num[(len-i-1)/8+1]*10+word[i]-'0';
        num[0]=(len-1)/8+1;
    }
}N;
ll m;
int len;
void mul(ll* a,ll* b) {
	rep(i,0,len-1) a[i]=(ll)a[i]*b[i]%MOD;
}
ll a[maxn],b[maxn];
int main() {
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	N.read();
	scanf("%lld",&m);
	int n=0;
	while(1) {
		if(!N.num[N.num[0]]) break;
		a[n]=N.calc();
		N/=2ll;
		n++;
	}
	rep(i,0,n-2) (a[i]-=a[i+1])%=MOD;
	
	len=1;
	while(len<=n) len<<=1;
	b[0]=1;
	fwt(a,len,1);fwt(b,len,1);
	for(;m;m>>=1,mul(a,a)) if(m&1) mul(b,a);
	fwt(b,len,-1);
	int res=0;
	rep(i,1,len-1) (res+=b[i])%=MOD;
	printf("%d\n",(res+MOD)%MOD);
	return 0;
}
