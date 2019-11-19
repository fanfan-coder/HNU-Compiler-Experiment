#ifndef ANALYSE_H_INCLUDED
#define ANALYSE_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2;

struct Grid{
    int n; //产生式右侧符号的数量
    int pn; //产生式的编号
    string x[maxn]; //产生式的符号
    Grid() { n = 0; pn = -1; }
    Grid(int n, int pn): n(n), pn(pn) {}
};

class LL1{
public:
    int pdnum; //产生式数量
    int ternum; //终结符+#的数量
    int ntnum; //非终结符数量
    string production[maxn]; //产生式
    Grid predictTable[maxn][maxn]; //第一维非终结符，第二维终结符
    map<string, int> t2i; //终结符转下标
    map<string, int> n2i; //非终结符转下标

    LL1();
    void getTable(); //填充该LL(1)文法的预测分析表
    void printTable(); //打印预测分析表
};


#endif // ANALYSE_H_INCLUDED
