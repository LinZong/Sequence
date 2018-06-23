#include"Sequence.h"
#include<string>
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
	int TempPos=0;
	typedef struct Pattern
	{
		Pattern(string _Init_):_Pattern(_Init_),Pos(0){}
		string _Pattern;
		int Pos; 
	} Comb;
	Comb longA("A"), longT("T"), longC("C"), longG("G");
	while (string::npos != (TempPos=Context.find(longA._Pattern)))
		longA._Pattern.append("A"),longA.Pos=TempPos;
	while (string::npos != (TempPos=Context.find(longT._Pattern)))
		longT._Pattern.append("T"),longT.Pos=TempPos;
	while (string::npos != (TempPos=Context.find(longC._Pattern)))
		longC._Pattern.append("C"),longC.Pos=TempPos;
	while (string::npos != (TempPos=Context.find(longG._Pattern)))
		longG._Pattern.append("G"),longG.Pos=TempPos;
	longA._Pattern.erase(0, 1);
	longT._Pattern.erase(0, 1);
	longC._Pattern.erase(0, 1);
	longG._Pattern.erase(0, 1);
	Comb CalcRank[]={longA,longT,longC,longG};
	sort(CalcRank,CalcRank+4,[](Comb a,Comb b){if(a._Pattern.length()==b._Pattern.length()) return a.Pos<b.Pos; return a._Pattern.length()>b._Pattern.length();});
	return CalcRank[0]._Pattern;
}
string Sequence::longestRepeated()
{
	int ContextLength = Context.length();
	char* Original=new char[1500000]{ 0 };
	char** Address=new char*[1500000]{ 0 };	
	copy(Context.begin(), Context.end(), Original);
	int CommonLength = 0, StartOffset = 0, MaxLength = 0;
	for (int i = 0; i<ContextLength; ++i)
		Address[i] = &Original[i];
	qsort(Address,ContextLength,sizeof(char*),[](const void *a, const void*b){return strcmp(*(char**)a, *(char**)b);});
	for (int i = 0; i<ContextLength - 1; ++i)
	{
		CommonLength = ([](char *a, char* b) {int i = 0; while (*a && (*a++ == *b++)) ++i; return i; })(Address[i], Address[i + 1]);
		if (CommonLength>MaxLength)
		{
			MaxLength = CommonLength;
			StartOffset = i;
		}
	}
	string Result=string(*(Address+StartOffset), *(Address+StartOffset)+MaxLength);
	return Result;
}
