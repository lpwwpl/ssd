//: EnhancedLinkedList.h Llinpeiwen
#ifndef ENHANCEDLINKEDLIST_H
#define ENHANCEDLINKEDLIST_H
#include "LinkedList.h"
#include <stdexcept>

using namespace std;

//Define ListItemNotFoundException exception class 
class ListItemNotFoundException : public logic_error {

public:
    ListItemNotFoundException (const string& what_arg ) throw() :
    logic_error ("ListItem no found exception: " + what_arg) {}
};

//Implement template class EnhancedLinkedList
template <class T>
class EnhancedLinkedList : public LinkedList<T> {

public:

T& find_first (const T& key);
EnhancedLinkedList<T> find_all (const T& key);
void remove_first (const T& key);
void remove_all (const T& key); 
};

/*
 * Search the EnhancedLinkedList for the first occurrence of an item that matches the 
 * value in the parameter key.
 */
template <class T>
T& EnhancedLinkedList<T>::find_first (const T& key) {

	//The invoking EnhancedLinkedList object is empty throw exception
	if(head == NULL) {
		throw ListItemNotFoundException("find_first()");
	}

	Node<T>* node = head;

	while(node != NULL && node->getData()!=key) {
		node = node->getNext();
	}

	//No item is found that matches the parameter, throw a ListItemNotFoundException,
	//else return a reference to the first matching item
	if(node == NULL) {
		throw ListItemNotFoundException("find_first()");
	} else {
		return node->getData();
	}
}

/*
 * Search the invoking EnhancedLinkedList for all elements that match the value in 
 * the parameter key.
 */
template <class T>
EnhancedLinkedList<T> EnhancedLinkedList<T>::find_all (const T& key) {

	EnhancedLinkedList<T> ell;
	Node<T>* node = head;

	//Put copies of all the items that match key into an EnhancedLinkedList object
	while(node != NULL) {

		if(node->getData() == key) {
			ell.push_back(node->getData());
		}
		node = node->getNext();
	}
	return ell; 
}

/*
 * Remove the first element from the invoking EnhancedLinkedList whose data item 
 * matches the parameter key.
 */
template <class T>
void EnhancedLinkedList<T>::remove_first (const T& key) {
	
	if(!empty()) {
		Node<T>* node;
		Node<T>* p;
		node = head;

		while(node != NULL && node->getData()!=key) {

			p = node;
			node = node->getNext();
		}

		//If no item matches key,do nothing
		if(node == NULL) {
		
		} else {
			//if head data item matches key,then pop it
			if(node == head) {
				pop_front();				
			} else {
				//if last data item matches key,then pop it
				if(node == tail) {
					pop_back();
				} else {
					//if middle item matches key,then delete it
					node = p->getNext();
					p->getNext() = node->getNext(); 
					delete node;
					count--;
				}
			}			
		}
	}
}

/*
 * Remove all elements from the invoking EnhancedLinkedList whose data items match 
 * the parameter key.
 */
template <class T>
void EnhancedLinkedList<T>::remove_all (const T& key) {

	Node<T>* p;
	p = head;
	while(p != NULL) {
		Node<T>* q;
		while(p->getData() != key) {
			q = p;
			p = p->getNext();			
		}

		//The head data item matches key,delete the item and head point to the next
		if(p == head) {
			q = p;
			p = p->getNext();
			head = p;
			delete q;
			count--;
		} else {
			//The last data item matches key,delete then break
			if(p == tail) {
				
				tail = q;
				tail->getNext() = NULL;
				q = p;
				delete q;
				count--;
				break;
			} else {

				//delete the middle item that matches key
				q->getNext() = p->getNext();
				q = p;
				p = p->getNext();
				delete q;
				count--;
			}					
		}
	}
}
#endif
///:~