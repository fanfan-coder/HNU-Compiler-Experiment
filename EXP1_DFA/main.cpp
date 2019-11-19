#include <bits/stdc++.h>
#include "dfa.h"
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
DFA dfa;

bool read()
{
    dfa.read();
    if(dfa.check())
    {
        dfa.print();
        return 1;
    }
    return 0;
}

void solve()
{
    freopen("CON", "r", stdin);
    freopen("CON", "w", stdout);
    cout << "������϶����DFA�����Լ��г��ȡ�N�����й����ַ���������N��" << endl;
    int n;
    cin >> n;
    cout << "����С�ڵ���" << n << "�ĺϷ��ַ����У�" << endl;
    dfa.getLang(n);
    cout << endl;

    cout << "�ж����ַ����Ƿ��ǹ����ַ���������s��" << endl;
    string s;
    while(cin >> s)
        cout << endl << s << ' ' << (dfa.isLang(s) ? "�Ϸ�" : "�Ƿ�") << endl;
}

int main()
{
    //freopen("in0.dfa", "r", stdin); freopen("out0.dfa", "w", stdout);
    //freopen("in1.dfa", "r", stdin); freopen("out1.dfa", "w", stdout);
    freopen("in2.dfa", "r", stdin); freopen("out2.dfa", "w", stdout);
    if(read())
        solve();
    return 0;
}
