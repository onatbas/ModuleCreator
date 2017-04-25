## ModuleEditor
----------------

This is a CMake project creator that's designed to create reusable cmake-based
libraries. The project templates will include a base supporting bdd tests 
with cucumber, and unit tests with gtest/gmock, which is executed my ctest.


Steps to install: 

1. Make sure the libraries/dependencies can be found via CMake. 
	See `cmake/` for list. The dependencies for the tool are required. The rest (which is for the actual development) are optional, feel free to ignore them. You're free to ignore the required dependencies to build the tool (Qt for example) when you're developing your own thing.
2. Create a bin folder. For ease of use, I'll say under the source folder.
	`mkdir bin`
	`cd bin`
3. Build the project files.
	`cmake ..`
4. Compile
	`cmake --build .`
5. Copy the contents of the materials folder into bin.
	`cp ../materials/* .`

And that's it. You may use the ModuleCreator to create new cmake projects with a GUI.

This might be an overkill for some people to use a cmake-build GUI tool to generate cmake projects, but that's what saves me some time building all that cmakelist files and setting up test suite and etc. 
