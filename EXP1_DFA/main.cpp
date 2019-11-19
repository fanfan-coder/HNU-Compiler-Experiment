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
    cout << "输出以上定义的DFA的语言集中长度≤N的所有规则字符串。输入N：" << endl;
    int n;
    cin >> n;
    cout << "长度小于等于" << n << "的合法字符串有：" << endl;
    dfa.getLang(n);
    cout << endl;

    cout << "判定该字符串是否是规则字符串。输入s：" << endl;
    string s;
    while(cin >> s)
        cout << endl << s << ' ' << (dfa.isLang(s) ? "合法" : "非法") << endl;
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
