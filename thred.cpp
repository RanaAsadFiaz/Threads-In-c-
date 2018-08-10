#include <iostream>
#include <thread>
using namespace std;
int sum(int a, int b)
{
	int c;
	c = a + b;
	cout << "Sum is:" << c << endl;
	return c;
}
int sub(int a, int b)
{
	int c;
	c = a - b;
	cout << "Subtraction is:" << c << endl;
	return c;
}
int main()
{
	thread first(sum,5, 6);
	thread second(sub,6, 5);
	cout << "sum and subtraction is being called concurrently:" << endl;
	first.join();
	second.join();
	cout << "Threads have been executed successfully:" << endl;
	system("Pause");
}