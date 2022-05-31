
#include "../include/Character.hpp"

#include <iostream>
#include "../Include/stb_image.h"


static GLuint texName;
static GLint fogMode;

Character::Character()
{
    projectionMatrix_ = glm::perspective(glm::radians(60.0f), 900.0f / 700.0f, 1.0f, 30000.0f);
    matrix_ = glm::rotate(matrix_,glm::radians(15.0f), glm::vec3(0.0f, 0.0f, 1.0f));
}

Character::~Character()
{
}
void Character::privateInit()
{

    glShadeModel(GL_SMOOTH);

    VertexBufferLayout layout;
    layout.Push<float>(3);
    layout.Push<float>(3);
    layout.Push<float>(2);
    va.AddBuffer(vb,layout);
    shader.initShader("D:/UIT/VG-3609/start_code/include/Character.shader");
    shader.Bind();
//    shader.SetUniform4f("u_Color",0.2f,0.3f,0.8f,1.0f);


    texture.Bind(texSlot);
    shader.SetUniform1i("u_Texture", texSlot);


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



}


void Character::privateRender()
{
//    if(state_ == state::jump){
//        update
//    }

    shader.Bind();
    texture.Bind(texSlot);


    shader.SetUniformMat4f("model",matrix_);
    shader.SetUniformMat4f("view",viewMatrix_);
    shader.SetUniformMat4f("projection",projectionMatrix_);
    shader.SetUniform4f("lightPos",100.0f,200.0f,300.0f,0.0);
//    shader.SetUniformMat4f("u_MVP",projectionMatrix_ * viewMatrix_* matrix_);

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

//     glEnable(GL_TEXTURE_2D);
//     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


//     glBindTexture(GL_TEXTURE_2D,texture1);
//     glTexCoordPointer(2,GL_FLOAT,0,billboardTexture_.data());
//     glColor3f( 1.0f, 1.0f, 1.0f);

//     glEnableClientState(GL_TEXTURE_COORD_ARRAY);




//     glEnableClientState(GL_VERTEX_ARRAY);
//     glVertexPointer(3,GL_FLOAT,0,billboardArray_.data());

//     glDrawArrays(GL_QUADS,0,4);

//      glEnableClientState(GL_NORMAL_ARRAY);
//      glNormalPointer(GL_FLOAT,0,billboardNormal_.data());



//      glDisableClientState(GL_TEXTURE_COORD_ARRAY);
//      glBindTexture(GL_TEXTURE_2D,0);
//      glDisableClientState(GL_VERTEX_ARRAY);
//      glDisable(GL_TEXTURE_2D);


    glDisable(GL_COLOR_MATERIAL);

}


void Character::moveUpward()
{

    if(colState_ == state::notColided && jumpState_ == Jstate::notJump)
    {
        jumpState_ = Jstate::jump;
        velocity_.y = 5.0f;
    }
}
void Character::privateUpdate()
{
    if(jumpState_ == Jstate::jump)
    {
        if(count>=1&& position_.y >= getPos().y)
        {
            jumpState_ = Jstate::notJump;
            count =0;
        }
        else{
        velocity_ = velocity_ +  gravity_;
        if (velocity_.y !=0.0f){
            matrix_ = glm::translate(matrix_, velocity_);
            count += 1;
        }
        }
    }

    matrix_ = glm::rotate(matrix_, 0.007f, glm::vec3(0.0f, 1.0f, 0.0f));

}

