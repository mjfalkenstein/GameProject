#include "Graphics.h"
#include "EngineInternals.h"
#include "GLFW/glfw3.h"

namespace Graphics {
static GLFWwindow* window = nullptr;
// TODO resource managers2

extern "C" {
void glfwError(int error, const char* description) {
  println("GLFW error: ", description);
}
}

bool initialize(const String& title, int width, int height) {
  // only initialize once
  if (window) return true;
  
  // try to initialize GLFW
  glfwSetErrorCallback(glfwError);
  if (!glfwInit()) return false;
  
  // try to create a window
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
  if (!window) { glfwTerminate(); return false; }

  // try to initialize OpenGL
  glfwMakeContextCurrent(window);
  // TODO initialize
  if (false) { shutdown(); return false; }
  
  // TODO set up callbacks
  return true;
}

void shutdown() {
  if (window) {
    // release graphics resources
    glfwDestroyWindow(window);
    glfwTerminate();
    window = nullptr;
  }
}

void Scene::addEntity(Entity* entity) {
  
}

void Scene::removeEntity(Entity* entity) {

}

Spritesheet* loadSpriteSheet(const String& filename, int tilesX, int tilesY) {
  return nullptr;
}

}
