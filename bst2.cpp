#include <algorithm>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

int maxValue(int i, const vector<Node> & tree){
	if (tree[i].right == -1)
		return tree[i].key;
	int tmp;
	while (i >= 0){
		tmp = i;
		i = tree[i].right;
	}
	return tree[tmp].key;
}

int minValue (int i, const vector<Node> & tree){
	if (tree[i].left == -1)
		return tree[i].key;
	int tmp;
	while (i >= 0){
		tmp = i;
		i = tree[i].left;
	}
	return tree[tmp].key;
}

bool isBST (int i, const vector<Node>& tree){
	if (tree.empty())
		return true;
	if (i == -1)
		return true;
	if (tree[i].left != -1 && maxValue(tree[i].left, tree) >= tree[i].key)
		return false;
	if (tree[i].right != -1 && minValue(tree[i].right, tree) < tree[i].key)
		return false;
	if (!isBST(tree[i].left, tree) || !isBST(tree[i].right, tree)){
		return false;
	}
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
	bool result = isBST(0, tree);
  return result;
}

int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  if (IsBinarySearchTree(tree)) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  system("pause");
  return 0;
}
