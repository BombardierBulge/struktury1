#include <iostream>
#include <random>
#include "timer/timer.hpp"
#include "dynamic_array/dynamic_array.hpp"
#include "random/random_generator.hpp"
#include "dynamic_array/dynamic_array_read_from_file.hpp"
#include "singly_linked_list/Lista_jednokierunkowa.hpp"
#include "singly_linked_list/Lista_jednokierunkowa_wczytaj.hpp"
#include <vector>

using namespace std;
void createFile(int size)
{
	RandomNumberGenerator generator(1, 1000000, "losowe" + to_string(size) + ".txt");
	generator.generateFile(size);
}
int fileSizes[] = {10000, 30000, 60000, 90000, 120000, 150000, 180000, 210000};
const int FilesNumber = 8;
const int iloscBadan = 30;
const int iloscOperacji = 7;
void createNFiles()
{ 
	int n = sizeof(fileSizes) / sizeof(fileSizes[0]);
	for (int i = 0; i < n; i++)
	{
		createFile(fileSizes[i]);
	}
}
void fillstructures(List *list[], ArrayList *array[])
{
	for (int i = 0; i < FilesNumber; i++)
	{
		loadFileToSinglyLinkedList("losowe" + to_string(fileSizes[i]) + ".txt", *list[i]);
		loadFileToArrayList("losowe" + to_string(fileSizes[i]) + ".txt", *array[i]);
	}
}
int main()
{
	cout << "////////////////////////start////////////////////////" << endl;
	createNFiles();
	List *listy[iloscOperacji][iloscBadan][FilesNumber];
	ArrayList *tablice[iloscOperacji][iloscBadan][FilesNumber];
	for (int k = 0; k < iloscOperacji; k++)
	{
		for (int j = 0; j < iloscBadan; j++)
		{
			for (int i = 0; i < FilesNumber; i++)
			{
				listy[k][j][i] = new List();
				tablice[k][j][i] = new ArrayList();
			}
		}
	}

	for (int k = 0; k < iloscOperacji; k++)
	{
		for (int j = 0; j < iloscBadan; j++)
		{
			fillstructures(listy[k][j], tablice[k][j]);
		}
	}
	Timer timer;

	for (int i = 0; i < FilesNumber; i++)
	{
		srand(static_cast<unsigned>(time(0)));
		int randomTestNumber = 1 + (rand() % (1000000 - 1 + 1));
		srand(static_cast<unsigned>(time(0)));

		///////////////////tablica dynamiczna//////////////////////

		int randomTestIndex = 0 + (rand() % (fileSizes[i] - 1 - 0 + 1));
		cout << "dynamiczna- dodawanie na koncu - rozmiar " << fileSizes[i] << ": ";
		int j = 0;
		timer.reset();
		while (j < iloscBadan)
		{
			tablice[0][j][i]->add(randomTestNumber);
			j++;
		}
		cout << timer.measurement_stop(Timer::TimeUnit::Microseconds) / iloscBadan << "\n";

		cout << "dynamiczna- dodawanie na poczatku - rozmiar " << fileSizes[i] << ": ";
		j = 0;
		timer.reset();
		while (j < iloscBadan)
		{
			tablice[1][j][i]->addFirst(randomTestNumber);
			j++;
		}
		cout << timer.measurement_stop(Timer::TimeUnit::Microseconds) / iloscBadan << "\n";

		cout << "dynamiczna- dodawanie na losowym id: " << randomTestIndex << " - rozmiar " << fileSizes[i] << ": ";
		j = 0;
		timer.reset();
		while (j < iloscBadan)
		{
			tablice[2][j][i]->addAt(randomTestIndex, randomTestNumber);
			j++;
		}
		cout << timer.measurement_stop(Timer::TimeUnit::Microseconds) / iloscBadan << "\n";

		cout << "dynamiczna- usuwanie ostatniego :  - rozmiar " << fileSizes[i] << ": ";
		j = 0;
		timer.reset();
		while (j < iloscBadan)
		{
			tablice[3][j][i]->removeLast();
			j++;
		}
		cout << timer.measurement_stop(Timer::TimeUnit::Microseconds) / iloscBadan << "\n";

		cout << "dynamiczna - usuwanie pierwszego - rozmiar " << fileSizes[i] << ": ";
		j = 0;
		timer.reset();
		while (j < iloscBadan)
		{
			tablice[4][j][i]->removeFirst();
			j++;
		}
		cout << timer.measurement_stop(Timer::TimeUnit::Microseconds) / iloscBadan << "\n";

		cout << "dynamiczna- usuwanie na losowym id: " << randomTestIndex << " - rozmiar " << fileSizes[i] << ": ";
		j = 0;
		timer.reset();
		while (j < iloscBadan)
		{
			tablice[5][j][i]->removeAt(randomTestIndex);
			j++;
		}
		cout << timer.measurement_stop(Timer::TimeUnit::Microseconds) / iloscBadan << "\n";

		cout << "dynamiczna- szukanie o losowej wartosci:  " << randomTestNumber << " - rozmiar " << fileSizes[i] << ": ";
		j = 0;
		timer.reset();
		while (j < iloscBadan)
		{
			tablice[6][j][i]->find(randomTestNumber);
			j++;
		}
		cout << timer.measurement_stop(Timer::TimeUnit::Microseconds) / iloscBadan << "\n\n";

		//////////////////////lista jednokierunkowa/////////////////////////

		cout << "lista jedno - dodawanie na koncu - rozmiar " << fileSizes[i] << ": ";
		j = 0;
		timer.reset();
		while (j < iloscBadan)
		{

			listy[0][j][i]->addLast(randomTestNumber);
			j++;
		}
		cout << timer.measurement_stop(Timer::TimeUnit::Microseconds) / iloscBadan << "\n";

		cout << "lista jedno- dodawanie na poczatku - rozmiar " << fileSizes[i] << ": ";
		j = 0;
		timer.reset();
		while (j < iloscBadan)
		{

			listy[1][j][i]->addFirst(randomTestNumber);
			
			j++;
		}
		
		cout << timer.measurement_stop(Timer::TimeUnit::Microseconds) / iloscBadan << "\n";

		cout << "lista jedno- dodawanie na losowym id: " << randomTestIndex << " - rozmiar " << fileSizes[i] << ": ";
		j = 0;
		timer.reset();
		while (j < iloscBadan)
		{
			listy[2][j][i]->addAt(randomTestNumber,randomTestIndex);
			j++;
		}
		cout << timer.measurement_stop(Timer::TimeUnit::Microseconds) / iloscBadan << "\n";

		cout << "lista jedno- usuwanie ostatniego :  - rozmiar " << fileSizes[i] << ": ";
		j = 0;
		timer.reset();
		while (j < iloscBadan)
		{
			listy[3][j][i]->deleteLast();
			j++;
		}
		cout << timer.measurement_stop(Timer::TimeUnit::Microseconds) / iloscBadan << "\n";

		cout << "lista jedno - usuwanie pierwszego - rozmiar " << fileSizes[i] << ": ";
		j = 0;
		timer.reset();
		while (j < iloscBadan)
		{
			listy[4][j][i]->deleteFirst();
			j++;
		}
		cout << timer.measurement_stop(Timer::TimeUnit::Microseconds) / iloscBadan << "\n";

		cout << "lista jedno- usuwanie na losowym id: " << randomTestIndex << " - rozmiar " << fileSizes[i] << ": ";
		j = 0;
		timer.reset();
		while (j < iloscBadan)
		{
			listy[5][j][i]->deleteAt(randomTestIndex);
			j++;
		}
		cout << timer.measurement_stop(Timer::TimeUnit::Microseconds) / iloscBadan << "\n";

		cout << "lista jedno- szukanie o losowej wartosci:  " << randomTestNumber << " - rozmiar " << fileSizes[i] << ": ";
		j = 0;
		timer.reset();
		while (j < iloscBadan)
		{
			
			listy[6][j][i]->search(randomTestNumber);
			j++;
		}
		cout << timer.measurement_stop(Timer::TimeUnit::Microseconds) / iloscBadan << "\n";
	}

	for (int k = 0; k < iloscOperacji; k++)
	{
		for (int j = 0; j < 30; j++)
		{
			for (int i = 0; i < FilesNumber; i++)
			{
				delete listy[k][j][i];
				delete tablice[k][j][i];
			}
		}
	}
	return 0;
}