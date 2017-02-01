#include "Symbol.h"

bool SymbolTableClass::Exists(std::string s){
	std::vector<Variable>::const_iterator ptr;
	for (ptr = SymbolTable.begin();ptr != SymbolTable.end();ptr++){
		if (ptr->mLabel == s){
			return true;
		}
	}
	return false;
}
void SymbolTableClass::AddEntry(std::string s){
	if (!Exists(s)){
		Variable entry = {s,0}; 
		SymbolTable.push_back(entry);
	}
	else {
		MSG("Symbol already exists: "<<s);
	}
}
int SymbolTableClass::GetValue(std::string s){
	if (!Exists(s)){
		std::cerr << "Error, variable does not exist: "<<s<<std::endl;
		exit(1);
	}	
	//return value of s
	std::vector<Variable>::const_iterator ptr;
	for (ptr = SymbolTable.begin();ptr != SymbolTable.end();ptr++){
		if (ptr->mLabel == s){
			return ptr->mValue;
		}
	}

}
void SymbolTableClass::SetValue(std::string s, int v){
	if (!Exists(s)){
		std::cerr << "Error, variable does not exist: "<<s<<std::endl;
		exit(1);
	}	
	//set value
	std::vector<Variable>::iterator ptr;
	for (ptr = SymbolTable.begin();ptr != SymbolTable.end();ptr++){
		if (ptr->mLabel == s){
			ptr->mValue = v;
		}
	}
	
}
int SymbolTableClass::GetIndex(std::string s){
	if (!Exists(s)){
		return -1;
	}	
	//return index of s
	int count = 0;
	std::vector<Variable>::const_iterator ptr;
	for (ptr = SymbolTable.begin();ptr != SymbolTable.end();ptr++){
		if (ptr->mLabel == s){
			return count;
		}
		count ++;
	}
}
int SymbolTableClass::GetCount(){
	int count = 0;
	std::vector<Variable>::const_iterator ptr;
	for (ptr = SymbolTable.begin();ptr != SymbolTable.end();ptr++){
		count ++;
	}
	return count;
}
