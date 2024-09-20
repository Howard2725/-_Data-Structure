#include <iostream>  
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

    // ����ֵ  
    bool search(int val) {
        return searchRec(root, val);
    }

    // �ݹ����  
    bool searchRec(TreeNode* root, int val) {
        if (root == nullptr) {
            return false;
        }

        if (root->val == val) {
            return true;
        }

        if (val < root->val) {
            return searchRec(root->left, val);
        }
        else {
            return searchRec(root->right, val);
        }
    }
  

    // �ݹ��������  
    void inorderTraversalRec(TreeNode* root) {
        if (root != nullptr) {
            inorderTraversalRec(root->left);
            cout << root->val << " ";
            inorderTraversalRec(root->right);
        }
    }
    // �������BST  
    void inorderTraversal() {
        inorderTraversalRec(root);
        cout << endl;
    }


    // ǰ�����BST  
    void preorderTraversal() {
        preorderTraversalRec(root);
        cout << endl;  
    }
    // �ݹ�ǰ�����  
    void preorderTraversalRec(TreeNode* root) {
        if (root != nullptr) {
            cout << root->val << " "; // ���ʸ��ڵ�  
            preorderTraversalRec(root->left); // �ݹ����������  
            preorderTraversalRec(root->right); // �ݹ����������  
        }
    }


    // �������BST  
    void postorderTraversal() {
        postorderTraversalRec(root);
        cout << endl; 
    }
    // �ݹ�������  
    void postorderTraversalRec(TreeNode* root) {
        if (root != nullptr) {
            postorderTraversalRec(root->left); // �ݹ����������  
            postorderTraversalRec(root->right); // �ݹ����������  
            cout << root->val << " "; // ���ʸ��ڵ�  
        }
    }
};

int main() {
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "Searching 20: " << (bst.search(20) ? "Found" : "Not Found") << endl;
    cout << "Searching 100: " << (bst.search(100) ? "Found" : "Not Found") << endl;
    bst.inorderTraversal();
    bst.postorderTraversal();
    bst.preorderTraversal();

    return 0;
}