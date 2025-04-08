#include <iostream>
#include "timer/timer.hpp"
#include "dynamic_array/dynamic_array.hpp"
#include "random/random_generator.hpp"
#include "dynamic_array/dynamic_array_read_from_file.hpp"
#include "singly_linked_list/Lista_jednokierunkowa.hpp"
#include "singly_linked_list/Lista_jednokierunkowa_wczytaj.hpp"

using namespace std;
void createFile(int size) {
	RandomNumberGenerator generator(1, 1000000, "losowe" + to_string(size) + ".txt");
	generator.generateFile(size);
}
int fileSizes[] = { 10000 ,30000,50000,100000,300000,500000,1000000,3000000,5000000,10000000 };
const int FilesNumber = 10;
void createNFiles() {//Tworzy pliki o rozmiarach z fileSizes[]
	int n = sizeof(fileSizes) / sizeof(fileSizes[0]);
	for (int i = 0; i < n; i++) {
		createFile(fileSizes[i]);
	}
}
void fillstructures(List* list[], ArrayList* array[]) {
	for (int i = 0; i < FilesNumber; i++) {
			loadFileToSinglyLinkedList("losowe" + to_string(fileSizes[i]) + ".txt", *list[i]);
			loadFileToArrayList("losowe" + to_string(fileSizes[i]) + ".txt", *array[i]);
	}
}
int main() {
	cout<<"start"<<endl;
	createNFiles();
   List* listy[FilesNumber];
   ArrayList* tablice[FilesNumber];
   
   for (int i = 0; i < FilesNumber; i++) {
	   listy[i] = new List();
	   tablice[i] = new ArrayList();
   }
   Timer timer;
   cout<<"pomiar czasu wczytu... \n";
   timer.reset();
   fillstructures(listy, tablice);
   cout<<"czas wczytywania do tablicy: "<<timer.measurement_stop(Timer::TimeUnit::Microseconds)<<"\n";
   cout<<"index ostatni(5000000): "<<tablice[9]->get(9999999)<<endl;
   for (int i = 0; i < FilesNumber; i++) {
	   delete listy[i];
	   delete tablice[i];
   }
    return 0;
}