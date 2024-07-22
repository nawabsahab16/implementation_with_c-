#include <iostream>
#include <queue> 
#include <thread> 
#include <chrono>
#include <mutex>
#include<condition_variable> 

    const int WINDOW_SIZE = 4;
    const int TOTAL_PACKETS = 10;
    
    std::mutex mtx;
    std:condition_variable cv;
    std::queue<int> ackQueue;
    
    
 void sendPackets() {
     int nextPacketToSend = 0;
     while(nextPacketToSend < TOTAL_PACKETS) {
         std::unique_lock<std::mutex> lock(mtx)l
         cv.wait(lock , [] {return ackQueue.size() < WINDOW_SIZE;});
         
        std::cout << "SENDING PACKETS" << nextPacketToSend << std::endl;
        ackQueue.push(nextPacketToSend);
        nextPacketToSend++;
        lock.unlock();
        cv.notify_all();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    
     }
 }
    
  void receiveAcks() {
      
       int NextAckExpected = 0;
       while(NextAckExpected < TOTAL_PACKETS) {
           std::this_thread::sleep_for(std::chrono::milliseconds(800));
           
          std::unique_lock<<std::mutex> lock(mtx);
          
          if(!ackQueue.empty() && ackQueue.front() == nextActExpected) {
              std:cout << "Received ACK for packet" << nextAckExpected << std :: endl;
              
            ackQueue.pop();
            nextAckExpected++;
          }
          
           lock.unlock();
           cv.notify_all();
          
       }
  }    

int main() {
    
    
    std::thread sender(sendPackets);
    std::thread receiver(receiveAcks);
    
    sender.join();
    receiver.join();
    
    return 0;
}    