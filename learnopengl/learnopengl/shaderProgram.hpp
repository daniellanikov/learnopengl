//
//  shaderProgram.hpp
//  learnopengl
//
//  Created by Nikov Daniella on 2025. 01. 04..
//

#ifndef shaderProgram_hpp
#define shaderProgram_hpp

#include "pch.hpp"
#include "shaders.hpp"

void test();

class ShaderProgram
{
    
public:
    
    unsigned int program1 = glCreateProgram();
    
    ShaderProgram()
    {
        struct Shaders shaders;

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &shaders.vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &shaders.fragmentShaderSource1, NULL);
        glCompileShader(fragmentShader);
        
        glAttachShader(program1, vertexShader);
        glAttachShader(program1, fragmentShader);
        glLinkProgram(program1);
        
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
         
    };
    
    
};

#endif /* shaderProgram_hpp */
