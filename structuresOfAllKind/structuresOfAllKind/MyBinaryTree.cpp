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

bool MyBinaryTree::insert(int key, int value)
{
	return insertWithRules(find(key), value);

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
			node->greater->notLesser = std::max(node->key, node->notLesser);
			node->greater->notGreater = node->notGreater;

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
			node->lesser->notGreater = std::min(node->key, node->notGreater);
			node->lesser->notLesser = node->notLesser;
		}
		else
		{
			insert(node->lesser, value);
		}
	}


}

bool MyBinaryTree::insertWithRules(BinaryTreeNode* node, int value)
{
	if (node != &root)
	{
		
		if (value > node->notGreater)
		{
			return false;
		}
		if (value < node->notLesser)
		{
			return false;
		}
	}
	

	if (node->key == value)
	{
		m_numberOfRepeats++;
		return true;
	}
	if (value > node->key)
	{
		if (node->greater == nullptr)
		{
			node->greater = new BinaryTreeNode();
			m_numberOfNodes++;
			node->greater->parent = node;
			node->greater->key = value;
			
			node->greater->notLesser = std::max(node->key, node->notLesser);
			node->greater->notGreater = node->notGreater;
			
		}
		else
		{
			return insertWithRules(node->greater, value);
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
			
			node->lesser->notGreater = std::min(node->key, node->notGreater);
			node->lesser->notLesser = node->notLesser;
		}
		else
		{
			return insertWithRules(node->lesser, value);
		}
	}
	return true;

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
		
		return node->greater != nullptr? findNextStep(node->greater, key) : nullptr;
	}
	else
	{
		return node->lesser != nullptr ? findNextStep(node->lesser, key) : nullptr;
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
