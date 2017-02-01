#ifndef _NODE_H_
#define _NODE_H_

#include <cstdlib>
#include <vector>


// forward declarations:
class Node;
class StartNode;
class ProgramNode;
class BlockNode;
class StatementGroupNode;
class StatementNode;
class DeclarationStatementNode;
class AssignmentStatementNode;
class IdentifierNode;
class ExpressionNode;
class CoutStatementNode;
class ExpressionNode;
class IntegerNode;
class IdentifierNode;
class BinaryOperatorNode;
class PlusNode;

class Node
{
public:
	virtual ~Node();
};

class StartNode : public Node
{
public:
	StartNode( ProgramNode *programNode );
	~StartNode();
private:
	ProgramNode *mProgramNode;
};

class ProgramNode : public Node
{
public:
	ProgramNode( BlockNode *block );
	~ProgramNode();
private:
	BlockNode *mBlockNode;
};

//maybe not right
class BlockNode : public Node
{
public:
	BlockNode( StatementGroupNode *group);
	~BlockNode();
private:
	StatementGroupNode *mStatementGroupNode;
};

class StatementGroupNode : public BlockNode
{
public:
	StatementGroupNode();
	~StatementGroupNode();
	void AddStatement(StatementNode *statement);
private:
	std::vector<StatementNode *> mStatementNodes;
};

//maybe not right
class StatementNode : public Node
{
};

class DeclarationStatementNode : public StatementNode
{
public:
	DeclarationStatementNode(IdentifierNode *node);
	~DeclarationStatementNode();
private:
	IdentifierNode *mIdentifierNode;
};

class AssignmentStatementNode : public StatementNode
{
public:
	AssignmentStatementNode(IdentifierNode *ident, ExpressionNode *expr);
	~AssignmentStatementNode();
private:
	IdentifierNode *mIdentifierNode;
	ExpressionNode *mExpressionNode;
};

#endif /* _NODE_H_ */
/* Local Variables: */
/* mode:c++ 				*/
/* End: 						*/
