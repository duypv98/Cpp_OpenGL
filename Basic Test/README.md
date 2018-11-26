# Set up OPEN GL on MS Visual Studio 2017

* Download glut library and copy *.h file to C:\Program Files(x86)\Windows Kit\..\Include\um\gl, *.lib file to C:\Program Files(x86)\Windows Kit\..\Lib\um\gl and *.dll file to C:\Windows\System32
* Create a Project C++, Console Application type
* Configuring "pch.h" file
* Function:
  * Init(): Initiating the initial selection for the graphical environment
  * ReShape(): Setting the view mode for the graphical environment
  * RenderScene(): Creating graphical objects