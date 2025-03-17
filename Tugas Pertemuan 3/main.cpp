#include <GL/glut.h>

static int bahu = 0, siku = 0, pergelangan = 0;
static int jempol[3] = {0, 0, 0}, telunjuk[3] = {0, 0, 0}, tengah[3] = {0, 0, 0}, manis[3] = {0, 0, 0}, kelingking[3] = {0, 0, 0};

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void drawFinger(int angles[3]) {
    for (int i = 0; i < 3; i++) {
        glRotatef((GLfloat)angles[i], 0.0, 0.0, 1.0);
        glTranslatef(0.2, 0.0, 0.0);
        glPushMatrix();
        glScalef(0.25, 0.1, 0.1);
        glutWireCube(1.0);
        glPopMatrix();
        glTranslatef(0.1, 0.0, 0.0);
    }
}

void drawFinger2(int angles[3]) {
    for (int i = 0; i < 2; i++) {
        glRotatef((GLfloat)angles[i], 0.0, 0.0, 1.0);
        glTranslatef(0.2, 0.0, 0.0);
        glPushMatrix();
        glScalef(0.25, 0.1, 0.1);
        glutWireCube(1.0);
        glPopMatrix();
        glTranslatef(0.1, 0.0, 0.0);
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // Lengan atas (bahu)
    glTranslatef(-1.0, 0.0, 0.0);
    glRotatef((GLfloat)bahu, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Lengan bawah (siku)
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)siku, 0.0, 0.0, 1.0);
    glTranslatef(1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();

    // Telapak tangan (pergelangan)
    glTranslatef(1.0, 0.0, 0.0);
    glRotatef(90, 0.5, 1.0, 0.0); 
	glRotatef(90, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)pergelangan, 0.0, 1.0, 0.0);
    glTranslatef(0.5, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.0, 0.3, 0.5);
    glutWireCube(1.0);
    glPopMatrix();

    // Gambar jari-jari
    glPushMatrix();
    glTranslatef(0.2, 0.2, 0.3);
    drawFinger2(jempol);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0.15, 0.15);
    drawFinger(telunjuk);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0.15, 0.0);
    drawFinger(tengah);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0.15, -0.15);
    drawFinger(manis);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0.15, -0.3);
    drawFinger(kelingking);
    glPopMatrix();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y) {
    int *joint = NULL;
    switch (key) {
        case 's': bahu = (bahu + 5) % 360; break;
        case 'S': bahu = (bahu - 5) % 360; break;
        case 'e': siku = (siku + 5) % 360; break;
        case 'E': siku = (siku - 5) % 360; break;
        case 'p': joint = jempol; break;
        case 'i': joint = telunjuk; break;
        case 'o': joint = tengah; break;
        case 'l': joint = manis; break;
        case 'k': joint = kelingking; break;
        case 27: exit(0); break;
        default: break;
    }
    if (joint) {
        for (int i = 0; i < 3; i++) joint[i] = (joint[i] + 5) % 360;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lengan dengan Telapak Tangan dan Jari");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}

