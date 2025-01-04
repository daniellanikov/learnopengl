//
//  Shader.hpp
//  learnopengl
//
//  Created by Nikov Daniella on 2025. 01. 04..
//

#ifndef SHADER_H
#define SHADER_H

#include "pch.hpp"
#include <string>

class Shader {
public:
    Shader(const char* vertexShaderSource, const char* fragmentShaderSource);
    ~Shader();

    void use() const;
    bool isCompiled() const { return m_compiled; }

private:
    unsigned int m_ID;
    bool m_compiled;

    std::string loadShaderSource(const std::string& filepath) const;
    void compileShader(unsigned int shader, const char* source);
};

#endif
