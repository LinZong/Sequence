#include"Sequence.h"
using namespace std;
int main(void)
{
	Sequence seq("dna.txt");
	//Test functions
	cout<<"�����Ŀ : "<< seq.length() << endl;
	cout<<"������Ӵ� : "<<seq.longestConsecutive()<<endl;
	cout<<"A : "<<seq.numberOf('A')<<endl; 
	cout<<"T : "<<seq.numberOf('T')<<endl; 
	cout<<"C : "<<seq.numberOf('C')<<endl; 
	cout<<"G : "<<seq.numberOf('G')<<endl; 
	cout<<"��ظ��Ӵ� : "<<seq.longestRepeated()<<endl;
	return 0;
}
