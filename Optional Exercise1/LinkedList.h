#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <stdexcept>

using namespace std;

class EmptyListException : public logic_error {
public:
    EmptyListException(const string& what_arg ) throw() :
    logic_error ("Empty list exception: " + what_arg) {}
};

template <class T> class Node {
private:
	T data;
	Node* next;
public:
	Node(T d,Node* n = NULL):data(d),next(n) {}
	T& getData() {return data;}
	Node*& getNext(){return next;}
};

template <class T> class LinkedList {
protected:
	Node<T>* head;
	Node<T>* tail;
	int count;
public:
	LinkedList(void):head(NULL),tail(NULL),count(0){}
	LinkedList(const LinkedList<T>& src);
	virtual ~LinkedList(void);

	virtual T& front(void) {
		if(head == NULL) {
			throw EmptyListException("front()");
		}
		return head->getData();
	}
	virtual T& back(void) {
		if(tail == NULL) {
			throw EmptyListException("back()");
		}
		return tail ->getData();
	}
	virtual int size(void) {
		return count;
	}
	virtual bool empty(void) {
		return count == 0;
	}
	virtual void push_front(T);
	virtual void push_back(T);
	virtual void pop_front(void);
	virtual void pop_back(void);
	virtual void dump(void);
};

template <class T> LinkedList<T>::LinkedList(const LinkedList<T>& src):count(0),head(NULL),tail(NULL) {
	Node<T>* current = src.head;
	while(current != NULL) {
		this->push_back(current->getData());
		current = current->getNext();
	}
}

template <class T> LinkedList<T>::~LinkedList(void) {
    while (!this->empty()) {
        this->pop_front();
    }
}

template <class T> void LinkedList<T>::push_back(T d) {
	Node<T>* newNode = new Node<T>(d,NULL);

	if(this->empty()) {
		head = newNode;
	} else {
		tail->getNext() = newNode;
	}
	tail = newNode;
	count++;
}


template <class T> void LinkedList<T>::push_front(T d) {
	Node<T>* newNode = new Node<T>(d,head);
	if(this->empty()) {
		head = tail = newNode;
	} else {
		head = newNode;
	}
	count++;
}

template <class T>
void LinkedList<T>::pop_front(void) {

    if (head == NULL) {
        throw EmptyListException("pop_front()");
    }

    Node<T>* old_head = head;

    if (this->size() == 1) {
        head = NULL;
        tail = NULL;
    }
    else {
        head = head->getNext();
    }

    delete old_head;
    count--;
}

// Remove an element from the end
template <class T>
void LinkedList<T>::pop_back(void) {

    if (tail == NULL) {
        throw EmptyListException("pop_back()");
    }

    Node<T>* old_tail = tail;

    if (this->size() == 1) {
        head = NULL;
        tail = NULL;
    }
    else {

        // Traverse the list
        Node<T>* current = head;
        while (current->getNext() != tail) {
            current = current->getNext();
        }

        // Unlink and reposition
        current->getNext() = NULL;
        tail = current;
    }

    delete old_tail;
    count--;
}

// Display the contents of the list
template <class T>
void LinkedList<T>::dump(void) {

    cout << "(";

    if (head != NULL) {
        Node<T>* current = head;
        while (current->getNext() != NULL) {
            cout << current->getData() << ", ";
            current = current->getNext();
        }
        cout << current->getData();
    }

    cout << ")" << endl;
}

#endif
