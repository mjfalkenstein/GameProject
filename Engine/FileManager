FileManager handles loading and writing files

API:
FileManager::Read(String filename, Buffer buffer) // reads a file into buffer, expanding it if necessary
FileManager::Write(Buffer buffer, String filename) // writes buffer to a file
FileManager::ReadAsync(String filename, function(Buffer) callback) // reads a file asynchronously, expanding it if necessary, then calling the callback function when complete
FileManager::WriteAsync(Buffer buffer, String filename, function() callback) // writes a file asynchronously, then calls the callback
FileManager::AwaitAsync() // Waits until the async files are written

Internals:
Starts an IO thread when initialized by Engine
Has an internal queue of io requests used by async, done in order. Some sorting could be done to do smallest first or something
This could be expanded to work with sockets and not just files if multiplayer is ever added
