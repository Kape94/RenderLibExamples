#include "RenderLib/RenderLib.h"

#include "RenderLib/Buffer.h"
#include "RenderLib/Shader.h"

#include "Utils/Window.h"

int main() {
  Window win(1280, 1080);

  RenderLib::Initialize();

  const char* vShader = R"(
    #version 330

    layout (location = 0) in vec3 pos;
    layout (location = 1) in vec3 color;

    out vec3 vertexColor;

    void main() {
      gl_Position = vec4(pos, 1.0);
      vertexColor = color;
    }
  )";

  const char* fShader = R"(
    #version 330

    in vec3 vertexColor;

    out vec4 fragColor;

    void main() {
      fragColor = vec4(vertexColor, 1.0);
    }
  )";

  RenderLib::Shader shader;
  shader.Create(vShader, fShader);

  const float vertex[] = {
    0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
    1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f
  };
  const unsigned vertexDataSize = 18;

  RenderLib::Buffer buffer;
  buffer.Create(vertex, vertexDataSize,
    { {0/*position*/, 3/*nFloats*/},
      {1/*color*/, 3/*nFLoats*/} }
  );

  while (!win.ShouldClose()) {

    shader.Use();
    buffer.Render();

    win.Swap();
    win.PollEvents();
  }

  return 0;
}