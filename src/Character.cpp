
#include "../include/Character.hpp"

#include <iostream>
#include "../Include/stb_image.h"


static GLuint texName;
static GLint fogMode;

Character::Character()
{
    //getting the projection matrix to send into shader to draw the character
    projectionMatrix_ = glm::perspective(glm::radians(60.0f), 900.0f / 700.0f, 1.0f, 30000.0f);
    //rotating the charactre so it would lay on landscape
    matrix_ = glm::rotate(matrix_,glm::radians(20.0f), glm::vec3(0.0f, 0.0f, 1.0f));
}

Character::~Character()
{
}
void Character::privateInit()
{

    // below we initialize our shader, vertex array and vertex buffer to draw the character with shader

    glShadeModel(GL_SMOOTH);

    VertexBufferLayout layout;
    // position layout
    layout.Push<float>(3);
    // normal layout
    layout.Push<float>(3);
    // texture coordinate layout
    layout.Push<float>(2);
    va.AddBuffer(vb,layout);
    shader.initShader("D:/UIT/VG-3609/start_code/include/Character.shader");
    shader.Bind();



    texture.Bind(texSlot);
    shader.SetUniform1i("u_Texture", texSlot);


    texture.Unbind();
    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();


}


void Character::privateRender()
{
    //drawing the character with shaders

    shader.Bind();
    texture.Bind(texSlot);

   // sending in model, view and projection matrix and the light position for character
    shader.SetUniformMat4f("model",matrix_);
    shader.SetUniformMat4f("view",viewMatrix_);
    shader.SetUniformMat4f("projection",projectionMatrix_);
    shader.SetUniform4f("lightPos",100.0f,200.0f,300.0f,0.0);

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

    glDisable(GL_COLOR_MATERIAL);

}


void Character::moveUpward()
{
  // activates when user press j and checks if is not already in the jump state and not colliding it will jump
    if(colState_ == state::notColided && jumpState_ == Jstate::notJump)
    {
        //change the state to jump and set a velocity to jump
        jumpState_ = Jstate::jump;
        velocity_.y = 5.0f;
    }
}
void Character::privateUpdate()
{
    if(jumpState_ == Jstate::jump)
    {
        //checks if the cube had reached the landscape so it wouldn't keep going down
        if(count>=1&& position_.y >= getPos().y)
        {
            jumpState_ = Jstate::notJump;
            count =0;
        }
        //moves the character with gravity and velocity
        else{
        velocity_ = velocity_ +  gravity_;
        if (velocity_.y !=0.0f){
            matrix_ = glm::translate(matrix_, velocity_);
            count += 1;
        }
        }
    }
//keeps rotating throughout the game
    matrix_ = glm::rotate(matrix_, 0.007f, glm::vec3(0.0f, 1.0f, 0.0f));

}

