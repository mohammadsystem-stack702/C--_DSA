#include<iostream>
using namespace std;
class Hash {
	int size;
	struct node {
		int item;
		node* next;
		node(int val) :item(val), next(nullptr) {}
	};
	node** arr;
	int count;
public:
	Hash(int s) {
		if (s <= 0)
			s = 100;
		size = s;
		count = 0;
		arr = new node * [size];
		for (int i = 0; i < size; i++)
			arr[i] = nullptr;
	}
	void insert(int element) {
		int index = element % size;
		node* newNode = new node(element);
		newNode->next = arr[index];
		arr[index] = newNode;
		count++;
	}
	bool search(int element) {
		int index = element % size;
		node* cur = arr[index];
		while (cur != nullptr) {
			if (cur->item == element)
				return true;
			cur = cur->next;
		}
		return false;	
	}
	void remove(int element) {
		int index = element % size;
		if (arr[index] == nullptr) {
			cout << "this index is empty so we can't delete\n";
			return;
		}
		else if (arr[index]->item == element) {
			node* temp = arr[index];
			arr[index] = arr[index]->next;
			delete temp;
			count--;
		}
		else {
			node* cur = arr[index];
			while (cur->next != nullptr  && cur->next->item != element)
				cur = cur->next;
			if (cur->next == nullptr)
				cout << "The elemnet (" << element << ") was not found\n";
			else {
				node* temp = cur->next;
				cur->next = temp->next;
				delete temp;
				count--;
			}
		}
	}
	void print() {
		for (int i = 0; i < size; i++) {
			cout << "Index (" << i << ") : ";
			node* cur = arr[i];
			while (cur != nullptr) {
				cout << cur->item << "->";
				cur = cur->next;
			}
			cout << "nullptr\n";
		}
	}
	~Hash() {
		for (int i = 0; i < size; i++) {
			node* cur = arr[i];
			while (cur != nullptr) {
				node* deletor = cur;
				cur = cur->next;
				delete deletor;
			}
		}
		delete[] arr;
	}
	int getCountOfElement() { return count; }
	double getLoadFactor() {
		return (double)count / size;
	}
};

int main() {
	cout << "Hello world!\n";
	Hash table(5);
	table.insert(8);
	table.insert(18);
	table.insert(28);
	table.insert(3);
	table.insert(13);
	table.insert(23);
	table.insert(33);
	table.insert(34);
	table.insert(45);
	table.insert(56);
	table.insert(34);
	table.insert(23);
	table.insert(45);
	table.print();
	cout << "The count of element is: " << table.getCountOfElement() << endl;
	table.remove(45);
	table.remove(0);
	table.remove(12);
	table.print();
	cout << "The load factor is: " << table.getLoadFactor() << endl;


}