#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;

int main()
{
	// using vector 
	vector<string> v =
	{
		"Lewis Hamilton", "Lewis Hamilton", "Nico Roseberg",
		"Sebsatian Vettel", "Lewis Hamilton", "Sebsatian Vettel",
		"Sebsatian Vettel", "Sebsatian Vettel", "Fernando Alonso"
	}; // Latest -> last

	auto it = v.begin(); // O(1)
	cout << "Latest winner: " << *it << '\n';

	it += 8; // O(1), 8 years ago
	cout << "8 years ago winner: " << *it << '\n';

	advance(it, -3); // O(1), 5 years ago
	cout << "5 years ago winner: " << *it << '\n';

	// using forward_list
	forward_list<string> fl(v.begin(), v.end());

	auto iit = fl.begin(); // O(1)
	cout << "Latest winner: " << *iit << '\n';

	// iit += 8; // error
	// cout << "8 years ago winner: " << *iit << '\n';

	advance(iit, 5); // O(1), 5 years ago
	cout << "5 years ago winner: " << *iit << '\n';

	// advabce(iit, -3); // error
}