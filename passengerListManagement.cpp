#include<iostream>
#include <fstream>
#include "Queue.h"
#include "Stack.h"

class Passenger{
	private:
		string name,surname,destination;
	public:
		Passenger(string name="", string surname="", string destination=""):name(name),surname(surname),destination(destination){}
		
		string Name()
		{
			return name + " " + surname;
		}
		
		string Destination()
		{
			return destination;
		}
};

int main()
{
	int ist_capacity,ank_capacity,adn_capacity;
	Queue<Passenger> passenger;
	ifstream File("passenger.txt");
	string name,surname,destination,line;
	
	if (File.is_open())
	{
		while(getline(File,line))
		{
			File >> name >> surname >> destination;
			passenger.insertQueue(Passenger(name,surname,destination));
		}
		File.close();
	}
	else
	{
		cout<<"Can't find passenger.txt!";
		return 0;
	}
	
	cout<<"What is the capacity of Istanbul Train: "; 	cin>>ist_capacity;
	cout<<"What is the capacity of Adana Train: "; 		cin>>adn_capacity;
	cout<<"What is the capacity of Ankara Train: "; 	cin>>ank_capacity;
	
	Stack<string> istanbul(ist_capacity), adana(adn_capacity), ankara(ank_capacity);
	
	while(!passenger.isEmpty())
	{
		if(passenger.showFront().Destination()=="istanbul")
		{
			if(!istanbul.isFull())
			{
				istanbul.push(passenger.showFront().Name());
			}
			else
			{
				cout<<"ISTANBUL train is FULL! Passenger Name: "<<passenger.showFront().Name()<<endl;
			}
		}
		else if(passenger.showFront().Destination()=="Adana")
		{
			if(!adana.isFull())
			{
				adana.push(passenger.showFront().Name());
			}
			else
			{
				cout<<"ADANA train is FULL! Passenger Name: "<<passenger.showFront().Name()<<endl;
			}
		}
		else if(passenger.showFront().Destination()=="Ankara")
		{
			if(!ankara.isFull())
			{
				ankara.push(passenger.showFront().Name());
			}
			else
			{
				cout<<"ANKARA train is FULL! Passenger Name: "<<passenger.showFront().Name()<<endl;
			}
		}
		passenger.deleteQueue();
	}
	
	
	ofstream Fistanbul("istanbul.txt");
	while(!istanbul.isEmpty())
	{
		if(Fistanbul.is_open())
		{
			Fistanbul<<istanbul.showTop()<<"\n";
			istanbul.pop();
		}
		else
		{
			cout<<"istanbul.txt can't opened!";
			return 0;
		}
	}
	Fistanbul.close();
	
	
	ofstream Fadana("adana.txt");
	while(!adana.isEmpty())
	{
		if(Fadana.is_open())
		{
			Fadana<<adana.showTop()<<"\n";
			adana.pop();
		}
		else
		{
			cout<<"adana.txt can't opened!";
			return 0;
		}
	}
	Fadana.close();
	
	
	ofstream Fankara("ankara.txt");
	while(!ankara.isEmpty())
	{
		if(Fankara.is_open())
		{
			Fankara<<ankara.showTop()<<"\n";
			ankara.pop();
		}
		else
		{
			cout<<"ankara.txt can't opened!";
			return 0;
		}
	}
	Fankara.close();

	
	return 0;
}
