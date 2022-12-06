#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<cassert>
using namespace std;

template <class T>
class Stack{
	private:
		T *arr;
		int top;
		int size;
	public:
		Stack(int stackSize = 100);
		bool isFull();
		bool isEmpty();
		void destroy();
		void push(T const &);
		T pop();
		T showTop();
		~Stack();
};

//Constructor, default size is 100
template <class T>
Stack<T>::Stack(int stackSize)
{
	size = stackSize;
	top = 0;
	arr = new T[size];
}

//Destructor, sets the stack to a beginning state
template <class T>
Stack<T>::~Stack()
{
	destroy();
}

//Checks whether the stack is empty or not
template <class T>
bool Stack<T>::isEmpty()
{
	if(top == 0)
	return true;

	else
	return false;
}

//Checks whether the stack is full or not
template <class T>
bool Stack<T>::isFull()
{
	if(top == size)
	return true;
	
	else
	return false;
}

//Destroy the elements
template <class T>
void Stack<T>::destroy()
{
	top=0;
}

//Inserts a T type item into the top of the stack
template <class T>
void Stack<T>::push(T const& item)
{
	if( !isFull() )
	arr[top++] = item; //Equal to arr[top] = item; top = top+1;
	
	else
	cerr << "Stack is Full." << endl;
	
}

//Removes the top most item and returns its value.
template <class T>
T Stack<T>::pop()
{
	assert( !isEmpty() );
	
	return arr[--top]; //top=top-1
}


//Doesn't change the contents of the stack, just show the top element.
template <class T>
T Stack<T>::showTop()
{
	assert ( !isEmpty() );
	
	return arr[top-1]; //Not changing the value of top
}


#endif
