## Objective

To review OpenGL rendering with C++ language in 2D and 3D spaces.

## Outcomes

![2D Graphics](/assets/2d.png?raw=true "2D Graphics")

## Environment Setup

Environment setup in Ubuntu (Linux-based) is as follows:
1) TER: sudo apt-get update
2) TER: sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
3) EDIT: Write OpenGL program using GLUT utility tools.
4) TER: g++ main.cpp -o main -lglut -lGLU -lGL 

NOTE: The libraries in #4 can be linked with the use of a Makefile.

## Lessons Learned

- With the environment setup, ran into installer issues with GLFW with Windows. Linux Ubuntu was preconfigured with necessary command line tools and package managers (i.e. Debian's apt, gcc etc.). Also, Windows leads to system-specific configurations and learning whereas Linux is transferrable.
