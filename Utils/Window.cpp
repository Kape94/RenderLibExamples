#include "Window.h"

#include <GLFW/glfw3.h>

//---------------------------------------------------------------------------------------

Window::Window(
  const unsigned width,
  const unsigned height
)
{
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  
  this->window = glfwCreateWindow(width, height, "Example 1", nullptr, nullptr);

  glfwMakeContextCurrent(window);
}

//---------------------------------------------------------------------------------------

Window::~Window() {
  glfwDestroyWindow(window);
  glfwTerminate();
}

//---------------------------------------------------------------------------------------

bool Window::ShouldClose() const {
  return glfwWindowShouldClose(this->window);
}

//---------------------------------------------------------------------------------------

void Window::Swap() {
  glfwSwapBuffers(this->window);
}

//---------------------------------------------------------------------------------------

void Window::PollEvents() {
  glfwPollEvents();
}

//---------------------------------------------------------------------------------------
