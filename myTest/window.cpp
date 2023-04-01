#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
    // 初始化GLFW
    glfwInit();

    // 创建窗口
    /*
        GLFWwindow* glfwCreateWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
        width和height：分别表示窗口的宽度和高度，以像素为单位。
        title：一个字符串，表示窗口的标题。
        monitor：一个指向GLFWmonitor结构体的指针，表示将窗口创建在哪个显示器上。如果为NULL，则表示将窗口创建在主显示器上。
        share：一个指向另一个GLFWwindow结构体的指针，表示将窗口与该窗口共享资源。如果为NULL，则表示不与其他窗口共享资源。
        调用该函数后，将创建一个窗口，并返回一个指向该窗口的指针。开发者可以使用该指针来操作该窗口，例如设置窗口大小、位置、处理窗口事件等。
    */
    GLFWwindow* window = glfwCreateWindow(800, 600, "My OpenGL Window", nullptr, nullptr);
    /*
    glfwMakeContextCurrent(window):调用该函数后，指定的窗口上下文将被设置为当前上下文，即后续的OpenGL函数调用将作用于该窗口上下文。
    */
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
