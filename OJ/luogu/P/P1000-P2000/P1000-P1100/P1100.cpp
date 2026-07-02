#include <iostream>
#include <cstdint>
using namespace std;

int main()
{
    uint32_t n;
    cin >> n;
    uint32_t high16 = n >> 16;
    uint32_t low16 = n & 0x0000FFFF;
    uint32_t res = (low16 << 16) | high16;
    cout << res << '\n';
    return 0;
}