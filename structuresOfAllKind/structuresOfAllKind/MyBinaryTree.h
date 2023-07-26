#pragma once
#include "Nodes.h"

class MyBinaryTree
{
public:
	MyBinaryTree();
	~MyBinaryTree();
	void add(int value);
	BinaryTreeNode* find(int key);
	void insert(int key, int value);
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
	//debug
	uint64_t m_numberOfNodes = 0;
	uint64_t m_numberOfRepeats = 0;

};

void createTree(MyBinaryTree& treeToCreate, int numberOfInputs);