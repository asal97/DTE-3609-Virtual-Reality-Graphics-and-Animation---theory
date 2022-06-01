#include "../include/Billboard.h"
#include <iostream>
#include "../Include/stb_image.h"
#include "../../glm-master/glm/gtc/matrix_transform.hpp"
#include "../../glm-master/glm/glm.hpp"
#include "../../glm-master/glm/gtc/type_ptr.hpp"

Billboard::Billboard()
{
    //rotate to sit on the landscape and scale to ideal size
 matrix_ = glm::scale(glm::mat4(1.0f),glm::vec3(10.0f,6.0f,2.0f)) * glm::translate(glm::mat4(1.0f),glm::vec3(0.0f,15.0f,0.0f));
}
Billboard::~Billboard()
{

}
void Billboard::privateInit()
{
    //drawing billboard with vertex array
    billboardArray_.push_back(glm::vec3(-size_,-size_,size_));
    billboardArray_.push_back(glm::vec3(size_,-size_,size_));
    billboardArray_.push_back(glm::vec3(size_,size_,size_));
    billboardArray_.push_back(glm::vec3(-size_,size_,size_));

    //setting normals
    billboardNormal_.push_back(glm::vec3(0.0f,0.0f,1.0f));
    billboardNormal_.push_back(glm::vec3(0.0f,0.0f,1.0f));
    billboardNormal_.push_back(glm::vec3(0.0f,0.0f,1.0f));
    billboardNormal_.push_back(glm::vec3(0.0f,0.0f,1.0f));

    //setting texture coordinates
    billboardTexture_.push_back(glm::vec2(0.0,1.0f));
     billboardTexture_.push_back(glm::vec2(1.0f,1.0f));
      billboardTexture_.push_back(glm::vec2(1.0f,0.0f));
    billboardTexture_.push_back(glm::vec2(0.0f,0.0f));

    DrawTexture();
}
void Billboard::privateRender()
{

    // only draws when the game is over!
    if(draw){


    glEnable(GL_NORMALIZE);

    glEnable(GL_TEXTURE_2D);

    //activate texture
    glBindTexture(GL_TEXTURE_2D,texture1);
    glTexCoordPointer(2,GL_FLOAT,0,billboardTexture_.data());
    glColor3f( 1.0f, 1.0f, 1.0f);

    glEnableClientState(GL_TEXTURE_COORD_ARRAY);


    //draw based on vertex array
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,billboardArray_.data());

    glDrawArrays(GL_QUADS,0,4);

    //reading and setting the normals
     glEnableClientState(GL_NORMAL_ARRAY);
     glNormalPointer(GL_FLOAT,0,billboardNormal_.data());


    // read and set the texture coordinates
     glDisableClientState(GL_TEXTURE_COORD_ARRAY);
     glBindTexture(GL_TEXTURE_2D,0);
     glDisableClientState(GL_VERTEX_ARRAY);
     glDisable(GL_TEXTURE_2D);


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
    unsigned char *data = stbi_load("D:/UIT/VG-3609/start_code/assets/gameover.png", &width, &height, &nrChannels, 0);

    // load and generate the texture
       if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
        glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}
void Billboard::privateUpdate(){}
