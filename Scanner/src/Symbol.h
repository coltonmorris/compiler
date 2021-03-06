#include "Debug.h"
#include "StateMachine.h"
#include "Token.h"
#include <vector>


#ifndef SYMBOL
#define SYMBOL


class SymbolTableClass
{
public:
	struct Variable {
		std::string mLabel;
		int mValue;
	};
	std::vector<Variable> SymbolTable;

	bool Exists(std::string s); 
	// returns true if <s> is already in the symbol table.
		void AddEntry(std::string s); 
	// adds <s> to the symbol table, 
	// or quits if it was already there
		int GetValue(std::string s); 
	// returns the current value of variable <s>, when
	// interpreting. Meaningless for Coding and Executing.
	// Prints a message and quits if variable s does not exist.
		void SetValue(std::string s, int v); 
	// sets variable <s> to the given value, when interpreting.
	// Meaningless for Coding and Executing.
	// Prints a message and quits if variable s does not exist.
	int GetIndex(std::string s); 
	// returns the index of where variable <s> is.
	// returns -1 if variable <s> is not there.
	int GetCount(); 
	// returns the current number of variables in the symbol
	// table.  
//private:
};

#endif // SYMBOL
