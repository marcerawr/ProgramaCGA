#ifndef _MAIN_H
#define _MAIN_H

#include <windows.h>		// Archivo de cabecera para Windows
#include <math.h>			// Archivo de cabecera para Funciones Matemáticas
#include <stdio.h>			// Header File For Standard Input/Output
#include <stdlib.h>			// Header File For Standard Library
#include <fstream>
#include <vector>
#include <crtdbg.h>
#include "gl/gl.h"				// Archivo de cabecera para la libreria OpenGL32
#include "gl/glu.h"			// Archivo de cabecera para la libreria GLu32
#include "gl/glaux.h"			// Archivo de cabecera para la libreria Glaux
#include "gl/glext.h"			// Archivo de cabecera para la libreria Glext
#include "Vector.h"
#include "cargadorTGA.h"
#include "Materiales.h"
#include "Font.h"
#include "Control.h"

#define GL_CLAMP_TO_EDGE	0x812F	//Usado para skybox

int  ManejaTeclado();

struct infoScene
{
	int idEscenario;
	int numMapa;
};

struct opcionesMenuPrincipal
{
	int opcionSelec;
	int dificultad; //0: facil, 1: normal, 2: dificil
	int numVidas;
	int sonido;
};

struct infoGame
{
	int glWidth;
	int glHeight;
	//0: inicializa datos, 1: dibuja logo estudio, 2: pantalla de carga
	//3: introduccion, 4: titulo del juego, 5: Menu principal,
	//6: juego, 7: pausa, 8: menu de opciones principal, 9: conf control
	int estadoJuego;
	infoScene *infEsc;
	int tiempoEstado;
	int cargaArchivosCompleta;
	int opcionMenuSelec;

	opcionesMenuPrincipal opMenuPrinc;

};

struct paramObj
{
	CVector PosicionObj;	//La posición (x,y,z) del objeto
	CVector PosicionObjAnt;	//La posición anterior (x,y,z) del objeto
	CVector Direccion;		//La dirección en que se dirige el objeto en forma de vector=(x,y,z)
	CVector DireccionCam;   //La dirección que define la posición de la cámara respecto al personaje
	CVector PosicionCam;    //La posición de la cámara que sigue al objeto
	CVector ObjetivoCam;	//El punto (x,y,z) que está viendo la cámara; en este caso al objeto

	float VelocidadObj;		//La velocidad a la que se mueve el objeto
	float DistanciaCam;		//La distancia que la cámara está separada del objeto
	float AngDir;			//Se usa para llevar control del angulo para el cálculo del vector de dirección
	float AngDirCam;		//Se usa para llevar control del angulo para el cálculo de posición de la cámara
	float AngObj;			//Se usa para llevar control del ángulo de rotación para el modelo del objeto

	float CamaraPosAlt;		//Se usa para definir y cambiar si es necesario la altura de la cámara
	float CamaraObjAlt;		//Se usa para definir y cambiar si es necesario la altura del objetivo de la cámara

	float escalaX;
	float escalaY;
	float escalaZ;

	int   dir;
	int   contAuxAnim;

	bool visible;
	bool caminando;
	bool saltando;
	bool kick;
		
};

struct paramCam
{
	CVector DireccionCam;   //La dirección que define la posición de la cámara respecto al personaje
	CVector PosicionCam;    //La posición de la cámara que sigue al objeto
	CVector ObjetivoCam;	//El punto (x,y,z) que está viendo la cámara; en este caso al objeto

	float DistanciaCam;		//La distancia que la cámara está separada del objeto
	float deltaAngDirCam;	//Se usa para llevar control del angulo para el cálculo de posición de la cámara
	float AngDirCam;		//Se usa para llevar control del angulo para el cálculo de posición de la cámara
	
	float CamaraPosAlt;		//Se usa para definir y cambiar si es necesario la altura de la cámara
	float CamaraObjAlt;		//Se usa para definir y cambiar si es necesario la altura del objetivo de la cámara

	float VariacionCam;
	float VariacionDist;

	float FactorCam;

	float VariacionDespDist;
	float VariacionDespCam;

};

struct FRAME
{
	float Angt1;
	float Angt2;
	float Angc1;
	float Angc2;
	float Angbi1;
	float Angbi2;
	float Angbib;
	float Angbd1;
	float Angbd2;
	float Angbdb;
	float Angpizq;
	float Angpder;
	float Angpi;
	float Angpd;

	float Xtor;
	float Ytor;
	float Ztor;

	float incAngt1;
	float incAngt2;
	float incAngc1;
	float incAngc2;
	float incAngbi1;
	float incAngbi2;
	float incAngbib;
	float incAngbd1;
	float incAngbd2;
	float incAngbdb;
	float incAngpizq;
	float incAngpder;
	float incAngpi;
	float incAngpd;

	float incXtor;
	float incYtor;
	float incZtor;

};

#endif 