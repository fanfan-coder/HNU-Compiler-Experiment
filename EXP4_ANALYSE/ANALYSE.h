#ifndef ANALYSE_H_INCLUDED
#define ANALYSE_H_INCLUDED

#include <bits/stdc++.h>
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
public:
    int pdnum; //����ʽ����
    int ternum; //�ս��+#������
    int ntnum; //���ս������
    string production[maxn]; //����ʽ
    Grid predictTable[maxn][maxn]; //��һά���ս�����ڶ�ά�ս��
    map<string, int> t2i; //�ս��ת�±�
    map<string, int> n2i; //���ս��ת�±�

    LL1();
    void getTable(); //����LL(1)�ķ���Ԥ�������
    void printTable(); //��ӡԤ�������
};


#endif // ANALYSE_H_INCLUDED
