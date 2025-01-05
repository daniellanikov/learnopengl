//
//  main.cpp
//  learnopengl
//
//  Created by Nikov Daniella on 2024. 11. 14..
//

#include "Window.h"
#include "Shader.h"
#include "Renderer.h"
#include <iostream>
#include "glsl.h"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    // Initialize the window
    Window window(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL");
    if (!window.init()) {
        std::cerr << "Failed to initialize window" << std::endl;
        return -1;
    }

    // Create and compile shaders
    GLSL glsl;
    Shader shader(glsl.vertexShaderSource, glsl.fragmentShaderSource1);
    if (!shader.isCompiled()) {
        return -1;
    }

    // Initialize renderer
    Renderer renderer;
    renderer.setup();

    // Main render loop
    while (!window.shouldClose()) {
        window.processInput();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Render
        renderer.render(shader);
        
        // Swap buffers and poll events
        window.swapBuffers();
    }

    return 0;
}
