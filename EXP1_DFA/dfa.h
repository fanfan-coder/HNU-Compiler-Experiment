#ifndef DFA_H_INCLUDED
#define DFA_H_INCLUDED
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3;

class DFA
{
public:
    int chNum; //字符集的字符个数
    char alphabet[maxn]; //字符集
    int stNum; //状态个数
    int stID[maxn]; //状态编号
    int stStNum; //开始状态个数
    int stState; //开始状态编号
    int fiStNum; //接受状态个数
    int fiState[maxn]; //接收状态编号
    map<char, int> ch2ID; //字符在字符集中的次序
    map<int, int> ID2i; //字符编号在字符集中的次序（从0开始）

    struct Edge
    {
        char c; //读入的字符
        int to; //到达的状态
        Edge() {}
        Edge(char c, int to): c(c), to(to) {}
    };

    struct State
    {
        int ID; //状态编号
        int move[maxn]; //转换表 用于稠密图
        vector<Edge> vmove; //用于稀疏图
        bool isStart, isFinish; //标记开始状态或接受状态
        State()
        {
            ID = 0;
            memset(move, -1, sizeof(move));
            vmove.clear();
            isStart = isFinish = 0;
        }
    }state[maxn];

    DFA();
    void read(); //读入DFA的各个参数
    void print(); //打印DFA的各个参数
    bool checkPt1();
    bool checkPt2();
    bool checkPt3();
    bool checkPt4();
    bool check(); //检查DFA的合法性
    void getLangDFS(int, int, int, string);
    void getLang(int); //得到该DFA能产生的长度小于等于n的串
    bool isLang(string); //判断某个串是否被该DFA接收
};

#endif // DFA_H_INCLUDED
