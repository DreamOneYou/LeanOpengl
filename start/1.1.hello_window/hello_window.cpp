#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    /*
        void glfwWindowHint(int hint, int value);
        其中，hint表示要设置的窗口属性，value表示属性的值。

        可以使用glfwWindowHint函数设置的窗口属性包括但不限于：

        GLFW_CONTEXT_VERSION_MAJOR：OpenGL上下文的主版本号
        GLFW_CONTEXT_VERSION_MINOR：OpenGL上下文的次版本号
        GLFW_OPENGL_PROFILE：OpenGL的配置文件
        GLFW_RESIZABLE：窗口是否可调整大小
        GLFW_VISIBLE：窗口是否可见
        GLFW_DECORATED：窗口是否带有装饰（如标题栏、边框等）
        GLFW_SAMPLES：多重采样的样本数
    */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    // GLFW_OPENGL_FORWARD_COMPAT: opengl是否支持向前兼容模式，在opengl 3.0及以上版本中，引入了一些不兼容opengl 2.x版本的新特性。这些新特性被称为
    // “向前兼容特性”，因为他们与旧版本opengl不兼容。如果启用向前兼容模式，怎opengl将不支持这些新特性，只支持与旧版本opengl兼容的特性。
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // 利用glfw创建一个窗口，并返回一个与之相关联的指针。如果创建失败，怎么指针返回null。
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); //将当前opengl上下文设置为我们刚才创建的窗口
    // 当窗口的针缓冲大小（窗口像素大小）发生变化是调用这个回调函数。
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); 

    // glad: 加载所有的opengl函数指针
    // 函数接受一个函数指针加载器函数作为参数，它可以加载系统特定的OpenGL函数指针。
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // 获取opengl函数指针，并指定其类型
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }    

    // 渲染
    // -----------
    while (!glfwWindowShouldClose(window))  // 判断当前这个窗口是否关闭。当用户尝试关闭窗口时，返回true，如果是false，怎表明程序继续执行
    {
        // input
        // -----
        processInput(window);

        // glfw: 交换缓冲区和poll IO 事件（按下/释放键、移动鼠标等）
        /*
            glfwSwapBuffers(window);
             交换窗口前后缓冲区内容。在opengl中，所有的绘制操作都是在后缓冲区进行的，而前缓冲区负责显示绘制结果。
             使用双缓冲技术，可以避免闪烁和其他视觉缺陷。这个函数可以把后缓冲区的内容复制到前缓冲区中。
        */
        glfwSwapBuffers(window); 
        glfwPollEvents(); // 通常在循环中调用这个函数。这个函数将检查窗口事件的队列并调用相应的回调函数，如键盘，鼠标和窗口大小变化等事件。
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();  // 与glfwInit()搭配，防止内存泄露。用于销毁opengl库所有资源并终止glfw库的运行。
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    /*
        glfwGetKey(GLFWwindow* window, int key)：用于检测指定窗口中的某个键是否被按下
        GLFW_KEY_ESCAPE:是键盘上的esc按键。
        GLFW_PRESS: 是glfw库中表示按键状态之一，表示某个按键被按下。
    */
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  // 当我们按下esc按键时，窗口就会被关闭
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    //确保视口与新的窗口尺寸相匹配； 请注意，宽度和高度将明显大于retina （苹果公司出的一种高分辨率技术）显示器上指定的值。

    glViewport(0, 0, width, height);
}
