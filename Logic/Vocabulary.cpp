/**
    Provides an interface for the logic to get words from a file.
    @author Benjamin Ferenc Hajas
    @credits D�niel Eke
*/

#include "Vocabulary.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits>
#include <iostream>

Vocabulary::Vocabulary(std::string filename)
{
	srand(time(NULL));
	easy.open((filename + "_easy").c_str());
	easyCount = std::count(std::istreambuf_iterator<char>(easy), std::istreambuf_iterator<char>(), '\n');
	medium.open((filename + "_medium").c_str());
	mediumCount = std::count(std::istreambuf_iterator<char>(medium), std::istreambuf_iterator<char>(), '\n');
	hard.open((filename + "_hard").c_str());
	hardCount = std::count(std::istreambuf_iterator<char>(hard), std::istreambuf_iterator<char>(), '\n');
}

Vocabulary::~Vocabulary()
{
	easy.close();
	medium.close();
	hard.close();
}

std::string Vocabulary::gotoLine(std::ifstream& file, int num){
    file.seekg(0,std::ios::beg);
    for(int i=0; i < num - 1; ++i){
        file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
	std::string line;
	file >> line;
	return line;
}

std::string Vocabulary::getRandomWord(Difficulty d)
{
	switch (d)
	{
		case Easy: return gotoLine(easy, rand() % easyCount);
		case Medium: return gotoLine(medium, rand() % mediumCount);
		case Hard: return gotoLine(hard, rand() % hardCount);
	}

	int random = rand() % easyCount;
	gotoLine(easy,random);
    std::string randomLine;
    easy >> randomLine;
	return randomLine;
}
