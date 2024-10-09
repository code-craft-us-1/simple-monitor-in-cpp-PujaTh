#include "./monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;
void pattern(std::string pat) {
cout << pat << flush;
sleep_for(seconds(1));
}
void displayMessage(std::string msg) {
    report(msg);
    for (int i = 0; i < 6; i++) {
        pattern("\r*");
        pattern("\r *");
    }
}

void report(std::string entry)
{
  cout<<entry;
}
bool criticalTemp(float temperature)
{
  if(temperature > 102 || temperature < 95)
    return true;
  else
    return false;
}
bool criticalPulseRate(float pulse)
{
 if (pulseRate < 60 || pulseRate > 100)
  return true;
else
  return false;
}
bool ciriticalSpoc(float spoc2)
{
  if (spo2 < 90)
    return true;
  else
   return false;
}
int vitalsOk(float temperature, float pulseRate, float spo2) {
  if (criticalTemp(temperature)) {
    displayMessage("Temperature is critical!\n");
    return 0;
  } else if (criticalPulseRate(pulseRate)) {
    displayMessage("Pulse Rate is out of range!\n");
    return 0;
  } else if (ciriticalSpoc(spo2)) {
    displayMessage("Oxygen Saturation out of range!\n");
    return 0;
  }
  return 1;
}
