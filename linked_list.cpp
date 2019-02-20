#include "pch.h"
#include <iostream>

struct node
{
	int data;
	node* next;
};

class LList {
private:
	node *head, *tail;
public: 
	LList();
	void newNode(int);
	int  listLen();
	void print();
	void insert_start(int);
	void insert_at_position(int,int);
	void delete_start();
	void delete_end();
	void delete_at_position(int);
};

LList::LList()
{
	/*Initialisation of empty list*/
	head = NULL;
	tail = NULL;
};
void LList::newNode(int value)
{
	/* Create node and make it header and tail.
		If list isn't empty add node to the end. */
	node* temp = new node;
	temp->data = value;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
};
int LList::listLen()
{
	/*checking if list is empty*/
	if (head == NULL)
		return 0;
	else
	{
		/*Otherwise go through the list counting nodes */
		node* current = head->next;
		int counter = 1;
		while (current != NULL) {
			counter++;
			current = current->next;
		}
		return counter;
	}
};
void LList::print()
{	/*Check if list is empty*/
	if (head == NULL)
		std::cout << "Empty\n";
	else
	{
		/*Create pointer to the current node.
		  Print the value of current node until its value is NULL*/
		node* current = head;
		while (current != NULL) {
			std::cout << current->data << " -> ";
			current = current->next;
		};
		std::cout << "NULL\n";
	}
}
void LList::insert_start(int value) 
{
	/*Create new node, make it point to the head.
		Make it head-node */
	node* temp = new node;
	temp->data = value;
	temp->next = head;
	head = temp;
};
void LList::insert_at_position(int pos, int value)
{
	/*Check if position of insertion is incorrect*/
	if (pos > listLen()) 
		std::cout << "Error. The list is too short\n"; 
	else
	{
		/*Create new node, pointer to the current node, counter of position*/
		node* temp = new node, *current = head;
		temp->data = value;
		int counter = 1; 
		/*Looking for node which points to the needed position */
		while (counter != pos-1) {
			counter++;
			current = current->next;
		}
		/*Insert the new node in the needed position*/
		temp->next = current->next;
		current->next = temp;
	}
};
void LList::delete_start() 
{
	
	node *temp = new node;
	temp = head;
	head = head->next;
	delete temp;
};
void LList::delete_end()
{
	/* Find last and penult nodes.
	   delete last one and make penult be tail of list */
	node *temp = head, *prev = head;
	while (temp->next != NULL) {
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	tail = prev;
	delete temp;
}
void LList::delete_at_position(int pos)
{
	/* Check if position of insertion is incorrect */
	if (pos > listLen())
		std::cout << "Error. The list is too short\n";
	else
	{
		/* Find node for deletion and connect
		   previous and next nodes together */
		node *current = head, *prev = head;
		int counter = 1;
		while (counter != pos ) {
			counter++;
			prev = current;
			current = current->next;
		}
		prev->next = current->next;
		delete current;
	}
}


int main()
{
	LList abc = LList();
	abc.print();
	abc.newNode(1);
	abc.newNode(2);
	abc.newNode(3);
	abc.print();
	abc.newNode(4);
	abc.newNode(5);
	abc.newNode(6);
	abc.print();
	std::cout << "List length: " << abc.listLen() << std::endl;
	abc.insert_start(7);
	abc.print();
	abc.insert_at_position(3, 8);
	abc.print();
	std::cout << "List length: " << abc.listLen() << std::endl;
	abc.delete_at_position(5);
	abc.print();
}
