#pragma once

#include <stdlib.h>
#include <iostream>
using namespace std;

template <class Object>

class TreeNode {
private:

	Object object;

	TreeNode* leftdown;
	TreeNode* leftup;

	TreeNode* rightup;
	TreeNode* rightdown;

	bool b;
	bool w;
	bool g;
 // end class TreeNode

public:

	// constructors

	TreeNode();

	TreeNode(Object object);

	Object getInfo();

	void setInfo(Object);

	TreeNode* getLeftup();
	TreeNode* getLeftdown();
	void setLeftup(TreeNode* leftup);
	void setLeftdown(TreeNode* leftdown);
	TreeNode* getRightup();
	TreeNode* getRightdown();
	void setRightup(TreeNode* rightup);
	void setRightdown(TreeNode* rightdown);
	int isLeaf(TreeNode<int>*);

	void insert(TreeNode<int>* root, int info);

	void inorder(TreeNode<int>* treeNode);
};