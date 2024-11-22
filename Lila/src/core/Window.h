#pragma

#include "platform/types.h"

#include <glfw/glfw3.h>

namespace Lila {

class Window {
public:
    Window(str name, u32 width, u32 height);
    ~Window();

    void destroy();

    GLFWwindow* getPointer();
private:
    void create();

private:
    GLFWwindow* windowPtr_m;
    str name_m;
    u32 width_m, height_m;
    b8 fullscreen_m, maximized_m;
    GLFWmonitor* monitor_m;
    GLFWvidmode vidmode_m;
};


} // namespace Lila
