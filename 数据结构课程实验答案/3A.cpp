#include<iostream>  
using namespace std;



class tree{

public:
	char arr[100];

	tree() { // ���캯��  
		// ��ʼ��arr�����е�����Ԫ��Ϊ'0'  
		for (int i = 0; i < 100; ++i) {
			arr[i] = '0';
		}		
	}


	//�������ڵ�֮�����ϵ
	int parent(int pos) {
		return (pos - 1) / 2;
	}

	int leftchild(int pos) {
		return 2 * pos + 1;
	}

	int rightchild(int pos) {
		return 2 * pos + 2;
	}

	bool insertch(char ch, int i) {
		if (arr[i] == '0') {
			arr[i] = ch;
			return true;
		}
		if (int(arr[i]) >= 97) { // ��ǰ�ڵ���Сд��ĸ  
			// �������ӽڵ�  
			if (insertch(ch, leftchild(i))) {
				return true;
			}
			// ���ӽڵ�ʧ�ܣ��������ӽڵ�  
			return insertch(ch, rightchild(i));
		}
		if (int(arr[i]) >= 65 && int(arr[i]) <= 90) { // ��ǰ�ڵ��Ǵ�д��ĸ�������������²���  
			return false;
		}
	}


	void insert(char ch) {
		insertch(ch, 0);
	}

	void print() {
		for (int i = 0; i < 100; i++) {
			if (arr[i] == '0') {
				continue;
			}
			cout << arr[i];
		}
		cout << endl;
	}

};


int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; j++) {
		tree t;
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); i++) {
			t.insert(str[i]);
		}
		t.print();
	}
	return 0;
}