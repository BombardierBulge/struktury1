#include <iostream>
#include "timer/timer.hpp"

using namespace std;

int main() {
    Timer timer; // Utwórz obiekt Timer
    timer.reset(); // Rozpocznij pomiar czasu
    cout<< "Pomiar czasu w mikrosekundach: " << endl;
    timer.stop(); // Zatrzymaj pomiar czasu
    cout<< timer.measurement_micro()<<" \xE6s"<<std::endl;
    timer.reset(); // Rozpocznij pomiar czasu
    cout<< "Pomiar czasu w mikrosekundach: " << endl;
    cout<< timer.measurement_stop(Timer::TimeUnit::Microseconds)<<" \xE6s"<<std::endl;
    return 0;
}