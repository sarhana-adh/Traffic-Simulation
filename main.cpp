
#include <iostream>
using namespace std;
#include "Objects.h"

int TrafficLight:: numberOfLight=0;
int main() {
Intersection I1;
    I1.AddLight();
    I1.AddLight();
    I1.AddLight();
    I1.AddLight();
    while(true){I1.run();}
}
