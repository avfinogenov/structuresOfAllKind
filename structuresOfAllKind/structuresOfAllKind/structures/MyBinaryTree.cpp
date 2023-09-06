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

bool MyBinaryTree::insertSpecial(long long key, long long value)
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
	//need find with rules
	// node with rules
	//rethink insert with rules
	BinaryTreeNodeWithRules tmp, resultOfSearch;
	resultOfSearch = *findWithRules(&tmp, key);
	return insertWithRules(&resultOfSearch, value);

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
	
	// используется функцией add
	
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
			
		}
		else
		{
			insert(node->lesser, value);
		}
	}


}

bool MyBinaryTree::insertWithRules(BinaryTreeNodeWithRules* node, long long value)
{

	// используется функцией insertSpecial
	if (node->node != &root)
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
	

	if (node->node->key == value)
	{
		m_numberOfRepeats++;
		return true;
	}
	if (value > node->node->key)
	{
		if (node->node->greater == nullptr)
		{
			node->node->greater = new BinaryTreeNode();
			m_numberOfInserts++;
			node->node->greater->parent = node->node;
			node->node->greater->key = value;
			
			
			
		}
		else
		{
			//make rules
			node->notLesser = std::max(node->node->key, node->notLesser);
			node->notGreater = node->notGreater;
			

		

			node->node = node->node->greater;
			return insertWithRules(node, value);
		}
	}
	if (value < node->node->key)
	{
		if (node->node->lesser == nullptr)
		{
			node->node->lesser = new BinaryTreeNode();
			m_numberOfInserts++;
			node->node->lesser->parent = node->node;
			node->node->lesser->key = value;
			
			
		}
		else
		{
			node->notGreater = std::min(node->node->key, node->notGreater);
			node->notLesser = node->notLesser;


			node->node = node->node->lesser;
			return insertWithRules(node, value);
			
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

BinaryTreeNodeWithRules* MyBinaryTree::findNextStepWithRules(BinaryTreeNodeWithRules* node, long long key)
{
	if (node->node->lesser == nullptr && node->node->greater== nullptr &&
		node->node->key != key)
	{
		return nullptr;
	}
	if (key == node->node->key)
	{
		

		return node;
	}
	if (key > node->node->key)
	{

		node->notLesser = std::max(node->node->key, node->notLesser);
		node->notGreater = node->notGreater;
		if (node->node->greater != nullptr)
		{
			node->node = node->node->greater; 
			return findNextStepWithRules(node, key);
		} 
		else
		{
			 node->node = nullptr;
			 return node;
		}
		
	}
	else
	{
		node->notGreater = std::min(node->node->key, node->notGreater);
		node->notLesser = node->notLesser;
		if (node->node->lesser != nullptr)
		{
			node->node = node->node->lesser;
			return findNextStepWithRules(node, key);
		}
		else
		{
			node->node = nullptr;
			return node;
		}
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

BinaryTreeNodeWithRules* MyBinaryTree::findWithRules(BinaryTreeNodeWithRules* node, long long key)
{
	
	node->node = &root;
	return node->node->key == key ? node : findNextStepWithRules(node, key);
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


void MyBinaryTree::traverseNLR(Travers_t foo, BinaryTreeNode* node)
{
	
	(*foo)(node->key);
	if (node->greater)
	{
		traverseNLR(foo, node->greater);
	}
	
	if (node->lesser)
	{
		traverseNLR(foo, node->lesser);
	}
	
	
}


void MyBinaryTree::traverseGreaterToLess(Travers_t foo, BinaryTreeNode* node)
{

	
	if (node->greater)
	{
		traverseGreaterToLess(foo, node->greater);
	}
	(*foo)(node->key);
	if (node->lesser)
	{
		traverseGreaterToLess(foo, node->lesser);
	}

}

void MyBinaryTree::traverseLRN(Travers_t foo, BinaryTreeNode* node)
{

	
	if (node->greater)
	{
		traverseLRN(foo, node->greater);
	}
	if (node->lesser)
	{
		traverseLRN(foo, node->lesser);
	}
	(*foo)(node->key);

}


void MyBinaryTree::traverseLessToGreater(Travers_t foo, BinaryTreeNode* node)
{

	
	if (node->lesser)
	{
		traverseLessToGreater(foo, node->lesser);
	}
	(*foo)(node->key);
	if (node->greater)
	{
		traverseLessToGreater(foo, node->greater);
	}
	

}



void MyBinaryTree::traverseNLR(Travers_t foo)
{

	(*foo)(root.key);
	traverseNLR(foo, root.greater);
	traverseNLR(foo, root.lesser);

}


void MyBinaryTree::traverseGreaterToLess(Travers_t foo)
{


	traverseGreaterToLess(foo, root.greater);
	(*foo)(root.key);
	traverseGreaterToLess(foo, root.lesser);

}

void MyBinaryTree::traverseLRN(Travers_t foo)
{


	traverseLRN(foo, root.greater);
	traverseLRN(foo, root.lesser);
	(*foo)(root.key);

}


void MyBinaryTree::traverseLessToGreater(Travers_t foo)
{


	traverseLessToGreater(foo, root.lesser);
	(*foo)(root.key);
	traverseLessToGreater(foo, root.greater);


}

