SoundManager contains utility functions for loading and playing sounds.

API:
class Sound {
  sound data
  looping
  duration
  etc
  if we have stereo stuff, sound could be "moved" in 3d space
}

Sound SoundManager::LoadSound(String filename);
void SoundManager::PlaySound(Sound* sound);
void SoundManager::StopSound(Sound* sound);

Internals:
Backed by OpenAL or something similar.  All 3 functions add a command to a queue, and a dedicated sound thread will process them as they come.
