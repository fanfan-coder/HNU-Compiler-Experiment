#include <bits/stdc++.h>
#include "dfa.h"
#define INF 0x3f3f3f3f
using namespace std;
FA nfa, dfa, mindfa;

void cmp1()
{
    int cnt = 0;
    string s;
    map<string, bool> m;
    ifstream infile;
    infile.open("out2_nfa.txt");
    while (!infile.eof())
    {
        infile >> s;
        if(!m.count(s))
        {
            ++cnt;
            m[s] = 1;
        }
    }
    infile.close();

    infile.open("out2_dfa.txt");
    while (!infile.eof())
    {
        infile >> s;
        if(m.count(s) && m[s] == 1)
        {
            m[s] = 0;
            --cnt;
        }
        else if(!m.count(s))
        {
            cnt = INF;
        }
    }
    infile.close();

    if(!cnt)
        cout << "NFA与DFA等价" << endl;
    else
        cout << "有冇搞错" << endl;
}

void cmp2()
{
    int cnt = 0;
    string s;
    map<string, bool> m;
    ifstream infile;
    infile.open("out2_dfa.txt");
    while (!infile.eof())
    {
        infile >> s;
        if(!m.count(s))
        {
            ++cnt;
            m[s] = 1;
        }
    }
    infile.close();

    infile.open("out2_mindfa.txt");
    while (!infile.eof())
    {
        infile >> s;
        if(m.count(s) && m[s] == 1)
        {
            m[s] = 0;
            --cnt;
        }
        else if(!m.count(s))
        {
            cnt = INF;
        }
    }
    infile.close();

    if(!cnt)
        cout << "DFA与MinDFA等价" << endl;
    else
        cout << "有冇搞错" << endl;
}

int main()
{
    freopen("in2.txt", "r", stdin);
    nfa.read();
    freopen("CON", "r", stdin);

    if(nfa.check())
        nfa.print();
    freopen("out2_nfa.txt", "w", stdout);
    nfa.getLang(7);
    freopen("CON", "w", stdout);

    nfa.NFA2DFA(dfa);
    if(dfa.check())
        dfa.print();
    freopen("out2_dfa.txt", "w", stdout);
    dfa.getLang(7);
    freopen("CON", "w", stdout);

    dfa.DFAMinimise(mindfa);
    if(mindfa.check())
        mindfa.print();
    freopen("out2_mindfa.txt", "w", stdout);
    mindfa.getLang(7);
    freopen("CON", "w", stdout);

    cmp1();
    cmp2();
    return 0;
}
