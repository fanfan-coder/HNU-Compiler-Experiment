#ifndef PARSE_H_INCLUDED
#define PARSE_H_INCLUDED

#include <bits/stdc++.h>
#include "SCAN.H"
using namespace std;
const int maxn = 1e2;

struct Grid{
    int n; //����ʽ�Ҳ���ŵ�����
    int pn; //����ʽ�ı��
    string x[maxn]; //����ʽ�ķ���
    Grid() { n = 0; pn = -1; }
    Grid(int n, int pn): n(n), pn(pn) {}
};

class LL1{
private:
    void printTable(); //��ӡԤ�������
    void printQueue(queue<string>);
    void printStack(stack<string>);
    void printStep(int, int);
    void init();
    queue<string> ready, done;
    stack<string> st;

public:
    int pdnum; //����ʽ����
    int ternum; //�ս��+#������
    int ntnum; //���ս������
    string production[maxn]; //����ʽ
    Grid predictTable[maxn][maxn]; //��һά���ս�����ڶ�ά�ս��
    map<string, int> t2i; //�ս��ת�±�
    map<string, int> n2i; //���ս��ת�±�
    LL1();
    void getTable(string); //����LL(1)�ķ���Ԥ�������
    void getCode(string);
    void analyse(string, string);
};


#endif // PARSE_H_INCLUDED
