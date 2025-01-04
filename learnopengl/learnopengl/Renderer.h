//
//  Renderer.h
//  learnopengl
//
//  Created by Nikov Daniella on 2025. 01. 04..
//

#ifndef RENDERER_H
#define RENDERER_H

#include "pch.hpp"
#include "Shader.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void setup();
    void render(const Shader& shader);

private:
    unsigned int VAO, VBO, EBO;
};

#endif
