<h2> Sliding Window Protocol</h2>

Implementing flow control mechanisms in C++ 
<br>
![sliding-window-protocol-4](https://github.com/user-attachments/assets/0bd31f39-df7e-4713-bc90-e3a932c0c97e)

<br>
<h3> How It Works </h3>
<br> 
The sender sends packets as long as the window size permits.
<br>
The receiver simulates the acknowledgment process, allowing the window to slide forward. 
<br>
Synchronization is managed using mutexes and condition variables to ensure the sender waits when the window is full and continues when acknowledgments are received.

