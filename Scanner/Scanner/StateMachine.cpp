#include "StateMachine.h"

StateMachineClass::StateMachineClass()
	: mCurrentState(START_STATE) {
	// First, initialize all the mLegalMoves to CANTMOVE_STATE
	for(int i=0; i<LAST_STATE; i++)
	{
		for(int j=0; j<LAST_CHAR; j++)
		{
			mLegalMoves[i][j] = CANTMOVE_STATE;
		}
		//mLegalMoves[i][WHITESPACE_CHAR] = START_STATE;
	}
	// Then, reset the mLegalMoves that are legitimate 
	//UPDATE
	//Integer state
	mLegalMoves[START_STATE][DIGIT_CHAR]= INTEGER_STATE;
	mLegalMoves[INTEGER_STATE][DIGIT_CHAR]= INTEGER_STATE;
	//whitespace
	mLegalMoves[START_STATE][WHITESPACE_CHAR] = START_STATE;
	mLegalMoves[START_STATE][SPACE_CHAR] = START_STATE;
	mLegalMoves[START_STATE][TAB_CHAR] = START_STATE;
	mLegalMoves[START_STATE][RETURN_CHAR] = START_STATE;
	//Identifier
	mLegalMoves[START_STATE][LETTER_CHAR] = IDENTIFIER_STATE;
	mLegalMoves[IDENTIFIER_STATE][LETTER_CHAR] = IDENTIFIER_STATE;
	mLegalMoves[IDENTIFIER_STATE][DIGIT_CHAR] = IDENTIFIER_STATE;
	//Lparen
	mLegalMoves[START_STATE][LPAREN_CHAR] = LPAREN_STATE;
	//Rparen
	mLegalMoves[START_STATE][RPAREN_CHAR] = RPAREN_STATE;
	//Lcurly
	mLegalMoves[START_STATE][LCURLY_CHAR] = LCURLY_STATE;
	//Rcurly
	mLegalMoves[START_STATE][RCURLY_CHAR] = RCURLY_STATE;
	//semi colon
	mLegalMoves[START_STATE][SEMICOLON_CHAR] = SEMICOLON_STATE;
	//assignment
	mLegalMoves[START_STATE][ASSIGNMENT_CHAR] = ASSIGNMENT_STATE;
	//plus
	mLegalMoves[START_STATE][PLUS_CHAR] = PLUS_STATE;
	//minus
	mLegalMoves[START_STATE][MINUS_CHAR] = MINUS_STATE;
	//insertion
	mLegalMoves[LESS_STATE][LESS_CHAR] = INSERTION_STATE;
	//end of file
	mLegalMoves[START_STATE][EOF_CHAR] = EOF_STATE;
	//times
	mLegalMoves[START_STATE][ASTERISK_CHAR] = TIMES_STATE;
	//Divide
	mLegalMoves[START_STATE][DIVIDE_CHAR] = DIVIDE_STATE;
	//comment  (when in comment state, only eof and return exit)
	mLegalMoves[DIVIDE_STATE][DIVIDE_CHAR] = COMMENT_STATE;
	for(int j=0; j<LAST_CHAR; j++)
		{
		mLegalMoves[COMMENT_STATE][j] = COMMENT_STATE;
	}
	mLegalMoves[COMMENT_STATE][RETURN_CHAR] = START_STATE;
	mLegalMoves[COMMENT_STATE][EOF_CHAR] = EOF_STATE;
	//block comment
		//block start
		mLegalMoves[DIVIDE_STATE][ASTERISK_CHAR] = BLOCK_START_STATE;
		for(int j=0; j<LAST_CHAR; j++){
				mLegalMoves[BLOCK_START_STATE][j] = BLOCK_START_STATE;
		}
		//block end
		mLegalMoves[BLOCK_START_STATE][ASTERISK_CHAR] = BLOCK_END_STATE;
		for(int j=0; j<LAST_CHAR; j++){
			mLegalMoves[BLOCK_END_STATE][j] = BLOCK_START_STATE;
		}
		mLegalMoves[BLOCK_END_STATE][ASTERISK_CHAR] = BLOCK_END_STATE;
		mLegalMoves[BLOCK_END_STATE][DIVIDE_CHAR] = START_STATE;
	//relational operators
	//equal
	mLegalMoves[ASSIGNMENT_STATE][ASSIGNMENT_CHAR] = EQUAL_STATE;
	//notequal
	mLegalMoves[START_STATE][NOT_CHAR] = NOTEQUAL_START_STATE;
	mLegalMoves[NOTEQUAL_START_STATE][ASSIGNMENT_CHAR] = NOTEQUAL_STATE;
	//Less than
	mLegalMoves[START_STATE][LESS_CHAR] = LESS_STATE;
	//lessequal than
	mLegalMoves[LESS_STATE][ASSIGNMENT_CHAR] = LESSEQUAL_STATE;
	//greater than
	mLegalMoves[START_STATE][GREATER_CHAR] = GREATER_STATE;
	//greaterequal than
	mLegalMoves[GREATER_STATE][ASSIGNMENT_CHAR] = GREATEREQUAL_STATE;

	// First, initialize all states to correspond to the BAD token type.
	for(int i=0; i<LAST_STATE; i++)
	{
		mCorrespondingTokenTypes[i]=BAD_TOKEN;
	}
	// Then, reset the end states to correspond to the correct token types.
	//is space a toekn?
	//UPDATE
	mCorrespondingTokenTypes[IDENTIFIER_STATE] = IDENTIFIER_TOKEN;
	mCorrespondingTokenTypes[LPAREN_STATE] = LPAREN_TOKEN;
	mCorrespondingTokenTypes[RPAREN_STATE] = RPAREN_TOKEN;
	mCorrespondingTokenTypes[LCURLY_STATE] = LCURLY_TOKEN;
	mCorrespondingTokenTypes[RCURLY_STATE] = RCURLY_TOKEN;
	mCorrespondingTokenTypes[SEMICOLON_STATE] = SEMICOLON_TOKEN;
	mCorrespondingTokenTypes[ASSIGNMENT_STATE] = ASSIGNMENT_TOKEN;
	mCorrespondingTokenTypes[PLUS_STATE] = PLUS_TOKEN;
	mCorrespondingTokenTypes[INSERTION_STATE] = COUT_TOKEN;
	mCorrespondingTokenTypes[EOF_STATE] = ENDFILE_TOKEN;
	mCorrespondingTokenTypes[MINUS_STATE] = MINUS_TOKEN;
	mCorrespondingTokenTypes[TIMES_STATE] = TIMES_TOKEN;
	mCorrespondingTokenTypes[DIVIDE_STATE] = DIVIDE_TOKEN;
	mCorrespondingTokenTypes[INTEGER_STATE] = INTEGER_TOKEN;
	//relational operators
	mCorrespondingTokenTypes[EQUAL_STATE] = EQUAL_TOKEN;
	mCorrespondingTokenTypes[NOTEQUAL_STATE] = NOTEQUAL_TOKEN;
	mCorrespondingTokenTypes[LESS_STATE] = LESS_TOKEN;
	mCorrespondingTokenTypes[LESSEQUAL_STATE] = LESSEQUAL_TOKEN;
	mCorrespondingTokenTypes[GREATER_STATE] = GREATER_TOKEN;
	mCorrespondingTokenTypes[GREATEREQUAL_STATE] = GREATEREQUAL_TOKEN;


}

MachineState StateMachineClass::UpdateState(char currentCharacter,
	TokenType & correspondingTokenType){

		/*eventually return CANTMOVE_STATE which signifies to the calling
			code that the current token is completed. 
		  correspondingTokenType is set so that the calling code knows what kind
			of TokenType is should make. If the current state of the machine is not
			a valid end state, then correspondingTokenType should be set to BAD_TOKEN,
			which tells the calling code to print an error message.
		*/
		
		// convert the input character into an input character type
		CharacterType charType = BAD_CHAR;

		//UPDATE
		//no bad char?, return is whitespace and '\n',
		if(currentCharacter == EOF)
			charType = EOF_CHAR;
		if(isalpha(currentCharacter))
			charType = LETTER_CHAR;
		if(isdigit(currentCharacter))
			charType = DIGIT_CHAR;
		if(isspace(currentCharacter))
			charType = WHITESPACE_CHAR;
		if(currentCharacter=='+')
			charType = PLUS_CHAR;
		if(currentCharacter=='-')
			charType = MINUS_CHAR;
		//possible problems for return
		if(currentCharacter == '\n')
			charType = RETURN_CHAR;
		//eof char?
		if(currentCharacter == '*')
			charType = ASTERISK_CHAR;
		if(currentCharacter == '(')
			charType = LPAREN_CHAR;
		if(currentCharacter == ')')
			charType = RPAREN_CHAR;
		if(currentCharacter == '{')
			charType = LCURLY_CHAR;
		if(currentCharacter == '}')
			charType = RCURLY_CHAR;
		if(currentCharacter == ';')
			charType = SEMICOLON_CHAR;
		if(currentCharacter == '<')
			charType = LESS_CHAR;
		if(currentCharacter == '>')
			charType = GREATER_CHAR;
		if(currentCharacter == '/')
			charType = DIVIDE_CHAR;
		if(currentCharacter=='=')
			charType = ASSIGNMENT_CHAR;
		if(currentCharacter == '!')
			charType = NOT_CHAR;
		
		correspondingTokenType = mCorrespondingTokenTypes[mCurrentState];
		mCurrentState = mLegalMoves[mCurrentState][charType];
		return mCurrentState;
}

MachineState StateMachineClass::getCurrentState(){
	return mCurrentState;
}