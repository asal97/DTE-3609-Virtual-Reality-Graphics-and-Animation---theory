#include "../include/MiniMap.h"


#include "../include/stb_image.h"

Minimap::Minimap(){}
Minimap::~Minimap(){
    glDeleteFramebuffersEXT(1, &g_fbo);
    glDeleteBuffers(1, &g_pbo);
}
void Minimap::privateInit(){
    // Create FBO
        glGenFramebuffersEXT(1, &g_fbo);
        glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, g_fbo);

        // Initialize Texture
        glGenTextures(1, &g_texture);
        glBindTexture(GL_TEXTURE_2D, g_texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, g_iTexWidth, g_iTexHeight, 0, GL_BGRA, GL_UNSIGNED_BYTE, NULL);

        // Attach Texture to Framebuffer Color Buffer
        glFramebufferTexture2DEXT(GL_FRAMEBUFFER_EXT, GL_COLOR_ATTACHMENT0_EXT, GL_TEXTURE_2D, g_texture, 0);
}
void Minimap::privateRender(){


    // render to texture
    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, g_fbo);

    // Save State
    float fPrevColor[4];
    int iPrevPolygonMode[2];
    glGetIntegerv(GL_POLYGON_MODE, iPrevPolygonMode);
    glGetFloatv(GL_CURRENT_COLOR, fPrevColor);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0.683f, 0.113f, 0.234f);


    glColor4fv(fPrevColor);
    glPolygonMode(GL_FRONT, iPrevPolygonMode[0]);
    glPolygonMode(GL_BACK, iPrevPolygonMode[1]);

    glBindFramebufferEXT(GL_FRAMEBUFFER_EXT, 0);


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_texture);

    glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-500.0f, -100.0f, 100.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-300.0f, -100.0f, 100.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-300.0f, 100.0f, 100.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-500.0f, 100.0f,100.0f);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
void Minimap::privateUpdate(){

}
