#include <iostream>

template<class T>
class LinkedList {

private:

	struct Node {
		T data;
		Node * next;
	};

	Node * head;
	unsigned int size;

public:

	LinkedList() {
		size = 0;
		head = nullptr;
	}

	~LinkedList<T>() {
		Node * curr = nullptr;

		while (head->next != nullptr) {
			curr = head->next;
			head->next = head->next->next;
			delete(curr);
		}

		delete(head);
	}


	T get(int index) {
		Node * temp = head;
		unsigned int ctr = 0;

		while (temp != nullptr) {
			if (ctr == index)
				return temp->data;

			ctr++;
			temp = temp->next;
		}
	}

	int length() {

		return size;
	}

	void insert(int index, T data) {
		Node * temp = head;
		Node * node = new Node;
		node->data = data;

		if (head == nullptr || index == 0) {
			node->next = head;
			head = node;
		}

		else if (size == index + 1) {
			while (temp->next != nullptr)
				temp = temp->next;

			node->next = nullptr;
			temp->next = node;
		}

		else {
			Node * prev = new Node;
			for (int i = 0; i < index; i++) {
				prev = temp;
				temp = temp->next;
			}

			prev->next = node;
			node->next = temp;
		}
		size++;
	}

	void pop(int index) {
		Node * node = head;

		if (head == nullptr || size < index + 1)
			return;

		else if (head->next == nullptr || index == 0) {
			if (size == 1) {
				size--;
				return;
			}

			while (node->next->next != nullptr)
				node = node->next;

			delete(node->next);
			node->next = nullptr;
		}

		else if (size == index + 1) {
			head = head->next;
			delete(node);
		}

		else {
			Node * temp = new Node;
			for (int i = 0; i < index; i++) {
				temp = node;
				node = node->next;
			}

			temp->next = temp->next->next;
			delete(node);
		}
		size--;
	}
};
