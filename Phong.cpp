#include "Phong.h"
#include<QTime>
void Phong::init()
{
    
    if (!gladLoadGL())
    {
        std::cout<<("glad init failed!");
        
    }
    
    phong_shader= new Shader("res/shaders/phong.vs", "res/shaders/phong.fs");
    phong_shader->use();
    camera = Camera(glm::vec3(0.0f, 0.0f, 5.0f));
    glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)width / (float)height, 0.1f, 100.0f);
    glm::mat4 view = camera.GetViewMatrix();
    glm::mat4 model = glm::mat4(1.0f);
    //glm::vec3 lightPos(1.0f, 4.0f, 5.0f);
    
    
    Texture texture_d(diffuse.c_str(),GL_REPEAT);
    Texture texture_n(normal.c_str(), GL_REPEAT);
    Texture texture_s(specular.c_str(), GL_REPEAT);
    texture_d.Bind(GL_TEXTURE0);
    texture_n.Bind(GL_TEXTURE1);
    texture_s.Bind(GL_TEXTURE2);
    char obj_path[] = "res/models/128_ball.obj";
    ball=new Model(obj_path);


    phong_shader->setInt("diffuseMap", 0);
    phong_shader->setInt("normalMap", 1);
    phong_shader->setInt("specularMap", 2);
    phong_shader->setVec3("viewPos", camera.Position);
    phong_shader->setMat4("model", model);
    phong_shader->setMat4("projection", projection);
    phong_shader->setMat4("view", view);
    glEnable(GL_DEPTH_TEST);

}

void Phong::paint()
{   
    float time = QTime::currentTime().msecsSinceStartOfDay();
    glm::vec3 lightPos(2.0*glm::cos(time/500), 1.0f, 2.0*glm::sin(time/500));
    phong_shader->use();
    phong_shader->setVec3("lightPos", lightPos);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ball->Draw();
}

Phong::Phong(std::string d, std::string n, std::string s, unsigned int width, unsigned int height):diffuse(d),normal(n),specular(s),width(width),height(height)
{
}

Phong::~Phong()
{
    delete ball;
    delete phong_shader;
}
