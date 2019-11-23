#include <bits/stdc++.h>
#include "PARSE.h"
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

LL1:: LL1()
{
    for(int i = 0; i < maxn; ++i)
        production[i] = "NULL";
    for(int i = 0; i < maxn; ++i)
        for(int j = 0; j < maxn; ++j)
            predictTable[i][j] = Grid();
}

void LL1:: getTable(string FILE)
{
    ifstream infile;
    infile.open(&FILE[0]);
    string s;
    infile >> pdnum;
    infile.get();
    for(int i = 0; i < pdnum; ++i)
        getline(infile, production[i]);
    infile >> ternum;
    for(int i = 0; i < ternum; ++i)
    {
        infile >> s;
        t2i[s] = i;
    }
    infile >> ntnum;
    for(int i = 0; i < ntnum; ++i)
    {
        infile >> s;
        n2i[s] = i;
    }
    for(int i = 0; i < pdnum; ++i)
    {
        int ntn, n, t; //非终结符编号, 体的符号个数, 要填入的格子的数目
        string ss[maxn]; //当前产生式的体

        infile >> ntn >> n;
        for(int j = 0; j < n; ++j)
            infile >> ss[j];
        infile >> t;
        for(int j = 0; j < t; ++j)
        {
            infile >> s;
            predictTable[ntn][t2i[s]] = Grid(n, i); //创建项目
            for(int k = 0; k < n; ++k)
                predictTable[ntn][t2i[s]].x[k] = ss[k];
        }
    }
    infile.close();
}

void LL1:: printTable()
{
    cout << "Production: " << endl;
    for(int i = 0; i < pdnum; ++i)
        cout << production[i] << endl;
    cout << endl;

    for(int i = 0; i < ntnum; ++i)
    {
        cout << i << ": ";
        for(int j = 0; j < ternum; ++j)
        {
            if(!predictTable[i][j].n)
                cout << "E\t";
            else
            {
                //cout << predictTable[i][j].n << ',' << predictTable[i][j].pn;
                for(int k = 0; k < predictTable[i][j].n; ++k)
                    cout << predictTable[i][j].x[k] << ' ';
                cout << '\t';
            }
        }
        cout << endl;
    }
}

void LL1:: printQueue(queue<string> q)
{
    while(!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }
}

void LL1:: printStack(stack<string> s)
{
    while(!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
}

void LL1:: printStep(int i, int pi) //打印中间步骤
{
    cout << "STEP #" << i << endl;

    cout << "DONE: ";
    printQueue(done);
    cout << endl;

    cout << "STACK: ";
    printStack(st);
    cout << endl;

    cout << "READY: ";
    printQueue(ready);
    cout << endl;

    cout << "ACTION: ";
    if(~pi) cout << production[pi] << endl << endl;
}

void LL1:: getCode(string FILE)
{
    freopen(&FILE[0], "r", stdin);
    TokenType token;
    while(!EOFFlag && (token = getToken()) != ERROR)
    {
        ready.push(getTokenString(token));
    }
}

void LL1:: init()
{
    while(!ready.empty()) ready.pop();
    while(!done.empty()) done.pop();
    while(!st.empty()) st.pop();
}

void LL1:: analyse(string TABLE, string CODE)
{
    init();
    getTable(TABLE);
    getCode(CODE);

    st.push("ENDFILE"); //将#压栈
    st.push("program"); //将开始符号压栈
    printStep(0, -1); //打印初始状态
    cout << endl << endl;

    int cnt = 1;
    string X;
    while((X = st.top()) != "ENDFILE") //如果不在栈底
    {
        string a = ready.front(); //当前输入
        if(X == a) //如果相等
        {
            done.push(a); //将当前输入放到已匹配队列
            ready.pop(); //出队
            st.pop(); //匹配成功，出栈
            printStep(cnt++, -1);
            cout << "Match " << X << endl << endl; //打印匹配动作
        }
        else if(t2i.count(X)) //如果X != a，但X是个终结符，说明失配
        {
            cout << "ERROR1" << endl;
            break;
        }
        else if(!predictTable[n2i[X]][t2i[a]].n) //如果预测分析表该处为空，则说明ERROR
        {
            cout << "ERROR2" << endl;
            break;
        }
        else //如果预测分析表该处不为空，说明可以状态转移
        {
            st.pop(); //先将当前状态出栈
            for(int i = predictTable[n2i[X]][t2i[a]].n-1; i >= 0; --i) //将体逆序入栈
            {
                string stoken = predictTable[n2i[X]][t2i[a]].x[i];
                if(stoken != "$") //如果是空字就不入栈了
                    st.push(predictTable[n2i[X]][t2i[a]].x[i]);
            }
            printStep(cnt++, predictTable[n2i[X]][t2i[a]].pn);
        }
    }
}
