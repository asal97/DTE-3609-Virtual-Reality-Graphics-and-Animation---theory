#shader vertex
#version 330 core
layout(location = 0) in vec3 position;

out vec3 v_TexCoord;

uniform mat4 u_MVP;

void main(){

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
          FragColor = texture(u_Skybox,v_TexCoord);
};


