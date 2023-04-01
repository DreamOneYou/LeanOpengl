#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
    // 初始化GLFW
    glfwInit();

    // 创建窗口
    GLFWwindow* window = glfwCreateWindow(800, 600, "My OpenGL Window", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // 初始化GLAD
    gladLoadGL();

    // 使用OpenGL函数
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // 交换缓冲区
    glfwSwapBuffers(window);

    // 主循环
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
    }

    // 清理
    glfwTerminate();
    return 0;
}
