//
//  Shader.cpp
//  learnopengl
//
//  Created by Nikov Daniella on 2025. 01. 04..
//

// Shader.cpp
#include "Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const char* vertexShaderSource, const char* fragmentShaderSource)
    : m_ID(0), m_compiled(true) {
    
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    compileShader(vertexShader, vertexShaderSource);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    compileShader(fragmentShader, fragmentShaderSource);

    m_ID = glCreateProgram();
    glAttachShader(m_ID, vertexShader);
    glAttachShader(m_ID, fragmentShader);
    glLinkProgram(m_ID);

    int success;
    char infoLog[512];
    glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(m_ID, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        m_compiled = false;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader() {
    glDeleteProgram(m_ID);
}

void Shader::use() const {
    glUseProgram(m_ID);
}

std::string Shader::loadShaderSource(const std::string& filepath) const {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " << filepath << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void Shader::compileShader(unsigned int shader, const char* source) {
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
        m_compiled = false;
    }
}
