// Packets are sent to different ports on a computer system based on the hash of their packet ID. The value of the hash is as given below:

// Hash = mod(packet_id, numberOfPorts) where mod is the modulus operator and takes the mod of first operand by second operand.

// The ports are numbered from 0 to (number of ports) - 1, and a packet is initially sent to the port that has the port number equal to the hash of its packet ID. Each port requires t seconds to process an arriving packet. If a port is currently processing a packet, any arriving packet is rerouted to the next port number, and so on. The list of ports is circular. If a packet arrives at the last port and it is busy, it is rerouted to the first port.

// Given a list of IDs of n packets that arrive 1 per second, find the port to which each packet is finally sent. The first packet is sent at second t = 1.

// Each port requires time t to send a packet. If a port is currently sending a packet, this packet is then sent to the next port number, and so on. Given a list of IDs of n packets that arrive 1 per second, find the port to which each packet is finally sent. The first packet is sent at time t = 1.

#include<bits/stdc++.h>

using namespace std;

vector<int> findPorts(vector<int>& packetIds, int numberOfPorts, int ProcessingTime) {
  int n=packetIds.size();


  vector<int> ports=packetIds;
  for(int i=0; i<n; i++)
  {
    ports[i]=ports[i]%numberOfPorts;
  }
  
  vector<int> occupied(numberOfPorts,0);
  occupied[ports[0]]=1+ProcessingTime;


  for(int t=2; t<=n; t++)
  {
    int curr_port=ports[t-1];
    
    while(occupied[curr_port]>t)
    {
      curr_port=(curr_port+1)%numberOfPorts;
    }
    ports[t-1]=curr_port;
    occupied[curr_port]=t+ProcessingTime;
  }

  return ports;
}

int main()
{
  vector<int> packetIds = {0,2,6};
  int numberOfPorts = 4;
  int ProcessingTime = 2;


  vector<int> result = findPorts(packetIds, numberOfPorts, ProcessingTime);
  for (int port : result) {
      cout << port << " ";
  }
  cout << endl;

  return 0;
}