#pragma once
#include <list>
#include <vector>
#include "Nodes.h"

typedef void (*Travers_t)(long long);

// find height of a tree
// right placement of colour
// balancing
// ---------------------

//todo


// testing
// add height() to old tree

class MyRNBTree
{
public:


	MyRNBTree();
	~MyRNBTree();
	void add(long long value);
	RedNBlackBinaryTreeNode* find(long long key);
	
	void remove(long long key);
	void traverseNLR(Travers_t foo);
	void traverseGreaterToLess(Travers_t foo);
	void traverseLRN(Travers_t foo);
	void traverseLessToGreater(Travers_t foo);
	void traverseBFS(Travers_t foo);
	void join(MyRNBTree anotherTree);

	//debug
	uint64_t getNumberOfInserts();
	uint64_t getNumberOfRepeats();
	uint64_t getNumberOfDeletes();


private:
	RedNBlackBinaryTreeNode root;
	bool isRootInit = false;
	void insert(RedNBlackBinaryTreeNode* node, long long value);
	
	//debug
	uint64_t m_numberOfInserts = 0;
	uint64_t m_numberOfDeletes = 0;
	uint64_t m_numberOfRepeats = 0;
	RedNBlackBinaryTreeNode* findNextStep(RedNBlackBinaryTreeNode* node, long long key);
	
	RedNBlackBinaryTreeNode* findLessiest(RedNBlackBinaryTreeNode* node);
	RedNBlackBinaryTreeNode* findGreatest(RedNBlackBinaryTreeNode* node);
	
	void traverseNLR(Travers_t foo, RedNBlackBinaryTreeNode* node);
	void traverseGreaterToLess(Travers_t foo, RedNBlackBinaryTreeNode* node);
	void traverseLRN(Travers_t foo, RedNBlackBinaryTreeNode* node);
	void traverseLessToGreater(Travers_t foo, RedNBlackBinaryTreeNode* node);

	int height();
	int height(RedNBlackBinaryTreeNode* node, int counter);
	void balance(RedNBlackBinaryTreeNode* node);




};

void createTree(MyRNBTree& treeToCreate, std::vector<long long>& inputValues);