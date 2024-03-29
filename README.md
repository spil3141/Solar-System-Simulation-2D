# Solar-System-Simulation-2D

An exercise using the SFML graphics API, the project is a 2D physics simulation in which entities are affected by simulated gravity.  

## Screenshot
![GifMaker_20200821135207666.gif](https://trello-attachments.s3.amazonaws.com/5f066448ad4865740ae83658/5f3b227970dadc452aaf969c/7c9420361789c2e2e9989075cb434c57/GifMaker_20200821135207666.gif) 

## Getting Started
SFML API was added to this github repository as a submodule therefore there are additional steps to get the "C++ Linker" connected to the "dynamic libraries" of SFML. The steps are listed below.  
#### Steps
- Clone or download this repository : [github repository](https://github.com/spil3141/Solar-System-Simulation-2D.git)
- **Make sure that you do a [--recursive](https://git-scm.com/book/en/v2/Git-Tools-Submodules) clone to fetch all submodules**
- use "Cmake" to [build SFML](https://www.youtube.com/watch?v=pLy69V2F_8M) from source, this is because we need the DLL for our [c++ linker](https://www.youtube.com/watch?v=H4s55GgAg0I&t=259s) (dynamic library/.dll) 
- create a folder in the SFML folder (this folder should be inside our Dependencies folder) and call the folder "lib"
- cmake build the project and generate a folder with the name "lib", copy all files from this copy into the new "lib" folder you created inside the SFML submodule folder. 
- the result should look like this : 

---

![image.png](https://trello-attachments.s3.amazonaws.com/5dd6b3a80a513e0ac0bd38eb/5f3bba93fe4f8c14ff6b2f6c/92dd2d92e63b7dc3b7ec1e6fde804f7d/image.png) 
