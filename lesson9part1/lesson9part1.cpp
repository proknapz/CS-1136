/*
* Omar Khan 
* 11/15/2021
* Stock, Spools, and Shipping
*/
#include <cmath>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

int readNumSpools()
{
	int spools;
	cout << "Spools to be ordered" << endl; cin >> spools;
	while (spools <= 1)
	{
		cout << "Spools order must be 1 or more" << endl;
		cout << "Spools to be ordered" << endl; cin >> spools;
	}
	return spools;
}

int readSpoolsStock()
{
	int stock;
	cout << "Spools in stock" << endl; cin >> stock;
	while (stock < 0)
	{
		cout << "Spools in stock must be 0 or more" << endl;
		cout << "Spools in stock" << endl; cin >> stock;
	}
	return stock;
}



double shippingANDhandling()
{
	double charges = 0;
	char choice = ' ';
	cout << "Special shipping and handling (y or n)" << endl; cin >> choice;
	if (choice == 'y')
	{
		cout << "Shipping and handling amount" << endl; cin >> charges;
		while (charges < 0)
		{
			cout << "The spool shipping and handling charge must be 0.0 or more" << endl;
			cout << "Shipping and handling amount" << endl; cin >> charges;
			continue;
		}
	}
	else
	{
		return 12.99;
	}
	return charges;
}

void display(int spools, int stock, double charges)
{
	double backOrder, spoolsOrdered, subTotal, shipping, total;

	backOrder = spools - stock;
	if (backOrder < 0) 
			backOrder = 0;

	spoolsOrdered = spools - backOrder;
	cout << "Spools ready to ship: " << spoolsOrdered << endl;

	cout << "Spools on back-order: " << backOrder << endl;

	subTotal = (spoolsOrdered * 100) + (4 * spoolsOrdered);
	cout << "Subtotal ready to ship: $ " << showpoint << fixed << setprecision(2) << setw(9) << subTotal << endl;

	shipping = spoolsOrdered * charges;
	cout << "Shipping and handling:  $ " << showpoint << fixed << setprecision(2) << setw(9) << shipping << endl;

	total = shipping + subTotal;
	cout << "Total shipping charges: $ " << showpoint << fixed << setprecision(2) << setw(9) << total << endl;
	
}
int main()
{
	int s = readNumSpools();
	int w = readSpoolsStock();
	float p = shippingANDhandling();
	display(s, w, p);

}