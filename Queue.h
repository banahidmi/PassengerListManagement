#ifndef Queue_h
#define Queue_h
#include<iostream>
#include<cassert>
using namespace std;


template <class T>
class Queue{
		int max;	//Maximum size of the array
		int count;	//Number of items in the queue
		int front, rear;	//Position of front and rear in the array
		T *list;	//Dynamic array pointer
	public:
		//Constructor: initializes the size of the array to 100 by default
		Queue(int = 100);
		
		//Destructor: deletes the array pointer
		~Queue()
		{
			delete []list;
		}
		
		//Checks whether the queue is empty or not
		bool isEmpty()
		{
			return count==0;
		}
		
		//Checks whether the queue is full or not
		bool isFull()
		{
			return count==max;
		}
		
		//Deletes the content of the array
		void destroyQueue();
		
		//Display the value of the item that is in the very front of the queue
		T showFront();
		
		//Displays the value of the item that is end/rear of the queue
		T showRear();
		
		//Inserts a new item to the queue. Inserts are always dont at the rear
		void insertQueue(T const& item);
		
		//Deletes one item from the queue and returns its value. Alwas from the front
		T deleteQueue();
		
		//Return the value of the count
		int getCount()
		{
			return count;
		}
};


template <class T>
Queue<T>::Queue(int size)
{
	max = size;
	list = new T[max];
	front = 0;
	rear = max - 1;
	count = 0;
}

template <class T>
void Queue<T>::destroyQueue()
{
	front = count = 0;
	rear = max - 1;
}

template <class T>
T Queue<T>::showFront()
{
	assert(!isEmpty());
	return list[front];
}

template <class T>
T Queue<T>::showRear()
{
	assert(!isEmpty());
	return list[rear];
}

template <class T>
void Queue<T>::insertQueue(T const& item)
{
	if(!isFull())
	{
		rear = (rear+1) % max;
		list[rear] = item;
		count++;
	}
	else
	{
		cerr<<"No space left in the queue!"<<endl;
	}
}

template <class T>
T Queue<T>::deleteQueue()
{
	assert(!isEmpty());
	T temp;
	temp = list[front];
	front = (front + 1) % max;
	count--;
	return temp;
}



#endif
