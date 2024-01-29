# Owner avatar
Cppgame-or-Pygame-if-it-was-made-for-Cpp-instead-of-Python

Cppgame or C++game is a library which aims to make SDL2 syntax as easy as Pygame(A module which uses SDL2 in Python)

# Usage
Before writing a project remember to install libsdl2-dev, libsdl2-image-dev, and libsdl2-mixer-dev by the following commands:
```bash
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev
```
alternatively you need to have the sourcefiles of SDL2 and its other components in your project.

Afterwards you can use Cppgame as any other library, some tips are:
- Project structure should be:
```
project_name/
|_src/ {source and header files of your project}
|_libs/ {static libraries (including Cppgame)}
|_include/ {library sourcefiles}
|_build/ {executable}
|_obj/ {.o files}
```
- if you decide to make your project in the place of Application folder of this project, use the included Makefile and modify paths in it

# Credits
ported to linux by @darksoulq
Usage guide by @darksoulq