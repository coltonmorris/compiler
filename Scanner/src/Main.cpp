#include "Token.h"
#include "Scanner.h"
#include "StateMachine.h"
#include "Symbol.h"
#include "Node.h"

int main(){
	bool token = false;
	bool state = false;
	bool scanner = false;
	bool symbol = true;
	
	//token class testing
	if (token){
		std::cout<<"Check Reserved check"<<std::endl;
		std::cout<<"reserved word and identifier token should be changed"<<std::endl;
		TokenClass a(IDENTIFIER_TOKEN,"int");
		std::cout<<a<<std::endl;
		a.CheckReserved();
		std::cout<<a<<std::endl;
		
		std::cout<<"should not change the token"<<std::endl;
		TokenClass b(BAD_TOKEN,"void");
		std::cout<<b<<std::endl;
		b.CheckReserved();
		std::cout<<b<<std::endl;
	}
	//state machine class testing
	if (state){
		StateMachineClass machine;
		std::cout<<machine.getCurrentState()<<std::endl;
		machine.setCurrentState(DIVIDE_STATE);
		TokenType type = DIVIDE_TOKEN;
		std::cout<<machine.UpdateState(' ',type)<<std::endl;
	}
	//scanner class testing
	if (scanner){
		//lexemes arent working
		ScannerClass scanner_obj("input.txt");
		bool flag = true;
		while (flag){
			TokenClass token = scanner_obj.GetNextToken();
			MSG(token);
			if (token.GetTokenType() == ENDFILE_TOKEN){
				flag = false;
			}
		}
	}
	if (symbol){
		SymbolTableClass table;
		table.AddEntry("test");
		table.SetValue("test", 100);
		table.AddEntry("hi");
		table.SetValue("hi", 9);
		std::cout<<table.SymbolTable[1].mValue<<std::endl;
		//std::cout<<table.GetValue("test")<<std::endl;
	}
	return 0;
}