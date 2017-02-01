#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>

#ifndef SCANNER
#define SCANNER

#include "Debug.h"
#include "Token.h"
#include "StateMachine.h"

class ScannerClass
{
public:
	ScannerClass(std::string input);
	~ScannerClass();

	int getLineNumber();
	TokenClass GetNextToken();

private:
	std::fstream mFin;
	int mLineNumber;
};
#endif // SCANNER
