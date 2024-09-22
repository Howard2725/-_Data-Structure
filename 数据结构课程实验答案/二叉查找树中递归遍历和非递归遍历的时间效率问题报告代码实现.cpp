#include <iostream> 
#include <stack>
#include <omp.h>
#include <random>
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
            //cout << root->val << " ";
            inorderTraversalRec(root->right);
        }
    }
    // �������BST  
    void inorderTraversal() {
        inorderTraversalRec(root);
        //cout << endl;
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

    //�ǵݹ��������
    void inorderTraversal_alter() {
        inorderTraversal_alterRec(root);
    }
    void inorderTraversal_alterRec(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (curr != nullptr || !stk.empty()) {
            while (curr != nullptr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();
            //cout << curr->val << " ";
            curr = curr->right;
        }
        //cout << endl;
    }

};

int main() {
    BST bst;
    cout << "���������밴 Enter ��ʼ������������";
    cin.get();
    cout << "ѭ������\t" << "�ݹ����\t" << "�ǵݹ����" << endl;
    for (int n = 10000; n < 100000; n += 10000) {
        srand(time(NULL));
        for (int i = 0; i < 100; i++) {
            bst.insert(rand() % 1000);
        }

        double start = 0, end = 0;

        //�ݹ������������ʱ��
        start = omp_get_wtime();
        for (int i = 0; i < n; i++) {
            bst.inorderTraversal();
        }
        end = omp_get_wtime();
        cout << n << "\t\t" << end - start;

        //�����������ʱ��
        start = omp_get_wtime();
        for (int i = 0; i < n; i++) {
            bst.inorderTraversal_alter();
        }
        end = omp_get_wtime();
        cout << "\t" << end - start << endl;
    }

    return 0;
}