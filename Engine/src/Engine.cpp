#include "Engine.h"
#include "EngineInternals.h"

namespace Engine {
static struct Engine {
  ~Engine() {
    println("Stopping Engine...");
//  EventManager::shutdown();
    JobManager::shutdown();
    Graphics::shutdown();
  }
  void startup(const String& title, int width, int height) {
    println("Starting Engine...");
    Graphics::initialize(title, width, height);
    JobManager::initialize();
//  EventManager::initialize(); TODO this and others
  }
} instance;

void initialize(const String& title, int width, int height) {
  instance.startup(title, width, height);
}

}
