#undef GLFW_DLL
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>
#include <cmath>

#include "Libs/Shader.h"
#include "Libs/Window.h"
#include "Libs/Mesh.h"
#include "Libs/stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const GLint WIDTH = 800, HEIGHT = 600;
GLuint uniformModel = 0, uniformProjection = 0, uniformView = 0;

Window mainWindow;
std::vector<Mesh *> meshList;
std::vector<Shader *> shaderList;
std::vector<unsigned int> textures;

float yaw = -90.0f, pitch = 0.0f;

// Vertex Shader
static const char *vShader = "Shaders/shader.vert";

// Fragment Shader
static const char *fShader = "Shaders/shader.frag";

glm::vec3 lightColour = glm::vec3(1.0f, 1.0f, 1.0f);
glm::mat4 view(1.0f);
glm::mat4 projection;

unsigned int LoadTexture(const std::string &filePath);

void CreateShaders()
{
    Shader *shader1 = new Shader();
    shader1->CreateFromFiles(vShader, fShader);
    shaderList.push_back(shader1);
}

void CreateOBJ()
{
    bool loaded;
    Mesh *obj00 = new Mesh();
    loaded = obj00->CreateMeshFromOBJ("Models/cube.obj");
    if (loaded)
        meshList.push_back(obj00);

    /* Mesh *obj01 = new Mesh();
    loaded = obj01->CreateMeshFromOBJ("Models/snake.obj");
    if (loaded)
        meshList.push_back(obj01);

    Mesh *obj02 = new Mesh();
    loaded = obj02->CreateMeshFromOBJ("Models/horse.obj");
    if (loaded)
        meshList.push_back(obj02);

    Mesh *obj03 = new Mesh();
    loaded = obj03->CreateMeshFromOBJ("Models/kangaroo.obj");
    if (loaded)
        meshList.push_back(obj03);

    Mesh *obj04 = new Mesh();
    loaded = obj04->CreateMeshFromOBJ("Models/lizard.obj");
    if (loaded)
        meshList.push_back(obj04);

    Mesh *obj05 = new Mesh();
    loaded = obj05->CreateMeshFromOBJ("Models/sealino.obj");
    if (loaded)
        meshList.push_back(obj05); */

    Mesh *obj09 = new Mesh();
    loaded = obj09->CreateMeshFromOBJ("Models/armadillo.obj");
    if (loaded)
        meshList.push_back(obj09);

    Mesh *obj10 = new Mesh();
    loaded = obj10->CreateMeshFromOBJ("Models/penguin.obj");
    if (loaded)
        meshList.push_back(obj10);

    Mesh *obj11 = new Mesh();
    loaded = obj11->CreateMeshFromOBJ("Models/bird_toucan.obj");
    if (loaded)
        meshList.push_back(obj11);

    Mesh *obj12 = new Mesh();
    loaded = obj12->CreateMeshFromOBJ("Models/lamb.obj");
    if (loaded)
        meshList.push_back(obj12);

    Mesh *obj13 = new Mesh();
    loaded = obj13->CreateMeshFromOBJ("Models/hare.obj");
    if (loaded)
        meshList.push_back(obj13);

    Mesh *obj14 = new Mesh();
    loaded = obj14->CreateMeshFromOBJ("Models/limousin.obj");
    if (loaded)
        meshList.push_back(obj14);

    Mesh *obj15 = new Mesh();
    loaded = obj15->CreateMeshFromOBJ("Models/ibex.obj");
    if (loaded)
        meshList.push_back(obj15);

    /* Mesh *obj16 = new Mesh();
    loaded = obj16->CreateMeshFromOBJ("Models/wood_fence.obj");
    if (loaded)
        meshList.push_back(obj16);

    Mesh *obj06 = new Mesh();
    loaded = obj06->CreateMeshFromOBJ("Models/spider_monkey.obj");
    if (loaded)
        meshList.push_back(obj06);

    Mesh *obj07 = new Mesh();
    loaded = obj07->CreateMeshFromOBJ("Models/crocodile.obj");
    if (loaded)
        meshList.push_back(obj07);

    Mesh *obj08 = new Mesh();
    loaded = obj08->CreateMeshFromOBJ("Models/gray_wolf.obj");
    if (loaded)
        meshList.push_back(obj08); */
}

void CreateTextures()
{
    std::string texturePath;
    texturePath = "Textures/uvmap.png";
    textures.push_back(LoadTexture(texturePath));
    /* texturePath = "Textures/10050_RattleSnake_v04.jpg";
    textures.push_back(LoadTexture(texturePath));
    texturePath = "Textures/Horse_v01.jpg";
    textures.push_back(LoadTexture(texturePath));
    texturePath = "Textures/Kangaroo_diff.jpg";
    textures.push_back(LoadTexture(texturePath));

    texturePath = "Textures/12275_Lizars_Diffuse.jpg";
    textures.push_back(LoadTexture(texturePath));
    texturePath = "Textures/10041_sealion_v1_Diffuse.jpg";
    textures.push_back(LoadTexture(texturePath)); */

    texturePath = "Textures/10002_Armadillo_v1_Diffuse.jpg";
    textures.push_back(LoadTexture(texturePath));
    texturePath = "Textures/10033_Penguin_v1_Diffuse.jpg";
    textures.push_back(LoadTexture(texturePath));
    texturePath = "Textures/12260_Bird_Toucan_Diffuse.jpg";
    textures.push_back(LoadTexture(texturePath));
    texturePath = "Textures/12955_Lamb_diff.jpg";
    textures.push_back(LoadTexture(texturePath));
    texturePath = "Textures/12956_WhiteHare_diffuse.jpg";
    textures.push_back(LoadTexture(texturePath));
    texturePath = "Textures/13087_Limousin_Cattle_v2_diff.jpg";
    textures.push_back(LoadTexture(texturePath));
    texturePath = "Textures/13575_Ibex_diff.jpg";
    textures.push_back(LoadTexture(texturePath));
    /* texturePath = "Textures/Gothic_Wood_Fence_Pane_diffuse.jpg";
    textures.push_back(LoadTexture(texturePath));
    texturePath = "Textures/12958_Spider_Monkey_diff.jpg";
    textures.push_back(LoadTexture(texturePath));
    texturePath = "Textures/12262_Crocodile_diff.jpg";
    textures.push_back(LoadTexture(texturePath));
    texturePath = "Textures/10055_Gray_Wolf_Diffuse_v1.jpg";
    textures.push_back(LoadTexture(texturePath)); */
}

unsigned int LoadTexture(const std::string &filePath)
{
    // Generate texture ID
    unsigned int texture;
    glGenTextures(1, &texture);

    // Activate texture unit 0
    glActiveTexture(GL_TEXTURE0);

    // Bind the texture
    glBindTexture(GL_TEXTURE_2D, texture);

    // Set texture wrapping and filtering options
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Load image data from file
    int width, height, nrChannels;
    unsigned char *data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);

    if (data)
    {
        // Specify the format of the image data
        GLenum format = (nrChannels == 3) ? GL_RGB : GL_RGBA;

        // Upload the image data to the texture
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);

        // Generate mipmaps for the texture
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture: " << filePath << std::endl;
    }

    // Free the loaded image data
    stbi_image_free(data);

    return texture;
}

void RenderModelWithTexture(Mesh *model, unsigned int texture, const glm::vec3 &position, float s)
{
    glm::mat4 modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, position);
    modelMatrix = glm::rotate(modelMatrix, glm::radians(2.0f), glm::vec3(1.0f, 0.3f, 0.5f));
    modelMatrix = glm::scale(modelMatrix, glm::vec3(s, s, s));

    glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(modelMatrix));
    glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));

    // Bind texture
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);

    // Render the mesh
    model->RenderMesh();

    // Light
    glUniform3fv(shaderList[0]->GetUniformLocation("lightColour"), 1, (GLfloat *)&lightColour);
    model->RenderMesh();
}

void checkMouse()
{
    double xpos, ypos;
    glfwGetCursorPos(mainWindow.getWindow(), &xpos, &ypos);

    static float lastX = xpos;
    static float lastY = ypos;

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos;

    lastX = xpos;
    lastY = ypos;

    float sensitivity = 0.06f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw += xoffset;
    pitch += yoffset;

    pitch = glm::clamp(pitch, -89.0f, 89.0f);
}

int main()
{
    mainWindow = Window(WIDTH, HEIGHT, 3, 3);
    mainWindow.initialise();

    CreateShaders();
    CreateOBJ();
    CreateTextures();

    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 5.0f);
    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

    glm::vec3 cameraDirection = glm::normalize(cameraTarget - cameraPos);
    glm::vec3 cameraRight = glm::normalize(glm::cross(cameraDirection, up));
    glm::vec3 cameraUp = glm::normalize(glm::cross(cameraRight, cameraDirection));

    projection = glm::perspective(45.0f, (GLfloat)mainWindow.getBufferWidth() / (GLfloat)mainWindow.getBufferHeight(), 0.1f, 100.0f);
    // glm::mat4 projection = glm::ortho(-4.0f, 4.0f, -3.0f, 3.0f, 0.1f, 100.0f);

    float deltaTime, lastFrame;

    // Loop until window closed
    while (!mainWindow.getShouldClose())
    {
        // Get + Handle user input events
        glfwPollEvents();

        checkMouse();

        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        glm::vec3 direction;

        direction.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
        direction.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
        direction.y = sin(glm::radians(pitch));

        if (glfwGetKey(mainWindow.getWindow(), GLFW_KEY_W) == GLFW_PRESS)
        {
            cameraPos += cameraDirection * deltaTime * 5.0f;
        }
        if (glfwGetKey(mainWindow.getWindow(), GLFW_KEY_S) == GLFW_PRESS)
        {
            cameraPos -= cameraDirection * deltaTime * 5.0f;
        }
        if (glfwGetKey(mainWindow.getWindow(), GLFW_KEY_A) == GLFW_PRESS)
        {
            cameraPos -= cameraRight * deltaTime * 5.0f;
        }
        if (glfwGetKey(mainWindow.getWindow(), GLFW_KEY_D) == GLFW_PRESS)
        {
            cameraPos += cameraRight * deltaTime * 5.0f;
        }

        cameraDirection = glm::normalize(direction);
        cameraRight = glm::normalize(glm::cross(cameraDirection, up));
        cameraUp = glm::normalize(glm::cross(cameraRight, cameraDirection));

        // Clear window
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // draw here
        shaderList[0]->UseShader();
        uniformModel = shaderList[0]->GetUniformLocation("model");
        uniformView = shaderList[0]->GetUniformLocation("view");
        uniformProjection = shaderList[0]->GetUniformLocation("projection");

        glm::vec3 pyramidPositions[] =
            {
                glm::vec3(-3.5f, 0.0f, -1.4f),
                glm::vec3(-2.4f, 0.0f, -1.0f),
                glm::vec3(-1.2f, 0.0f, -1.4f),
                glm::vec3(2.4f, 0.0f, -1.0f),
                glm::vec3(3.5f, 0.0f, -1.5f),
                glm::vec3(-1.2f, 0.0f, 0.0f),
                glm::vec3(0.3f, 0.0f, 0.2f),
                glm::vec3(1.2f, 0.0f, 0.0f),
                glm::vec3(-2.3f, 0.0f, 1.2f),
                glm::vec3(1.3f, 0.0f, 1.6f),
                glm::vec3(-1.3f, 0.0f, 1.5f)};

        glm::mat4 cameraPosMat(1.0f);
        cameraPosMat[3][0] = -cameraPos.x;
        cameraPosMat[3][1] = -cameraPos.y;
        cameraPosMat[3][2] = -cameraPos.z;
        glm::mat4 cameraRotateMat(1.0f);
        cameraRotateMat[0] = glm::vec4(cameraRight.x, cameraUp.x, -cameraDirection.x, 0.0f);
        cameraRotateMat[1] = glm::vec4(cameraRight.y, cameraUp.y, -cameraDirection.y, 0.0f);
        cameraRotateMat[2] = glm::vec4(cameraRight.z, cameraUp.z, -cameraDirection.z, 0.0f);
        view = cameraRotateMat * cameraPosMat;

        // Object

        RenderModelWithTexture(meshList[1], textures[1], glm::vec3(0.3f, 0.0f, 1.5f), 0.07f);
        RenderModelWithTexture(meshList[2], textures[2], glm::vec3(0.0f, 0.0f, -1.5f), 0.1f);
        RenderModelWithTexture(meshList[3], textures[3], glm::vec3(1.2f, 0.0f, -1.0f), 0.1f);
        RenderModelWithTexture(meshList[4], textures[4], glm::vec3(1.3f, 0.0f, 1.6f), 0.1f);
        RenderModelWithTexture(meshList[5], textures[5], glm::vec3(-1.2f, 0.0f, -1.4f), 0.1f);
        RenderModelWithTexture(meshList[6], textures[6], glm::vec3(1.2f, 0.0f, 0.0f), 0.1f);
        RenderModelWithTexture(meshList[7], textures[7], glm::vec3(0.0f, 0.0f, 0.0f), 0.1f);
        // RenderModelWithTexture(meshList[8], textures[8], glm::vec3(-1.3f, 0.0f, 1.5f), 0.1f);
        // RenderModelWithTexture(meshList[9], textures[9], glm::vec3(-2.3f, 0.0f, -1.5f), 0.1f);
        // RenderModelWithTexture(meshList[10], textures[10], glm::vec3(-2.3f, 0.0f, 1.2f), 0.1f);
        // RenderModelWithTexture(meshList[11], textures[11], glm::vec3(-3.3f, 0.0f, -1.4f), 0.1f);
        // RenderModelWithTexture(meshList[12], textures[12], glm::vec3(3.5f, 0.0f, -1.5f), 0.1f);

        for (int i = 0; i < 11; i++)
        {
            RenderModelWithTexture(meshList[0], textures[0], pyramidPositions[i], 0.4f);
        }

        view = glm::lookAt(cameraPos, cameraPos + cameraDirection, cameraUp);

        glUseProgram(0);
        // end draw

        mainWindow.swapBuffers();
    }

    return 0;
}
