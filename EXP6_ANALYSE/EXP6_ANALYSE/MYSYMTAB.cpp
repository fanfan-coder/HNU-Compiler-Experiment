#include <bits/stdc++.h>
#include "SYMTAB.H"
using namespace std;

struct symEntry
{
    string name; //variable name
    vector<int> lines; //lines where symbol appears in source code
    int memloc; //memory location for variable
    symEntry() { lines.clear(); }
    symEntry(string name, int memloc): name(name), memloc(memloc) { lines.clear(); }
    void addLine(int lineno) {
		//if(find(lines.begin(), lines.end(), lineno) == lines.end()) //if there's no need for multi entries
			lines.push_back(lineno);
	}

	bool operator < (const symEntry& se) const
	{
		return memloc < se.memloc;
	}
};
unordered_map<string, symEntry> mss;

void st_insert(char * name, int lineno, int * loc)
{
	symEntry se;
    if(mss.count(name)) //name has been recorded
        se = mss[name];
    else
        se = symEntry(name, (*loc)++);
	se.addLine(lineno);
	mss[name] = se;
}

int st_lookup (char * name)
{
    if(mss.count(name))
        return mss[name].memloc;
    else
        return -1;
}

bool cmp(pair<string, symEntry>& a, pair<string, symEntry>& b)
{
	return a.second < b.second;
}

void printSymTab(FILE * listing)
{
    cout << "Variable Name  Location   Line Numbers" << endl;
    cout << "-------------  --------   ------------" << endl;

	vector<pair<string, symEntry>> tmp;
	for (auto& i : mss) tmp.push_back(i);
	sort(tmp.begin(), tmp.end(), cmp);
    vector<pair<string, symEntry> >::iterator iter;
    for(iter = tmp.begin(); iter != tmp.end(); ++iter)
    {
        symEntry se = iter->second;
        cout << left << setw(15) << se.name;
        cout << left << setw(11) << se.memloc;
        for(int i = 0; i < se.lines.size(); ++i)
            cout << left << setw(4) << se.lines[i];
        cout << endl;
    }
}
