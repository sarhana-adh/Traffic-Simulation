#include <iostream>
using namespace std;
#include "Objects.h"

int TrafficLight:: numberOfLight=0;
int main() {
Intersection I1;
    for (int i=0;i<5;++i){
    I1.AddLight();}
    I1.dropLight(3);
    I1.dropLight(6);

}
