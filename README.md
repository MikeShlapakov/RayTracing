# RayTracing
Here I am implementing a simple ray-tracing code based on the article "Ray Tracing in One Weekend"<br/>
<br/>
## Goals
* understand what ray tracing is and how to implement it.<br/>
* explore new tools like dispaying images and learn advanced math.<br/>
* have fun and get some cool pictures to show mom and dad :)

## Building and running
* compiling: `cmake -S . -B build -G "NMake Makefiles"` then `cmake --build build`
* running: `.\build\rayTracing.exe > image.ppm`
* open `image.ppm` with ppm viewer. 

## My Encounters
* I had a problem with creating a `CMakelist.txt` file. The Cmake were using `"NMake Makefiles"` generator. The solution was simply changing the generetor to `-G "MinGW Makefiles"`