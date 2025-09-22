#pragma once
struct TreeNode
{
	int Key = 0;
	TreeNode* Left = nullptr;
	TreeNode* Right = nullptr;

	TreeNode() = default;
	TreeNode(int InKey) : Key(InKey) {}
};

class BinarySearchTree
{
public:
	BinarySearchTree() = default;
	~BinarySearchTree();

	void Insert(int Inkey);
	void Delete(int Inkey);
	TreeNode* Search(int Inkey);

	void printPreOrder() const;
	void printInOrder() const;
	void printPostOrder() const;

	inline bool isEmpty() const { return Root == nullptr; }
private:
	TreeNode* Root = nullptr;

	TreeNode* InsertNode(TreeNode* inNode, int inKey);
	TreeNode* DeleteNode(TreeNode* inNode, int inKey);
	TreeNode* SearchNode(TreeNode* inNode, int inKey);
	TreeNode* FindMinNode(TreeNode* inNode);
	TreeNode* FindMaxNode(TreeNode* inNode);

	void PreorderTraversal(const TreeNode* inNode) const;
	void InorderTraversal(const TreeNode* inNode) const;
	void PostOrderTraversal(const TreeNode* inNode) const;

	void DestroyTree(TreeNode* inNode);
};

