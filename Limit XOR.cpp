#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,int> si;
typedef pair<int,ii> iii;
typedef vector<si> vsi;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef map<string,vs> msvs;
typedef map<string,int> msi;
typedef map<string,string> mss;
typedef map<int,bool> mib;

#define REP(i,n) for(int i = 0, _n = (n); i < _n; i++)
#define REPD(i,n) for(int i = (n) - 1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i,a,b) for(int i = (a), _b = (b); i < _b; i++)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define RESET(c,x) memset (c, x, sizeof (c))
#define DEBUG1(s,c) cout << s << c << endl

#define PI acos(-1)
#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ALL(c) (c).begin(), (c).end()
#define SIZE(c) (int)(c).size()

static struct IO {
    char tmp[1 << 10];

    // fast input routines
    char cur;

//#define nextChar() (cur = getc_unlocked(stdin))
//#define peekChar() (cur)
    inline char nextChar() { return cur = getc_unlocked(stdin); }
    inline char peekChar() { return cur; }

    inline operator bool() { return peekChar(); }
    inline static bool isBlank(char c) { return (c < '-' && c); }
    inline bool skipBlanks() {
        while (isBlank(nextChar()));
        return peekChar() != 0;
    }

    inline IO& operator >> (char & c) { c = nextChar(); return *this; }

    inline IO& operator >> (char * buf) {
        if (skipBlanks()) {
            if (peekChar()) {
                *(buf++) = peekChar();
                while (!isBlank(nextChar())) *(buf++) = peekChar();
            } *(buf++) = 0; } return *this; }

    inline IO& operator >> (string & s) {
        if (skipBlanks()) {    s.clear(); s += peekChar();
            while (!isBlank(nextChar())) s += peekChar(); }
        return *this; }

    inline IO& operator >> (double & d) { if ((*this) >> tmp) sscanf(tmp, "%lf", &d); return *this;    }

#define defineInFor(intType) \
    inline IO& operator >>(intType & n) { \
        if (skipBlanks()) { \
            int sign = +1; \
            if (peekChar() == '-') { \
                sign = -1; \
                n = nextChar() - '0'; \
            } else \
                n = peekChar() - '0'; \
            while (!isBlank(nextChar())) { \
                n += n + (n << 3) + peekChar() - 48; \
            } \
            n *= sign; \
        } \
        return *this; \
    }

defineInFor(int)
defineInFor(unsigned int)
defineInFor(long long)

    // fast output routines

//#define putChar(c) putc_unlocked((c), stdout)
    inline void putChar(char c) { putc_unlocked(c, stdout); }
    inline IO& operator << (char c) { putChar(c); return *this; }
    inline IO& operator << (const char * s) {
        while (*s) putChar(*s++);
        return *this;
    }

    inline IO& operator << (const string & s) { for (int i = 0; i < (int)s.size(); ++i) putChar(s[i]); return *this; }

    char * toString(double d) { sprintf(tmp, "%lf%c", d, '\0'); return tmp; }
    inline IO& operator << (double d) { return (*this) << toString(d); }


#define defineOutFor(intType) \
    inline char * toString(intType n) { \
        char * p = (tmp + 30); \
        if (n) { \
            bool isNeg = 0; \
            if (n < 0) isNeg = 1, n = -n; \
            while (n) \
                *--p = (n % 10) + '0', n /= 10; \
            if (isNeg) *--p = '-'; \
        } else *--p = '0'; \
        return p; \
    } \
    inline IO& operator << (intType n) { return (*this) << toString(n); }

defineOutFor(int)
defineOutFor(ll)
defineOutFor(ull)

#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;

#define PROD //clocking off

struct trienode{
    struct trienode *pt[2];
    ll key[2];
};

struct trienode *newnode(){
    struct trienode *temp = new trienode;
    for (int i=0;i<2;i++){
        temp->pt[i] = NULL;
        temp->key[i] = 0;
    }
    return temp;
}

void insert(struct trienode *root,ll key){
    struct trienode *temp = root;
    bool bit;

    for (int i=31;i>=0;i--){
        bit = key & (1<<i);
        if (temp->pt[bit] == NULL)
            temp->pt[bit] = newnode();
        temp->key[bit] = temp->key[bit]+1;
        temp = temp->pt[bit];
    }
}

ll maxor(struct trienode *root,ll pre,ll k){
    struct trienode *temp = root;
    bool bit;
    bool bi;
    ll ans=0;
    //cout<<"key= "<<pre<<endl;
    for (int i=31;i>=0;i--){
        bit = pre & (1<<i);
        bi = k & (1<<i);
        /*cout<<"bit= "<<bit<<endl;
        cout<<"bi= "<<bi<<endl;*/
        if (bit && bi){
            //cout<<"raghav"<<endl;
            ans += temp->key[1];
            if (temp->pt[0] != NULL)
                temp = temp->pt[0];
            else
                return ans;
        }
        else if (bit && !bi){
            //cout<<"raman"<<endl;
            if (temp->pt[1] != NULL){
                //cout<<"temp->key[1]= "<<temp->key[1]<<endl;
                temp = temp->pt[1];
            }
            else
                return ans;
        }

        else if (!bit && bi){
            //cout<<"jyoti"<<endl;
            ans += temp->key[0];
            //cout<<"temp->key[0]= "<<temp->key[0]<<endl;
            if (temp->pt[1] != NULL)
                temp = temp->pt[1];
            else
                return ans;
        }
        else if (!bit && !bi){
            //cout<<"deepak"<<endl;
            if (temp->pt[0]!= NULL){
                //cout<<"shrey"<<endl;
                temp = temp->pt[0];
            }
            else
                return ans;

        }
        //cout<<"ans= "<<ans<<endl;
    }
    return ans;
}



int main(int argc,char *argv[]){
   // int t;
    //cin>>t;
 //   while(t--){
        ll n,k;
        cin>>n>>k;
        ll arr[n];

        for (int i=0;i<n;i++)
            cin>>arr[i];

        struct trienode *root = newnode();
        insert(root,0);
        ll pre=0;
        ll ans=0;

        for (int i=0;i<n;i++){
            pre = pre^arr[i];
            ans += maxor(root,pre,k);
            insert(root,pre);
        }
        cout<<ans<<endl;
    //}
}
