//
//  Window.hpp
//  learnopengl
//
//  Created by Nikov Daniella on 2025. 01. 04..
//

// Window.h
#ifndef WINDOW_H
#define WINDOW_H

#include "pch.hpp"
#include <string>

class Window {
public:
    Window(unsigned int width, unsigned int height, const std::string& title);
    ~Window();

    bool init();
    bool shouldClose() const;
    void processInput() const;
    void swapBuffers();

private:
    GLFWwindow* m_window;
    unsigned int m_width;
    unsigned int m_height;
    std::string m_title;

    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
};

#endif
