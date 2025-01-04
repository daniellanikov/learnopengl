//
//  vertices.hpp
//  learnopengl
//
//  Created by Nikov Daniella on 2025. 01. 04..
//

#ifndef vertices_hpp
#define vertices_hpp

struct Vertices
{
    
public:
    
    float vertices[9] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };
    
    float vertices2[9] = {
         0.0f, -0.5f, 0.0f,
         1.0f, -0.5f, 0.0f,
         0.5f,  0.5f, 0.0f
    };
    
    float vertices3[9] = {
        -1.0f, -0.5f, 0.0f,
         0.0f, -0.5f, 0.0f,
        -0.5f,  0.5f, 0.0f,
    };
    
    float vertices_rectangle[12] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left
    };
    
    unsigned int indices[6] = {
         0, 1, 3,   // first triangle
         1, 2, 3    // second triangle
    };
    
};

#endif /* vertices_hpp */
