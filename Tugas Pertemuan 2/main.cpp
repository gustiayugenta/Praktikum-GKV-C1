#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898

// Fungsi untuk menggambar lingkaran
void drawCircle(float cx, float cy, float r, int num_segments, float rColor, float gColor, float bColor) {
    glColor3f(rColor, gColor, bColor);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= num_segments; i++) {
        float angle = 2.0f * PI * i / num_segments;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

// Fungsi untuk menggambar mobil
void drawCar() {
    glPushMatrix();

    // Badan Mobil (merah tua)
    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.1f);
        glVertex2f( 0.3f, -0.1f);
        glVertex2f( 0.3f,  0.03f);
        glVertex2f(-0.25f,  0.1f);
    glEnd();
    
    // Badan Mobil (merah)
    glColor3f(0.9f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.1f);
        glVertex2f( 0.3f, -0.1f);
        glVertex2f( 0.3f,  -0.01f);
        glVertex2f(-0.276f,  -0.01f);
    glEnd();
	
    // Atap Mobil (merah tua)
    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.255f,  0.08f);
        glVertex2f( 0.17f,  0.04f);
        glVertex2f( 0.1f,  0.18f);
        glVertex2f(-0.23f,  0.18f);
    glEnd();
    
    // Kaca Depan Mobil (putih)
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(0.01f, 0.08f);
        glVertex2f(0.135f, 0.08f);
        glVertex2f(0.095f, 0.167f);
        glVertex2f(0.01f, 0.167f);
    glEnd();
    
    // Kaca Depan Mobil (abu-abu)
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
        glVertex2f(0.01f, 0.08f);
        glVertex2f(0.125f, 0.08f);
        glVertex2f(0.01f, 0.167f);
        glVertex2f(0.01f, 0.167f);
    glEnd();
    
    // Kaca Tengah Mobil (putih)
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.01f, 0.08f);
        glVertex2f(-0.13f, 0.08f);
        glVertex2f(-0.13f, 0.167f);
        glVertex2f(-0.01, 0.167f);
    glEnd();
    
    // Kaca Tengah Mobil (abu-abu)
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
        glVertex2f(-0.03f, 0.08f);
        glVertex2f(-0.13f, 0.08f);
        glVertex2f(-0.13f, 0.167f);
        glVertex2f(-0.13f, 0.167f);
    glEnd();
    
    // Kaca Belakang Mobil (putih)
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.15f, 0.08f);
        glVertex2f(-0.256f, 0.08f);
        glVertex2f(-0.233f, 0.167f);
        glVertex2f(-0.15f, 0.167f);
    glEnd();
    
    // Kaca Belakang Mobil (abu-abu)
    glColor3f(0.9f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
        glVertex2f(-0.17f, 0.08f);
        glVertex2f(-0.256f, 0.08f);
        glVertex2f(-0.233f, 0.167f);
        glVertex2f(-0.233f, 0.167f);
    glEnd();
    
    // Lampu Depan (Kuning)
    glColor3f(1.0f, 0.9f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(0.26f, -0.065f);
        glVertex2f(0.30f, -0.065f);
        glVertex2f(0.30f, -0.03f);
        glVertex2f(0.26f, -0.03f);
    glEnd();
    
    // Lampu Depan (Kuning tua)
    glColor3f(1.0f, 0.7f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(0.30f, -0.065f);
        glVertex2f(0.30f, -0.065f);
        glVertex2f(0.30f, -0.03f);
        glVertex2f(0.26f, -0.03f);
    glEnd();
    
    // Lampu Belakang (Kuning)
    glColor3f(1.0f, 0.9f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.25f, -0.065f);
        glVertex2f(-0.293f, -0.065f);
        glVertex2f(-0.284f, -0.03f);
        glVertex2f(-0.25f, -0.03f);
    glEnd();
    
    // Lampu Belakang (Kuning tua)
    glColor3f(1.0f, 0.7f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.25f, -0.065f);
        glVertex2f(-0.25f, -0.065f);
        glVertex2f(-0.284f, -0.03f);
        glVertex2f(-0.25f, -0.03f);
    glEnd();
    
    // Bagian Bawah Lampu Depan (abu-abu)
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_QUADS);
        glVertex2f(0.23f, -0.1f);
        glVertex2f(0.30f, -0.1f);
        glVertex2f(0.30f, -0.07f);
        glVertex2f(0.23f, -0.07f);
    glEnd();
    
     // Bagian Bawah Lampu Belakang (abu-abu)
    glColor3f(0.8f, 0.8f, 0.8f);
    glBegin(GL_QUADS);
        glVertex2f(-0.23f, -0.1f);
        glVertex2f(-0.30f, -0.1f);
        glVertex2f(-0.294f, -0.07f);
        glVertex2f(-0.23f, -0.07f);
    glEnd();
    
    // Gagang Pintu Mobil Depan (hitam)
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(0.03f, 0.05f);
        glVertex2f(0.07f, 0.05f);
        glVertex2f(0.07f, 0.04f);
        glVertex2f(0.03f, 0.04f);
    glEnd();
    
    // Gagang Pintu Mobil Belakang (hitam)
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.07f, 0.05f);
        glVertex2f(-0.11f, 0.05f);
        glVertex2f(-0.11f, 0.04f);
        glVertex2f(-0.07f, 0.04f);
    glEnd();

	// Roda Depan
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(0.2f, -0.10f, 0.05f, 30, 0.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(0.2f, -0.10f, 0.02f, 30, 1.0f, 1.0f, 1.0f);

    // Roda Belakang
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(-0.2f, -0.10f, 0.05f, 30, 0.0f, 0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(-0.2f, -0.10f, 0.02f, 30, 1.0f, 1.0f, 1.0f);
    
    glPopMatrix();
    
}

// Fungsi untuk menggambar jalan dan area hijau di sampingnya
void drawRoad() {
	
    // Area hijau di samping jalan
    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-2.0f, -2.0f);
        glVertex2f( 2.0f, -2.0f);
        glVertex2f( 2.0f, -0.17f);
        glVertex2f(-2.0f, -0.17f);
    glEnd();

    // Jalan raya
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
        glVertex2f(-2.0f, -0.5f);
        glVertex2f( 2.0f, -0.5f);
        glVertex2f( 2.0f, -0.2f);
        glVertex2f(-2.0f, -0.2f);
    glEnd();

    // Garis putus-putus di jalan
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        for (float i = -2.0f; i < 2.0f; i += 0.2f) {
            glVertex2f(i, -0.35f);
            glVertex2f(i + 0.1f, -0.35f);
        }
    glEnd();
}

// Fungsi untuk menggambar pohon
void drawTree(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(-0.02f, -0.1f);
        glVertex2f( 0.02f, -0.1f);
        glVertex2f( 0.02f,  0.1f);
        glVertex2f(-0.02f,  0.1f);
    glEnd();

    glColor3f(0.0f, 0.6f, 0.0f);
    drawCircle(0.0f, 0.15f, 0.08f, 30, 0.0f, 0.6f, 0.0f);
    glPopMatrix();
}

// Fungsi untuk menggambar awan
void drawCloud(float x, float y) {
    glColor3f(1.0f, 1.0f, 1.0f);
    drawCircle(x, y, 0.08f, 30, 1.0f, 1.0f, 1.0f);
    drawCircle(x + 0.08f, y, 0.07f, 30, 1.0f, 1.0f, 1.0f);
    drawCircle(x - 0.08f, y, 0.07f, 30, 1.0f, 1.0f, 1.0f);
    drawCircle(x + 0.04f, y + 0.05f, 0.06f, 30, 1.0f, 1.0f, 1.0f);
    drawCircle(x - 0.04f, y + 0.05f, 0.06f, 30, 1.0f, 1.0f, 1.0f);
}

// Fungsi untuk menggambar matahari dengan tiga lapisan
void drawSun() {
    drawCircle(0.7f, 0.7f, 0.12f, 50, 1.0f, 1.0f, 0.0f);  // Lapisan luar (kuning terang)
    drawCircle(0.7f, 0.7f, 0.10f, 50, 1.0f, 0.9f, 0.0f);  // Lapisan tengah (kuning biasa)
    drawCircle(0.7f, 0.7f, 0.08f, 50, 1.0f, 0.6f, 0.0f);  // Lapisan dalam (oranye)
}

// Fungsi untuk menampilkan semua objek ke layar
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

	drawSun();
	
	drawCloud(-0.6f, 0.7f);
    drawCloud(0.3f, 0.8f);
    drawCloud(-0.2f, 0.6f);

	glRotatef(15, 0.0f, 0.0f, 1.0f);
    drawRoad();
    drawTree(-0.7f, -0.1f);
    drawTree(0.7f, -0.1f);

    glPushMatrix();
    glTranslatef(0.0f, -0.3f, 0.0f);
    drawCar();
    glPopMatrix();

    glFlush();
}

void init() {
    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Mobil dengan roda");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}




