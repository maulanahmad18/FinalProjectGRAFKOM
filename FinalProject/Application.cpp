#include "Application.h"

Application::Application()
{
	for (int i = 0; i < 4; i++) {
		lampStatus[i] = true; // Semua lampu menyala pada awalnya
	}
	angle = 0;
}

Application::~Application()
{
}

void Application::setupPerspective()
{
	// Pass perspective projection matrix
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 1000.0f);
	shader->setMat4("projection", projection);
}

void Application::setupCamera()
{
	// LookAt camera (position, target/direction, up)
	viewPos = glm::vec3(5, 1, 5);
	glm::mat4 view = glm::lookAt(viewPos, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	shader->setMat4("view", view);
}

void Application::setupLighting()
{
	// set lighting attributes
	glm::vec3 lightPos = glm::vec3(4, 4, 0);
	shader->setVec3("lightPos", lightPos);
	shader->setVec3("viewPos", viewPos);
	glm::vec3 lightColor = glm::vec3(0.2f, 0.2f, 0.2f);
	shader->setVec3("lightColor", lightColor);
}

void Application::Init()
{
	// Build a lighting map shader
	shader = new Shader("cube.vert", "cube.frag");
	shader->Init();
	// Create instance of cube
	cube = new Cube(shader);
	cube->Init();
	cube->SetRotation(0, 0, 1, 0);

	// setup perspective 
	setupPerspective();
	// setup camera
	setupCamera();
	// setup lighting
	setupLighting();
}

void Application::DeInit()
{
	delete cube;
}

void Application::Update(double deltaTime)
{
	lastLightToggled += deltaTime;
	angle += (float)((deltaTime * 0.5f) / 1000);
	ProcessInput(this->window);
}

void Application::Render()
{
	glViewport(0, 0, this->screenWidth, this->screenHeight);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SetBackgroundColor(94, 232, 247);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);

	// Lemari
			// Balok utama
	cube->SetColor(205.0f, 133.0f, 63.0f);
	cube->SetPosition(-1.80f, 0.60f, 1.0f);
	cube->SetScale(1.5f, 2.2f, 0.7f);
	cube->Draw();

	// Pintu Kiri
	cube->SetColor(120.0f, 120.0f, 120.0f);
	cube->SetPosition(-1.695f, 0.6f, 0.65f);
	cube->SetScale(0.01f, 1.0f, 0.1f);
	cube->Draw();

	// Pintu Kanan
	cube->SetColor(120.0f, 120.0f, 120.0f);
	cube->SetPosition(-2.0f, 0.6f, 0.65f);
	cube->SetScale(0.01f, 1.0f, 0.1f);
	cube->Draw();



	// Kasur
	// Ranjang
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(1.0f, -0.25f, 0.254f);
	cube->SetScale(1.75f, 0.5f, 2.0f);
	cube->Draw();

	// Sandaran Kasur (Atas)
	cube->SetColor(205.0f, 133.0f, 63.0f);
	cube->SetPosition(1.0f, 0.0f, 1.300f);
	cube->SetScale(1.75f, 1.0f, 0.1f);
	cube->Draw();

	// Bantal 1
	cube->SetColor(120.0f, 120.0f, 120.0f);
	cube->SetPosition(1.5f, 0.2f, 1.2f);
	cube->SetScale(0.6f, 0.3f, 0.2f);
	cube->Draw();

	// Bantal 2
	cube->SetColor(120.0f, 120.0f, 120.0f);
	cube->SetPosition(0.6f, 0.2f, 1.200f);
	cube->SetScale(0.6f, 0.3f, 0.2f);
	cube->Draw();

	// Guling 1
	cube->SetColor(120.0f, 120.0f, 120.0f);
	cube->SetPosition(1.11f, 0.1f, 0.1f);
	cube->SetScale(0.2f, 0.2f, 1.5f);
	cube->Draw();

	// Guling 2
	cube->SetColor(120.0f, 120.0f, 120.0f);
	cube->SetPosition(0.89f, 0.1f, 0.1f);
	cube->SetScale(0.2f, 0.2f, 1.5f);
	cube->Draw();


	// Selimut
	cube->SetColor(0.0f, 0.0f, 0.0f);
	cube->SetPosition(0.999f, 0.0f, 0.0f);
	cube->SetScale(1.75f, 0.1f, 1.45f);
	cube->Draw();

	// Meja Kecil
	cube->SetColor(205.0f, 133.0f, 63.0f);
	cube->SetPosition(3.0f, -0.29f, 1.0f);
	cube->SetScale(0.8f, 0.4f, 0.8f);
	cube->Draw();

	// Lampu Tidur
	// Badan Lampu
	cube->SetColor(0.0f, 0.0f, 0.0f);;
	cube->SetPosition(2.890f, 0.08f, 1.0f);
	cube->SetScale(0.350f, 0.3f, 0.350f);
	cube->Draw();

	// Leher Lampu
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(2.890f, 0.28f, 1.0f);
	cube->SetScale(0.100f, 0.35f, 0.100f);
	cube->Draw();

	// Lampu
	cube->SetColor(120.0f, 120.0f, 120.0f);
	cube->SetPosition(2.890f, 0.48f, 1.0f);
	cube->SetScale(0.450f, 0.15f, 0.450f);
	cube->Draw();

	//karpet
	cube->SetColor(0.0f, 0.0f, 0.0f);
	cube->SetPosition(1.0f, -0.52f, -3.0f);
	cube->SetScale(5.0f, 0.01f, 3.5f);
	cube->Draw();

	//Dinding Atas
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(0.0f, 2.680f, -2.4f);
	cube->SetScale(8.1f, 0.1f, 7.9f);
	cube->Draw();

	// Dinding Kanan
	cube->SetColor(14.0f, 77.0f, 146.0f);
	cube->SetPosition(4.0f, 1.0f, -2.4f);
	cube->SetScale(0.1f, 3.3f, 7.9f);
	cube->Draw();

	// Dinding Kiri
	cube->SetColor(14.0f, 77.0f, 146.0f);
	cube->SetPosition(-4.0f, 1.0f, -2.4f);
	cube->SetScale(0.1f, 3.3f, 7.9f);
	cube->Draw();

	// Dinding Bawah
	cube->SetColor(120.0f, 120.0f, 120.0f);
	cube->SetPosition(0.0f, -0.6f, -2.4f);
	cube->SetScale(8.1f, 0.1f, 8.0f);
	cube->Draw();

	// Dinding Depan
	cube->SetColor(14.0f, 77.0f, 146.0f);
	cube->SetPosition(0.0f, 1.0f, 1.5f);
	cube->SetScale(8.0f, 3.3f, 0.1f);
	cube->Draw();

	// Dinding Belakang
	cube->SetColor(14.0f, 77.0f, 146.0f);
	cube->SetPosition(0.0f, 1.0f, -6.3f);
	cube->SetScale(8.0f, 3.3f, 0.1f);
	cube->Draw();

	// Objek TV
	// Layar TV
	cube->SetColor(120.0f, 120.0f, 120.0f);
	cube->SetPosition(1.2f, 0.9f, -6.0f);
	cube->SetScale(2.0f, 0.9f, 0.1f);
	cube->Draw();

	// Bagian bingkai TV
	cube->SetColor(0.0f, 0.0f, 0.0f);
	cube->SetPosition(1.2f, 0.3f, -6.0f);
	cube->SetScale(2.1f, 0.1f, 0.2f);
	cube->Draw();

	// Antena TV
	cube->SetColor(0.0f, 0.0f, 0.0f);
	cube->SetPosition(1.2f, 1.5f, -6.0f);
	cube->SetScale(0.05f, 0.7f, 0.05f);
	cube->Draw();

	// Lukisan 
	// Bingkai Lukisan
	cube->SetColor(205.0f, 133.0f, 63.0f);
	cube->SetPosition(0.9f, 1.4f, 1.499f);
	cube->SetScale(1.0f, 1.0f, 0.1f);
	cube->Draw();

	// Lukisan
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(0.9f, 1.4f, 1.420f);
	cube->SetScale(0.8f, 0.8f, 0.01f);
	cube->Draw();

	// Pintu
	cube->SetColor(205.0f, 133.0f, 63.0f);
	cube->SetPosition(3.9f, 1.f, -5.5f);
	cube->SetScale(0.1f, 3.2f, 1.5f);
	cube->Draw();

	// Kunci Pintu
	// Badan Kunci
	cube->SetColor(192.0f, 192.0f, 192.0f);
	cube->SetPosition(3.8f, 0.9f, -4.9f);
	cube->SetScale(0.02f, 0.2f, 0.2f);
	cube->Draw();

	// Gagang Kunci
	cube->SetColor(120.0f, 120.0f, 120.0f);
	cube->SetPosition(3.788, 1.0f, -4.9f);
	cube->SetScale(0.03f, 0.1f, 0.1f);
	cube->Draw();

	// Meja Rias
	cube->SetColor(0.0f, 0.0f, 0.0f);
	cube->SetPosition(-3.290f, 0.4f, -5.7f);
	cube->SetScale(1.5f, 0.2f, 1.0f);
	cube->Draw();


	// Kaca Cermin
	cube->SetColor(173.0f, 216.0f, 230.0f);
	cube->SetPosition(-3.290f, 1.0f, -6.2f);
	cube->SetScale(1.5f, 1.0f, 0.02f);
	cube->Draw();

	// AC - Badan Utama
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(3.9f, 1.5f, -0.8f);
	cube->SetScale(0.08f, 0.5f, 1.2f);
	cube->Draw();

	// AC - Panel Atas
	cube->SetColor(255.0f, 255.0f, 255.0f);
	cube->SetPosition(3.840f, 1.5f, -0.8f);
	cube->SetScale(0.1f, 0.01, 1.0f);
	cube->Draw();

	// AC - Kipas
	cube->SetColor(120.0f, 120.0f, 120.0f);
	cube->SetPosition(3.840f, 1.5f, -0.8f);
	cube->SetScale(0.015f, 0.3f, 0.885f);
	cube->Draw();

	// AC - Sisi Kanan
	cube->SetColor(0.0f, 0.0f, 0.0f);
	cube->SetPosition(3.840f, 1.5f, -0.3f);
	cube->SetScale(0.01f, 0.5f, 0.1f);
	cube->Draw();

	// AC - Sisi Kiri
	cube->SetColor(0.0f, 0.0f, 0.0f);
	cube->SetPosition(3.840f, 1.5f, -1.3f);
	cube->SetScale(0.01f, 0.5f, 0.1f);
	cube->Draw();

	// Kursi
	// Bangku Kursi
	cube->SetColor(205.0f, 133.0f, 63.0f);
	cube->SetPosition(-3.290f, 0.2f, -5.5f);
	cube->SetScale(1.4f, 0.1f, 1.0f);
	cube->Draw();

	// Kaki Kursi - Kiri Depan
	cube->SetColor(205.0f, 133.0f, 63.0f);
	cube->SetPosition(-3.7f, -0.2f, -5.1f);
	cube->SetScale(0.1f, 0.7f, 0.1f);
	cube->Draw();

	// Kaki Kursi - Kiri Belakang
	cube->SetColor(205.0f, 133.0f, 63.0f);
	cube->SetPosition(-3.7f, -0.2f, -5.9f);
	cube->SetScale(0.1f, 0.7f, 0.1f);
	cube->Draw();

	// Kaki Kursi - Kanan Depan
	cube->SetColor(205.0f, 133.0f, 63.0f);
	cube->SetPosition(-2.8f, -0.2f, -5.1f);
	cube->SetScale(0.1f, 0.7f, 0.1f);
	cube->Draw();

	// Kaki Kursi - Kanan Belakang
	cube->SetColor(205.0f, 133.0f, 63.0f);
	cube->SetPosition(-2.8f, -0.2f, -5.9f);
	cube->SetScale(0.1f, 0.7f, 0.1f);
	cube->Draw();

	// Sandaran Kursi
	cube->SetColor(205.0f, 133.0f, 63.0f);
	cube->SetPosition(-3.290f, 0.6f, -5.090f);
	cube->SetScale(1.2f, 0.8f, 0.1f);
	cube->Draw();

	// Lampu Menggantung
	// Kabel Lampu
	cube->SetColor(0.0f, 0.0f, 0.0f);
	cube->SetPosition(0.0f, 2.58f, -2.4f);
	cube->SetScale(0.02f, 0.02f, 0.2f);
	cube->Draw();

	// Badan Lampu
	cube->SetColor(192.0f, 192.0f, 192.0f);
	cube->SetPosition(0.0f, 2.5f, -2.4f);
	cube->SetScale(0.15f, 0.15f, 0.15f);
	cube->Draw();

	// Kaca Lampu
	cube->SetColor(255.0f, 255.0f, 0.0f);
	cube->SetPosition(0.0f, 2.45f, -2.4f);
	cube->SetScale(0.14f, 0.14f, 0.14f);
	cube->Draw();

	// Pemanis Lampu 
	cube->SetColor(0.0f, 0.0f, 0.0f);
	cube->SetPosition(0.0f, 2.45f, -2.4f);
	cube->SetScale(0.02f, 0.02f, 0.02f);
	cube->Draw();

	// Tempat Sampah
	// Badan Tempat Sampah
	cube->SetColor(120.0f, 120.0f, 120.0f);
	cube->SetPosition(3.8f, -0.3f, -4.0f);
	cube->SetScale(0.3f, 0.6f, 0.5f);
	cube->Draw();

	// Tutup Atas Tempat Sampah
	cube->SetColor(0.0f, 0.0f, 0.0f);
	cube->SetPosition(3.8f, 0.01f, -4.0f);
	cube->SetScale(0.29f, 0.02f, 0.38f);
	cube->Draw();


	// Tutup kanan Tempat Sampah
	cube->SetColor(120.0f, 120.0f, 120.0f);
	cube->SetPosition(3.8f, -0.1f, -3.77f);
	cube->SetScale(0.28f, 0.6f, 0.02f);
	cube->Draw();

	// Tutup kiri Tempat Sampah
	cube->SetColor(120.0f, 120.0f, 120.0f);
	cube->SetPosition(3.8f, -0.1f, -4.23f);
	cube->SetScale(0.28f, 0.6f, 0.02f);
	cube->Draw();


	// Bagian atas Tempat Sampah
	cube->SetColor(120.0f, 120.0f, 120.0f);
	cube->SetPosition(3.8f, 0.20f, -4.0f);
	cube->SetScale(0.3f, 0.01f, 0.5f);
	cube->Draw();

	// Vas Bunga
	// Badan Vas
	cube->SetColor(205.0f, 133.0f, 63.0f);
	cube->SetPosition(-1.1f, -0.1f, -6.0f);
	cube->SetScale(0.5f, 0.9f, 0.6f);
	cube->Draw();

	// Batang Bunga 1
	cube->SetColor(0.0f, 128.0f, 0.0f);
	cube->SetPosition(-1.1f, 0.27f, -6.0f);
	cube->SetScale(0.02f, 0.4f, 0.02f);
	cube->Draw();

	// Bunga 1
	cube->SetColor(255.0f, 0.0f, 0.0f);
	cube->SetPosition(-1.1f, 0.54f, -6.0f);
	cube->SetScale(0.15f, 0.15f, 0.15f);
	cube->Draw();

	// Batang Bunga 2
	cube->SetColor(0.0f, 128.0f, 0.0f);
	cube->SetPosition(-1.15f, 0.27f, -6.0f);
	cube->SetScale(0.02f, 0.4f, 0.02f);
	cube->Draw();

	// Bunga 2
	cube->SetColor(0.0f, 0.0f, 255.0f);
	cube->SetPosition(-1.15f, 0.49f, -6.0f);
	cube->SetScale(0.12f, 0.12f, 0.12f);
	cube->Draw();

	// Batang Bunga 3
	cube->SetColor(0.0f, 128.0f, 0.0f);
	cube->SetPosition(-1.05f, 0.27f, -6.0f);
	cube->SetScale(0.02f, 0.4f, 0.02f);
	cube->Draw();

	// Bunga 3
	cube->SetColor(255.0f, 255.0f, 0.0f);
	cube->SetPosition(-1.05f, 0.49f, -6.0f);
	cube->SetScale(0.12f, 0.12f, 0.12f);
	cube->Draw();

	//lamp
	if (lampStatus[0]) {
		cube->SetColor(255, 255, 0); // Warna lampu menyala
	}
	else {
		cube->SetColor(255, 255, 255); // Warna lampu mati
	}
	



	glm::vec3 lightPos = glm::vec3(4, 4, 0);
	shader->setVec3("lightPos", lightPos);
	shader->setVec3("viewPos", viewPos);
	glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f) * lightIntensity;
	shader->setVec3("lightColor", lightColor);



	glDisable(GL_DEPTH_TEST);

}

void Application::UpdateCameraDirection(double xpos, double ypos)
{
	// Update yaw dan pitch berdasarkan input mouse
	yaw += xpos;
	pitch += ypos;

	// Batasi pitch agar tidak melebihi batas atas dan bawah
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	// Hitung vektor arah kamera berdasarkan yaw dan pitch
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	// Normalisasi vektor arah kamera
	viewDir = glm::normalize(front);

	// Perbarui matriks pandangan (view matrix)
	glm::mat4 view = glm::lookAt(viewPos, viewPos + viewDir, glm::vec3(0, 1, 0));
	shader->setMat4("view", view);
}


void Application::ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	if (firstMouse) {
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	// Faktor sensitivitas mouse
	float sensitivity = 0.4f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	// Update orientasi kamera berdasarkan input mouse
	UpdateCameraDirection(xoffset, yoffset);

	// Fixed camera movement speed
	float fixedMovementSpeed = 0.003f;

	// Update camera position based on keyboard input
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		viewPos += fixedMovementSpeed * viewDir;

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		viewPos -= fixedMovementSpeed * viewDir;

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		viewPos -= glm::normalize(glm::cross(viewDir, glm::vec3(0.0f, 1.0f, 0.0f))) * fixedMovementSpeed;

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		viewPos += glm::normalize(glm::cross(viewDir, glm::vec3(0.0f, 1.0f, 0.0f))) * fixedMovementSpeed;


	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && lastLightToggled > 200)
	{
		for (int i = 0; i < 4; i++)
		{
			lampStatus[i] = !lampStatus[i]; // Toggle status lampu
		}

		lightIntensity += 0.5f; // Atur nilai peningkatan sesuai kebutuhan

		lastLightToggled = 0;
	}

	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && lastLightToggled > 200)
	{
		for (int i = 0; i < 4; i++)
		{
			lampStatus[i] = !lampStatus[i]; // Toggle status lampu
		}

		lightIntensity -= 0.5f; // Atur nilai peningkatan sesuai kebutuhan

		lastLightToggled = 0;
	}
}



int main(int argc, char** argv) {
	Application app = Application();
	app.Start("Classroom",
		1366, 768,
		false,
		false);
}