#shader vertex
#version 330 core
layout(location = 0) in vec3 position;

out vec3 v_TexCoord;

uniform mat4 u_MVP;

void main(){

    //setting position and sending texcoord through fragment
        v_TexCoord = position;
        gl_Position = u_MVP * vec4(position,1.0);
};


#shader fragment
#version 330 core

out vec4 FragColor;

in vec3 v_TexCoord;

uniform samplerCube u_Skybox;

void main()
{
    //setting up skybox with texture
          FragColor = texture(u_Skybox,v_TexCoord);
};


