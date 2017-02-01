#include <iostream>
using namespace std;

// Classes with dynamic memory require a destructor, copy constructor, and assignment operator
class robust
{
public:
	robust() {
		x = NULL;
	}
	~robust() {
		if (x != NULL) {
			delete []x;
		}
	}
	void SetSize(int num)
	{
		//Release any old memory
		if (x != NULL) {
			delete []x;
			x = NULL;
		}

		//Bail out if new memory is not wanted
		if ( num<=0 )
			return;

		//Alocate new memory
		x = new int[num];
	}
private:
	int *x;
};

int main()
{
	cout << "How many integers do you really need? ";
	int num;
	cin >> num;
	robust r;
	r.SetSize(num);

	return 0;

}