#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<class Elem>

class Set{

public:

	//�ڼ����в���һ��Ԫ�� e

	virtual void Insert(const Elem& e) = 0;

	//�ڼ�����ɾ��һ��ֵ����e��Ԫ�أ����ɾ���ɹ��򷵻�true�����򷵻�false

	virtual bool Remove(const Elem& e) = 0;

	//��ȡ������뵽���ϵ�һ��Ԫ�أ���Ԫ�ص�ֵ��¼�ڲ���e�з��ء��������Ϊ�գ���������false,���򷵻�true��

	virtual bool GetFirstElement(Elem& e) = 0;

	//��ȡ������뵽���ϵ�Ԫ�أ���Ԫ�ص�ֵ��¼�ڲ���e�з��ء� �������Ϊ�գ���������false,���򷵻�true��

	virtual bool GetLastElement(Elem& e) = 0;

	//��ȡ���ϵ�Ԫ�صĸ���

	virtual int GetSize() = 0;

	//��ȡ��������Ԫ�ص�ֵ��¼�ڲ���array�з��ء��������ؼ���Ԫ�صĸ���

	virtual int GetElements(Elem array[]) = 0;

	//�����뼯�ϵĴ������δ�ӡ��������е�Ԫ��

	virtual void Print() = 0;

	//������s�е�Ԫ�غϲ�����ǰ������

	virtual void operator += (Set<Elem> & s) = 0;

};

template<class Elem>
class ASet :public Set<Elem> {
private:
	vector<Elem> elements;

public:
	void Insert(const Elem& e) override{
		if(find(elements.begin(),elements.end(),e)==elements.end()){
		elements.push_back(e);
		}
	}

	bool Remove(const Elem& e) override {
		auto it = find(elements.begin(), elements.end(), e);
		if (it != elements.end()) {
			elements.erase(it);
			return true;
		}
		return false;
	}

	bool GetFirstElement(Elem& e) override {
		if (elements.empty()) return false;
		e = elements.front();
		return true;
	}

	bool GetLastElement(Elem& e) override {
		if (elements.empty()) return false;
		e = elements.back();
		return true;
	}

	int GetSize()override {
		return elements.size();
	}

	int GetElements(Elem array[]) override {
		copy(elements.begin(), elements.end(), array);
		return elements.size();
	}

	void Print()override {
		for (unsigned int i = 0; i < elements.size(); i++) {
			cout << elements[i]<<" ";
		}
	}

	void operator += (Set<Elem> & s) override {
		Elem array[1000];
		int size = s.GetElements(array);
		for (int i = 0; i < size; i++) {
			Insert(array[i]);
		}
	}
};

int main() {
	ASet<int> S1, S2, S3;
	int temp;

	while (cin >> temp) {
		S1.Insert(temp);
		if (cin.peek() == '\n') break;
	};

	while (cin >> temp) {
		S2.Insert(temp);
		if (cin.peek() == '\n') break;
	};

	while (cin >> temp) {
		S3.Insert(temp);
		if (cin.peek() == '\n') break;
	};

	int first=0, last=0;
	S1.GetFirstElement(first);
	S1.GetLastElement(last);
	cout << first << " " << last << endl;

	cout << S2.GetSize() << endl;

	S3.Print();
	cout << endl;

	S1 += S2;
	S1.Print();
	cout << endl;

	int array[1000];
	int size = S3.GetElements(array);
	for (int i = 0; i < size; i++) {
		S2.Remove(array[i]);
	}

	S2.Print();

	return 0;
}