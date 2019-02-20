// practice_stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#define SIZE  10

class Stack {
private:

	int* arr;
	int top;
	int capacity;

public:
	Stack(int size = SIZE);
	void push(int);
	int pop();
	int peek();

	int size();
	bool isEmpty();
	bool isFull();
};

Stack::Stack(int size) {
	arr = new int[size];
	capacity = size;
	top = -1;
};
void Stack::push(int x) 
{
	if (isFull()) 
	{
		std::cout << "Error. Stack overflow." << std::endl;
		exit(EXIT_FAILURE);
	}
	else 
	{
		std::cout << "Inserting value : " << x << std::endl;
		arr[++top] = x;
	};
}
 int Stack::pop() 
 {
	 if (!isEmpty()) 
	 {
		 std::cout << "Removing value : " << peek() << std::endl;
		 return arr[top--];
	 }
	 else 
	 {
		 std::cout << "Error. Stack underflow\nProgram Terminated\n";
		 exit(EXIT_FAILURE);
	 }
 };
 int Stack::peek() 
 {
	 if( !isEmpty() )
		return arr[top];
	 else 
		 exit(EXIT_FAILURE);

 };
 int Stack::size() 
 {
	 return top + 1;
 }
 bool Stack::isEmpty() 
 {
	 return top == -1;
 };
 bool Stack::isFull() 
 {
	 return top + 1 == capacity;
 };


 int main()
 {



 };