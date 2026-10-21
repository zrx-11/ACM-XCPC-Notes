#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
#define mp make_pair
#define pb push_back
#define xx first
#define yy second
typedef long long ll;
typedef pair<int,int> pii;
inline int read() {
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=x*10+c-'0';
    return x*f;
}
const int maxn=10;
char s[maxn];
int n;
int solve() {
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(x,1,n-1) {
		rep(S,0,(1<<n-1)-1) {
			int left=0,cur=0,right=0;
			rep(i,1,x) {
				cur=cur*10+s[i]-'0';
				if(S>>i-1&1) left+=cur,cur=0;
			}
			left+=cur;cur=0;
			rep(i,x+1,n) {
				cur=cur*10+s[i]-'0';
				if(S>>i-1&1) right+=cur,cur=0;
			}
			right+=cur;cur=0;
			if(left==right) return 1;
		
		}
	}
	return 0;
}
int main() {
	freopen("equation.in","r",stdin);
	freopen("equation.out","w",stdout);
	int T=read();
	while(T--) puts(solve()?"Yes":"No");
	return 0;
}
