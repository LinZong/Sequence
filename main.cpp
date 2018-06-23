#include"Sequence.h"
using namespace std;
int main(void)
{
	Sequence seq("dna.txt");
	//Test functions
	cout<<"碱基数目 : "<< seq.length() << endl;
	cout<<"最长连续子串 : "<<seq.longestConsecutive()<<endl;
	cout<<"A : "<<seq.numberOf('A')<<endl; 
	cout<<"T : "<<seq.numberOf('T')<<endl; 
	cout<<"C : "<<seq.numberOf('C')<<endl; 
	cout<<"G : "<<seq.numberOf('G')<<endl; 
	cout<<"最长重复子串 : "<<seq.longestRepeated()<<endl;
	return 0;
}
