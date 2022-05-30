#include "../include/Billboard.h"
#include <iostream>
#include "../Include/stb_image.h"
#include "../../glm-master/glm/gtc/matrix_transform.hpp"
#include "../../glm-master/glm/glm.hpp"
#include "../../glm-master/glm/gtc/type_ptr.hpp"

Billboard::Billboard()
{
 matrix_ = glm::scale(glm::mat4(1.0f),glm::vec3(5.0f,3.0f,2.0f)) * glm::translate(glm::mat4(1.0f),glm::vec3(5.0f,10.0f,0.0f));
}
Billboard::~Billboard()
{

}
void Billboard::privateInit()
{
    billboardArray_.push_back(glm::vec3(-size_,-size_,size_));
    billboardArray_.push_back(glm::vec3(size_,-size_,size_));
    billboardArray_.push_back(glm::vec3(size_,size_,size_));
    billboardArray_.push_back(glm::vec3(-size_,size_,size_));

    billboardNormal_.push_back(glm::vec3(0.0f,0.0f,1.0f));
    billboardNormal_.push_back(glm::vec3(0.0f,0.0f,1.0f));
    billboardNormal_.push_back(glm::vec3(0.0f,0.0f,1.0f));
    billboardNormal_.push_back(glm::vec3(0.0f,0.0f,1.0f));

    billboardTexture_.push_back(glm::vec2(0.0,1.0f));
     billboardTexture_.push_back(glm::vec2(1.0f,1.0f));
      billboardTexture_.push_back(glm::vec2(1.0f,0.0f));
    billboardTexture_.push_back(glm::vec2(0.0f,0.0f));

    DrawTexture();
}
void Billboard::privateRender()
{
    if(draw){
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glEnable(GL_NORMALIZE);

    glEnable(GL_TEXTURE_2D);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    glBindTexture(GL_TEXTURE_2D,texture1);
    glTexCoordPointer(2,GL_FLOAT,0,billboardTexture_.data());
    glColor3f( 1.0f, 1.0f, 1.0f);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);




    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,billboardArray_.data());

    glDrawArrays(GL_QUADS,0,4);

     glEnableClientState(GL_NORMAL_ARRAY);
     glNormalPointer(GL_FLOAT,0,billboardNormal_.data());



     glDisableClientState(GL_TEXTURE_COORD_ARRAY);
     glBindTexture(GL_TEXTURE_2D,0);
     glDisableClientState(GL_VERTEX_ARRAY);
     glDisable(GL_TEXTURE_2D);


   glDisable(GL_COLOR_MATERIAL);
   glDisable(GL_BLEND);
   }

}
void Billboard::DrawTexture(){


    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    int width, height, nrChannels;
     stbi_set_flip_vertically_on_load(0);
    unsigned char *data = stbi_load("D:/UIT/VG-3609/start_code/assets/gameover.jpg", &width, &height, &nrChannels, 0);

    // load and generate the texture
       if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
        glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}
void Billboard::privateUpdate(){}
