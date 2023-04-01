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
    
    /*
        GL_COLOR_BUFFER_BIT：颜色缓冲区
        GL_DEPTH_BUFFER_BIT：深度缓冲区
        GL_STENCIL_BUFFER_BIT：模板缓冲区
    */
    // 交换缓冲区
    glfwSwapBuffers(window);

    // 主循环
    while (!glfwWindowShouldClose(window)) // 如果返回GLFW_TRUE，怎关闭窗口，如果返回GLFW_FALSE则不关闭窗口
    {
        glfwPollEvents(); // 处理窗口事件，如果不处理窗口事件，就会导致窗口无法相应用户输入等事件。
    }

    // 清理
    glfwTerminate(); // 用于关闭GLFW库，并释放所有资源。如果使用了glfwInit()而在最后没有glfwTerminate(),就会导致内存泄露问题。
    return 0;
}
