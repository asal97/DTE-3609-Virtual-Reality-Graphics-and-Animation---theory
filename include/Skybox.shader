#shader vertex
#version 330 core
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 texCoord;

out vec3 v_TexCoord;

uniform mat4 u_MVP;

void main()
{
        gl_Position = u_MVP * vec4(position,1.0);
        v_TexCoord = position;
};


#shader fragment
#version 330 core
layout(location = 0) out vec4 color;
//out vec4 color;

in vec3 v_TexCoord;

uniform vec4 u_Color;
uniform samplerCube u_Skybox;

void main()
{
        vec4 texColor = texture(u_Skybox, v_TexCoord);
        color = u_Color;
};


