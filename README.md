# Traffic-Simulation
Traffic simulation according to assumed data 
The system has the following components:
Traffic semaphores (signal lights): these are standard semaphores with three lights: red, yellow, and
green.
Traffic sensors that are embedded in each lane near the intersection to record the traffic flow for all roads
(4 sensors generating 4 traffic rate values when four traffic lights are used). The sensors save the traffic
rate information into a file (average number of vehicles per hour passing through a particular road in one
direction).
The signals operate in a conventional fashion. Traffic is allowed to move on one road, say R1, and then
the next (R2), alternatively across the four roads of the intersection. Assume that the four traffic lights are
represented as L1, L2, L3, and L4. The system operates as follows:
Traffic light (L1) is green for a duration calculated based on the traffic flow rate in road R1, the other
traffic lights (L2, L3, and L4) are red.
L1 becomes yellow for X seconds (X being a constant value). The Department of Transportation's traffic
manual recommends that yellow lights are between 3 and 6 seconds long. Other traffic lights (L2, L3, and
L4) remain in red state.
Then, traffic light L2 becomes green for a duration calculated based on the traffic flow rate in road R2.
Meanwhile, L1, L3, and L4 are red. 

![alt text](https://github.com/sarhana-adh/Traffic-Simulation/blob/master/img.png)
