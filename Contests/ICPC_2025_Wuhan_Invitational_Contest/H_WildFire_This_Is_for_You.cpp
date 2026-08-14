#include <cstdio>
#define TY ll
#define MAXN 202
#define FOR(i, a, b) for (TY i = (a); i <= (b); i = -~i)
#define fOR(i, a, b) for (TY i = (a); i < (b); i = -~i)
#define ROF(i, a, b) for (TY i = (a); i >= (b); i = ~-i)
#define rOF(i, a, b) for (TY i = (a); i > (b); i = ~-i)
#define EDG(i, u) for (TY i = hed[u]; i; i = nxt[i])
using namespace std;
typedef long long ll;
const TY M = 998244353, B = 1e12;
typedef unsigned long long ull;
TY _abs(TY a) { return a < 0 ? -a : a; }
TY maxn(TY a, TY b) { return a > b ? a : b; }
TY minn(TY a, TY b) { return a < b ? a : b; }
inline void updmx(TY &x, TY y)
{
    if (x < y)
        x = y;
}
inline void updmn(TY &x, TY y)
{
    if (x > y)
        x = y;
}
inline void add(TY &x, TY y)
{
    if ((x += y) >= M)
        x -= M;
}
TY gcd(TY a, TY b) { return b ? gcd(b, a % b) : a; }
TY qp(TY a, TY b)
{
    TY ans = 1;
    do
    {
        if (1 & b)
            ans = ans * a % M;
        a = a * a % M;
    } while (b >>= 1);
    return ans;
}
char getc()
{
    char ch = getchar();
    while (ch == ' ' || ch == '\n' || ch == '\r')
        ch = getchar();
    return ch;
}
TY qr()
{
    char ch = getchar();
    TY s = 0, x = 1;
    for (; ch < '0' || ch > '9'; ch = getchar())
        if (ch == '-')
            x = -1;
    for (; ch >= '0' && ch <= '9'; ch = getchar())
        s = s * 10 + ch - '0';
    return x * s;
}
void qw(TY a)
{
    if (a > 9)
        qw(a / 10);
    putchar(a % 10 + '0');
}
void qw(TY a, char ch)
{
    if (a < 0)
    {
        a = -a;
        putchar('-');
    }
    if (a > 9)
        qw(a / 10);
    putchar(a % 10 + '0');
    if (ch)
        putchar(ch);
}
TY n = qr(), p = 3;
bool vs[40][40];
bool is(TY n)
{
    for (TY i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}
struct node
{
    TY a[MAXN];
    void operator+=(const node b)
    {
        fOR(i, 0, MAXN)
        {
            a[i] += b.a[i];
            if (a[i] >= B)
            {
                ++a[i + 1];
                a[i] -= B;
            }
        }
    }
    void operator*=(const TY b)
    {
        fOR(i, 0, MAXN) a[i] *= b;
        fOR(i, 0, MAXN - 1)
        {
            a[i + 1] += (a[i] / B);
            a[i] %= B;
        }
    }
    TY operator%(const TY b)
    {
        TY s = 0;
        ROF(i, MAXN - 1, 0)
        s = (s * B + a[i]) % b;
        return s;
    }
    void print()
    {
        bool fl = false;
        ROF(i, MAXN - 1, 0)
        {
            if (!fl && !a[i])
                continue;
            if (fl)
                printf("%012lld", a[i]);
            else
            {
                printf("%lld", a[i]);
                fl = true;
            }
        }
    }
} x, y, ml, tmp;
void make(node &a, TY v, TY x)
{
    TY p = a % v, q = ml % v, nm = -1;
    fOR(i, 0, v) if ((p + q * i) % v == x)
    {
        nm = i;
        break;
    }
    if (nm)
    {
        tmp = ml;
        tmp *= nm;
        a += tmp;
    }
}
int main()
{
    if (n == 0)
    {
        printf("1\n1");
        return 0;
    }
    if (1 & n)
        x.a[0] = y.a[0] = 2;
    else
        x.a[0] = y.a[0] = 1;
    --n;
    ml.a[0] = 2;
    FOR(i, -n, n)
    FOR(j, -n, n)
    {
        if (_abs(i) + _abs(j) > n)
            continue;
        if (!(1 & ((i ^ n) | (j ^ n))))
            continue;
        if (vs[i + n][j + n])
            continue;
        while (!is(p))
            ++p;
        FOR(x, -n, n)
        if (_abs(i - x) % p == 0)
            FOR(y, -n, n) if (_abs(j - y) % p == 0) vs[x + n][y + n] = true;
        make(x, p, (p - i % p) % p);
        make(y, p, (p - j % p) % p);
        ml *= p;
        ++p;
    }
    x.print();
    putchar('\n');
    y.print();
    return 0;
}