#include <iostream>
using namespace std;


// TASKS
// void AddBefore(const string& x, const string& data);
// void AddAfter(const string& x, const string& data);
// void DeleteEnd();


class Node {
public:
	string data;
	Node* next;
	Node(const string& data) : data(data), next(nullptr) {}
};


class SinglyLinkedList {
	Node* head = nullptr;
public:
	void AddBegin(const string& data) {
		Node* newNode = new Node(data);
		newNode->next = head;
		head = newNode;
		newNode = nullptr;
	}

	void AddEnd(const string& data) {
		Node* newNode = new Node(data);
		if (head == nullptr) {
			head = newNode;
			return;
		}
		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
		temp = nullptr;
		newNode = nullptr;
	}



	//1
	void AddBefore(const string& x, const string& data) {
		Node* temp = head;
		Node* newNode = new Node(data);
		if (temp->data == x) {
			newNode->next = temp;
			head = newNode;
			return;
		}
		while (temp->next->data != x) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;

	}


	//2
	void AddAfter(const string& x, const string& data) {
		Node* temp = head;
		Node* newNode = new Node(data);
		if (temp->data == x) {
			newNode->next = temp->next;
			head->next = newNode;
			return;
		}
		while (temp->next->data == x) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}

	//3
	void DeleteEnd() {
		Node* temp = head;
		if (temp->next == nullptr) {
			delete temp;
			temp = nullptr;
			return;
		}
		while (temp->next->next != nullptr) {
			temp = temp->next;
		}
		delete temp->next;
		temp->next = nullptr;
	}

	void Print() {
		auto temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};


void main() {
	SinglyLinkedList sl;
	sl.AddBegin("Hakuna");
	sl.Print();
	sl.AddAfter("Hakuna","Matata");
	sl.Print();
	sl.AddBefore("Hakuna", "42");
	sl.Print();
	sl.DeleteEnd();
	sl.Print();
}