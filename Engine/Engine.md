The core engine has a pretty simple api.  It initializes all the other modules at startup, and cleans up resources when shut down.
It may also contain some utility functions and classes that arent tied to a single module

API:
void Engine::start() // initializes all modules of the engine
string Engine::getPlatform() // returns the name of the OS, or some Platform class
...

Internals:
an Engine class, with an initialize function (called by start) and a destructor which loads/releases resources
a static instance of Engine, hidden by the public API, initialized by start and cleanup handled by destructor
similar to singleton, but this pattern should be cleaner
