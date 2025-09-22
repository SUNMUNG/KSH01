#include "BinarySearchTree.h"
#include <stdio.h>

BinarySearchTree::~BinarySearchTree()
{
	DestroyTree(Root);
}

void BinarySearchTree::LoopInsert(int Inkey)
{
	Root = LoopInsertNode(Root, Inkey);
}

void BinarySearchTree::LoopDelete(int Inkey)
{
	Root = LoopDeleteNode(Root, Inkey);
}

TreeNode* BinarySearchTree::LoopSearch(int Inkey)
{
	return LoopSearchNode(Root, Inkey);
}

TreeNode* BinarySearchTree::LoopInsertNode(TreeNode* inNode, int inKey)
{
	TreeNode* tmp =inNode;
	TreeNode* prev =nullptr;
	if (inNode == nullptr) {
		return new TreeNode(inKey);
	}

	while (tmp != nullptr) {
		
		if (inKey < tmp->Key) {
			prev = tmp;
			tmp = tmp->Left;
		}
		else if (inKey > tmp->Key) {
			prev = tmp;
			tmp = tmp->Right;
		}
	}
	tmp = new TreeNode(inKey);
	
	if (inKey < inNode->Key) {
		prev->Left = tmp;
	}
	else if (inKey > inNode->Key) {
		prev->Right = tmp;
	}
	return inNode;

	
}

TreeNode* BinarySearchTree::LoopDeleteNode(TreeNode* inNode, int inKey)
{
	return inNode;
}

TreeNode* BinarySearchTree::LoopSearchNode(TreeNode* inNode, int inKey)
{
	return inNode;
}

TreeNode* BinarySearchTree::LoopFindMinNode(TreeNode* inNode)
{
	return inNode;
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
	printf("InOrder : ");
	InorderTraversal(Root);
	printf("\n");
}

void BinarySearchTree::printPostOrder() const
{
	printf("PostOrder : ");
	PostOrderTraversal(Root);
	printf("\n");
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
	//트왼오
	if (inNode != nullptr)
	{
		printf("%d ", inNode->Key);
		PreorderTraversal(inNode->Left);
		PreorderTraversal(inNode->Right);
	}
}

void BinarySearchTree::InorderTraversal(const TreeNode* inNode) const 
{
	//왼트오
	if (inNode != nullptr)
	{
		PreorderTraversal(inNode->Left);
		printf("%d ", inNode->Key);
		PreorderTraversal(inNode->Right);
	}
}

void BinarySearchTree::PostOrderTraversal(const TreeNode* inNode) const
{
	//왼오트
	if (inNode != nullptr)
	{
		PreorderTraversal(inNode->Left);
		PreorderTraversal(inNode->Right);
		printf("%d ", inNode->Key);
	}
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
