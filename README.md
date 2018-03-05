# Progression

## Description
'Progression' is my first attempt at creating a game engine. It's written in C++, and runs on Linux operating systems. It's largely modeled after Unity. See below for more details about the design and installing.

## Features
* Entity component system: Each gameobject has a transform, and a list of components
* Render system that groups together render components to minimize GPU calls by batching
* Easy to add new shaders, and autodetection of shader attributes and uniforms
* Resource manager: handles materials and meshes, and keeps track of references so it can deallocate each resource when its no longer needed.
* Input system: handles all key presses and mouse actions
* Default blinn-phong shader is loaded

## Installing

### Prerequisites
* [OpenGL installed](https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Linux)
* [SDL2 installed](https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Linux)

Clone or download this repository    
Then use the makefile to build it.    
Building library and examples:     
```sh
make all
```
Building just the library:     
```sh
make lib
```

Running the examples: example1:
```sh
cd [Progression root dir]
./build/examples/example1
```
Result:   
![Example1 output](https://lh3.googleusercontent.com/ysYM82HDNjdLZY2HWuaRijtDOehv0JnY2_n8pLeAj9yWjCneWxzWz_RA5DuAcVDxVZUuPhbdrg4zeMiNWog2_S_4h4-rQzIALmNHZTjKSHnrmTUd0DtPFa7OrORxOvvKNAZSg0Cr=w2400)

### Using Progression Engine in another project
Since Progression compiles a static library, you can link it with whatever project you want. See the [Makefile template](makefile.template) to see the makefile I commonly use to compile my projects that also use Progression.

## Platforms
* Linux

## Tools Used
* OpenGL for rendering
* GLM for vector and matrix operations
* SDL2 for windowing and input handling
* STB\_image for image loading and saving

## Authors
* [Liam Tyler](http://www.liamtyler.com)

## License
MIT License. See [LICENSE](LICENSE)

## Acknowledgments
* [Moses Adeagbo](https://sub-surf.blog/) whose own game engine and work gave me a lot of inspiration to start working on this
