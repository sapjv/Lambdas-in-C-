

#include <iostream>
using namespace std;

int main1()
{
	[]() {};

	[]() {
		cout << "Lambda calling this cout" << endl; 
	}();

	[](int val) {
		cout << "The value passed in this function is ->" << val<< endl; 
	}(100);

	return 0;
}
