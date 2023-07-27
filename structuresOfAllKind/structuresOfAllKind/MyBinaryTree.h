#pragma once
#include <list>
#include "Nodes.h"

class MyBinaryTree
{
public:
	MyBinaryTree();
	~MyBinaryTree();
	void add(long long value);
	BinaryTreeNode* find(long long key);
	//родилась из неправильного понимания теории, решил сделать потому что забавно
	bool insert(long long key, long long value);
	void remove(int key);
	void traverse(void* foo);
	void join(MyBinaryTree anotherTree);
	//debug
	uint64_t getNumberOfNodes();
	uint64_t getNumberOfRepeats();
	

private:
	BinaryTreeNode root;
	bool isRootInit = false;
	void insert(BinaryTreeNode* node, long long value);
	bool insertWithRules(BinaryTreeNode* node, long long value);
	//debug
	uint64_t m_numberOfNodes = 0;
	uint64_t m_numberOfRepeats = 0;
	BinaryTreeNode* findNextStep(BinaryTreeNode* node, long long key);
	

};

void createTree(MyBinaryTree& treeToCreate, std::vector<long long>& inputValues);