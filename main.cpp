#include <iostream>
#include "timer/timer.hpp"
#include "dynamic_array/dynamic_array.hpp"
#include "random/random_generator.hpp"
#include "dynamic_array/dynamic_array_read_from_file.hpp"
#include "singly_linked_list/Lista_jednokierunkowa.hpp"
#include "singly_linked_list/Lista_jednokierunkowa_wczytaj.hpp"

using namespace std;

int main() {
    Timer timer; //initialize the timer and start it
	cout<< "test " << endl;
    List lista;
	RandomNumberGenerator generator(1, 1000000, "losowe1.txt");
	generator.generateFile(100);
	timer.reset(); 
	loadFileToSinglyLinkedList("losowe1.txt", lista);
    cout << timer.measurement_stop(Timer::TimeUnit::Microseconds)<<" \xE6s"<<std::endl;
	PrintList(lista);
   
    return 0;
}