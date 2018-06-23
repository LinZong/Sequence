#ifndef SEQUENCE_H_
#define SEQUENCE_H_
#include<iostream>
#include<cstring>
#include<vector>
class Sequence
{
	public:
	Sequence(std::string fn);
	int length();
	int numberOf(char base);
	std::string longestConsecutive();
	std::string longestRepeated();	
	private:
	std::vector<std::string> SeprateRow;
	std::string Context;
};

#endif
