#include"Sequence.h"
#include<cstring>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
Sequence::Sequence(string filename)
{
	ifstream ifs(filename);
	if (ifs.is_open())
	{
		while (!ifs.eof())
		{
			string tmp;
			getline(ifs, tmp);
			SeprateRow.push_back(tmp);
		}
		ifs.close();
		SeprateRow.erase(SeprateRow.end() - 1, SeprateRow.end());//delete the last blank row.
		for (string x : SeprateRow)
		{
			Context.append(x);
		}
	}
}
int Sequence::length()
{
	return (SeprateRow.size() - 1) * 100 + (*(SeprateRow.end() - 1)).length();
}
int Sequence::numberOf(char base)
{
	int cnt = 0;
	for (string x : SeprateRow)
	{
		cnt += count(x.begin(), x.end(), base);
	}
	return cnt;
}
string Sequence::longestConsecutive()
{
	string longA = "A", longT = "T", longC = "C", longG = "G";
	while (string::npos != Context.find(longA))
	{
		longA.append("A");
	}
	while (string::npos != Context.find(longT))
	{
		longT.append("T");
	}
	while (string::npos != Context.find(longC))
	{
		longC.append("C");
	}
	while (string::npos != Context.find(longG))
	{
		longG.append("G");
	}
	longA.erase(0, 1);
	longT.erase(0, 1);
	longC.erase(0, 1);
	longG.erase(0, 1);
	int maxlength = max(max(max(longA.length(), longT.length()), longC.length()), longG.length());
	if (longA.length() == maxlength) cout << longA << endl;
	else if (longT.length() == maxlength) cout << longT << endl;
	else if (longC.length() == maxlength) cout << longC << endl;
	else if (longG.length() == maxlength) cout << longG << endl;
}
