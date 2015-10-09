fe-cli
------

FE:CLI puts the Fire Emblem tactical RPG gameplay in your terminal! Built for extensibility, flexibility, and faithfulness to the originals.
Read the docs for more information.

requirements
------------

 * CMake 2.8+
 * ncurses
 * a lot of terminal real estate

build & install
---------------

Make sure you have the latest ncurses development library and CMake 2.8 or higher.

```
$ git clone https://github.com/chocolatemelt/fe-cli.git
$ cd fe-cli
$ cmake .
$ make
```

It works on Windows! Proof:
![Cygwin](http://i.imgur.com/0NQXCBe.png)
As stated before, you only require the latest ncurses development library from Cygwin sources and CMake 2.8 or higher. [Babun](http://babun.github.io/) comes with ncurses so you can just run ```pact install cmake``` and you're good to go.

controls
--------

 * WASD - move
 * Arrow keys - move
 * Enter - select
 * Tab - open menu