

#include <iostream>
#include "EngineFramework/GraphEngine/Function/Shader.h"
#include "EngineFramework/GraphEngine/GraphEngine.h"

std::map<int,std::map<int,int>> m;
void func()
{
    std::map<int,int> m2;
    m2.insert(std::pair<int,int>(3,3));
    m.insert(std::pair<int,std::map<int,int>>(1,m2));
}
int main()
{
// glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//    // glfw window creation
//    // --------------------
//    GLFWwindow* window = glfwCreateWindow(1920, 500, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//
//    // glad: load all OpenGL function pointers
//    // ---------------------------------------
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    // render loop
//    // -----------
//    while (!glfwWindowShouldClose(window))
//    {
//        // input
//
//        // render
//        // ------
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
////        glfwPollEvents();
//    }
//
//    // glfw: terminate, clearing all previously allocated GLFW resources.
//    // ------------------------------------------------------------------
//    glfwTerminate();
//    return 0;
    GraphEngine::AddWindow();
    GraphEngine::RunWindows();
//    while (true)
//    {
//        glfwPollEvents();
//    }
//    while (true);
//    EngineSetting::RefreshEngineSetting();
//    GameObject obj;
//    engine.addObject(obj);
//    engine.run();
//    Shader shader("/Users/tandijie/MisThe/GameEngine/BaseCode/SystemDocuments/ShaderDocuments/test.shader","/Users/tandijie/MisThe/GameEngine/BaseCode/SystemDocuments/ShaderDocuments/test.shader");
//    int a;
//    std::cin >> a;
//    std::cout << a;
    return 0;
}