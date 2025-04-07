#include <iostream>
#include "timer/timer.hpp"
#include "dynamic_array/dynamic_array.hpp"
#include "random/random_generator.hpp"
#include "dynamic_array/dynamic_array_read_from_file.hpp"

using namespace std;

int main() {
    Timer timer; //initialize the timer and start it
	cout<< "test " << endl;
	timer.reset(); 
    ArrayList list(30);
	RandomNumberGenerator generator(1, 1000000, "losowe1.txt");
	generator.generateFile(100);
	try{
	loadFileToArrayList("losowe1.txt", list);
	}
	catch (const std::runtime_error& e) {
		std::cerr << "Błąd: " << e.what() << std::endl;
	}
    cout << timer.measurement_stop(Timer::TimeUnit::Microseconds)<<" \xE6s"<<std::endl;
    list.display();

   
    return 0;
}