#include "practice0922.h"
#include "BinarySearchTree.h"

void practice0922::TestBinarySearchTree()
{
	BinarySearchTree bst;
	bst.Insert(30);
	bst.Insert(50);
	bst.Insert(10);
	bst.Insert(20);
	bst.printPreOrder();
	bst.printInOrder();
	bst.printPostOrder();
}

void practice0922::TestBinarySearchTreeLoop()
{
	BinarySearchTree bst;
	bst.LoopInsert(30);
	bst.LoopInsert(50);
	bst.LoopInsert(10);
	bst.LoopInsert(20);
	bst.printPreOrder();
	bst.printInOrder();
	bst.printPostOrder();
}

