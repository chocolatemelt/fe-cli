Testing
=======

Testing is currently done via CMake's own CTest. There is only one test that handles everything, found in ```src/tests.cpp```.

The test simply prints ```1``` for passed tests and ```0``` for failed tests and CTest just checks that the only character printed is ```1```.

Future Considerations
=====================

We may want to move to a testing suite like GTests or CppUnit. Otherwise, we could also create seperated tests for CTest so we can identify where the tests go wrong (since currently it only tells us if the tests passed).

Open to suggestions.
