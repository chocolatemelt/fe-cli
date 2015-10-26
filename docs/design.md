Program Design
--------------

This is just a quick overview of how the program should work in relation to the user as well as what it should be displaying.

User Interface
--------------

Upon starting the program a splash screen with version number and credits should appear. Below the splash, there will be several menu items, including:

1. Play
2. View Maps
3. View Rosters
4. Options
5. Exit

Play will proceed to a screen where one can select a map and a roster, proceeding into the game.

Viewing maps and rosters does exactly as they say they do. In the case of View Rosters, player can also edit their roster with the exact same functionality as during a campaign in the game.

Options will include things like changing colors but not much else (this is only a terminal after all).

Upon entering a map with a roster, the player is then presented with the Battle Screen. The battle screen is composed of two panels; an information panel (essentially the bottom screen of the DS) and the map panel (essentially the top screen of the DS). Below is an example of the information panel. Players can use ```tab``` to switch panels, like most paneled curses applications.

```
+--------------------------------+
| Lucina (Olivia)                |
| Great Lord   | [P. Falchion]   |
| Lv20 | - exp | Ephraim's Lance |
| HP60 | 60    | Elixir 1/3      |
| ------------ | (none)          |
| STR 27 (+5)  | (none)          |
| MAG 21 (+1)  | --------------- |
| SKL 29 (+5)  | Galeforce       |
| SPD 31 (+4)  | Aether          |
| LCK 32       | Limit Breaker   |
| DEF 24 (+4)  | Dual Strike+    |
| RES 24       | Charm           |
| Sword A      |                 |
| Lance A      |                 |
| -------------+-----------------+
| Something agrees with me       |
| today. I must have at least    |
| twice my normal strength!      |
+--------------------------------+
```
In the map panel, background colors will differentiate between different tiles. Filled tiles are considered uncrossable terrain. When selecting a unit, blue signifies a potential movement option, red signifies potential attack options, and green signifies potential staff options. Other colors are in consideration for tiles that slope, "air" tiles, sparkling tiles, village tiles, and others.

Splash Screen
-------------

ASCII art logos are in ```dat/``` as ```logo_en.txt``` and ```logo_jp.txt```. Created by the ![DeGraeve tool](http://www.degraeve.com/img2txt.php) and edited afterward. Feel free to use it elsewhere; it's not exactly difficult to make.
