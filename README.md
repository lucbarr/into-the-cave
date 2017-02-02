into the cave
-------------

This is yet a prototype of a roguelike-ish platormer game coded in C++ using SFML library for graphics.
As a result of game design suggestion from Naum Azeredo, this game's design and art came to be inspired by a 
game-development-jam-made game Roguelight and by Towerfall Ascencion. My goal with this is to have fun and to as
well develop and test my skills.

ok but how do I test it ?
-------------------------

I'm doing this in a linux environment, not sure how you would run it in another environment. For Windows, I'd
download the source code and set a IDE like Code::Blocks to link SFML library and to do its project compiling magic. Not sure if
works, haven't tested. You'll need any C++11 compiler such as clang-3.8 and, as before mentioned, SFML properly installed.
For Linux (and shouldn't be an issue in OS X as well), simply open the terminal, clone the repository, cd to it and run make:

        ~$ make

and then, after the build, run it:

        ~$ ./itc.out

as simple as that.
