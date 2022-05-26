
#include "../include/Character.hpp"

#include <iostream>
#include "../Include/stb_image.h"


static GLuint texName;
static GLint fogMode;

Character::Character()
{

}

Character::~Character()
{
}
void Character::privateInit()
{

    glShadeModel(GL_SMOOTH);

    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(2);
    va.AddBuffer(vb,layout);
    shader.initShader("D:/UIT/VG-3609/start_code/include/Basic.shader");
    shader.Bind();
    shader.SetUniform4f("u_Color",0.2f,0.3f,0.8f,1.0f);



    texture.Bind(texSlot);
    shader.SetUniform1i("u_Texture", texSlot);
    projectionMatrix_ = glm::perspective(glm::radians(60.0f), 900.0f / 700.0f, 1.0f, 30000.0f);

    texture.Unbind();
    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();






//    auto list_id = glGenLists(1);
//    glNewList(list_id,GL_COMPILE);
//        glBegin(GL_QUADS);
        //front


//                glNormal3f( -1.0f, -1.0f, 1.0f);glTexCoord2f(0.0f, 0.0f); glVertex3f(-size_, -size_,  size_);
//                glNormal3f( 1.0f, -1.0f, 1.0f);glTexCoord2f(1.0f, 0.0f); glVertex3f( size_, -size_,  size_);
//                glNormal3f( 1.0f, 1.0f, 1.0f);glTexCoord2f(1.0f, 1.0f); glVertex3f( size_,  size_,  size_);
//                glNormal3f( -1.0f, 1.0f, 1.0f);glTexCoord2f(0.0f, 1.0f);  glVertex3f( -size_,  size_,  size_);
//             //top

//                 glNormal3f( -1.0f, 1.0f, 1.0f);glTexCoord2f(0.0f, 0.0f); glVertex3f(-size_, size_,  size_);
//                 glNormal3f( 1.0f, 1.0f, 1.0f);glTexCoord2f(1.0f, 0.0f); glVertex3f( size_, size_,  size_);
//                 glNormal3f( 1.0f, 1.0f, -1.0f);glTexCoord2f(1.0f, 1.0f); glVertex3f( size_,  size_,  -size_);
//                 glNormal3f( -1.0f, 1.0f, -1.0f);glTexCoord2f(0.0f, 1.0f);  glVertex3f( -size_,  size_,  -size_);
//             //right

//                   glNormal3f( 1.0f, -1.0f, 1.0f);glTexCoord2f(0.0f, 0.0f); glVertex3f(size_, -size_,  size_);
//                   glNormal3f( 1.0f, -1.0f, -1.0f);glTexCoord2f(1.0f, 0.0f); glVertex3f( size_, -size_,  -size_);
//                   glNormal3f( 1.0f, 1.0f, -1.0f);glTexCoord2f(1.0f, 1.0f); glVertex3f( size_,  size_,  -size_);
//                   glNormal3f( 1.0f, 1.0f, 1.0f);glTexCoord2f(0.0f, 1.0f);  glVertex3f( size_,  size_,  size_);
//                //left

//                     glNormal3f( -1.0f, -1.0f, -1.0f);glTexCoord2f(0.0f, 0.0f); glVertex3f(-size_, -size_, -size_);
//                     glNormal3f( -1.0f, -1.0f, 1.0f);glTexCoord2f(1.0f, 0.0f); glVertex3f( -size_, -size_,  size_);
//                     glNormal3f( -1.0f, 1.0f, 1.0f);glTexCoord2f(1.0f, 1.0f); glVertex3f( -size_,  size_,  size_);
//                     glNormal3f( -1.0f, 1.0f, -1.0f);glTexCoord2f(0.0f, 1.0f);  glVertex3f( -size_,  size_,  -size_);
//                    //back

//                     glNormal3f( 1.0f, -1.0f, -1.0f);glTexCoord2f(0.0f, 0.0f); glVertex3f(size_, -size_,  -size_);
//                     glNormal3f( -1.0f, -1.0f, -1.0f);glTexCoord2f(1.0f, 0.0f); glVertex3f( -size_, -size_,  -size_);
//                     glNormal3f( -1.0f, 1.0f, -1.0f);glTexCoord2f(1.0f, 1.0f); glVertex3f( -size_,  size_,  -size_);
//                     glNormal3f( 1.0f, 1.0f, -1.0f);glTexCoord2f(0.0f, 1.0f);  glVertex3f( size_,  size_,  -size_);
//                 //buttom

//                     glNormal3f( -1.0f, -1.0f, -1.0f);glTexCoord2f(0.0f, 0.0f); glVertex3f(-size_, -size_,  -size_);
//                     glNormal3f( 1.0f, -1.0f, -1.0f);glTexCoord2f(1.0f, 0.0f); glVertex3f( size_, -size_,  -size_);
//                     glNormal3f( 1.0f, -1.0f, 1.0f);glTexCoord2f(1.0f, 1.0f); glVertex3f( size_,  -size_,  size_);
//                     glNormal3f( -1.0f, -1.0f, 1.0f);glTexCoord2f(0.0f, 1.0f);  glVertex3f( -size_, -size_,  size_);
//                 //back


//              glEnd();
//     glEndList();


//     auto But_left = glm::vec3(-size_-50,-size_-50,size_+50);
//     auto But_right = glm::vec3(size_+50,-size_-50,size_+50);
//     auto Top_right = glm::vec3(size_+50,  size_+50,  size_+50);
//     auto Top_left = glm::vec3( -size_-50,  size_+50,  size_+50);


//     auto back_top_right = glm::vec3( size_+50,  size_+50,  -size_-50);
//     auto back_top_left = glm::vec3( -size_-50,  size_+50,  -size_-50);
//     auto back_but_right = glm::vec3( size_+50,  -size_-50,  -size_-50);
//     auto back_but_left = glm::vec3( -size_-50,  -size_-50,  -size_-50);

//    auto list_id2 = glGenLists(2);
//     glNewList(list_id2,GL_COMPILE);
//         glBegin(GL_LINES);
//           // Near Face
//         //fron
//          glColor3f(1.0f, 1.0f, 1.0f);

//               glVertex3f(-size_,-size_,size_);glVertex3f(But_left.x, But_left.y, But_left.z);
//               glVertex3f(size_,-size_,size_);glVertex3f(But_right.x,But_right.y,But_right.z);
//               glVertex3f( size_,  size_,  size_);glVertex3f(Top_right.x,Top_right.y,Top_right.z);
//               glVertex3f( -size_,  size_,  size_);glVertex3f(Top_left.x,Top_left.y,Top_left.z);
//               glVertex3f( size_,  size_,  -size_);glVertex3f(back_top_right.x,back_top_right.y,back_top_right.z);
//               glVertex3f( -size_,  size_,  -size_);glVertex3f(back_top_left.x,back_top_left.y,back_top_left.z);
//               glVertex3f( size_,  -size_,  -size_);glVertex3f(back_but_right.x,back_but_right.y,back_but_right.z);
//               glVertex3f( -size_,  -size_,  -size_);glVertex3f(back_but_left.x,back_but_left.y,back_but_left.z);

//               glEnd();
//      glEndList();


DrawBillboard();
CreateTexture();
DrawTexture();

}


void Character::privateRender()
{

    shader.Bind();
    texture.Bind(texSlot);


    shader.SetUniformMat4f("u_MVP",projectionMatrix_ * viewMatrix_* matrix_);

    vb.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElements(GL_QUADS, ib.GetCount(), GL_UNSIGNED_INT, nullptr));




     shader.Unbind();
     va.Unbind();
     ib.Unbind();
     vb.Unbind();
     texture.Unbind();



    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    glEnable(GL_NORMALIZE);
//    glColor3f(0.0f, 1.0f, 0.0f);




//              glCallList(1);


//    glCallList(2);

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



}

void Character::DrawBillboard(){
    billboardArray_.push_back(glm::vec3(-2*size_,2*size_,size_));
    billboardArray_.push_back(glm::vec3(2*size_,2*size_,size_));
    billboardArray_.push_back(glm::vec3(2*size_,4*size_,size_));
    billboardArray_.push_back(glm::vec3(-2*size_,4*size_,size_));

    billboardNormal_.push_back(glm::vec3(0.0f,0.0f,1.0f));
    billboardNormal_.push_back(glm::vec3(0.0f,0.0f,1.0f));
    billboardNormal_.push_back(glm::vec3(0.0f,0.0f,1.0f));
    billboardNormal_.push_back(glm::vec3(0.0f,0.0f,1.0f));

}
void Character::CreateTexture(){

    billboardTexture_.push_back(glm::vec2(0.0,1.0f));
     billboardTexture_.push_back(glm::vec2(1.0f,1.0f));
      billboardTexture_.push_back(glm::vec2(1.0f,0.0f));
    billboardTexture_.push_back(glm::vec2(0.0f,0.0f));



}
void Character::DrawTexture(){


    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1);
    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    int width, height, nrChannels;
    unsigned char *data = stbi_load("D:/UIT/VG-3609/start_code/assets/Healthbar.png", &width, &height, &nrChannels, 0);

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
void Character::moveUpward()
{
    auto translate = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    matrix_ *= translate;
}
void Character::moveDownward()
{
      auto translate = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, -1.0f, 0.0f));
      matrix_ *= translate;
}
void Character::privateUpdate()
{
    matrix_ = glm::rotate(matrix_, 0.01f, glm::vec3(0.0f, 1.0f, 0.0f));
//    matrix_ = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f,0.0f,0.0f)) * glm::rotate(matrix_, 0.01f, glm::vec3(0.0f,1.0f,0.0f)) ;

}

