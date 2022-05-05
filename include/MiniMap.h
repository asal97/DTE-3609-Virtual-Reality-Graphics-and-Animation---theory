#pragma once

#include <windows.h>
#include <GL/glew.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "SceneObject.hpp"



class Minimap : public SceneObject
{
public:
    Minimap();
    ~Minimap();

protected:
    void privateInit();
    void privateRender();
    void privateUpdate();


private:
    GLuint g_fbo;				// frame buffer object
    GLuint g_pbo;				// pixel buffer object
    GLuint g_texture;			// texture object
    int g_iTexWidth  = 512;		// texture width
    int g_iTexHeight = 512;		// texture height

};


