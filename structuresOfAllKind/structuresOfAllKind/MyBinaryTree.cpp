#include "MyBinaryTree.h"

MyBinaryTree::MyBinaryTree()
{
	std::cout << "todo a constructor\n";
}

MyBinaryTree::~MyBinaryTree()
{
	std::cout << "todo a destructor\n";
}

void MyBinaryTree::add(int value)
{
	if (!isRootInit)
	{
		root.key = value;
		isRootInit = true;
	}
	else
	{
		insert(&root, value);
	}
	
	

}

uint64_t MyBinaryTree::getNumberOfNodes()
{
	return m_numberOfNodes;
}

uint64_t MyBinaryTree::getNumberOfRepeats()
{
	return m_numberOfRepeats;
}

void MyBinaryTree::insert(BinaryTreeNode* node, int value)
{
	
	
	
	if (node->key == value)
	{
		m_numberOfRepeats++;
		return;
	}
	if (value > node->key)
	{ 
		if (node->greater == nullptr)
		{
			node->greater = new BinaryTreeNode();
			m_numberOfNodes++;
			node->greater->parent = node;
			node->greater->key = value;
		}
		else
		{
			insert(node->greater, value);
		}
	}
	if (value < node->key)
	{
		if (node->lesser == nullptr)
		{
			node->lesser = new BinaryTreeNode();
			m_numberOfNodes++;
			node->lesser->parent = node;
			node->lesser->key = value;
		}
		else
		{
			insert(node->lesser, value);
		}
	}


}




void createTree(MyBinaryTree& treeToCreate, int numberOfInputs)
{
	
	for (int i = 0; i < numberOfInputs; ++i)
	{
		treeToCreate.add(rand() % 1000);
	}


}
