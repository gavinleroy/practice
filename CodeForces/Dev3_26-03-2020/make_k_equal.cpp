#include <cmath>
#include <string>
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef double lf;
typedef long double llf;
typedef bool bl;
#define I __attribute__((always_inline))inline
//template<typename T> I T max(T a,T b){return a>b?a:b;}
//template<typename T> I T min(T a,T b){return a<b?a:b;}
template<typename T> I T abs(T a){return a>0?a:-a;}
#define RUC register unsigned char
#define RC register char
#define UC unsigned char
#define OP operator
#define RT return *this;
#define TR *this,x;return x;
#define SS std::string
struct CHARG{bl err=0;I UC OP()(){RC r=getchar();err=r==EOF;return r;}};
struct CHARP{I void OP()(char x){putchar(x);}};
#define RX x=0; RUC t=P(); while((t<'0'||t>'9')&&t!='-'&&!P.err)t=P(); bool f=0;\
if(t=='-')t=P(),f=1; x=t-'0';for(t=P();t>='0'&&t<='9'&&!P.err; t=P()) x=x*10+t-'0'
#define RL if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9'&&!P.err;t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x
#define RU x=0; RUC t=P(); while((t<'0'||t>'9')&&!P.err)t=P();x=t-'0';\
for(t=P();t>='0'&&t<='9'&&!P.err;t=P())x=x*10+t-'0'
I bool IS(char x){ return x==10||x==13||x==' '; }
template<typename T>struct FREAD{T P;I OP bl(){return !P.err;}I FREAD&OP,(int&x){RX; if(f)x=-x; RT }I OP int(){int x;TR}I FREAD&OP,(ll & x){RX;if(f)x=-x;RT}I OP ll(){ll x;TR}I FREAD&OP,(char & x){for(x=P();IS(x)&&!P.err;x=P());RT}I OP char(){char x;TR}I FREAD&OP,(char* x){RUC t=P();for(;IS(t)&&!P.err;t=P());if(~t){for(;!IS(t)&&~t&&!P.err;t=P())*x++=t;}*x++=0;RT}I FREAD&OP,(lf&x){RX;RL;RT}I OP lf(){lf x;TR}I FREAD&OP,(llf&x){RX;RL;RT}I OP llf() {llf x;TR}I FREAD&OP,(uint&x){RU;RT}I OP uint(){uint x;TR}I FREAD&OP,(ull&x){RU;RT}I OP ull(){ull x;TR}I FREAD&OP,(ul&x){RU;RT}I OP ul(){ul x;TR}};FREAD<CHARG>in;
#define WI(S) if(x){if(x<0)P('-'),x=-x;RUC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
#define WL if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)\
x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);
#define WU(S) if(x){RUC s[S],c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0')
template<typename T>struct FWRITE{T P;I FWRITE&OP,(int x){WI(10);RT}I FWRITE&OP()(int x){WI(10);RT}I FWRITE&OP,(uint x){WU(10);RT}I FWRITE&OP()(uint x){WU(10);RT}I FWRITE&OP,(ll x){WI(19);RT}I FWRITE&OP()(ll x){WI(19);RT}I FWRITE&OP,(ull x){WU(20);RT}I FWRITE&OP()(ull x){WU(20);RT}I FWRITE&OP,(ul x){WU(20);RT}I FWRITE&OP()(ul x){WU(20);RT}I FWRITE&OP,(char x){P(x);RT}I FWRITE&OP()(char x){P(x);RT}I FWRITE&OP,(const char*x){while(*x)P(*x++);RT}I FWRITE&OP()(const char*x){while(*x)P(*x++);RT}I FWRITE&OP,(const SS & x){*this,x.c_str();RT}I FWRITE&OP()(const SS & x){*this(x.c_str());RT}I FWRITE&OP()(lf x,int y){WL;RT}I FWRITE&OP()(llf x,int y){WL;RT}};FWRITE<CHARP>out;
// DONE I/O ------------------------------------------------------------------------------------------------->

#include <algorithm>

using namespace std;

const ll inf = 1e18;
#define NL '\n'
 
void solve(int *aa, int n, int k) {
	sort (aa, aa+n);
	ll *P = new ll[n+1];
	P[0] = 0;
	for (int i = 1; i <= n; i++) // Create prefix sum array
		P[i] = P[i-1] + aa[i-1];

	ll answer = inf;
	for (int i = 0; i < n;) {
		int j = i;
		// Find how far this bucket stretches
		while (j < n && aa[i] == aa[j]) j++;
		int same_count = j - i;
		// Compute cost of movinga ll numbers to the left, to bucket-1
		ll cost_left = (ll)i * (aa[i] - 1) - P[i];
		// Compute cost of moving all numbers to the right, to bucket+1
		ll cost_right = P[n] - P[j] - (ll) (n - j) * (aa[i] + 1);
		
		if (same_count >= k) // If our current bucket has enough
			answer = 0ll;
		if (same_count + i >= k) // If there is enough to our left
			answer = min(answer, cost_left + k - same_count);
		if (same_count + n - j >= k) // If there is enough to our right
			answer = min(answer, cost_right + k - same_count);
		// We can always bring in both sides.
		answer = min(answer, cost_left + cost_right + k - same_count);
		i = j; // Skip over the rest of the elements in this bucket.
	}
	out,max(answer, 0ll),NL;
	delete []P;
}
int main(){
	int n, k, *aa;
	in,n,k;
	aa = new int[n]; 
	for(int i = 0; i < n; in,aa[i++]); //Read in array values.
	solve(aa, n, k);
	delete []aa;
	return 0;
}
