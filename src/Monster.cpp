#include "../include/Monster.h"

Monster::Monster()
{
 float pos = 400.0f;
 matrix_ = glm::translate(glm::mat4(1.0f),glm::vec3(pos,tan(glm::radians(20.0f))*pos,0.0f)) * glm::rotate(matrix_,glm::radians(20.0f), glm::vec3(0.0f, 0.0f, 1.0f));
}
Monster::~Monster(){

}
void Monster::privateInit(){

    // below we initialize our shader, vertex array and vertex buffer to draw the monster with shader

    VertexBufferLayout layout;
      // position layout
    layout.Push<float>(3);
     // texture coordinate layout
    layout.Push<float>(2);
    va.AddBuffer(vb,layout);
    //setting the shader file
    shader.initShader("D:/UIT/VG-3609/start_code/include/basic.shader");
    shader.Bind();
    shader.SetUniform4f("u_Color",0.2f,0.3f,0.8f,1.0f);


    //activating texture
    texture.Bind(texSlot);
    shader.SetUniform1i("u_Texture", texSlot);
    projectionMatrix_ = glm::perspective(glm::radians(60.0f), 900.0f / 700.0f, 1.0f, 30000.0f);

    texture.Unbind();
    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();
}
void Monster::privateRender(){

    // blend to make a transparent monster
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    shader.Bind();
    texture.Bind(texSlot);


    shader.SetUniformMat4f("u_MVP",projectionMatrix_ * viewMatrix_* matrix_);

    vb.Bind();
    va.Bind();
    ib.Bind();
     //draw as quads
    GLCall(glDrawElements(GL_QUADS, ib.GetCount(), GL_UNSIGNED_INT, nullptr));


     shader.Unbind();
     va.Unbind();
     ib.Unbind();
     vb.Unbind();
     texture.Unbind();
     glDisable(GL_BLEND);
}
void Monster::privateUpdate(){
    // check if it reaches a certain point remove and translate it to make an endless effect
    score +=1;
    if(matrix_[3].x<-400){
        auto translate = glm::translate(glm::mat4(1.0f),glm::vec3(800.0f,0.0f,0.0f));
        matrix_ = matrix_ * translate;
    }
    //increase the speed of monsters moving every 300 score
    int speedScale = (score/300) + 1;
    auto translate = glm::translate(glm::mat4(1.0f),glm::vec3(speed - (speedScale*0.5f) ,0.0f,0.0f)) ;
    matrix_ = matrix_ * translate;
}
