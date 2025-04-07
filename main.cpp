#include <iostream>
#include "timer/timer.hpp"
#include "dynamic_array/dynamic_array.hpp"
using namespace std;

int main() {
    Timer timer; //initialize the timer and start it
	cout<< "test " << endl;
	timer.reset(); 
    ArrayList list(30);
	for (int i = 0; i < 100; i++) {
		list.addAt(100-i,i);
	}
    cout << timer.measurement_stop(Timer::TimeUnit::Microseconds)<<" \xE6s"<<std::endl;
    list.display();

   
    return 0;
}