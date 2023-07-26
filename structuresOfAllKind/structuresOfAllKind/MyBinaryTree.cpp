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

BinaryTreeNode* MyBinaryTree::find(int key)
{
	//идем по дереву, пока ветки не нули


	return root.key == key? &root: findNextStep(&root, key);
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

BinaryTreeNode* MyBinaryTree::findNextStep(BinaryTreeNode* node, int key)
{
	if (node->lesser == nullptr && node->greater == nullptr &&
		node->key != key)
	{
		return nullptr;
	}
	if (key == node->key)
	{
		return node;
	}
	if (key > node->key)
	{
		return findNextStep(node->greater, key);
	}
	else
	{
		return findNextStep(node->lesser, key);
	}

}




std::list<int> createTree(MyBinaryTree& treeToCreate, int numberOfInputs)
{
	std::list<int> values;
	for (int i = 0; i < numberOfInputs; ++i)
	{
		int tmp = rand() % 1000;
		values.push_back(tmp);
		treeToCreate.add(tmp);
	}
	return values;


}
