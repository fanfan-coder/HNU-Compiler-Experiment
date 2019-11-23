#ifndef PARSE_H_INCLUDED
#define PARSE_H_INCLUDED

#include <bits/stdc++.h>
#include "SCAN.H"
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
private:
    void printTable(); //打印预测分析表
    void printQueue(queue<string>);
    void printStack(stack<string>);
    void printStep(int, int);
    void init();
    queue<string> ready, done;
    stack<string> st;

public:
    int pdnum; //产生式数量
    int ternum; //终结符+#的数量
    int ntnum; //非终结符数量
    string production[maxn]; //产生式
    Grid predictTable[maxn][maxn]; //第一维非终结符，第二维终结符
    map<string, int> t2i; //终结符转下标
    map<string, int> n2i; //非终结符转下标
    LL1();
    void getTable(string); //填充该LL(1)文法的预测分析表
    void getCode(string);
    void analyse(string, string);
};


#endif // PARSE_H_INCLUDED
