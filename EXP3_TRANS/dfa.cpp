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
        �����ʽ
        �ַ�������
        �ַ���
        ״̬����
        �ظ�״̬������   ״̬��� ״̬����{0:start; 1:normal; 2:finish; 3 start&finish}
        ת����
    */
    cin >> FAType;
    if(FAType == 0)
    {
        alphabet[0] = '-'; //���ַ����һ���ַ�����Ϊ����
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
        state[i].stbiID = 1 << i; //��i��״̬�ı��Ϊ2^i

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
            cin >> nextState; //״̬���
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

    cout << "�ַ����ַ�������" << chNum << endl;
    cout << "�ַ�����";
    for(int i = (FAType > 0 ? 1 : 0); i <= chNum; ++i)
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

    cout << "ת�����ߣ���" << endl;
    for(int i = 0; i < stNum; ++i)
    {
        int len = state[i].vmove.size();
        for(int j = 0; j < len; ++j)
            cout << stID[i] << ' ' << state[i].vmove[j].c << ' ' << state[i].vmove[j].to << endl;
    }
    cout << endl;
}

bool FA:: checkPt1() //������м��ϵ�Ԫ�ص�Ψһ�ԡ�
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

bool FA:: checkPt2()  //��顰��ʼ״̬���Ƿ�Ψһ�����Ƿ�����ڡ�״̬�����С�
{
    bool flag = (stStNum == 1);
    if(!flag)
        cout << "���󣺿�ʼ״̬��Ψһ" << endl;
    return flag;
}

bool FA:: checkPt3() //��顰����״̬�����Ƿ�Ϊ�գ����Ƿ�����ڡ�״̬�����С�
{
    bool flag = (fiStNum != 0);
    if(!flag)
        cout << "���󣺽���״̬��Ϊ��" << endl;
    return flag;
}

bool FA:: checkPt4() //��顰״̬ת�����Ƿ�����DFA��Ҫ��
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

ull FA:: getClosureDFS(int i, char c, bool visited)
{
    ull ret = 0;
    for(int j = 0; j < state[i].vmove.size(); ++j)
    {
        if(state[i].vmove[j].c == '-') //���֣�������
        {
            ret |= state[ID2i[state[i].vmove[j].to]].stbiID; //��ǰ״̬���Ա����뼯��
            ret |= getClosureDFS(ID2i[state[i].vmove[j].to], c, 0); //�����Ӹ�״̬�����ߵ�����
        }

        if(!visited && state[i].vmove[j].c == c) //�����δ�߹�c
        {
            ret |= state[ID2i[state[i].vmove[j].to]].stbiID;
            ret |= getClosureDFS(ID2i[state[i].vmove[j].to], c, 1); //visited��Ϊ1����ʾ�Ѿ��߹���c��֮��ֻ���߿�����
        }
    }
    return ret;
}

ull FA:: getClosure(ull curSet, char c) //�õ���ǰ�Ӽ�����һ��c�õ���״̬��
{
    ull ret = 0;
    for(int i = 0; i < 64; ++i)
    {
        if((curSet & ((ull)(1)<<i)) > 0) //�����״̬1<<i
            ret |= getClosureDFS(i, c, 0); //������c-closure
    }
    return ret;
}

void FA:: NFA2DFA(FA& dfa) //�Ӽ����취NFA����DFA
{
    ull setSet[maxState], setSize = 0, pos = 0; //�Ӽ���
    ull curSet = state[ID2i[stState]].stbiID, nextSet = 0; //�õ���ʼ״̬�Ķ����Ʊ��
    curSet |= getClosure(curSet, '-'); //�ȵõ���ʼ״̬�Ħ�-closure
    setSet[setSize++] = curSet; //�����Ӽ���
    int nextSetSet[maxState][maxState]; //�µ�ת�Ʊ�

    while(1)
    {
        for(int i = 1; i <= chNum; ++i) //�����ַ���
        {
            nextSet = getClosure(curSet, alphabet[i]); //�ҵ���ǰ���ϵ�c-closure
            bool flag = 1; //��Ǹ��Ӽ��Ƿ��ѳ��ֹ�
            for(int j = 0; j < setSize; ++j)
            {
                if(setSet[j] == nextSet) //�����ѳ��ֹ�
                {
                    nextSetSet[pos][i] = j; //�����µ�ת�Ʊ�
                    flag = 0;
                }
            }
            if(flag) //���δ���ֹ�
            {
                if(nextSet) //�����Ϊ0
                {
                    nextSetSet[pos][i] = setSize; //����ת�Ʊ�
                    setSet[setSize++] = nextSet; //�����ѳ��ֵ��Ӽ�����
                }
                else //Ϊ0��ʾ�ռ�
                {
                    nextSetSet[pos][i] = -1;
                }
            }
        }
        if(++pos >= setSize) break; //��������Ӽ����Ѵ���������˳�
        curSet = setSet[pos]; //���򽫵�ǰ�Ӽ����³���һ��
    }

    //�����ǽ�dfa����Ϣ����
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

void FA:: DFAMinimise(FA& mindfa) //�ȼۻ��ַ���С��DFA
{
    if((FAType > 0 ? 0 : 1)) //����������NFA������ת����NFA
        NFA2DFA(mindfa);
    int rt[maxState] = {0}, cnt = 1; //ÿ��״̬���ڵĻ��ּ�
    for(int i = 0; i < stNum; ++i)
        if(state[i].isFinish) //�ȷֿ���̬�����̬
            rt[i] = 1;

    for(int i = 0; i <= cnt; ++i) //һֱѭ�����޷������»���
    {
        int curSet[maxState] = {0}, curcnt = 0;
        for(int j = 0; j < stNum; ++j) //����ǰҪ����ļ��ϵ����ó���
            if(rt[j] == i)
                curSet[curcnt++] = j;

        for(int j = 1; j <= chNum; ++j) //���ÿ���ַ��������ܷ��������ֿ�
        {
            int curToRt = rt[state[curSet[0]].move[j]];
            bool flag = 0;
            for(int k = 1; k < curcnt; ++k)
                if(rt[state[curSet[k]].move[j]] != curToRt && rt[curSet[0]] == rt[curSet[k]]) //���ȥ���˲�ͬ�ļ���
                {
                    rt[curSet[k]] = cnt+1; //����»���
                    flag = 1;
                }
            if(flag) //����������»���
            {
                ++cnt; //�ܻ���+1
            }
        }
    }

    //�����ǹ���MinDFA
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
