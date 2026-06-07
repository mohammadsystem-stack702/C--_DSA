#include<iostream>
using namespace std;
template<class t>
class DoublyLinkedList {
	struct node {
		t item;
		node* next;
		node* prev;
		node(t val) : item(val), next(nullptr), prev(nullptr) {}
	};
	node* first, * last;
	int length;
public:
	DoublyLinkedList() :first(nullptr), last(nullptr), length(0) {}
	bool isEmpty() { return length == 0; } // or last==NULL  or first==NULL
	void getFirst() { cout << "First : " << first->item << endl; }
	void getLast() { cout << "Last : " << last->item << endl; }
	void getLength() { cout << "Length : " << length << endl; }
	void insertAtFirst(t element) {
		node* newNode = new node(element);
		if (isEmpty()) {
			first = last = newNode;
			newNode->next = newNode->prev = nullptr;
		}
		else {
			newNode->next = first;
			first->prev = newNode;
			newNode->prev = nullptr;
			first = newNode;
		}
		length++;
	}
	void insertAtLast(t element) {
		node* newNode = new node(element);
		if (isEmpty()) {
			first = last = newNode;
			newNode->next = newNode->prev = nullptr;
		}
		else {
			newNode->next = nullptr;
			newNode->prev = last;
			last->next = newNode;
			last = newNode;
		}
		length++;
	}
	void insertAtPos(t element, int pos) {
		if (pos<0 || pos>length)
			cout << "Invalid value to position\n";
		else if (pos == 0)
			insertAtFirst(element);
		else if (pos == length)
			insertAtLast(element);
		else {
			node* newNode = new node(element);
			node* cur = first;
			for (int i = 1; i < pos; i++)
				cur = cur->next;
			newNode->prev = cur;
			newNode->next = cur->next;
			cur->next->prev = newNode;
			cur->next = newNode;
			length++;
		}
	}
	void deleteFirst() {
		if (isEmpty())
			cout << "Cannot delete last from empty Doublylinkedlist\n";
		else if (length == 1) {
			node*temp= first;
			first = last = nullptr;
			delete temp;
			length = 0;
		}
		else {
			node* temp = first;
			first = first->next;
			first->prev = nullptr;
			delete temp;
			length--;
		}
	}
	void deleteLast() {
		if (isEmpty())
			cout << "Cannot delete last from empty DoublyLinkedlist\n";
		else if (length == 1) {
			node*temp= last;
			first = last = nullptr;
			delete temp;
			length = 0;
		}
		else {
			node* temp = last;
			last = last->prev;
			last->next = nullptr;
			delete temp;
			length--;
		}
	}
	void deleteElement(t element) {
		if (isEmpty())
			cout << "Cannot delete element from empty DoubleLinkedlist\n";
		else if (first->item == element)
			deleteFirst();
		else {
			node* cur = first->next;
			while (cur != nullptr) {
				if (cur->item == element)
					break;
				cur = cur->next;
			}
			if (cur == nullptr)
				cout << "The element (" << element << ") was not found\n";
			else if (cur == last)
				deleteLast();
			else {
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
					delete cur;
				length--;
			}
		}
	}
	void print() {
		if (isEmpty())
			cout << "Cannot print empty DoublyLinkedList\n";
		else {
			node* cur = first;
			cout << "DoublyLinkedList: [ ";
			while (cur != nullptr) {
				cout << cur->item << " ";
				cur = cur->next;
			}
			cout << "]\n";
		}
	}
	void reversedPrint() {
		if (isEmpty())
			cout << "Cannot reversedPrint empty DoublyLinkedList\n";
		else {
			node* cur = last;
			cout << "ReverseDoublyLinkedList: [ ";
			while (cur != nullptr) {
				cout << cur->item << " ";
				cur = cur->prev;
			}
			cout << "]\n";
		}
	}
	~DoublyLinkedList() {
		while (first != nullptr) {
			node* cur = first;
			first = first->next;
			delete cur;
		}
		first = last = nullptr;
		length = 0;
	}
	void reverse() {
		if (isEmpty() || length == 1)
			cout << "Cannot reverse empty Doublylinkedlist or one element\n";
		else {
			node* previouse = nullptr, * cur = first, nextptr = nullptr;
			while (cur != nullptr) {
				nextptr = cur->next;
				cur->next = previouse;
				cur->prev = nextptr;
				previouse = cur;
				cur = nextptr;
			}
			last = first;
			first = previouse;
		}
	}
	int search(t element) {
		if (isEmpty()) {
			cout << "Cannot search in empty doublyLinkedList\n";
			return -1;
		}
		else {
			node* cur = first;
			int pos = 0;
			while (cur != nullptr) {
				if (cur->item == element)
					break;
				pos++;
				cur = cur->next;
			}
			if (cur == nullptr)
				return -1;
			else
				return pos;
		}
	}
	void updateAtPos(int pos, t element) {
		if (isEmpty() || pos < 0 || pos >= length)
			cout << "Invalid value to position or empty doublylinkedLsit\n";
		else {
			node* cur = first;
			for (int i = 1; i <= pos; i++)
				cur = cur->next;
			cur->item = element;
			cout << "Done!\n";
		}
	}
	void removeDuplicate() {
		if (isEmpty() || length == 1)
			cout << "Cannot removeDuplicate in empty doublyLinkedList or it has one element\n";
		else {
			node * previouse = first;
			while (previouse != nullptr) {
				node* cur = previouse->next;
				while (cur != nullptr) {
					if (cur->item == previouse->item) {
						node* temp = cur;
						cur = cur->next;
						temp->prev->next = temp->next;
						if (temp->next != nullptr)
							temp->next->prev = temp->prev;
						else
							last = temp->prev;
						delete temp;
						length--;
					}
					else
						cur = cur->next;
				}
				previouse = previouse->next;
			}
		}
	}
	bool isPalindrome() {
		if (isEmpty()) {
			cout << "Cannot decide if it is plindrme or not because it's empty\n";
			return false;
		}
		if (length == 1)
			return true;
		else {
			node* firstptr = first, * lastptr = last;
			while (firstptr != lastptr && firstptr != nullptr && lastptr != nullptr && firstptr->prev != lastptr ){
				if (firstptr->item == lastptr->item) {
					firstptr = firstptr->next;
					lastptr = lastptr->prev;
				}
				else
					return false;

			}
			return true;

		}
	}

};
int main() {
	cout << "Hello world!\n";
	DoublyLinkedList<int>l;
	l.insertAtPos(10, 0);
	l.insertAtPos(2, 1);
	l.insertAtPos(23, 2);
	l.insertAtPos(34, 3);
	l.insertAtPos(654, 4);
	l.insertAtPos(5, 5);
	l.insertAtPos(23, 6);
	l.insertAtPos(54, 7);
	l.print();
	l.deleteElement(10);
	l.deleteElement(54);
	l.deleteElement(654);
	l.deleteElement(524151);
	l.print();
	cout << "Reversing print:\n";
	l.reversedPrint();


}