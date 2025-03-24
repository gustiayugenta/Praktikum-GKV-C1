#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

float angle=0.0, deltaAngle = 0.0, ratio;
float x=0.0f,y=1.75f,z=15.0f; // posisi awal kamera
float lx=0.0f,ly=0.0f,lz=-1.0f;
int deltaMove = 0,h,w;
int bitmapHeight=12;

void drawCube(float r, float g, float b) {
    glColor3f(r, g, b);
    glutSolidCube(1);
}

void Reshape(int w1, int h1)
{
    if(h1 == 0) h1 = 1;
    w = w1;
    h = h1;
    ratio = 1.0f * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45,ratio,0.1,1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        x, y, z,
        x + lx,y + ly,z + lz,
        0.0f,1.0f,0.0f);
}

void orientMe(float ang)
{
    lx = sin(ang);
    lz = -cos(ang);
    glLoadIdentity();
    gluLookAt(x, y, z,
    x + lx,y + ly,z + lz,
    0.0f,1.0f,0.0f);
}

void moveMeFlat(int i)
{
    x = x + i*(lx)*0.1;
    z = z + i*(lz)*0.1;
    glLoadIdentity();
    gluLookAt(x, y, z,
    x + lx,y + ly,z + lz,
    0.0f,1.0f,0.0f);
}

void drawGround() {
    glColor3f(0.5, 0.5, 0.5); // Warna abu-abu untuk lantai
    glBegin(GL_QUADS);
    glVertex3f(-50.0f, 0.0f, -50.0f);
    glVertex3f(-50.0f, 0.0f, 50.0f);
    glVertex3f(50.0f, 0.0f, 50.0f);
    glVertex3f(50.0f, 0.0f, -50.0f);
    glEnd();
}

void drawWheel(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);

    // Ban luar (hitam)
    glColor3f(0.0, 0.0, 0.0); 
    glutSolidTorus(0.05, 0.15, 12, 36);

    // Velg dalam (putih)
    glColor3f(1.0, 1.0, 1.0); 
    glutSolidTorus(0.03, 0.08, 12, 36);

    glPopMatrix();
}

void drawCar() {
    glPushMatrix();
    glTranslatef(0.0f, 0.6f, 0.0f); 
    
    // Badan Mobil
    glPushMatrix();
    glScalef(2.0, 0.5, 1.0);
    drawCube(0.0, 0.0, 1.0); // Warna biru
    glPopMatrix();

    // Atap Mobil
    glPushMatrix();
    glTranslatef(0.0, 0.4, 0.0);
    glScalef(1.2, 0.5, 0.8);
    drawCube(0.0, 0.0, 0.8); // Warna biru
    glPopMatrix();

    // Jendela Depan
    glPushMatrix();
    glTranslatef(0.0, 0.4, 0.41);
    glScalef(1.0, 0.4, 0.02);
    drawCube(1.0, 1.0, 1.0); // Warna putih
    glPopMatrix();

    // Jendela Belakang
    glPushMatrix();
    glTranslatef(0.0, 0.4, -0.41);
    glScalef(1.0, 0.4, 0.02);
    drawCube(1.0, 1.0, 1.0); // Warna putih
    glPopMatrix();

    // Jendela Samping Kanan
    glPushMatrix();
    glTranslatef(0.61, 0.4, 0.0);
    glScalef(0.02, 0.4, 0.8);
    drawCube(1.0, 1.0, 1.0); // Warna putih
    glPopMatrix();

    // Jendela Samping Kiri
    glPushMatrix();
    glTranslatef(-0.61, 0.4, 0.0);
    glScalef(0.02, 0.4, 0.8);
    drawCube(1.0, 1.0, 1.0); // Warna putih
    glPopMatrix();

    // Lampu Depan
    glPushMatrix();
    glTranslatef(1.01, 0.1, 0.3);
    glScalef(0.1, 0.1, 0.1);
    drawCube(1.0, 1.0, 0.0); // Warna kuning
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.01, 0.1, -0.3);
    glScalef(0.1, 0.1, 0.1);
    drawCube(1.0, 1.0, 0.0); // Warna kuning
    glPopMatrix();

    // Lampu Belakang
    glPushMatrix();
    glTranslatef(-1.01, 0.1, 0.3);
    glScalef(0.1, 0.1, 0.1);
    drawCube(1.0, 0.0, 0.0); // Warna merah
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.01, 0.1, -0.3);
    glScalef(0.1, 0.1, 0.1);
    drawCube(1.0, 0.0, 0.0); // Warna merah
    glPopMatrix();
    
    // Roda dengan velg putih
    drawWheel(0.8, -0.3, 0.5);
    drawWheel(-0.8, -0.3, 0.5);
    drawWheel(0.8, -0.3, -0.5);
    drawWheel(-0.8, -0.3, -0.5);
    
    glPopMatrix();
}


void drawTree(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    
    // Batang pohon
    glColor3f(0.55f, 0.27f, 0.07f); // Warna coklat
    glPushMatrix();
    glScalef(0.2f, 1.0f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Daun pohon (hanya bola)
    glColor3f(0.0f, 0.5f, 0.0f); // Warna hijau
    glPushMatrix();
    glTranslatef(0.0f, 0.75f, 0.0f);
    glutSolidSphere(0.5, 20, 20);
    glPopMatrix();
    
    glPopMatrix();
}

void drawPineTree(float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    
    // Batang pohon
    glColor3f(0.55f, 0.27f, 0.07f); // Warna coklat
    glPushMatrix();
    glScalef(0.2f, 1.0f, 0.2f);
    glutSolidCube(1.0);
    glPopMatrix();
    
    // Daun pohon (hanya kerucut, tidak ada bola)
    glColor3f(0.0f, 0.5f, 0.0f); // Warna hijau
    glPushMatrix();
    glTranslatef(0.0f, 0.5f, 0.0f); 
    glRotatef(-90, 1.0f, 0.0f, 0.0f); // Rotate ke atas
    glutSolidCone(0.5, 1.0, 20, 20);
    glPopMatrix();
    
    glPopMatrix();
}

void drawRock(float x, float y, float z, float size) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(size, size, size);
    glColor3f(0.3f, 0.3f, 0.3f); // Warna abu-abu batu
    glutSolidSphere(0.2, 10, 10); // Bentuk bola kasar sebagai batu
    glPopMatrix();
}

void drawRocks() {
    srand(42); // Seed agar posisi tetap konsisten setiap kali dijalankan
    for (int i = -40; i <= 40; i += 10) {
        for (int j = -40; j <= 40; j += 10) {
            if (abs(i) < 5 && abs(j) < 5) continue; // Hindari area dekat mobil

            int numRocks = rand() % 3 + 2; // 2-4 batu per lokasi
            for (int k = 0; k < numRocks; k++) {
                float offsetX = (rand() % 100) / 100.0f * 1.5f - 0.75f;
                float offsetZ = (rand() % 100) / 100.0f * 1.5f - 0.75f;
                float size = (rand() % 50) / 100.0f + 0.1f; // Ukuran random 0.1 - 0.6
                drawRock(i + offsetX, 0.1f, j + offsetZ, size);
            }
        }
    }
}

void display() {
    if (deltaMove)
        moveMeFlat(deltaMove);
    if (deltaAngle) {
        angle += deltaAngle;
        orientMe(angle);
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawGround();
    drawCar();
    drawRocks();
    
    // Pohon biasa (hanya bola)
	for (float i = -40.0f; i <= 40.0f; i += 10.0f) {
	    for (float j = -40.0f; j <= 40.0f; j += 10.0f) {
	        if (abs(i) < 5 && abs(j) < 5) continue; // Hindari area dekat mobil
	        drawTree(i, 0.5f, j);
	    }
	}
	
	// Pohon pinus (hanya kerucut)
	for (float i = -45.0f; i <= 45.0f; i += 15.0f) {
	    for (float j = -45.0f; j <= 45.0f; j += 15.0f) {
	        if (abs(i) < 5 && abs(j) < 5) continue; // Hindari area dekat mobil
	        drawPineTree(i, 0.5f, j);
	    }
	}

    glutSwapBuffers();
    glFlush();
}

void pressKey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT : deltaAngle = -0.01f;break;
        case GLUT_KEY_RIGHT : deltaAngle = 0.01f;break;
        case GLUT_KEY_UP : deltaMove = 1;break;
        case GLUT_KEY_DOWN : deltaMove = -1;break;
    }
}

void releaseKey(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT :
            if (deltaAngle < 0.0f)
                deltaAngle = 0.0f;
            break;
        case GLUT_KEY_RIGHT : 
            if (deltaAngle > 0.0f)
                deltaAngle = 0.0f;
            break;
        case GLUT_KEY_UP : 
            if (deltaMove > 0)
                deltaMove = 0;
            break;
        case GLUT_KEY_DOWN : 
            if (deltaMove < 0)
                deltaMove = 0;
            break;
    }
}

const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f };
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f };
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void lighting(){
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void init(void)
{
    glEnable (GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(640,480);
    glutCreateWindow("Mobil 3D");
    glutIgnoreKeyRepeat(1);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(Reshape);
    lighting();
    init();
    glutMainLoop();
    return(0);
}
