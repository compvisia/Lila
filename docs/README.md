<h1 align="center">
	Lila			
</h1>

<p align="center">Modern & easy-to-use 3D game engine</p>

<p align="center">
	<a title="License MIT" href="https://github.com/compvisia/Lila/blob/master/LICENSE"><img src="https://img.shields.io/badge/License-MIT-f9f9f9?style=flat"/></a>
</p>

---
## Summary

Lila is written in modern C++ 17, and is developed for learning purposes. It is made so you can learn it easily and have fun using it, while still being fast and optimized.

:computer: Lila is currently available for Windows & Linux, and hopefully more in the future!<br>
:bulb: Currently we are using OpenGL 4.6, but we support from OpenGL 3.3.<br>
:books: For how to get started [head over to the wiki](https://github.com/compvisia/Lila/wiki).<br>

## Installation

1. Clone or download this repository.<br>
	`git clone git@github.com:compvisia/Lila.git --recursive`<br>

2. Run premake5 (this repository already includes the binaries).<br>
	- Windows (vs2022)<br>
	   `"vendor/premake/premake5.exe vs2022"`
	- Linux (make)<br>
	   `vendor/premake/premake5 gmake2`<br>

3. Build with the generated files. (using vs2022, make, etc.)

4. To run the executable go to "bin/os-architecture/buildversion/Editor" and run the Editor program<br>
	  or just run the following command.<br>
	  `bin/linux-x86_64/Release/Editor/Editor` (linux example)


## Features

| Modules | Features |
|:-------:|----------|
|**Editor**|- Inspector<br>- Hierarchy<br>- Game viewport|
|**Math**|- Angles (degrees/radians)<br>- Vectors & matrices<br>- Transformations (translate, rotate scale)|
|**Rendering**|- Camera<br>- Windowing (window & input system)<br>- Rendering Context|
|**Misc**|- Custom data-driven [ecs](https://en.wikipedia.org/wiki/Entity_component_system)<br>- Logging<br>|

#### Planned
- Quaternions
- Identifying Computer specs (for debugging)
- Vulkan support
- Scripting
- Support multiple file formats
- Animation
- Audio
- Physics
- Worlds

## Libraries

| Library | Usage |
|--------|-----------|
|[Premake](https://premake.github.io/)|Build configuration tool|
|[Glfw](https://github.com/compvisia/glfw)|Window and input|
|[Glad](https://glad.dav1d.de/)|2D/3D Rendering|
|[Dear ImGui](https://github.com/compvisia/imgui)|User interface|
|[stb](https://github.com/nothings/stb)|Image loader|

## License

Currently we are under the [MIT License](https://mit-license.org/)
