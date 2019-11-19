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
        �����ʽ
        �ַ�������
        �ַ���
        ״̬����
        �ظ�״̬������   ״̬��� ״̬����{0:start; 1:normal; 2:finish; 3 start&finish}
        ת����
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
            cin >> nextState; //״̬���
            state[i].move[j] = nextState;
            if(~nextState)
                state[i].vmove.push_back(Edge(alphabet[j], nextState));
        }
}

void DFA:: print()
{
    cout << "�ַ����ַ�������" << chNum << endl;
    cout << "�ַ�����";
    for(int i = 0; i < stNum; ++i)
        cout << alphabet[i] << ' ';
    cout << endl;

    cout << "״̬��������" << stNum << endl;
    cout << "״̬����" << endl;
    for(int i = 0; i < stNum; ++i)
    {
        cout << "״̬��ţ�" << stID[i] << " ״̬���ͣ�";
        if(state[i].isStart && state[i].isFinish) cout << 3;
        else if(state[i].isStart) cout << 0;
        else if(state[i].isFinish) cout << 2;
        else cout << 1;
        cout << endl;
    }
    cout << endl;

    cout << "��ʼ״̬��ţ�" << stState << endl;
    cout << "����״̬������" << fiStNum << endl;
    cout << "����״̬��ţ�";
    for(int i = 0; i < fiStNum; ++i)
        cout << fiState[i] << ' ';
    cout << endl << endl;

    cout << "ת�����ڽӾ��󣩣�" << endl;
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

    cout << "ת�����ߣ���" << endl;
    for(int i = 0; i < stNum; ++i)
    {
        int len = state[i].vmove.size();
        for(int j = 0; j < len; ++j)
            cout << stID[i] << ' ' << state[i].vmove[j].c << ' ' << state[i].vmove[j].to << endl;
    }
    cout << endl;
}

bool DFA:: checkPt1() //������м��ϵ�Ԫ�ص�Ψһ�ԡ�
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
            cout << "�����ַ����ظ�" << endl;
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
            cout << "����״̬���ظ�" << endl;
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
            cout << "���󣺽���״̬���ظ�" << endl;
        }
    }

    return flag;
}

bool DFA:: checkPt2()  //��顰��ʼ״̬���Ƿ�Ψһ�����Ƿ�����ڡ�״̬�����С�
{
    bool flag = (stStNum == 1);
    if(!flag)
        cout << "���󣺿�ʼ״̬��Ψһ" << endl;
    return flag;
}

bool DFA:: checkPt3() //��顰����״̬�����Ƿ�Ϊ�գ����Ƿ�����ڡ�״̬�����С�
{
    bool flag = (fiStNum != 0);
    if(!flag)
        cout << "���󣺽���״̬��Ϊ��" << endl;
    return flag;
}

bool DFA:: checkPt4() //��顰״̬ת�����Ƿ�����DFA��Ҫ��
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
                cout << "����״̬ת��������Ҫ�󣬳���״̬��ţ�" << stID[i] << endl;
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
    cout << "״̬ת�ƣ�" << endl;
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
