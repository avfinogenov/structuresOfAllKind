#pragma once
#include <list>
#include <vector>
#include "Nodes.h"

typedef void (*Travers_t)(long long);

class MyBinaryTree
{
public:
	MyBinaryTree();
	~MyBinaryTree();
	void add(long long value);
	BinaryTreeNode* find(long long key);
	//родилась из неправильного понимания теории, решил сделать потому что забавно
	bool insertSpecial(long long key, long long value);
	void remove(long long key);
	void traverseNLR(Travers_t foo);
	void traverseGreaterToLess(Travers_t foo);
	void traverseLRN(Travers_t foo);
	void traverseLessToGreater(Travers_t foo);
	void traverseBFS(Travers_t foo);
	void join(MyBinaryTree anotherTree);
	
	//debug
	uint64_t getNumberOfInserts();
	uint64_t getNumberOfRepeats();
	uint64_t getNumberOfDeletes();
	

private:
	BinaryTreeNode root;
	bool isRootInit = false;
	void insert(BinaryTreeNode* node, long long value);
	bool insertWithRules(BinaryTreeNodeWithRules* node, long long value);
	//debug
	uint64_t m_numberOfInserts = 0;
	uint64_t m_numberOfDeletes = 0;
	uint64_t m_numberOfRepeats = 0;
	BinaryTreeNode* findNextStep(BinaryTreeNode* node, long long key);
	BinaryTreeNodeWithRules* findNextStepWithRules(BinaryTreeNodeWithRules* node, long long key);
	BinaryTreeNode* findLessiest(BinaryTreeNode* node);
	BinaryTreeNode* findGreatest(BinaryTreeNode* node);
	BinaryTreeNodeWithRules* findWithRules(BinaryTreeNodeWithRules* node, long long key);
	void traverseNLR(Travers_t foo, BinaryTreeNode* node);
	void traverseGreaterToLess(Travers_t foo, BinaryTreeNode* node);
	void traverseLRN(Travers_t foo, BinaryTreeNode* node);
	void traverseLessToGreater(Travers_t foo, BinaryTreeNode* node);
	
};

void createTree(MyBinaryTree& treeToCreate, std::vector<long long>& inputValues);

