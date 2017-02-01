#include "Scanner.h"

ScannerClass::ScannerClass(std::string inputFileName){
//	MSG("Initializing ScannerClass object");
//#define MSG(X)
	mFin.open(inputFileName.c_str());
	if(!mFin.is_open())
	{
		std::cerr << "Error opening Scanner input file: " << inputFileName;
		exit(1);
	}
	mLineNumber = 1;
}

ScannerClass::~ScannerClass(){
	mFin.close();
}

int ScannerClass::getLineNumber(){
	return mLineNumber;
}

TokenClass ScannerClass::GetNextToken(){
	StateMachineClass stateMachine;
	
	char c;
	std::string lexeme;
	MachineState state;
	TokenType correspondingTokenType;
	//do is executed first then re-looped
	do {
		c= mFin.get();
		state = stateMachine.UpdateState(c,correspondingTokenType);
		if (state == EOF_STATE){
			TokenClass token(ENDFILE_TOKEN, "ENDFILE");
			return token;
		}
		if (state == CANTMOVE_STATE){
			//read past the last token, so put back character
			mFin.unget();
			TokenClass token(correspondingTokenType,lexeme);
			token.CheckReserved();
			if (correspondingTokenType == BAD_TOKEN){
				std::cerr << "Error, bad token type on line: "<<mLineNumber<<std::endl
					<<"The Lexeme is: '"<<c<<"'"<<std::endl;
				exit(1);
			}	
			return token;
		}
		//strip lexeme of white space
		if (!isspace(c)){
			lexeme += c;
		}
		// erase lexeme on comments
		if (state == COMMENT_STATE || state == BLOCK_START_STATE || state == BLOCK_END_STATE){
			lexeme = "";
		}
		// reset lexeme on start state
		if (state == START_STATE){
			lexeme = "";
		}
		//MSG("lexeme: "<<lexeme<<" character: "<<c<<" state: "<<state);
		if (c == '\n')
			mLineNumber ++;
	} while (state != EOF_STATE);
	TokenClass token(correspondingTokenType,"ENDFILE");
	return token;

}