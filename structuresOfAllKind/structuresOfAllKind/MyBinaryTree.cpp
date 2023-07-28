#include "MyBinaryTree.h"

MyBinaryTree::MyBinaryTree()
{
	std::cout << "todo a constructor\n";
}

MyBinaryTree::~MyBinaryTree()
{

	
	while (root.greater != nullptr)
	{
		//std::cout << root.greater->key << "\n";
		//std::cout << LLONG_MAX << "\n";
		remove(root.greater->key);
	}
	while (root.lesser != nullptr)
	{
		remove(root.lesser->key);
	}

	//std::cout << "todo a destructor\n";
}

void MyBinaryTree::add(long long value)
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

BinaryTreeNode* MyBinaryTree::find(long long key)
{
	//идем по дереву, пока ветки не нули


	return root.key == key? &root: findNextStep(&root, key);
}

bool MyBinaryTree::insert(long long key, long long value)
{
	BinaryTreeNode* node;
	if ((node = find(value)) != nullptr)
	{
		while (node->key != key)
		{
			if (node->parent != nullptr)
			{
				node = node->parent;
			}
			else
			{
				return false;
			}
				
		}
	}

	return insertWithRules(find(key), value);

}

void MyBinaryTree::remove(long long key)
{
	BinaryTreeNode* node = find(key);
	if (node == nullptr)
	{
		return;
	}
	if (node->parent->greater == node)
	{
		if (!node->greater && !node->lesser)
		{
			node->parent->greater = nullptr;
			delete node;
			m_numberOfDeletes++;
			node = nullptr;
			return;
		}
		if (node->greater && node->lesser)
		{
			BinaryTreeNode* tmpNode = node;
			node->parent->greater = node->lesser;
			node->lesser->parent = node->parent;
			node->lesser->notLesser = node->notLesser;
			node->lesser->notGreater = node->notGreater;
			BinaryTreeNode* greaterNode = findGreatest(node->lesser);
			greaterNode->greater = node->greater;
			node->greater->parent = greaterNode;
			node = node->greater;

			delete tmpNode;
			m_numberOfDeletes++;
			tmpNode = nullptr;
			return;
		}
			
		BinaryTreeNode* tmpNode = node->greater ? node->greater : node->lesser;
		node->parent->greater = tmpNode;
		tmpNode->parent = node->parent;
		tmpNode->notLesser = node->notLesser;
		tmpNode->notGreater = node->notGreater;
		BinaryTreeNode* nodeForDelete = node;
		node = tmpNode;
		delete nodeForDelete;
		m_numberOfDeletes++;
		nodeForDelete = nullptr;
		return;
		
		
	}
	else
	{
		if (!node->greater && !node->lesser)
		{
			node->parent->lesser = nullptr;
			delete node;
			m_numberOfDeletes++;
			node = nullptr;
			return;
		}
		if (node->greater && node->lesser)
		{
			BinaryTreeNode* tmpNode = node;
			node->parent->lesser = node->greater;
			node->greater->parent = node->parent;
			node->greater->notLesser = node->notLesser;
			node->greater->notGreater = node->notGreater;
			BinaryTreeNode* lesserNode = findLessiest(node->greater);
			lesserNode->lesser = node->lesser;
			node->lesser->parent = lesserNode;
			node = node->greater;

			delete tmpNode;
			m_numberOfDeletes++;
			tmpNode = nullptr;
			return;



			
		}

		BinaryTreeNode* tmpNode = node->greater ? node->greater : node->lesser;
		node->parent->lesser = tmpNode;
		tmpNode->parent = node->parent;
		tmpNode->notLesser = node->notLesser;
		tmpNode->notGreater = node->notGreater;
		BinaryTreeNode* nodeForDelete = node;
		node = tmpNode;
		delete nodeForDelete;
		m_numberOfDeletes++;
		nodeForDelete = nullptr;
		return;



	

	}


	

	return;



}

uint64_t MyBinaryTree::getNumberOfInserts()
{
	return m_numberOfInserts;
}

uint64_t MyBinaryTree::getNumberOfRepeats()
{
	return m_numberOfRepeats;
}

uint64_t MyBinaryTree::getNumberOfDeletes()
{
	return m_numberOfDeletes;
}



void MyBinaryTree::insert(BinaryTreeNode* node, long long value)
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
			m_numberOfInserts++;
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
			m_numberOfInserts++;
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

bool MyBinaryTree::insertWithRules(BinaryTreeNode* node, long long value)
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
			m_numberOfInserts++;
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
			m_numberOfInserts++;
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

BinaryTreeNode* MyBinaryTree::findNextStep(BinaryTreeNode* node, long long key)
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

BinaryTreeNode* MyBinaryTree::findLessiest(BinaryTreeNode* node)
{
	while (node->lesser != nullptr)
	{
		node = node->lesser;
	}
	return node;
}

BinaryTreeNode* MyBinaryTree::findGreatest(BinaryTreeNode* node)
{
	while (node->greater != nullptr)
	{
		node = node->greater;
	}
	return node;
}




void createTree(MyBinaryTree& treeToCreate, std::vector<long long>& inputValues)
{
	//std::list<int> values;
	int numberOfInputs = inputValues.size();
	for (int i = 0; i < numberOfInputs; ++i)
	{
		//int tmp = rand() % (numberOfInputs * numberOfInputs * 2 /  100);
		//tmp = tmp - (numberOfInputs * numberOfInputs / ((numberOfInputs / 100 + 1) % 100));
		
		treeToCreate.add(inputValues[i]);
	}
	return;


}