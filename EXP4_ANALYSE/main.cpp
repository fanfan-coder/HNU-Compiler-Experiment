#include <bits/stdc++.h>
#include "scan.h"
#include "analyse.h"
using namespace std;
LL1 tiny;
queue<string> ready, done;
stack<string> st;
TokenType token;

void getTable()
{
    tiny.getTable();
    //tiny.printTable();
}

void printQueue(queue<string> q)
{
    while(!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }
}

void printStack(stack<string> s)
{
    while(!s.empty())
    {
        cout << s.top() << ' ';
        s.pop();
    }
}

void printStep(int i, int pi) //打印中间步骤
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
    if(~pi) cout << tiny.production[pi] << endl << endl;
}

void getCode()
{
    freopen("SAMPLE.TNY", "r", stdin);
    while(!EOFFlag && (token = getToken()) != ERROR)
    {
        ready.push(getTokenString(token));
    }
}

void analyse()
{
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
            printStep(cnt, -1);
            ++cnt;
            cout << "Match " << X << endl << endl; //打印匹配动作
        }
        else if(tiny.t2i.count(X)) //如果X != a，但X是个终结符，说明失配
        {
            cout << "ERROR1" << endl;
            break;
        }
        else if(!tiny.predictTable[tiny.n2i[X]][tiny.t2i[a]].n) //如果预测分析表该处为空，则说明ERROR
        {
            cout << "ERROR2" << endl;
            break;
        }
        else //如果预测分析表该处不为空，说明可以状态转移
        {
            st.pop(); //先将当前状态出栈
            for(int i = tiny.predictTable[tiny.n2i[X]][tiny.t2i[a]].n-1; i >= 0; --i) //将体逆序入栈
                if(tiny.predictTable[tiny.n2i[X]][tiny.t2i[a]].x[i] != "$") //如果是空字就不入栈了
                    st.push(tiny.predictTable[tiny.n2i[X]][tiny.t2i[a]].x[i]);
            printStep(cnt, tiny.predictTable[tiny.n2i[X]][tiny.t2i[a]].pn);
            ++cnt;
        }
    }
}

int main()
{
    getTable();
    getCode();
    analyse();
    return 0;
}
