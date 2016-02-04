#pragma once

#include "System.h"

namespace JobManager {
	void initialize();
	void shutdown();
}

namespace Graphics {
  bool initialize(const String& title, int width, int height);
  void shutdown();
}
