//
//  Window.cpp
//  learnopengl
//
//  Created by Nikov Daniella on 2025. 01. 04..
//

// Window.cpp
#include "Window.h"
#include <iostream>

Window::Window(unsigned int width, unsigned int height, const std::string& title)
    : m_width(width), m_height(height), m_title(title), m_window(nullptr) {}

Window::~Window() {
    if (m_window) {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
}

bool Window::init() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
    if (!m_window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(m_window);
    glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    return true;
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(m_window);
}

void Window::processInput() const {
    if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(m_window, true);
}

void Window::swapBuffers() {
    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
