#include "MyRNBTree.h"

MyRNBTree::MyRNBTree()
{
	std::cout << "todo a constructor\n";
}

MyRNBTree::~MyRNBTree()
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

void MyRNBTree::add(long long value)
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

RedNBlackBinaryTreeNode* MyRNBTree::find(long long key)
{
	//идем по дереву, пока ветки не нули


	return root.key == key ? &root : findNextStep(&root, key);
}


void MyRNBTree::remove(long long key)
{
	RedNBlackBinaryTreeNode* node = find(key);
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
			RedNBlackBinaryTreeNode* tmpNode = node;
			node->parent->greater = node->lesser;
			node->lesser->parent = node->parent;

			RedNBlackBinaryTreeNode* greaterNode = findGreatest(node->lesser);
			greaterNode->greater = node->greater;
			node->greater->parent = greaterNode;
			node = node->greater;

			delete tmpNode;
			m_numberOfDeletes++;
			tmpNode = nullptr;
			return;
		}

		RedNBlackBinaryTreeNode* tmpNode = node->greater ? node->greater : node->lesser;
		node->parent->greater = tmpNode;
		tmpNode->parent = node->parent;

		RedNBlackBinaryTreeNode* nodeForDelete = node;
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
			RedNBlackBinaryTreeNode* tmpNode = node;
			node->parent->lesser = node->greater;
			node->greater->parent = node->parent;

			RedNBlackBinaryTreeNode* lesserNode = findLessiest(node->greater);
			lesserNode->lesser = node->lesser;
			node->lesser->parent = lesserNode;
			node = node->greater;

			delete tmpNode;
			m_numberOfDeletes++;
			tmpNode = nullptr;
			return;




		}

		RedNBlackBinaryTreeNode* tmpNode = node->greater ? node->greater : node->lesser;
		node->parent->lesser = tmpNode;
		tmpNode->parent = node->parent;

		RedNBlackBinaryTreeNode* nodeForDelete = node;
		node = tmpNode;
		delete nodeForDelete;
		m_numberOfDeletes++;
		nodeForDelete = nullptr;
		return;





	}




	return;



}

uint64_t MyRNBTree::getNumberOfInserts()
{
	return m_numberOfInserts;
}

uint64_t MyRNBTree::getNumberOfRepeats()
{
	return m_numberOfRepeats;
}

uint64_t MyRNBTree::getNumberOfDeletes()
{
	return m_numberOfDeletes;
}



void MyRNBTree::insert(RedNBlackBinaryTreeNode* node, long long value)
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
			node->greater = new RedNBlackBinaryTreeNode();
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
			node->lesser = new RedNBlackBinaryTreeNode();
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



RedNBlackBinaryTreeNode* MyRNBTree::findNextStep(RedNBlackBinaryTreeNode* node, long long key)
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

		return node->greater != nullptr ? findNextStep(node->greater, key) : nullptr;
	}
	else
	{
		return node->lesser != nullptr ? findNextStep(node->lesser, key) : nullptr;
	}

}




RedNBlackBinaryTreeNode* MyRNBTree::findLessiest(RedNBlackBinaryTreeNode* node)
{
	while (node->lesser != nullptr)
	{
		node = node->lesser;
	}
	return node;
}

RedNBlackBinaryTreeNode* MyRNBTree::findGreatest(RedNBlackBinaryTreeNode* node)
{
	while (node->greater != nullptr)
	{
		node = node->greater;
	}
	return node;
}




void createTree(MyRNBTree& treeToCreate, std::vector<long long>& inputValues)
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


void MyRNBTree::traverseNLR(Travers_t foo, RedNBlackBinaryTreeNode* node)
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


void MyRNBTree::traverseGreaterToLess(Travers_t foo, RedNBlackBinaryTreeNode* node)
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

void MyRNBTree::traverseLRN(Travers_t foo, RedNBlackBinaryTreeNode* node)
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


void MyRNBTree::traverseLessToGreater(Travers_t foo, RedNBlackBinaryTreeNode* node)
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



void MyRNBTree::traverseNLR(Travers_t foo)
{

	(*foo)(root.key);
	traverseNLR(foo, root.greater);
	traverseNLR(foo, root.lesser);

}


void MyRNBTree::traverseGreaterToLess(Travers_t foo)
{


	traverseGreaterToLess(foo, root.greater);
	(*foo)(root.key);
	traverseGreaterToLess(foo, root.lesser);

}

void MyRNBTree::traverseLRN(Travers_t foo)
{


	traverseLRN(foo, root.greater);
	traverseLRN(foo, root.lesser);
	(*foo)(root.key);

}


void MyRNBTree::traverseLessToGreater(Travers_t foo)
{


	traverseLessToGreater(foo, root.lesser);
	(*foo)(root.key);
	traverseLessToGreater(foo, root.greater);


}

