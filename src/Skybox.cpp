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
    layout.Push<float>(2);
    va.AddBuffer(vb,layout);
    shader.initShader("D:/UIT/VG-3609/start_code/include/Skybox.shader");
    shader.Bind();
    shader.SetUniform4f("u_Color",0.2f,0.3f,0.8f,1.0f);


    texture.BindCubeMap(texSlot);
    shader.SetUniform1i("u_Skybox", texSlot);
    projectionMatrix_ = glm::perspective(glm::radians(60.0f), 900.0f / 700.0f, 1.0f, 3000.0f);

    texture.Unbind();
    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();

}

void Skybox::privateRender(){

    glDepthMask(GL_FALSE);

    shader.Bind();
    texture.BindCubeMap(texSlot);
    shader.SetUniformMat4f("u_MVP",projectionMatrix_ * viewMatrix_* matrix_);

    vb.Bind();
    va.Bind();
    ib.Bind();
    GLCall(glDrawElements(GL_QUADS, ib.GetCount(), GL_UNSIGNED_INT, nullptr));

    glDepthMask(GL_TRUE);


    shader.Unbind();
    va.Unbind();
    ib.Unbind();
    vb.Unbind();
    texture.Unbind();


}

void Skybox::privateUpdate(){}
