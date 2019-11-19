#include <bits/stdc++.h>
#include "ANALYSE.h"
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

void LL1:: getTable()
{
    ifstream infile;
    infile.open("TINY_LIST.txt");
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
