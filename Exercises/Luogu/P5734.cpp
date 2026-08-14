#include <iostream>
#include <string>
using namespace std;

int q, op;
int start, range;
string passage, str, tmp;
string pre, suf, mid, target;

int main()
{
    cin >> q;
    cin >> passage;
    while (q--)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> str;
            passage += str;
            cout << passage << '\n';
            break;
        case 2:
            cin >> start >> range;
            tmp = "";
            for (int i = start; i < start + range; i++)
                tmp += passage[i];
            passage = tmp;
            cout << passage << '\n';
            break;
        case 3:
            pre = "", suf = "";
            cin >> start;
            cin >> mid;
            for (int i = 0; i < start; i++)
                pre += passage[i];
            for (int i = start; i < passage.length(); i++)
                suf += passage[i];
            passage = pre + mid + suf;
            cout << passage << '\n';
            break;
        case 4:
            bool found = false;
            int i, j, cnt;
            cin >> target;
            for (i = 0; i < passage.length(); i++)
            {
                cnt = 0;
                for (j = 0; j < target.length(); j++)
                {
                    if (i + j >= passage.length())
                        break;
                    if (passage[i + j] == target[j])
                        cnt++;
                }
                if (cnt == target.length())
                {
                    found = true;
                    break;
                }
            }
            if (found)
                cout << i << '\n';
            else
                cout << -1 << '\n';
        }
        }
    return 0;
}