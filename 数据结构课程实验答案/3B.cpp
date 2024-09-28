#include <iostream> 
#include<string>
#include<sstream>
#include<vector>
using namespace std;

// ����BST�Ľڵ�  
class TreeNode {

private:
	int val;
	TreeNode* left;
	TreeNode* right;

public:
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
	}
	TreeNode() {
	}
	friend class BST;
};

// BST��  
class BST {
private:
	TreeNode* root;

public:

	BST() : root(nullptr) {}

	int maxDepthRec(TreeNode* root) {
		if (root == nullptr) {
			return 0; // �������Ϊ0  
		}
		int leftDepth = maxDepthRec(root->left); // �����������  
		int rightDepth = maxDepthRec(root->right); // �����������  

		// BST�����������������ȵ����ֵ��1  
		return (leftDepth > rightDepth) ? (leftDepth + 1) : (rightDepth + 1);
	}

	int maxDepth() {
		return maxDepthRec(root);
	}

	// ������ֵ  
	void insert(int val) {
		root = insertRec(root, val);
	}

	// �ݹ����  
	TreeNode* insertRec(TreeNode* root, int val) {
		if (root == nullptr) {
			root = new TreeNode(val);
			return root;
		}

		if (val < root->val) {
			root->left = insertRec(root->left, val);
		}
		else if (val > root->val) {
			root->right = insertRec(root->right, val);
		}

		// ���ֵ��ȣ�����򵥴���Ϊ�����룬���޸�  
		return root;
	}

	
};

int main() {

	int n = 0;
	cin >> n;
	cin.ignore();
	

	for (int i = 0; i < n; i++) {
		BST bst;

		string line;
		vector<int> numbers;

		// ��ȡһ����  
		getline(std::cin, line);

		// ʹ��istringstream���ָ��ȡ����  
		istringstream iss(line);
		int num;
		while (iss >> num) { // ʹ��>>��������istringstream�ж�ȡ����  
			numbers.push_back(num); // ����ȡ��������ӵ�vector��  
		}

		// �����ȡ����������֤���  
		for (int num : numbers) {
			bst.insert(num);
		}

		cout << bst.maxDepth() << endl;

	}

	return 0;
}