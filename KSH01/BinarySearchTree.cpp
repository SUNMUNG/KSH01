#include "BinarySearchTree.h"
#include <stdio.h>

BinarySearchTree::~BinarySearchTree()
{
	DestroyTree(Root);
}

void BinarySearchTree::Insert(int Inkey)
{
	Root = InsertNode(Root, Inkey);
}

void BinarySearchTree::Delete(int Inkey)
{
	Root = DeleteNode(Root, Inkey);
}

TreeNode* BinarySearchTree::Search(int Inkey)
{
	return SearchNode(Root,Inkey);
}

void BinarySearchTree::printPreOrder() const
{
	printf("PreOrder : ");
	PreorderTraversal(Root);
	printf("\n");
}

void BinarySearchTree::printInOrder() const
{
}

void BinarySearchTree::printPostOrder() const
{
}

TreeNode* BinarySearchTree::InsertNode(TreeNode* inNode, int inKey)
{

	if (inNode == nullptr) {
		return new TreeNode(inKey);
	}

	if (inKey < inNode->Key) {
		inNode->Left = InsertNode(inNode->Left, inKey);
	}
	else if (inKey > inNode->Key) {
		inNode->Right = InsertNode(inNode->Right, inKey);
	}
	//else{}
	return inNode;
}

TreeNode* BinarySearchTree::DeleteNode(TreeNode* inNode, int inKey)
{
	if (inNode == nullptr) {
		return inNode;
	}

	if (inKey < inNode->Key) {
		inNode->Left = DeleteNode(inNode->Left, inKey);
	}
	else if (inKey > inNode->Key) {
		inNode->Right = DeleteNode(inNode->Right, inKey);
	}
	else {
		if (inNode->Left == nullptr) {
			TreeNode* tmp = inNode->Right;
			delete inNode;
			return tmp;
		}
		else if (inNode->Right == nullptr) {
			TreeNode* tmp = inNode->Left;
			delete inNode;
			return tmp;
		}

		TreeNode* tmp = FindMinNode(inNode->Right);
		inNode->Key = tmp->Key;
		inNode->Right = DeleteNode(inNode->Right, tmp->Key);
	}
	return inNode;
}

TreeNode* BinarySearchTree::SearchNode(TreeNode* inNode, int inKey)
{
	if (inNode == nullptr) {
		return nullptr; //못찾음
	}

	if (inKey < inNode->Key) {
		return SearchNode(inNode->Left, inKey);//찾는중
	}
	else if (inKey > inNode->Key) {
		return SearchNode(inNode->Right, inKey); //찾는중
	}
	else {
		return inNode; //찾음
	}
}

TreeNode* BinarySearchTree::FindMinNode(TreeNode* inNode)
{
	while (inNode != nullptr && inNode->Left != nullptr) {
		inNode = inNode->Left;
	}
	return inNode;
}

void BinarySearchTree::PreorderTraversal(const TreeNode* inNode) const
{
	if (inNode != nullptr)
	{
		printf("%d ", inNode->Key);
		PreorderTraversal(inNode->Left);
		PreorderTraversal(inNode->Right);
	}
}

void BinarySearchTree::InorderTraversal(const TreeNode* inNode) const 
{
}

void BinarySearchTree::PostOrderTraversal(const TreeNode* inNode) const
{
}

void BinarySearchTree::DestroyTree(TreeNode* inNode)
{
	if (inNode != nullptr)
	{
		DestroyTree(inNode->Left);
		DestroyTree(inNode->Right);
		delete inNode;
	}
}
