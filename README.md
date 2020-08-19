# Solor-System-Simulation-2D

### Exercise project using SFML Graphics API 
- a simple 2D physics simulation:
  - a static and a dynamic body affected by simulated gravity.  

## Screenshot
![Screenshot.png](https://trello-attachments.s3.amazonaws.com/5dd6b3a80a513e0ac0bd38eb/5f3bba93fe4f8c14ff6b2f6c/84d87068531fa2692287b2e229939df5/Screenshot.png)

## How to Setup
The graphics API (SFML) is added to this github repository as a submodule therefore there are additional steps to the the "C++ Linker" connected to the "dynamic libraries" of SFML. 
#### Steps
- Clone or Download this repository 
- ** Make sure to check the recursive submodule option while cloning**
- use "Cmake" to [build](https://www.youtube.com/watch?v=pLy69V2F_8M) SFML from source, we need the DLL for our c++ linker (dynamic library/.dll) 
