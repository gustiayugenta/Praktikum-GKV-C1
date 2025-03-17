// Modul Pertemuan 3

//// Proyeksi
//
//#include <GL/glut.h> 
//void Display(void)
//	{ glClear(GL_COLOR_BUFFER_BIT);
//	glLoadIdentity();
//	glBegin(GL_POLYGON);
//	glColor3f(0.0,0.0,0.0);
//	glVertex3f(-0.5,-0.5,-3.0);
//	glColor3f(1.0,0.0,0.0);
//	glVertex3f(0.5,-0.5,-3.0);
//	glColor3f(0.0,0.0,1.0);
//	glVertex3f(0.5,0.5,-3.0);
//	glEnd();
//	glFlush(); //Selesai rendering
//}
//void Reshape(int x, int y)
//{ 	if (y == 0 || x == 0) return; //Jika tak ada lagi yang muncul, maka berhenti
//	//Mengatur proyeksi matrix baru
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity(); //Sudut : 40 derajat
//	//Jarak potongan dataran terdekat: 0.5 //Jarak potongan dataran terjauh: 20.0
//	gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
//	glMatrixMode(GL_MODELVIEW);
//	glViewport(0,0,x,y); //gunakan seluruh window untuk rendering
//}
//int main (int argc, char **argv)
//{
//	//Inisialisasi GLUT glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(300,300); glutCreateWindow("Intro");
//	glClearColor(0.0,0.0,0.0,0.0);
//	glutDisplayFunc(Display);
//	glutReshapeFunc(Reshape); //mengatur kembali bentuk objek
//	glutMainLoop(); return 0;
//}

//// Kubus Berotasi
//
//#include <GL\glut.h>
//GLfloat xRotated, yRotated, zRotated; 
//void Display(void)
//	{ glClear(GL_COLOR_BUFFER_BIT);
//	glLoadIdentity();
//	glTranslatef(0.0,0.0,-4.0);
//	glRotatef(xRotated,1.0,0.0,0.0);
//	glRotatef(yRotated,0.0,1.0,0.0);
//	glRotatef(zRotated,0.0,0.0,1.0);
//	glScalef(2.0,1.0,1.0);
//	glutWireCube(1.0); glFlush();
//	glutSwapBuffers();
//}
//void Reshape(int x, int y)
//{	if (y == 0 || x == 0) return;
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
//	glMatrixMode(GL_MODELVIEW); glViewport(0,0,x,y);
//}
//void Idle(void)
//{ 	xRotated += 0.3;
//	yRotated += 0.1;
//	zRotated += -0.4;
//	Display();
//}
//int main (int argc, char **argv)
//{ 	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(300,300);
//	glutCreateWindow("Cube example");
//	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
//	xRotated = yRotated = zRotated = 0.0;
//	glClearColor(0.0,0.0,0.0,0.0);
//	glutDisplayFunc(Display);
//	glutReshapeFunc(Reshape); glutIdleFunc(Idle);
//	glutMainLoop(); return 0;
//}

// Lengan Bergerak

#include <GL/glut.h>
static int shoulder = 0, elbow = 0;
void init(void) {
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glShadeModel (GL_FLAT);
}
void display(void) {
	glClear (GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef (-1.0, 0.0, 0.0);
	glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
	glTranslatef (1.0, 0.0, 0.0); glPushMatrix();
	glScalef (2.0, 0.4, 1.0);
	glutWireCube (1.0); glPopMatrix();
	glTranslatef (1.0, 0.0, 0.0);
	glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
	glTranslatef (1.0, 0.0, 0.0); glPushMatrix();
	glScalef (2.0, 0.4, 1.0);
	glutWireCube (1.0);
	glPopMatrix(); glPopMatrix();
	glutSwapBuffers();
}
void reshape (int w, int h) {
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode (GL_PROJECTION); glLoadIdentity();
	gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW); glLoadIdentity();
	glTranslatef (0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
switch (key) {
	case 's': shoulder = (shoulder + 5) % 360;
	glutPostRedisplay(); break;
	case 'S': shoulder = (shoulder - 5) % 360;
	glutPostRedisplay(); break;
	case 'e': elbow = (elbow + 5) % 360;
	glutPostRedisplay(); break;
	case 'E': elbow = (elbow - 5) % 360;
	glutPostRedisplay(); break;
	case 27: exit(0); break;
	default: break;
}
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
		glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (700, 600);
	glutInitWindowPosition (100, 100);
	glutCreateWindow (argv[0]); init();
		glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop(); return 0;
}
