#pragma once
#include <windows.h>

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexBufferLayout.h"
#include "Shader.h"
#include "Texture.h"
#include <vector>

#include <GL/gl.h>
#include <GL/glu.h>
#include "SceneObject.hpp"

class Skybox : public SceneObject {
public:
    Skybox();


protected:
    void privateInit();
    void privateRender();
    void privateUpdate();

private:
    int indicesSize;
    float size;

    unsigned int indices[4*6] = {
        0,1,2,3,
        4,5,6,7,
        8,9,10,11,
        12,13,14,15,
        16,17,18,19,
        20,21,22,23,
//        24,25,26,27,
//        28,29,30,31,
//        32,33,34,35
    };

    float positions[(3+2)*4*6] = {
        // positions
        //east
        1.0f,  -1.0f, 1.0f,0.0f,0.0f,
        1.0f, 1.0f, 1.0f,1.0f,0.0f,
         1.0f, 1.0f, -1.0f,1.0f,1.0f,
         1.0f, -1.0f, -1.0f,0.0f,1.0f,
//         1.0f,  1.0f, -1.0f,
//        -1.0f,  1.0f, -1.0f,

        //west
        -1.0f, -1.0f,  -1.0f,0.0f,0.0f,
        -1.0f, 1.0f, -1.0f,1.0f,0.0f,
        -1.0f,  1.0f, 1.0f,1.0f,1.0f,
        -1.0f,  -1.0f, 1.0f,0.0f,1.0f,
//        -1.0f,  1.0f,  1.0f,
//        -1.0f, -1.0f,  1.0f,


    //top
         -1.0f, 1.0f, 1.0f,0.0f,0.0f,
         -1.0f, 1.0f,  -1.0f,1.0f,0.0f,
        1.0f, 1.0f,  -1.0f,1.0f,1.0f,
        1.0f, 1.0f,  1.0f,0.0f,1.0f,

//         1.0f,  1.0f, -1.0f,
//         1.0f, -1.0f, -1.0f,

        //down
        -1.0f,-1.0f,-1.0f,0.0f,0.0f,
        -1.0f,-1.0f,1.0f,1.0f,0.0f,
        1.0f,-1.0f,1.0f,1.0f,1.0f,
        1.0f,-1.0f,-1.0f,0.0f,1.0f,


/*        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,*/
//south
        -1.0f,-1.0f,1.0f,0.0f,0.0f,
        -1.0f,1.0f,1.0f,1.0f,0.0f,
        1.0f,1.0f,1.0f,1.0f,1.0f,
        1.0f,-1.0f,1.0f,0.0f,1.0f,

//        -1.0f,  1.0f, -1.0f,
//         1.0f,  1.0f, -1.0f,
//         1.0f,  1.0f,  1.0f,
//         1.0f,  1.0f,  1.0f,
//        -1.0f,  1.0f,  1.0f,
//        -1.0f,  1.0f, -1.0f,
        //north
        1.0f,-1.0f,-1.0f,0.0f,0.0f,
        1.0f,1.0f,-1.0f,1.0f,0.0f,
        -1.0f,1.0f,-1.0f,1.0f,1.0f,
        -1.0f,-1.0f,-1.0f,0.0f,1.0f,

//        -1.0f, -1.0f, -1.0f,
//        -1.0f, -1.0f,  1.0f,
//         1.0f, -1.0f, -1.0f,
//         1.0f, -1.0f, -1.0f,
//        -1.0f, -1.0f,  1.0f,
//         1.0f, -1.0f,  1.0f
    };


    //Buffer objects
    GLuint vertexbuffer, VAO, mapTexture;

    VertexArray va;
    VertexBuffer vb = VertexBuffer(positions, (3+2)*4*6 * sizeof(float));;
    VertexBufferLayout layout;
    IndexBuffer ib = IndexBuffer(indices, 4*6);
    Shader shader;
    unsigned int texSlot = 0;
    std::vector<std::string> faces{
        //Space WORKS, Original texture was made for being OUTSIDE the box not inside
        "D:/UIT/VG-3609/start_code/assets/Skybox/skybox_east.bmp",
        "D:/UIT/VG-3609/start_code/assets/Skybox/skybox_west.bmp",
        "D:/UIT/VG-3609/start_code/assets/Skybox/skybox_up.bmp",
        "D:/UIT/VG-3609/start_code/assets/Skybox/skybox_down.bmp",
        "D:/UIT/VG-3609/start_code/assets/Skybox/skybox_south.bmp",
        "D:/UIT/VG-3609/start_code/assets/Skybox/skybox_north.bmp"
    };
    Texture texture = Texture(faces);
};

