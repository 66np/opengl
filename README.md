## Objective

To review OpenGL rendering with C++ language in 2D and 3D spaces.

## Outcomes

![2D Graphics](/assets/2d.png?raw=true "2D Graphics")
![2D Frag Shader](/assets/2d-frag.png?raw=true "2D Frag Shader")

## Environment Setup

Environment setup in Ubuntu (Linux-based) is as follows:
1) TER: sudo apt-get update
2) TER: sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
3) EDIT: Write OpenGL program using GLUT utility tools.
4) TER: g++ main.cpp -o main -lglut -lGLU -lGL 

NOTE: The libraries in #4 can be linked with the use of a Makefile.

## Lessons Learned

- With the environment setup, ran into installer issues with GLFW with Windows. Linux Ubuntu was preconfigured with necessary command line tools and package managers (i.e. Debian's apt, gcc etc.). Also, Windows leads to system-specific configurations and learning whereas Linux is transferrable.
- glutInitDisplayMode: GLUT\_SINGLE allows one to see code render onto screen whereas GLUT\_DOUBLE uses a complete buffer to mask the rendering of another buffer and allow for the buffer to swap to prevent flickering.
- For GLUT\_SINGLE, glFlush forces OpenGL code to finish within finite time wherease glFinish waits until every pixel is rendered. glFlush is preferred for complex single buffer screen rendering, whereas glFinish is best to use before calling to screenshot.
- For GLUT\_DOUBLE, glutSwapBuffers performs buffer swap for smooth animations
- glBlendFunc quantifies pixel color as in how red, green, blue and alpha they are
