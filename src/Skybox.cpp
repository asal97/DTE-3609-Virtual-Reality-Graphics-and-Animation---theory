#include "../include/Skybox.h"
#include "../include/stb_image.h"

#include "../../glm-master/glm/gtc/matrix_transform.hpp"
#include "../../glm-master/glm/gtx/string_cast.hpp"

#include <iostream>
#include <filesystem>

Skybox::Skybox(){
    auto scale = glm::scale(glm::mat4(1.0f),glm::vec3(1000.0f,1000.0f,1000.0f));
    matrix_ = scale;
}


void Skybox::privateInit(){

    VertexBufferLayout layout;
    layout.Push<float>(3);
    va.AddBuffer(vb,layout);
    shader.initShader("D:/UIT/VG-3609/start_code/include/Skybox.shader");
    shader.Bind();
    shader.SetUniform4f("u_Color",0.2f,0.3f,0.8f,1.0f);


    texture.BindCubeMap();
//    shader.SetUniform1i("u_Skybox", 0);
    projectionMatrix_ = glm::perspective(glm::radians(60.0f), 900.0f / 700.0f, 1.0f, 3000.0f);

    texture.UnbindCubeMap();
    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();

}

void Skybox::privateRender(){

    glDepthMask(GL_FALSE);

    shader.Bind();
    shader.SetUniformMat4f("u_MVP",projectionMatrix_ * glm::mat4(glm::mat3(viewMatrix_))* matrix_);
    texture.BindCubeMap();
    vb.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));

    glDepthMask(GL_TRUE);


    shader.Unbind();
    va.Unbind();
    ib.Unbind();
    vb.Unbind();
    texture.UnbindCubeMap();


}

void Skybox::privateUpdate(){}
