#include "Node.h"

Node::~Node(){
	//do nothing
}

StartNode::StartNode(ProgramNode *programNode)
	: Node() 
{
	mProgramNode = programNode;
}
StartNode::~StartNode(){
	delete mProgramNode;
}

ProgramNode::ProgramNode(BlockNode *block)
	: Node()
{
	mBlockNode = block;
}
ProgramNode::~ProgramNode(){
	delete mBlockNode;
}

//maybe not right
BlockNode::BlockNode(StatementGroupNode *block)
	: Node()
{
	mStatementGroupNode = block;
}
BlockNode::~BlockNode(){
	delete mStatementGroupNode;
}

StatementGroupNode::StatementGroupNode()
	: BlockNode(*this)
{
}
StatementGroupNode::~StatementGroupNode(){
	std::vector<StatementNode *>::const_iterator ptr;
	for (ptr = mStatementNodes.begin();ptr != mStatementNodes.end();ptr++){
		//ptr is a pointer to a pointer :D
		delete (*ptr);
	}
}
void StatementGroupNode::AddStatement(StatementNode *statement){
	mStatementNodes.push_back(statement);
}

DeclarationStatementNode::DeclarationStatementNode(IdentifierNode *node)
	: StatementNode()
{
	mIdentifierNode = node;
}
DeclarationStatementNode::~DeclarationStatementNode(){
	delete mIdentifierNode;
}

AssignmentStatementNode::AssignmentStatementNode(IdentifierNode *ident, ExpressionNode *expr)
	: StatementNode(), mIdentifierNode(ident),mExpressionNode(expr)
{}
AssignmentStatementNode::~AssignmentStatementNode(){
	delete mIdentifierNode;
	delete mExpressionNode;
}