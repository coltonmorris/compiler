#ifndef STATEMACHINE
#define STATEMACHINE

#include "Token.h"
#include "Debug.h"
/* states:
	Integer
	Identifier
	LParen
	RParen
	LCurly
	RCurly
	Semi Colon
	Assignment
	Plus
	Insertion
	End of File
	Minus
	Times
	Divide
*/
enum MachineState {
	//UPDATE
	START_STATE, IDENTIFIER_STATE, INTEGER_STATE, CANTMOVE_STATE,LPAREN_STATE,
	RPAREN_STATE, LCURLY_STATE, RCURLY_STATE, SEMICOLON_STATE, ASSIGNMENT_STATE,
	PLUS_STATE, INSERTION_STATE, LESS_STATE, GREATER_STATE, EOF_STATE, MINUS_STATE, TIMES_STATE,
	DIVIDE_STATE, COMMENT_STATE, BLOCK_START_STATE, BLOCK_END_STATE, EQUAL_STATE, LESSEQUAL_STATE,
	GREATEREQUAL_STATE, NOTEQUAL_START_STATE, NOTEQUAL_STATE,
	LAST_STATE 
	};

enum CharacterType {
	//UPDATE
	LETTER_CHAR, DIGIT_CHAR, WHITESPACE_CHAR, SPACE_CHAR, TAB_CHAR, PLUS_CHAR, MINUS_CHAR, BAD_CHAR,
	RETURN_CHAR, EOF_CHAR, ASTERISK_CHAR, LPAREN_CHAR, RPAREN_CHAR, LCURLY_CHAR, RCURLY_CHAR, NOT_CHAR,
	SEMICOLON_CHAR, ASSIGNMENT_CHAR, LESS_CHAR, GREATER_CHAR, MULTIPLY_CHAR, DIVIDE_CHAR,
	LAST_CHAR
	};

class StateMachineClass
{
public:
	StateMachineClass();
	MachineState UpdateState(char currentCharacter, TokenType &
								correspondingTokenType);

	MachineState getCurrentState();
	void setCurrentState(MachineState input) {mCurrentState = input;}

private:
	MachineState mCurrentState;

	// The matrix of legal moves:
	MachineState mLegalMoves[LAST_STATE][LAST_CHAR];

	// Which end-machine-states correspond to which token types.
	// (non end states correspond to the BAD_TOKEN token type)
	TokenType mCorrespondingTokenTypes[LAST_STATE];
};

#endif // STATEMACHINE