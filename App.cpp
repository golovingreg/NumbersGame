#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
using namespace std;

int main() 
{
	srand((unsigned)time(0));
	const int target = (rand() % 1000) + 1;
	string name;
	int guess{};

	cout << "Hello! What is your name?" << endl; cin >> name;
	cout << "Nice to see you, " << name << endl;
	this_thread::sleep_for(chrono::milliseconds(900));
	cout << "The rule is simple: I chose a number from 1 to 1000, you need to guess it! Good luck!" << endl;
	this_thread::sleep_for(chrono::milliseconds(1500));

	while (guess != target)
	{
		guess = {};
		cout << "Enter a number: ";
		cin >> guess;

		if (cin.fail() || guess < 1 || guess > 1000)
		{ 
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Wrong input, the number must be from 1 to 1000, try again." << endl; 
			continue; 
		}

		if (guess < target) { cout << "Higher! Try again." << endl; }
		else if (guess > target) { cout << "Lower! Try again." << endl; }
		else { cout << "That's right, " << name << "! The number was " << target << endl; }
	}

	cout << "Press ENTER to close the game.";
	cin.ignore(256, '\n');
	cin.get();

	return 0;
}