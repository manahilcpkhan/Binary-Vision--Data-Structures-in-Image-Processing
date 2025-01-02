#include "TreeNode.h"

template <class Object>
TreeNode<Object>::TreeNode()

{
	this->leftdown = NULL;
	this->leftup = NULL;
	
	this->rightup = NULL;
	this->rightdown = NULL;
	this->object = 0;
	b = false;
	w = false;
	g = false;

};

template <class Object>
TreeNode<Object>::TreeNode(Object object)

{

	this->object = object;
	this->leftdown = NULL;
	this->leftup = NULL;

	this->rightup = NULL;
	this->rightdown = NULL;
	b = false;
	w = false;
	g = false;


}
template <class Object>
Object TreeNode<Object>::getInfo()

{

	return this->object;

};
template <class Object>
void TreeNode<Object>::setInfo(Object object)

{

	this->object = object;

};
template <class Object>
TreeNode<Object>* TreeNode<Object>::getLeftup()

{

	return leftup;

};
template <class Object>
TreeNode<Object>* TreeNode<Object>::getLeftdown()

{

	return leftdown;

};
template <class Object>
void TreeNode<Object>::setLeftup(TreeNode* leftup)

{

	this->leftup = leftup;

};
template <class Object>
void TreeNode<Object>::setLeftdown(TreeNode* leftdown)

{

	this->leftdown = leftdown;

};
template <class Object>
TreeNode<Object>* TreeNode<Object>::getRightup()

{

	return rightup;

};
template <class Object>
TreeNode<Object>* TreeNode<Object>::getRightdown()

{

	return rightup;

};
template <class Object>
void  TreeNode<Object>::setRightup(TreeNode* rightup)

{

	this->rightup = rightup;

};
template <class Object>
void  TreeNode<Object>::setRightdown(TreeNode* rightdown)

{

	this->rightdown = rightdown;

};
template <class Object>
int  TreeNode<Object>::isLeaf(TreeNode<int>* n)

{

	// (this->leftup == NULL && this->rightup == NULL && this->leftdown == NULL && this->rightdown == NULL)
	if(n->getLeftup() == NULL && n->getLeftdown() == NULL && n->getRightup() == NULL && n->getRightdown() == NULL)
		return 1;

	return 0;

};
template <class Object>
void  TreeNode<Object>::insert(TreeNode<int>* root, int info)

{

	TreeNode<int>* node = new TreeNode<int>(info);

	TreeNode<int>* p, * q;

	p = q = root;

	if (p->getLeftup() == NULL) {
		p->setLeftup(node);
	}
	else if (p->getLeftdown() == NULL) {
		p->setLeftdown(node);
	}
	else if (p->getRightup() == NULL) {
		p->setRightup(node);
	}
	else if(p->getRightdown() == NULL) {
		p->setRightdown(node);
	}
	else {
		if (p->getLeftup()->getInfo()==2 && p->isLeaf(p->getLeftup())==1) {
			p=getLeftup();
			insert(p, info);
		}
		else if (p->getLeftdown()->getInfo() == 2 && p->isLeaf(p->getLeftdown()) == 1) {
			p = getLeftdown();
			insert(p, info);
		}
		else if (p->getRightup()->getInfo() == 2 && p->isLeaf(p->getRightup()) == 1) {
			p = getRightup();
			insert(p, info);
		}
		else if (p->getRightdown()->getInfo() == 2 && p->isLeaf(p->getRightdown()) == 1) {
			p = getRightdown();
				insert(p, info);
		}
		else {
			cout << "tree filled" << endl;
		}
	}
	//while (*info != *(p->getInfo()) && q != NULL)

	//{

	//	p = q;

	//	if (*info < *(p->getInfo()))

	//		q = p->getLeft();

	//	else

	//		q = p->getRight();

	//}
	///*if (*info  == *(p->getInfo())) {

	//	cout << "attempt to insert duplicate: "

	//		<< *info << endl;

	//	delete node;

	//}*/

	// if (*info < *(p->getInfo()))

	//	p->setLeft(node);

	//else

	//	p->setRight(node);

} // end of insert
template <class Object>
void  TreeNode<Object>::inorder(TreeNode<int>* treeNode)

{

	if (treeNode != NULL)

	{

		inorder(treeNode->getLeftup());
		inorder(treeNode->getLeftdown());
		cout << (treeNode->getInfo()) << " ";
		inorder(treeNode->getRightup());
		inorder(treeNode->getRightdown());

	}

}
/*void inorder(TreeNode<int>* root)

{

	Stack<TreeNode<int>* > stack;

	TreeNode<int>* p;

	p = root;

	do

	{

		while (p != NULL)

		{

			stack.push(p);

			p = p->getLeft();

		}

		// at this point, left tree is empty

		if (!stack.empty())

		{

			p = stack.pop();

			cout << *(p->getInfo()) << " ";

			// go back & traverse right subtree

			p = p->getRight();

		}

	} while (!stack.empty() || p != NULL);

}*/