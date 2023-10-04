#ifndef UTILS_H
#define UTILS_H

class GLFWwindow;

class Window {
  public:

    Window(
      const unsigned width,
      const unsigned height,
      const char* windowName
    );

    ~Window();

    bool ShouldClose() const;

    void Swap();

    void PollEvents();

  private:

    GLFWwindow* window = nullptr;
};

#endif