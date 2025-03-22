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
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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
    Shader shader(glsl.vertexShaderTexture, glsl.fragmentShaderTexture);
    if (!shader.isCompiled()) {
        return -1;
    }
    
    int width, height, nrChannels;
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);    // set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    unsigned char *data = stbi_load("/Users/nikovdaniella/Documents/projects/learnopengl/learnopengl/learnopengl/resources/textures/container.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        std::cout << "Texture loaded successfully: " << width << "x" << height << std::endl;
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture " << stbi_failure_reason() << std::endl;
    }
    stbi_image_free(data);
    
    // Initialize renderer
    Renderer renderer;
    renderer.setup();

    // Main render loop
    while (!window.shouldClose()) {
        window.processInput();

        glClearColor(0.06f, 0.02f, 0.04f, 0.2f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glBindTexture(GL_TEXTURE_2D, texture);
        // Render
        renderer.render(shader);
        
        // Swap buffers and poll events
        window.swapBuffers();
    }

    return 0;
}
