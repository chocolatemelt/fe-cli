Program Architecture
--------------------

The program's main goal is to be flexible, extensible, and faithful to the original games. As far as the last one goes, all of the mechanics in the games can be found on the internet, and shouldn't be a problem. For the former two, the program should ideally be able to read map files that load a map as well as saving a roster of characters to emulate the progression found in the original games. The program itself should not have anything remotely related to maps or the roster.

Key points:
  * A map handler that loads the required objects and events
  * A roster handler that loads the required objects and saves them (likely through some sort of diff)
  * A catch-all character class that can be used for both player characters and enemy characters, using various flags to differentiate the two
  * A generic calculator class that handles -all- calculations and rng

Folder Structure
----------------

```
root
 |-> docs  Documentation
 |-> lib   Generic libraries
 |-> src   Program source
 README
 TODO
```
