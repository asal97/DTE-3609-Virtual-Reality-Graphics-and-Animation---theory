#shader vertex
#version 330 core


layout(location = 0) in vec4 position;
layout (location = 1) in vec3 aNormal;
layout(location = 2) in vec2 texCoord;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


out vec3 Normal;
out vec3 LightPos;
out vec3 FragPos;
out vec2 v_TexCoord;


uniform vec4 lightPos;


void main()
{
        gl_Position = projection * view * model * position;
        Normal = aNormal;
        v_TexCoord = texCoord;
        LightPos = vec3(view * vec4(vec3(lightPos), 1.0));
        FragPos = vec3(view * model * position);
};


#shader fragment
#version 330 core
layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

//uniform vec4 u_Color;
uniform sampler2D u_Texture;
uniform sampler2D u_Texture2;

in vec3 FragPos;
in vec3 LightPos;
in vec3 Normal;


void main()
{
       vec4 texColor = mix(texture(u_Texture, v_TexCoord),texture(u_Texture2, v_TexCoord),0.5);

//        color = texColor;

        vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);
        // ambient
        vec3 material_ambient = vec3(1.0f, 0.5f, 0.31f);
        vec3 ambient = lightColor * material_ambient;

        // diffuse
        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(LightPos - FragPos);
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 material_diffuse = vec3(1.0f, 0.5f, 0.31f);
        vec3 diffuse = lightColor * (diff * material_diffuse);

//        // specular
        vec3 viewDir = normalize(- FragPos);
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0),32.0f);
        vec3 material_specular = vec3(0.5f, 0.5f, 0.5f);
        vec3 specular = lightColor * (spec * material_specular);

        vec3 result = ambient + diffuse + specular;
//        color = vec4(result, 1.0);

//       vec3 lightColor = vec3(1.0f, 1.0f, 1.0f);

//       float ambientStrength = 0.1;
//       vec3 ambient = ambientStrength * lightColor;

//       //Diffuse
//       vec3 norm = normalize(Normal);
//       vec3 lightDir = normalize(LightPos - FragPos);
//       float diff = max(dot(norm, lightDir), 0.0);
//       vec3 diffuse = diff * lightColor;

//       //Specular
//       float specularStrength = 0.5;
//       vec3 viewDir = normalize(-FragPos);
//       vec3 reflectDir = reflect(-lightDir, norm);
//       float spec = pow(max(dot(viewDir, reflectDir), 0.0), 2);
//       vec3 specular = specularStrength * spec * lightColor;

//       vec3 result = (ambient + diffuse + specular);

       color = mix(texColor, vec4(result, 1.0), 0.5);
};


