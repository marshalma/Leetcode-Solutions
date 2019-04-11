#include <iostream>
#include "Header.hpp"

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
	vector<string> res;
	queue<TreeNode*> bfsq;
	
	bfsq.push(root);
	while (bfsq.size() > 0) {
		int n = bfsq.size();
		for (int i = 0; i < n; i++) {
			TreeNode* thisNode = bfsq.front();
			bfsq.pop();
			if (!thisNode) {
				res.push_back("#");
				continue;
			}
			res.push_back(to_string(thisNode->val));
			bfsq.push(thisNode->left);
			bfsq.push(thisNode->right);
		}
	}
	
	string ret;
	for (auto &str: res) {
		ret += str + ",";
	}
	return ret;
}	


	// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
	vector<string> parsed;
	int p1 = 0;
	for (int i = 0; i < data.size(); i++) {
		if (data[i] == ',') {
			parsed.push_back(data.substr(p1, i - p1));
			p1 = i+1;
		}
	}
	
	int poundCount = 0;
	int i = 0;
	vector<TreeNode*> res(parsed.size(), nullptr);
	for (int i = 0; i < res.size(); i++) {
		if (parsed[i] == "#") continue;
		res[i] = new TreeNode(stoi(parsed[i]));
	}
	for (int i = 0; i < res.size(); i++) {
		if (parsed[i] == "#") {
			poundCount++;
			continue;
		}
		if (2*(i-poundCount)+1 < res.size()) res[i]->left = res[2*(i-poundCount)+1];
		if (2*(i-poundCount)+2 < res.size()) res[i]->right = res[2*(i-poundCount)+2];
	}
	return res.size()?res[0]:nullptr;
}

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(int argc, char *argv[]) {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	
	cout << serialize(root) << endl;
	cout << serialize(deserialize(serialize(root))) << endl;
}