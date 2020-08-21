# Solor-System-Simulation-2D

### Exercise project using SFML Graphics API 
- a simple 2D physics simulation:
  - a static and a dynamic body affected by simulated gravity.  

## Screenshot
![image.png](https://trello-attachments.s3.amazonaws.com/5f066448ad4865740ae83658/5f3b227970dadc452aaf969c/9c42589a569e75e72a82a5d932e960a4/image.png) 

## How to Setup
The graphics API (SFML) is added to this github repository as a submodule therefore there are additional steps to get the "C++ Linker" connected to the "dynamic libraries" of SFML. 
#### Steps
- Clone or download this repository : [github repository](https://github.com/spil3141/Solor-System-Simulation-2D.git)
- **Make sure to choose the [--recurse-submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules) option when cloning**
- use "Cmake" to [build SFML](https://www.youtube.com/watch?v=pLy69V2F_8M) from source, this is because we need the DLL for our [c++ linker](https://www.youtube.com/watch?v=H4s55GgAg0I&t=259s) (dynamic library/.dll) 
- create a folder in the SFML folder (this folder should be inside our Dependencies folder) and call the folder "lib"
- cmake build the project and generate a folder with the name "lib", copy all files from this copy into the new "lib" folder you created inside the SFML submodule folder. 
- the result should look like this : 

---

![image.png](https://trello-attachments.s3.amazonaws.com/5dd6b3a80a513e0ac0bd38eb/5f3bba93fe4f8c14ff6b2f6c/92dd2d92e63b7dc3b7ec1e6fde804f7d/image.png) 
