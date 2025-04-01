#version 330 core
in vec2 TexCoords;
in vec3 FragPos;
in vec3 TangentLightPos;
in vec3 TangentViewPos;
in vec3 TangentFragPos;
out vec4 FragColor;
uniform sampler2D normalMap;
uniform sampler2D floorTexture;
uniform sampler2D specularMap;
uniform samplerCube depthMap;
uniform vec3 lightPos;
uniform vec3 viewPos;
uniform bool blinn;

uniform float far_plane;

float ShadowCalculation(vec3 fragPos)
{
    
       
    vec3 fragToLight = fragPos - lightPos; 
    float closestDepth = texture(depthMap, fragToLight).r;
    closestDepth *= far_plane;
    float currentDepth = length(fragToLight);
    float bias = 0.2; 
    float shadow = currentDepth -  bias > closestDepth ? 1.0 : 0.0;

    return shadow;
}

float showdepth(vec3 fragPos)
{
    vec3 fragToLight = fragPos - lightPos; 
    float closestDepth = texture(depthMap, fragToLight).r;
    closestDepth *= far_plane;
    return closestDepth;
}

void main()
{   vec3 lightColor = vec3(0.5);
    vec3 color = texture(floorTexture, TexCoords).rgb;
    // ambient
    vec3 ambient = 0.3 * lightColor;
    // diffuse
    vec3 normal = texture(normalMap, TexCoords).rgb;
    normal = normalize(normal * 2.0 - 1.0);
    vec3 lightDir = normalize(TangentLightPos - TangentFragPos);
    float diff = max(dot(lightDir, normal), 0.0);
    vec3 diffuse = diff * lightColor;
    //vec3 diffuse = diff * color;
    // specular
    vec3 viewDir = normalize(TangentViewPos -TangentFragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    float spec = 0.0;
    if(blinn)
    {
        vec3 halfwayDir = normalize(lightDir + viewDir);  
        spec = pow(max(dot(normal, halfwayDir), 0.0), 64.0);
    }
    else
    {
        vec3 reflectDir = reflect(-lightDir, normal);
        spec = pow(max(dot(viewDir, reflectDir), 0.0), 16.0);
    }
    vec3 specular = spec * lightColor*texture(specularMap, TexCoords).r;// assuming bright white light color
    // º∆À„“ı”∞
    float shadow = ShadowCalculation(FragPos);       
    vec3 lighting = (ambient + (1.0 - shadow) * (diffuse + specular)) * color;    
    FragColor = vec4(lighting, 1.0f);

}
