#include <iostream>
using namespace std;

const int N = 2 * 1e5 + 10;
int n;
int arr[N];
long long ans = 0; // 不开 long long 可能会爆

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            ans += arr[i] * arr[j];
    cout << ans << '\n';
    return 0;
}

// #include <iostream>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;

//     long long s = 0;
//     long long current_sum = 0;
//     int val;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> val;
//         s += (long long)val * current_sum;
//         current_sum += val;
//     }

//     cout << s << endl;
//     return 0;
// }

// #include <iostream>
// using namespace std;

// const int N = 2 * 1e5 + 10;
// int n;
// int arr[N];
// long long s = 0, sum = 0;

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//         sum += arr[i];
//     }

//     for (int i = 0; i < n; i++)
//         s += (long long)arr[i] * (sum -= arr[i]);

//     cout << s << '\n';
// }

// #include <iostream>
// using namespace std;

// const int N = 2 * 1e5 + 10;
// int n;
// int arr[N], pre[N];
// long long s = 0;

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     cin >> n;
//     pre[0] = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> arr[i];
//         pre[i] = arr[i] + pre[i - 1];
//     }

//     for (int i = 1; i <= n; i++)
//         s += (long long)arr[i] * (pre[n] - pre[i]);

//     cout << s << '\n';

//     return 0;
// }