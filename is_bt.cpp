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

bool isBT(const Node & node, const vector<Node>& tree) {
	if (node.left >= 0 && node.right >= 0){
		bool lIsBT = isBT(tree[node.left], tree);
		bool rIsBT = isBT(tree[node.right], tree);
		bool maxNum(BT) 
		if (tree[node.left].key < node.key && tree[node.right].key > node.key){
			return isBT(tree[node.left], tree) && isBT(tree[node.right], tree);
		}
		return false;
	}
	if (node.left >= 0 && node.right == -1){
		if (tree[node.left].key < node.key){
			return isBT(tree[node.left], tree);
		}
		return false;
	}
	if (node.left == -1 && node.right >= 0){
		if (tree[node.right].key > node.key){
			return isBT(tree[node.right], tree);
		}
		return false;
	}
	if (node.left == -1 && node.right == -1){
		return true;
	}
}

bool IsBinarySearchTree(const vector<Node>& tree) {
  // Implement correct algorithm here
	if (tree.empty())
		return true;
	return isBT(tree[0], tree);
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
