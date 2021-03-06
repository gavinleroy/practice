#include <vector>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iomanip>
#include <random>
#include <functional>
#include <cassert>
#include <cstdio>
#include <cinttypes>
#include <cstdlib>
#include <cstdint>
#include <utility>
#include <cstring>
#include <climits>
#include <algorithm>
#include <forward_list>
#include <thread>

#define BOOST std::ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define P std::pair<int, int>
#define F first
#define S second

#define MAX_INT ~(1 << 31)
#define MIN_INT (1 << 31)
#define MAX_LL ~(1 << 63)
#define MIN_LL (1 << 63)
//#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

template<typename T>
static inline T gcd(T a, T b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b > 0) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}
 
template<typename T>
static inline T sqr(T a) {
    return a * a;
}
 
template<typename T>
static inline bool remin(T &a, const T &val) {
    if (a > val) {
        a = val;
        return true;
    }
    return false;
}
 
template<typename T>
static inline bool remax(T &a, const T &val) {
    if (a < val) {
        a = val;
        return true;
    }
    return false;
}

static double clock_t0;
 
static inline void init_time() {
    clock_t0 = clock();
} 

static inline double get_time() {
    return (clock() - clock_t0) / CLOCKS_PER_SEC;
}
 
static inline void print_time(const std::string &name) {
    std::cerr << name << " " << get_time() << "s." << std::endl;
}
 
template <class T>
static inline T pw(T a, ll n) {
    T ret = T(1);
    while (n > 0) {
        if (n & 1) ret = ret * a;
        a = a * a;
        n >>= 1;
    }
    return ret;
}
 
static inline ll pw(ll a, ll n, ll mod) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

template <class T>
inline static T mul(T a, T b, T mod) { 
    T res = T(0); 
    a = a % mod; 
    while (b > 0){ 
        if ((b & 1) == 0) 
            res = (res + a) % mod; 
        a = (a << 1) % mod; 
        b >>= 1; 
    } 
    return res % mod; 
} 

using namespace std;

ll solve(ll k, ll n){
	ll count, num, brac;
	ll a = k-1;
	ll d = n-1;
	if(a%d==0) num = a/d;
	else num = a/d + 1;
	d = (-1)*d;
	if(!(num & 1)){
		num = num/2;
		brac = ((2*a)+d*((num*2)-1));
	}else brac = ((2*a)+d*(num-1))/2;
	count = (num%MOD)*(brac%MOD);
	count %= MOD;
	return count;
}

int main(void){BOOST
	init_time();
	#ifdef LOCAL
		freopen("input.1", "r", stdin);
	#endif
	int t;
	ll n, k;
	cin >> t;
	while(t--){
		cin >> n >> k;
		cout << solve(k, n) << endl;
	}
	print_time("Time: ");
	return 0;
}
