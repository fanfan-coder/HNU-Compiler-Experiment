#include <bits/stdc++.h>
#include "dfa.h"
#define ull unsigned long long
#define maxState 66
using namespace std;

FA:: FA()
{
    chNum = stNum = stState = fiStNum = 0;
    memset(alphabet, 0, sizeof(alphabet));
    memset(stID, -1, sizeof(stID));
    memset(fiState, -1, sizeof(fiState));
}

void FA:: read()
{
    /*
        读入格式
        字符集个数
        字符集
        状态个数
        重复状态个数次   状态编号 状态类型{0:start; 1:normal; 2:finish; 3 start&finish}
        转换表
    */
    cin >> FAType;
    if(FAType == 0)
    {
        alphabet[0] = '-'; //将字符表第一个字符设置为空字
        ch2ID[alphabet[0]] = 0;
    }
    cin >> chNum;
    for(int i = 1; i <= chNum; ++i)
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
        state[i].stbiID = 1 << i; //第i个状态的编号为2^i

        int stType;
        cin >> stType;
        state[i].stateType = stType;
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
        for(int j = (FAType > 0 ? 1 : 0); j <= chNum; ++j)
        {
            cin >> nextState; //状态编号
            state[i].move[j] = nextState;
            if(~nextState)
                state[i].vmove.push_back(Edge(alphabet[j], nextState));
        }
}

void FA:: print()
{
    if(FAType == 0)
        cout << "NFA as follow: " << endl;
    else if(FAType == 1)
        cout << "DFA as follow: " << endl;
    else if(FAType == 2)
        cout << "MinDFA as follow: " << endl;

    cout << "字符集字符个数：" << chNum << endl;
    cout << "字符集：";
    for(int i = (FAType > 0 ? 1 : 0); i <= chNum; ++i)
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
    for(int i = (FAType > 0 ? 1 : 0); i <= chNum; ++i)
        cout << "  " << alphabet[i];
    cout << endl;
    for(int i = 0; i < stNum; ++i)
    {
        cout << stID[i];
        for(int j = (FAType > 0 ? 1 : 0); j <= chNum; ++j)
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

bool FA:: checkPt1() //检查所有集合的元素的唯一性。
{
    bool flag = 1;
    bool vis[maxn] = {0};
    for(int i = (FAType > 0 ? 1 : 0); i <= chNum; ++i)
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

bool FA:: checkPt2()  //检查“开始状态”是否唯一，并是否包含在“状态集”中。
{
    bool flag = (stStNum == 1);
    if(!flag)
        cout << "错误：开始状态不唯一" << endl;
    return flag;
}

bool FA:: checkPt3() //检查“接受状态集”是否为空，并是否包含在“状态集”中。
{
    bool flag = (fiStNum != 0);
    if(!flag)
        cout << "错误：接受状态集为空" << endl;
    return flag;
}

bool FA:: checkPt4() //检查“状态转换表”是否满足DFA的要求。
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

bool FA:: check()
{
    bool flag = 1;
    if(!checkPt1()) flag = 0;
    if(!checkPt2()) flag = 0;
    if(!checkPt3()) flag = 0;
    if(!checkPt4()) flag = 0;
    return flag;
}

void FA:: getLangDFS(int curState, int curLen, int totLen, string s)
{
    if(curLen > totLen) return;
    if(state[curState].isFinish)
        cout << s << endl;
    //if(curLen == totLen) return;

    int moveSum = state[curState].vmove.size();
    for(int i = 0; i < moveSum; ++i)
    {
        int nextState = ID2i[state[curState].vmove[i].to];
        if(state[curState].vmove[i].c == '-')
            getLangDFS(nextState, curLen, totLen, s);
        else
            getLangDFS(nextState, curLen+1, totLen, s+state[curState].vmove[i].c);
    }
}

void FA:: getLang(int n)
{
    string s = "";
    getLangDFS(ID2i[stState], 0, n, s);
}

bool FA:: isLang(string s)
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

ull FA:: getClosureDFS(int i, char c, bool visited)
{
    ull ret = 0;
    for(int j = 0; j < state[i].vmove.size(); ++j)
    {
        if(state[i].vmove[j].c == '-') //空字，可以走
        {
            ret |= state[ID2i[state[i].vmove[j].to]].stbiID; //当前状态可以被纳入集合
            ret |= getClosureDFS(ID2i[state[i].vmove[j].to], c, 0); //看看从该状态还能走到哪里
        }

        if(!visited && state[i].vmove[j].c == c) //如果尚未走过c
        {
            ret |= state[ID2i[state[i].vmove[j].to]].stbiID;
            ret |= getClosureDFS(ID2i[state[i].vmove[j].to], c, 1); //visited设为1，表示已经走过了c，之后只能走空字了
        }
    }
    return ret;
}

ull FA:: getClosure(ull curSet, char c) //得到当前子集经过一个c得到的状态集
{
    ull ret = 0;
    for(int i = 0; i < 64; ++i)
    {
        if((curSet & ((ull)(1)<<i)) > 0) //如果有状态1<<i
            ret |= getClosureDFS(i, c, 0); //找它的c-closure
    }
    return ret;
}

void FA:: NFA2DFA(FA& dfa) //子集构造法NFA生成DFA
{
    ull setSet[maxState], setSize = 0, pos = 0; //子集集
    ull curSet = state[ID2i[stState]].stbiID, nextSet = 0; //得到开始状态的二进制编号
    curSet |= getClosure(curSet, '-'); //先得到开始状态的ε-closure
    setSet[setSize++] = curSet; //放入子集集
    int nextSetSet[maxState][maxState]; //新的转移表

    while(1)
    {
        for(int i = 1; i <= chNum; ++i) //遍历字符集
        {
            nextSet = getClosure(curSet, alphabet[i]); //找到当前集合的c-closure
            bool flag = 1; //标记该子集是否已出现过
            for(int j = 0; j < setSize; ++j)
            {
                if(setSet[j] == nextSet) //假如已出现过
                {
                    nextSetSet[pos][i] = j; //更新新的转移表
                    flag = 0;
                }
            }
            if(flag) //如果未出现过
            {
                if(nextSet) //如果不为0
                {
                    nextSetSet[pos][i] = setSize; //更新转移表
                    setSet[setSize++] = nextSet; //假如已出现的子集集合
                }
                else //为0表示空集
                {
                    nextSetSet[pos][i] = -1;
                }
            }
        }
        if(++pos >= setSize) break; //如果所有子集都已处理完毕则退出
        curSet = setSet[pos]; //否则将当前子集更新成下一个
    }

    //以下是将dfa的信息更新
    dfa.FAType = 1;
    dfa.chNum = chNum;
    for(int i = 1; i <= chNum; ++i)
    {
        dfa.alphabet[i] = alphabet[i];
        dfa.ch2ID[alphabet[i]] = i;
    }
    dfa.stNum = setSize;
    for(int i = 0; i < setSize; ++i)
    {
        dfa.stID[i] = i;
        dfa.ID2i[dfa.stID[i]] = i;
    }
    dfa.stStNum = 1;
    dfa.stState = 0;
    dfa.state[0].isStart = 1;
    dfa.fiStNum = 0;
    for(int i = 0; i < setSize; ++i)
    {
        for(int j = 0; j < fiStNum; ++j)
        {
            int t = ID2i[fiState[j]];
            if((state[t].stbiID & setSet[i]) > 0)
            {
                dfa.fiState[dfa.fiStNum++] = dfa.stID[i];
                dfa.state[i].isFinish = 1;
            }
        }
    }

    for(int i = 0; i < setSize; ++i)
        for(int j = 1; j <= chNum; ++j)
        {
            dfa.state[i].move[j] = nextSetSet[i][j];
            if(~nextSetSet[i][j])
                dfa.state[i].vmove.push_back(Edge(alphabet[j], nextSetSet[i][j]));
        }
}

void FA:: DFAMinimise(FA& mindfa) //等价划分法最小化DFA
{
    if((FAType > 0 ? 0 : 1)) //如果输入的是NFA，就先转换成NFA
        NFA2DFA(mindfa);
    int rt[maxState] = {0}, cnt = 1; //每个状态属于的划分集
    for(int i = 0; i < stNum; ++i)
        if(state[i].isFinish) //先分开终态与非终态
            rt[i] = 1;

    for(int i = 0; i <= cnt; ++i) //一直循环到无法产生新划分
    {
        int curSet[maxState] = {0}, curcnt = 0;
        for(int j = 0; j < stNum; ++j) //将当前要处理的集合单独拿出来
            if(rt[j] == i)
                curSet[curcnt++] = j;

        for(int j = 1; j <= chNum; ++j) //针对每个字符，看看能否将它们区分开
        {
            int curToRt = rt[state[curSet[0]].move[j]];
            bool flag = 0;
            for(int k = 1; k < curcnt; ++k)
                if(rt[state[curSet[k]].move[j]] != curToRt && rt[curSet[0]] == rt[curSet[k]]) //如果去到了不同的集合
                {
                    rt[curSet[k]] = cnt+1; //添加新划分
                    flag = 1;
                }
            if(flag) //如果出现了新划分
            {
                ++cnt; //总划分+1
            }
        }
    }

    //以下是构造MinDFA
    mindfa.FAType = 2;
    mindfa.chNum = chNum;
    for(int i = 1; i <= chNum; ++i)
    {
        mindfa.alphabet[i] = alphabet[i];
        mindfa.ch2ID[alphabet[i]] = i;
    }
    mindfa.stNum = ++cnt;
    for(int i = 0; i < cnt; ++i)
    {
        for(int j = 0; j < stNum; ++j)
            if(rt[j] == i)
            {
                mindfa.state[i].ID = stID[j];
                mindfa.stID[i] = stID[j];
                mindfa.ID2i[mindfa.stID[i]] = i;
                break;
            }
    }

    mindfa.stStNum = 1;
    mindfa.stState = mindfa.stID[rt[0]];
    //mindfa.state[0].isStart = 0;
    mindfa.state[mindfa.ID2i[stState]].isStart = 1;
    mindfa.fiStNum = 0;
    for(int i = 0; i < cnt; ++i)
    {
        for(int j = 0; j < fiStNum; ++j)
        {
            int t = ID2i[fiState[j]];
            if(state[t].isFinish && rt[t] == i)
            {
                mindfa.fiState[mindfa.fiStNum++] = mindfa.stID[i];
                mindfa.state[i].isFinish = 1;
                break;
            }
        }
    }
    for(int i = 0; i < cnt; ++i)
        for(int j = 1; j <= chNum; ++j)
        {
            int nextState = state[ID2i[mindfa.stID[i]]].move[j];
            if(nextState != -1)
                nextState = mindfa.stID[rt[state[ID2i[mindfa.stID[i]]].move[j]]];
            mindfa.state[i].move[j] = nextState;
            if(~nextState)
                mindfa.state[i].vmove.push_back(Edge(alphabet[j], nextState));
        }
}
