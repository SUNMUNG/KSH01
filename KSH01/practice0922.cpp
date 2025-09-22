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
}
