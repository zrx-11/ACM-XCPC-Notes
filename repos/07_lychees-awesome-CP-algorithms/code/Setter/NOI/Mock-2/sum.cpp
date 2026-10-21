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
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=10000010; 
int pri[maxn/10],cnt;
bool vis[maxn];
void init(int n) {
	rep(i,2,n) {
		if(!vis[i]) pri[++cnt]=i;
		rep(j,1,cnt) {
			if(i*pri[j]>n) break;
			vis[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}	
	}
}
ll ans,n;
void dfs(int cur,ll g,ll last) {
	ans+=g*last;
	rep(i,cur+1,cnt) {
		ll tmp=last;
		if((ll)pri[i]*pri[i]<=last) {
			tmp/=pri[i];tmp/=pri[i];
			ll p1=pri[i],p2=1,res;
			rep(d,2,60) {
				if(!tmp) break;
				res=p1*(d%pri[i]==0?pri[i]:1)-p2*((d-1)%pri[i]==0?pri[i]:1);
				dfs(i,g*res,tmp);
				tmp/=pri[i];
				p1=p1*pri[i];
				p2=p2*pri[i];
			}
		}
		else break;
	}
}
int main() {
	init(10000000);
	scanf("%lld",&n);
	dfs(0,1,n);
	printf("%lld\n",ans);
	return 0;
}
