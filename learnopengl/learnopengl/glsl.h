//
//  shaders.hpp
//  learnopengl
//
//  Created by Nikov Daniella on 2025. 01. 04..
//

#ifndef shaders_hpp
#define shaders_hpp

struct GLSL
{
    
public:
    
    //-------------------------------Vertex Shader Sources-------------------------------
    const char *vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";
    
    const char *vertexShaderSourceColored = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "out vec4 vertexColor;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "   vertexColor = vec4(0.5, 0.0, 0.0, 1.0);\n"
        "}\0";
    
    const char *vertexShaderSourceColorAttribute = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "layout (location = 1) in vec3 aColor;\n"
        "out vec3 ourColor;\n"
        "uniform vec3 offset;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x + offset.x, aPos.y * -1, aPos.z, 1.0);\n"
        "   ourColor = aColor;\n"
        "}\0";
    
    //-------------------------------Fragment Shader Sources-------------------------------
    const char *fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
        "}\n\0";
    
    const char *fragmentShaderSourceVertexInput = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "in vec4 vertexColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vertexColor;\n"
        "}\n\0";
    
    const char *fragmentShaderSourceUniformInput = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "uniform vec4 ourColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = ourColor;\n"
        "}\n\0";
    
    const char *fragmentShaderSourceVertexInput2 = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "in vec3 ourColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(ourColor, 1.0);\n"
        "}\n\0";
};

#endif /* shaders_hpp */
