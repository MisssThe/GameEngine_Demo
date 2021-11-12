cmake_minimum_required(VERSION 3.20)
project (GameEngine)

set(CMAKE_CXX_STANDARD 14)

set(GLEW_H /usr/local/Cellar/glew/2.2.0_1/include/GL)
set(GLFW_H /usr/local/Cellar/glfw/3.3.4/include/GLFW)
set(GLAD_H //usr/local/Cellar/glad/include/glad)
set(KH_H /usr/local/Cellar/glad/include/KHR)
set(JSON_H /usr/local/Cellar/jsoncpp/1.9.4_1/include/json)
set(ASSIMP_H /usr/local/Cellar/assimp/5.0.1/include)
set(GLM_H /usr/local/Cellar/glm/0.9.9.8/include)
set(IMAGE_H /usr/local/Cellar/stb_image/include)
include_directories(${GLEW_H} ${GLFW_H} ${GLAD_H} ${KH_H} ${JSON_H} ${ASSIMP_H} ${GLM_H} ${IMAGE_H})

set(GLEW_LINK /usr/local/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.0.dylib)
set(GLFW_LINK /usr/local/Cellar/glfw/3.3.4/lib/libglfw.3.3.dylib)
set(JSON_LINK /usr/local/Cellar/jsoncpp/1.9.4_1/lib/libjsoncpp.24.dylib)
link_libraries(${OPENGL} ${GLFW_LINK} ${GLEW_LINK} ${JSON_LINK})

add_executable(GameEngine ../BaseCode/main.cpp ../BaseCode/glad.c ../BaseCode/CommonUtils/GameEngine2D.cpp ../BaseCode/CommonUtils/GameEngine2D.h ../BaseCode/EngineFramework/Engine.cpp ../BaseCode/EngineFramework/Engine.h ../BaseCode/EngineFramework/EngineSetting.cpp ../BaseCode/EngineFramework/EngineSetting.h ../BaseCode/CommonUtils/CommonUtils.cpp ../BaseCode/CommonUtils/CommonUtils.h ../BaseCode/EngineFramework/GraphEngine/Function/BaseRender.cpp ../BaseCode/EngineFramework/GraphEngine/Function/BaseRender.h ../BaseCode/Components/Component.h ../BaseCode/Components/GameObject.cpp ../BaseCode/Components/GameObject.h ../BaseCode/CommonUtils/Time.cpp ../BaseCode/CommonUtils/Time.h ../BaseCode/CommonUtils/GameLog.cpp ../BaseCode/CommonUtils/GameLog.h ../BaseCode/CommonUtils/ClassFactory.cpp ../BaseCode/CommonUtils/ClassFactory.h ../BaseCode/EngineFramework/GraphEngine/Function/Material.h ../BaseCode/EngineFramework/GraphEngine/Function/Shader.h ../BaseCode/EngineFramework/GraphEngine/Function/Model.h ../BaseCode/EngineFramework/GraphEngine/Function/Texture.h ../BaseCode/EngineFramework/RenderPipeline.h ../BaseCode/EngineFramework/GraphEngine/GraphEngine.cpp ../BaseCode/EngineFramework/GraphEngine/GraphEngine.h ../BaseCode/Components/Mesh/MeshFilter.cpp ../BaseCode/Components/Mesh/MeshFilter.h ../BaseCode/EngineFramework/GraphEngine/Function/Material.cpp ../BaseCode/scene.cpp)

if (APPLE)
    target_link_libraries(GameEngine "-framework OpenGL")
    target_link_libraries(GameEngine "-framework GLUT")
endif()