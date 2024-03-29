// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h" //ayuda a que compile mas rapido
#include <stdio.h> // esta cosa para librerias incluidas en c#
#include <stdlib.h>

#define GLEW_STATIC 

#include "GL/glew.h" //comillas para librerias personalizadas
#include "GLFW/glfw3.h"

#include <iostream>

#include "Shader.h"
#include "Vertice.h"

using namespace std; //aqui esta lo de c++

Shader *shader;
GLuint posicionID;
GLuint colorID;

//el vertice necesita saber como va a empezar a leer y donde
vector<Vertice> cuerpo;
GLuint vertexArrayCuerpoID;
GLuint bufferCuerpoID;

//el vertice necesita saber como va a empezar a leer y donde
vector<Vertice> brazos;
GLuint vertexArrayBrazosID;
GLuint bufferBrazosID;

vector<Vertice> manos;
GLuint vertexArrayManosID;
GLuint bufferManosID;

vector<Vertice> base;
GLuint vertexArrayBaseID;
GLuint bufferBaseID;

vector<Vertice> piso;
GLuint vertexArrayPisoID;
GLuint bufferPisoID;

vector<Vertice> pelo;
GLuint vertexArrayPeloID;
GLuint bufferPeloID;

vector<Vertice> pelo2;
GLuint vertexArrayPelo2ID;
GLuint bufferPelo2ID;

vector<Vertice> pelo3;
GLuint vertexArrayPelo3ID;
GLuint bufferPelo3ID;

vector<Vertice> barba;
GLuint vertexArrayBarbaID;
GLuint bufferBarbaID;

void inicializarCuadrado()
{
	Vertice v1 = { vec3(0.1f, -0.7f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) };
	Vertice v2 = { vec3(-0.1f, -0.7f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) };
	Vertice v3 = { vec3(-0.1f, 0.3f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) };
	Vertice v4 = { vec3(0.1f, 0.3f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) };

	cuerpo.push_back(v1);
	cuerpo.push_back(v2);
	cuerpo.push_back(v3);
	cuerpo.push_back(v4);
		
}
void inicializarBrazos()
{
	Vertice v1 = { vec3(0.4f, -0.05f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) };
	Vertice v2 = { vec3(-0.4f, -0.05f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) };
	Vertice v3 = { vec3(-0.4f, 0.1f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) };
	Vertice v4 = { vec3(0.4f, 0.1f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) };

	brazos.push_back(v1);
	brazos.push_back(v2);
	brazos.push_back(v3);
	brazos.push_back(v4);

}
void inicializarManos()
{
	Vertice v1 = { vec3(0.45f, 0.0f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) };
	Vertice v2 = { vec3(-0.45f, 0.0f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) };
	Vertice v3 = { vec3(-0.45f, 0.05f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) };
	Vertice v4 = { vec3(0.45f, 0.05f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) };

	manos.push_back(v1);
	manos.push_back(v2);
	manos.push_back(v3);
	manos.push_back(v4);
}
void inicializarBase()
{
	Vertice v1 = { vec3(0.2f, -0.7f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) };
	Vertice v2 = { vec3(-0.2f, -0.7f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) };
	Vertice v3 = { vec3(-0.2f, -0.9f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) };
	Vertice v4 = { vec3(0.2f, -0.9f, 0.0f), vec4(1.0f, 1.0f, 1.0f, 1.0f) };

	cuerpo.push_back(v1);
	cuerpo.push_back(v2);
	cuerpo.push_back(v3);
	cuerpo.push_back(v4);

}
void inicializarPiso()
{
	Vertice v1 = { vec3(1.0f, -0.9f, 0.0f), vec4(0.0f, 1.0f, 0.0f, 1.0f) };
	Vertice v2 = { vec3(-1.0f, -0.9f, 0.0f), vec4(0.0f, 1.0f, 0.0f, 1.0f) };
	Vertice v3 = { vec3(-1.0f, -1.0f, 0.0f), vec4(0.0f, 1.0f, 0.0f, 1.0f) };
	Vertice v4 = { vec3(1.0f, -1.0f, 0.0f), vec4(0.0f, 1.0f, 0.0f, 1.0f) };

	piso.push_back(v1);
	piso.push_back(v2);
	piso.push_back(v3);
	piso.push_back(v4);

}
void inicializarPelo()
{

	Vertice v1 = { vec3(0.1f, 0.25f, 0.0f), vec4(0.1f, 0.0f, 0.0f, 1.0f) };
	Vertice v2 = { vec3(-0.1f, 0.25f,0.0f), vec4(0.1f, 0.0f, 0.0f, 1.0f) };
	Vertice v3 = { vec3(-0.1f, 0.3f, 0.0f), vec4(0.1f, 0.0f, 0.0f, 1.0f) };
	Vertice v4 = { vec3(0.1f, 0.3f, 0.0f), vec4(0.1f, 0.0f, 0.0f, 1.0f) };

	pelo.push_back(v1);
	pelo.push_back(v2);
	pelo.push_back(v3);
	pelo.push_back(v4);

}
void inicializarPelo2()
{

	Vertice v1 = { vec3(-0.05f, 0.1f, 0.0f), vec4(0.1f, 0.0f, 0.0f, 1.0f) };
	Vertice v2 = { vec3(-0.1f, 0.1f,0.0f), vec4(0.1f, 0.0f, 0.0f, 1.0f) };
	Vertice v3 = { vec3(-0.1f, 0.3f, 0.0f), vec4(0.1f, 0.0f, 0.0f, 1.0f) };
	Vertice v4 = { vec3(-0.05f, 0.3f, 0.0f), vec4(0.1f, 0.0f, 0.0f, 1.0f) };

	pelo2.push_back(v1);
	pelo2.push_back(v2);
	pelo2.push_back(v3);
	pelo2.push_back(v4);

}
void inicializarPelo3()
{

	Vertice v1 = { vec3(0.05f, 0.1f, 0.0f), vec4(0.1f, 0.0f, 0.0f, 1.0f) };
	Vertice v2 = { vec3(0.1f, 0.1f,0.0f), vec4(0.1f, 0.0f, 0.0f, 1.0f) };
	Vertice v3 = { vec3(0.1f, 0.3f, 0.0f), vec4(0.1f, 0.0f, 0.0f, 1.0f) };
	Vertice v4 = { vec3(0.05f, 0.3f, 0.0f), vec4(0.1f, 0.0f, 0.0f, 1.0f) };

	pelo3.push_back(v1);
	pelo3.push_back(v2);
	pelo3.push_back(v3);
	pelo3.push_back(v4);

}
void inicializarBarba()
{
	Vertice v1 = { vec3(0.05f, -0.02f, 0.0f),vec4(0.1f, 0.0f, 0.0f, 1.0f) };
	Vertice v2 = { vec3(-0.05f, -0.02f, 0.0f),vec4(0.1f, 0.0f, 0.0f, 1.0f) };
	Vertice v3 = { vec3(-0.08f, 0.14f, 0.0f),vec4(0.1f, 0.0f, 0.0f, 1.0f) };
	Vertice v4 = { vec3(0.08f, 0.14f, 0.0f),vec4(0.1f, 0.0f, 0.0f, 1.0f) };

	barba.push_back(v1);
	barba.push_back(v2);
	barba.push_back(v3);
	barba.push_back(v4);
}

void dibujar()
{
	//Elegir el shader
	shader->enlazar();

	//cuadrado
	glBindVertexArray(vertexArrayCuerpoID);
	glDrawArrays(GL_QUADS, 0, cuerpo.size());

	//soltar el vertex array
	glBindVertexArray(0);

	//brazos
	glBindVertexArray(vertexArrayBrazosID);
	glDrawArrays(GL_QUADS, 0, brazos.size());

	//soltar el vertex array
	glBindVertexArray(0);

	//manos
	glBindVertexArray(vertexArrayManosID);
	glDrawArrays(GL_QUADS, 0, manos.size());

	//soltar el vertex array
	glBindVertexArray(0);

	//base
	glBindVertexArray(vertexArrayBaseID);
	glDrawArrays(GL_QUADS, 0, base.size());

	//soltar el vertex array
	glBindVertexArray(0);

	//piso
	glBindVertexArray(vertexArrayPisoID);
	glDrawArrays(GL_QUADS, 0, piso.size());

	//soltar el vertex array
	glBindVertexArray(0);

	//pelo
	glBindVertexArray(vertexArrayPeloID);
	glDrawArrays(GL_QUADS, 0, pelo.size());

	//soltar el vertex array
	glBindVertexArray(0);

	//pelo2
	glBindVertexArray(vertexArrayPelo2ID);
	glDrawArrays(GL_QUADS, 0, pelo2.size());

	//soltar el vertex array
	glBindVertexArray(0);

	//pelo3
	glBindVertexArray(vertexArrayPelo3ID);
	glDrawArrays(GL_QUADS, 0, pelo3.size());

	//soltar el vertex array
	glBindVertexArray(0);

	//barba
	glBindVertexArray(vertexArrayBarbaID);
	glDrawArrays(GL_QUADS, 0, barba.size());

	//soltar el vertex array
	glBindVertexArray(0);
	//soltar el shader
	shader->desenlazar();
}

void actualizar() {

}

int main()
{
	//Declaramos apuntador de ventana

	GLFWwindow *window;

	//Si no se pudo iniciar glfw terminamos ejecución

	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	//Si se pudo iniciar GLFW entonces inicializamos la ventana

	window = glfwCreateWindow(1024, 768, "Ventana", NULL, NULL);

	//Si no podemos iniciar la ventana entonces terminamos la ejecución
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido e contexto activamos funciones modernas
	glewExperimental = true; //permite trabajar con gpu y cpu al mismo tiempo,solo va a funcionar si ya esta establecido el contexto

	//en caso de haber error se guarda en la variable errorGlew que es tipo GLenum 
	GLenum errorGlew = glewInit(); //inicializa glew

	if (errorGlew != GLEW_OK) {
		cout << glewGetErrorString(errorGlew);
	}

	//se obtiene la version de OpenGL y se imprime
	const GLubyte *versionGL = glGetString(GL_VERSION); 
	cout << "Version OpenGL: " << versionGL; 

	inicializarCuadrado();
	inicializarBrazos();
	inicializarManos();
	inicializarBase();
	inicializarPiso();
	inicializarPelo();
	inicializarPelo2();
	inicializarPelo3();
	inicializarBarba();

	const char *rutaVertex = "VertexShader.shader";
	const char *rutaFragment = "FragmentShader.shader";

	//Se crea una nueva instancia de la clase
	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos
	//lleva 2 atributos el id del programa y la variable que va a obtener
	//aqui se estan guardando las entradas del vertex
	posicionID = glGetAttribLocation(shader -> getID(),"posicion");

	colorID = glGetAttribLocation(shader->getID(), "color");

	//Desenlazar el shader
	shader -> desenlazar();

	/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	//Vertex array y buffer para un cuadrado

	//Crear un vertex array (los vertex array son el conjunto de vertices)
	//pide cuantos arreglos se haran, la direccion de memoria donde se va a guardar
	glGenVertexArrays(1, &vertexArrayCuerpoID);
	//con este se le dice que todas las acciones referentes a los vertex array estan vinculadas al que acabamos de crear
	glBindVertexArray(vertexArrayCuerpoID);

	//crear vertex buffer
	//aqui es cantidad y direccion de memoria
	glGenBuffers(1, &bufferCuerpoID);
	//Se dice que todas las acciones de buffer se hacen a este que acabamos de hacer
	//se le dice que tipo de buffer es y la direccion
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuerpoID);

	//llenar el buffer
	//se le dice que tipo de buffer es, cuanto es el tamaño en bits de lo que le queremos mandar, el espacio de memoria donde va a empezar a leer y para que lo vas a utilizar
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * cuerpo.size(), cuerpo.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);

	//Especificar a OpenGL como se van a comunicar
	//el primer atributo es cual se va a comunicar, el segundo es el tamaño de lo que se tiene que mandar(en este caso 3 flotantes), el tipo de dato de lo que estas mandando,si esta normalizado,el stride es que se van a leer 3 valores y que tanto espacio va a dejar pasar para tomar otros 3 valores, se le pasa el tamaño del vertice incluyendo los 3 que ya se tomaron en cuenta
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));


	//soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Brazos
	//Crear un vertex array (los vertex array son el conjunto de vertices)
	glGenVertexArrays(1, &vertexArrayBrazosID);
	glBindVertexArray(vertexArrayBrazosID);

	//crear vertex buffer
	glGenBuffers(1, &bufferBrazosID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferBrazosID);

	//llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * brazos.size(), brazos.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	//soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//manos
	//Crear un vertex array (los vertex array son el conjunto de vertices)
	glGenVertexArrays(1, &vertexArrayManosID);
	glBindVertexArray(vertexArrayManosID);

	//crear vertex buffer
	glGenBuffers(1, &bufferManosID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferManosID);

	//llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * manos.size(), manos.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	//soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//base
	//Crear un vertex array (los vertex array son el conjunto de vertices)
	glGenVertexArrays(1, &vertexArrayBaseID);
	glBindVertexArray(vertexArrayBaseID);

	//crear vertex buffer
	glGenBuffers(1, &bufferBaseID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferBaseID);

	//llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * base.size(), base.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	//soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//piso
	//Crear un vertex array (los vertex array son el conjunto de vertices)
	glGenVertexArrays(1, &vertexArrayPisoID);
	glBindVertexArray(vertexArrayPisoID);

	//crear vertex buffer
	glGenBuffers(1, &bufferPisoID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferPisoID);

	//llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * piso.size(), piso.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	//soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	
	//pelo
	//Crear un vertex array (los vertex array son el conjunto de vertices)
	glGenVertexArrays(1, &vertexArrayPeloID);
	glBindVertexArray(vertexArrayPeloID);

	//crear vertex buffer
	glGenBuffers(1, &bufferPeloID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferPeloID);

	//llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * pelo.size(), pelo.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	//soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//pelo2
	//Crear un vertex array (los vertex array son el conjunto de vertices)
	glGenVertexArrays(1, &vertexArrayPelo2ID);
	glBindVertexArray(vertexArrayPelo2ID);

	//crear vertex buffer
	glGenBuffers(1, &bufferPelo2ID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferPelo2ID);

	//llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * pelo2.size(), pelo2.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	//soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//pelo3
	//Crear un vertex array (los vertex array son el conjunto de vertices)
	glGenVertexArrays(1, &vertexArrayPelo3ID);
	glBindVertexArray(vertexArrayPelo3ID);

	//crear vertex buffer
	glGenBuffers(1, &bufferPelo3ID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferPelo3ID);

	//llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * pelo3.size(), pelo3.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	//soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//barba
	//Crear un vertex array (los vertex array son el conjunto de vertices)
	glGenVertexArrays(1, &vertexArrayBarbaID);
	glBindVertexArray(vertexArrayBarbaID);

	//crear vertex buffer
	glGenBuffers(1, &bufferBarbaID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferBarbaID);

	//llenar el buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * barba.size(), barba.data(), GL_STATIC_DRAW);

	//habilitar atributos del shader
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*) sizeof(vec3));

	//soltar vertex array y buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//ciclo de dibujo (draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer region de dibujo
		glViewport(0, 0, 1024, 768); //dice donde va a empezar a renderear y donde va a terminar
		//Establecer color de borrado
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		//Borramos
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffer
		glfwSwapBuffers(window); //cambia el buffer de la pantalla por el otro que se lleno
		//reconocer si hay entradas
		glfwPollEvents();

	}

	glfwDestroyWindow(window); //terminamos los procesos y eliminamos la ventana
	glfwTerminate();
	return 0;
}



