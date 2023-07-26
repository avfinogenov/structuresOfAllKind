#pragma once
#include <list>
#include "Nodes.h"

class MyBinaryTree
{
public:
	MyBinaryTree();
	~MyBinaryTree();
	void add(int value);
	BinaryTreeNode* find(int key);
	//родилась из неправильного понимания теории, решил сделать потому что забавно
	bool insert(int key, int value);
	void remove(int key);
	void traverse(void* foo);
	void join(MyBinaryTree anotherTree);
	//debug
	uint64_t getNumberOfNodes();
	uint64_t getNumberOfRepeats();
	

private:
	BinaryTreeNode root;
	bool isRootInit = false;
	void insert(BinaryTreeNode* node, int value);
	bool insertWithRules(BinaryTreeNode* node, int value);
	//debug
	uint64_t m_numberOfNodes = 0;
	uint64_t m_numberOfRepeats = 0;
	BinaryTreeNode* findNextStep(BinaryTreeNode* node, int key);
	int makeAnotherRool(BinaryTreeNode* node);

};

std::list<int> createTree(MyBinaryTree& treeToCreate, int numberOfInputs);