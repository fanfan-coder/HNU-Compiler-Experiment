#include <bits/stdc++.h>
#include "dfa.h"
using namespace std;

DFA:: DFA()
{
    chNum = stNum = stState = fiStNum = 0;
    memset(alphabet, 0, sizeof(alphabet));
    memset(stID, -1, sizeof(stID));
    memset(fiState, -1, sizeof(fiState));
}

void DFA:: read()
{
    /*
        读入格式
        字符集个数
        字符集
        状态个数
        重复状态个数次   状态编号 状态类型{0:start; 1:normal; 2:finish; 3 start&finish}
        转换表
    */
    cin >> chNum;
    for(int i = 0; i < chNum; ++i)
    {
        cin >> alphabet[i];
        ch2ID[alphabet[i]] = i;
    }
    cin >> stNum;
    for(int i = 0; i < stNum; ++i)
    {
        int stateID;
        cin >> stateID;
        stID[i] = stateID;
        ID2i[stateID] = i;
        state[i].ID = stateID;

        int stType;
        cin >> stType;
        if(stType == 0)
        {
            stState = stateID;
            state[i].isStart = 1;
            ++stStNum;
        }
        else if(stType == 2)
        {
            state[i].isFinish = 1;
            fiState[fiStNum++] = stateID;
        }
        else if(stType == 3)
        {
            stState = stateID;
            state[i].isStart = 1;
            ++stState;
            state[i].isFinish = 1;
            fiState[fiStNum++] = stateID;
        }
    }

    int nextState;
    for(int i = 0; i < stNum; ++i)
        for(int j = 0; j < chNum; ++j)
        {
            cin >> nextState; //状态编号
            state[i].move[j] = nextState;
            if(~nextState)
                state[i].vmove.push_back(Edge(alphabet[j], nextState));
        }
}

void DFA:: print()
{
    cout << "字符集字符个数：" << chNum << endl;
    cout << "字符集：";
    for(int i = 0; i < stNum; ++i)
        cout << alphabet[i] << ' ';
    cout << endl;

    cout << "状态集个数：" << stNum << endl;
    cout << "状态集：" << endl;
    for(int i = 0; i < stNum; ++i)
    {
        cout << "状态编号：" << stID[i] << " 状态类型：";
        if(state[i].isStart && state[i].isFinish) cout << 3;
        else if(state[i].isStart) cout << 0;
        else if(state[i].isFinish) cout << 2;
        else cout << 1;
        cout << endl;
    }
    cout << endl;

    cout << "开始状态编号：" << stState << endl;
    cout << "接受状态个数：" << fiStNum << endl;
    cout << "接受状态编号：";
    for(int i = 0; i < fiStNum; ++i)
        cout << fiState[i] << ' ';
    cout << endl << endl;

    cout << "转换表（邻接矩阵）：" << endl;
    for(int i = 0; i < chNum; ++i)
        cout << "  " << alphabet[i];
    cout << endl;
    for(int i = 0; i < stNum; ++i)
    {
        cout << stID[i];
        for(int j = 0; j < chNum; ++j)
            cout << ' ' << state[i].move[j];
        cout << endl;
    }
    cout << endl;

    cout << "转换表（边）：" << endl;
    for(int i = 0; i < stNum; ++i)
    {
        int len = state[i].vmove.size();
        for(int j = 0; j < len; ++j)
            cout << stID[i] << ' ' << state[i].vmove[j].c << ' ' << state[i].vmove[j].to << endl;
    }
    cout << endl;
}

bool DFA:: checkPt1() //检查所有集合的元素的唯一性。
{
    bool flag = 1;
    bool vis[maxn] = {0};
    for(int i = 0; i < chNum; ++i)
    {
        int chID = ch2ID[alphabet[i]];
        if(!vis[chID])
            vis[chID] = 1;
        else
        {
            flag = 0;
            cout << "错误：字符集重复" << endl;
        }
    }

    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < stNum; ++i)
    {
        int stateID = stID[i];
        if(!vis[stateID])
            vis[stateID] = 1;
        else
        {
            flag = 0;
            cout << "错误：状态集重复" << endl;
        }
    }

    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < fiStNum; ++i)
    {
        int fiStateID = fiState[i];
        if(!vis[fiStateID])
            vis[fiStateID] = 1;
        else
        {
            flag = 0;
            cout << "错误：接受状态集重复" << endl;
        }
    }

    return flag;
}

bool DFA:: checkPt2()  //检查“开始状态”是否唯一，并是否包含在“状态集”中。
{
    bool flag = (stStNum == 1);
    if(!flag)
        cout << "错误：开始状态不唯一" << endl;
    return flag;
}

bool DFA:: checkPt3() //检查“接受状态集”是否为空，并是否包含在“状态集”中。
{
    bool flag = (fiStNum != 0);
    if(!flag)
        cout << "错误：接受状态集为空" << endl;
    return flag;
}

bool DFA:: checkPt4() //检查“状态转换表”是否满足DFA的要求。
{
    bool flag;
    for(int i = 0; i < stNum; ++i)
    {
        flag = 1;
        int moveSum = state[i].vmove.size();
        for(int j = 0; j < moveSum; ++j)
        {
            int nextState = state[i].vmove[j].to;
            if(!ID2i.count(nextState))
            {
                flag = 0;
                cout << "错误：状态转换表不满足要求，出错状态编号：" << stID[i] << endl;
            }
        }
    }
    return flag;
}

bool DFA:: check()
{
    bool flag = 1;
    if(!checkPt1()) flag = 0;
    if(!checkPt2()) flag = 0;
    if(!checkPt3()) flag = 0;
    if(!checkPt4()) flag = 0;
    return flag;
}

void DFA:: getLangDFS(int curState, int curLen, int totLen, string s)
{
    if(curLen <= totLen)
    {
        if(state[curState].isFinish)
            cout << s << endl;
        if(curLen == totLen)
            return;
    }

    int moveSum = state[curState].vmove.size();
    if(!moveSum) return;
    for(int i = 0; i < moveSum; ++i)
    {
        int nextState = ID2i[state[curState].vmove[i].to];
        getLangDFS(nextState, curLen+1, totLen, s+state[curState].vmove[i].c);
    }
}

void DFA:: getLang(int n)
{
    string s = "";
    getLangDFS(ID2i[stState], 0, n, s);
}

bool DFA:: isLang(string s)
{
    int len = s.length();
    int curState = ID2i[stState];
    cout << "状态转移：" << endl;
    cout << stState;
    for(int i = 0; i < len; ++i)
    {
        bool flag = 1;
        int moveSum = state[curState].vmove.size();
        for(int j = 0; j < moveSum; ++j)
            if(s[i] == state[curState].vmove[j].c)
            {
                curState = ID2i[state[curState].vmove[j].to];
                cout << " -> " << stID[curState];
                flag = 0;
                break;
            }
        if(flag)
            return false;
    }
    return state[curState].isFinish;
}
