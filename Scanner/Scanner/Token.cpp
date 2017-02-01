#include "Token.h"
#include <algorithm>

TokenClass::TokenClass(TokenType type, const std::string & lexeme)
	: mType(type),
	mLexeme(lexeme)
{
	//do nothing
}

TokenClass::TokenClass() :
	mType(VOID_TOKEN),
	mLexeme("void") 
{
	//do nothing
}

std::string TokenClass::GetLexeme() const { 
	return mLexeme; 
}

TokenType TokenClass::GetTokenType() const { 
	return mType;
}

const std::string & TokenClass::GetTokenTypeName() const { 
	return gTokenTypeNames[mType];
}

void TokenClass::CheckReserved(){
	//If mLexeme is one of the 4 reserved words, change
	//   mType to match it (iff mType is an Identifier token)

	//if mType is IDENTIFIER TOKEN check to rename
	if(mType != IDENTIFIER_TOKEN){
		return;
	}
	
	std::string upper = mLexeme;
	std::transform(upper.begin(), upper.end(), upper.begin(), toupper);
	//first four names in gTokenTypeNames are the reserved words
	for (int i= 0;i<4;i++){
		if(upper == gTokenTypeNames[i]){
			mType = TokenType(i);
			return;
		}
	}
}

std::ostream & operator<<(std::ostream &out, const TokenClass & tc){
	out<<"-------- TOKEN -------------"<<std::endl;
	out<<"Lexeme:_"<<tc.GetLexeme()<<"_"<<std::endl;
	//out<<"Token Type: "<<tc.GetTokenType()<<std::endl;
	out<<"Token Type Name: "<<tc.GetTokenTypeName()<<std::endl;
	out<<"-------- END TOKEN -------------"<<std::endl;
	return out;
}
