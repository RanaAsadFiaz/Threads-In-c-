#include<iostream>
#include<thread>
#include<mutex>
#include <conio.h>
#include <chrono>
using namespace std;
const int SIZE = 10;
mutex mymutex, mymutex1;
void shared_thread_even(int i)
{
	//mymutex.lock();
	//lock_guard <mutex> g(mymutex);
	
	//lock_guard <mutex> g1(mymutex1);
	cout << "  " << i << endl;
	//mymutex.unlock();
}
void shared_thread_odd(int i)
{
	//lock_guard <mutex> g1(mymutex1);
	//lock_guard <mutex> g(mymutex);
	//mymutex.lock();
	cout << "  " << i << endl;
	//mymutex.unlock();

}
void shared_thread_main(int i)
{
	mymutex.lock();

	//lock_guard <mutex> g(mymutex);
	cout << " " << i << endl;
	mymutex.unlock();
}

void f(int n)
{
	mymutex.lock();
	for (int i = SIZE*(n - 1);i < SIZE*n; i++)
	{
		if (i % 2 == 0)
		{
			shared_thread_even(i);
		}
		else
			shared_thread_odd(i);
	}
	mymutex.unlock();
}

int main()
{
	thread t(f, 1);//0-9
	thread t1(f, 2);
	thread t2(f, 3);
	thread t3(f, 4);
	thread t4(f, 5);
	for (int i = -1; i > -SIZE; i--)
	{
		shared_thread_main(i);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	t.join();
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	system("Pause");
	return 0;
}