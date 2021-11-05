//  Objects.h
//  Assignment4Take1
// Make 3 objects I think
//  Created by Sarhana Adhikari on 11/24/20.
#include <ctime>
#include <fstream>
#define maxLights 12
#define YellowTime 6
#define UpdatetimeinSec 120
#include <iostream>
using namespace std;

class TrafficLight{
private:
    int ID;
    int state; // 1 for red, 2 for yellow, 3 for Green
    int GreenTime;
    static int numberOfLight; // This is the number of lights created thus far, doesn't decrease if a light is deopped sice this is used for ID
public:

    TrafficLight(){
        ++numberOfLight;
        ID =numberOfLight;
        state= 1;
        // set Green timer to zero.
    }
    // wait is auxiliary function to pass a specific number of seconds and return only after (decided) number of seconds I may use time(NULL) functtion to retturn tthe current time in seconds to implement wait function.
    
    
    //pass seconds into wait function keep a do while till time Null now is <seconds less than tile null now >
    void Wait(int seconds){
        long int timenow=time(NULL);
        do {
            //Just Wait
        }while(time(NULL)<(timenow+seconds));
    }
    
    
    
    void PrintInfo(){
        if (state== 1){
            cout << "Red signal";
}
        else if (state == 2){
            cout << "Yellow signal";
}
        else if (state==3){
            cout << "Green signal";
        }
    }
    int getID(){
        return ID;
    }
//
//    int HowMany(){
//        return numberOfLight;
//    }
    
    void SetLight(int lightStatus){
        state =lightStatus;
    }
    
    void SetgreenTiming(int seconds){
        GreenTime = seconds;
    }
    int GetGreenTiming(){
        return GreenTime;
    }
    
};


class Intersection{
private:
    TrafficLight TLightsforThis[maxLights]; // an array of maximum number of trafficlights/Roads is already created.
    int NumberOfLightsInt; // This is only the number of light class in the particular Intersection
    int Cycle;
    double TrafficFlow[maxLights];
    double GreenTime[maxLights];
    int CycleCurrentlyRunning;

public:

    Intersection(){
        NumberOfLightsInt=0;
        CycleCurrentlyRunning=0;
        
    }
    void AddLight(){
        if (NumberOfLightsInt>maxLights){
            cout<<"More than maximum lights in an intersection!"<<endl;}
        else {
            ++NumberOfLightsInt;
// reading Flow would make sense here
        }
    }
    
    void dropLight(int LightID) {
        bool isFound = false;
        
        for (int i=0; i<NumberOfLightsInt; i++)
        {
                if(LightID == TLightsforThis[i].getID())
                {
                    cout << "The light to be removed is found" << endl;
                    for (int j=i; j<NumberOfLightsInt;j++)
                    {
                        TLightsforThis[j] = TLightsforThis[j+1];
                    }
                    NumberOfLightsInt--;
                    isFound = true;
                }
        }
        
        if(!isFound)
            cout << "Can't find the traffic light to drop" << endl;
    }

    void ReadData(){
        ifstream DataFile;
        DataFile.open("Trafficlight.txt",ios::in);
        if (DataFile.fail()){cout<<"Failed to open\n";}
        DataFile>>Cycle;
        for(int i=0;i<NumberOfLightsInt;++i){
            DataFile>>TrafficFlow[i];
//            cout<<TrafficFlow[i];
        }
        DataFile.close();
    }
    
    
    void UpdateTiming(){
        ReadData();
            double SumOfFlow(0);
            for (int i=0;i<NumberOfLightsInt;++i){
                SumOfFlow = SumOfFlow + TrafficFlow[i];}
        
            for (int j=0;j<NumberOfLightsInt;++j){
                TLightsforThis[j].SetgreenTiming(int (Cycle*(TrafficFlow[j]/SumOfFlow))); // set as TrafficFLow
                
            }
        }
    void PrintTime(){
        time_t timetoday;
          time (&timetoday);
          cout <<asctime(localtime(&timetoday));
    }
    
    
    void run(){
        long StartTime;
        if (CycleCurrentlyRunning==0){

        UpdateTiming();   // updates at first run
            cout<<"Green light time interval for each light at time ";
            PrintTime();
            for (int x=0;x<NumberOfLightsInt;++x){
                cout<<"Traffic ID:"<< TLightsforThis[x].getID();
                cout<<" "<<TLightsforThis[x].GetGreenTiming()<<" seconds."<<endl;
            }
            cout<<endl;
        CycleCurrentlyRunning++;
            StartTime= time(NULL);

        }
    
            if (time(NULL)>=(StartTime+120)){ // updates in right time / only when required
                UpdateTiming(); //
                cout<<"Updated Green timings at ";
                PrintTime();
                for (int x=0;x<NumberOfLightsInt;++x){
                    cout<<"Traffic ID: "<< TLightsforThis[x].getID();
                    cout<<"    "<<TLightsforThis[x].GetGreenTiming()<<" seconds."<<endl;
                }
                cout<<endl;
                StartTime= time(NULL);
            }
        
        TLightsforThis[j].SetLight(2);// set this to yellow (wait time between turning green to red)
        PrintTime();
        for (int x=0;x<NumberOfLightsInt;++x){
            cout<<"Light ID:"<< TLightsforThis[x].getID()<<"  ";
            TLightsforThis[x].PrintInfo();
            cout<<"\n";
        }
        cout<<endl;
        TLightsforThis[j].Wait(YellowTime);
        
        for (int j=0; j<NumberOfLightsInt;++j){
        for(int i=0; i<NumberOfLightsInt;++i){
            TLightsforThis[i].SetLight(1); // set this to red
        }
            
            
            TLightsforThis[j].SetLight(2);// set this to yellow
            PrintTime();
            for (int x=0;x<NumberOfLightsInt;++x){
                cout<<"Light ID:"<< TLightsforThis[x].getID()<<"  ";
                TLightsforThis[x].PrintInfo();
                cout<<"\n";
            }
            cout<<endl;
            TLightsforThis[j].Wait(YellowTime);


            TLightsforThis[j].SetLight(3); //set this to green
            PrintTime();
            for (int x=0;x<NumberOfLightsInt;++x){
                cout<<"Light ID:"<< TLightsforThis[x].getID()<<"  ";
                TLightsforThis[x].PrintInfo();
                cout<<"\n";
            }
            cout<<endl;
            TLightsforThis[j].Wait(TLightsforThis[j].GetGreenTiming());
        }
    }
};

