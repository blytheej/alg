#include <stdio.h>
#include <vector>
using namespace std;

const char icube[6][3][3] = //initial cube
{
{'w','w','w', 'w','w','w', 'w','w','w'}, //0 up  
{'r','r','r', 'r','r','r', 'r','r','r' }, //1 front  
{'y','y','y', 'y','y','y', 'y','y','y' }, //2 bottom
{'g','g','g', 'g','g','g', 'g','g','g' }, // 3left
{'b','b','b', 'b','b','b', 'b','b','b' }, // 4 right
{'o','o','o', 'o','o','o', 'o','o','o' } //5 back
}; 


char cube[6][3][3];

void reset_cube() {

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cube[i][j][k] = icube[i][j][k];
			}
		}
	}
}

void turn_face(int s, char dir) {
	if (dir == '+') {
		char tmp;
		tmp = cube[s][0][0];
		cube[s][0][0] = cube[s][2][0]; cube[s][2][0] = cube[s][2][2]; cube[s][2][2] = cube[s][0][2]; cube[s][0][2] = tmp;
		tmp = cube[s][0][1];
		cube[s][0][1] = cube[s][1][0]; cube[s][1][0] = cube[s][2][1]; cube[s][2][1] = cube[s][1][2]; cube[s][1][2] = tmp;
		
	}
	else {
		char tmp;
		tmp = cube[s][0][2];
		cube[s][0][2] = cube[s][2][2]; cube[s][2][2] = cube[s][2][0]; cube[s][2][0] = cube[s][0][0]; cube[s][0][0] = tmp;
		tmp = cube[s][1][2];
		cube[s][1][2] = cube[s][2][1]; cube[s][2][1] = cube[s][1][0]; cube[s][1][0] = cube[s][0][1]; cube[s][0][1] = tmp;
	}
} 

void turnU(char dir) {

	if (dir == '+') {
		char tmp[3];
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[4][0][i];
			cube[4][0][i] = cube[5][0][i];
			cube[5][0][i] = cube[3][0][i];
			cube[3][0][i] = cube[1][0][i];
			cube[1][0][i] = tmp[i];
		}
		turn_face(0, '+');
	}
	else {
		char tmp[3];
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[1][0][i];
			cube[1][0][i] = cube[3][0][i];
			cube[3][0][i] = cube[5][0][i];
			cube[5][0][i] = cube[4][0][i];
			cube[4][0][i] = tmp[i] ;

		}
		turn_face(0, '-');
	}
}

void turnD(char dir) {

	if (dir == '-') {
		char tmp[3];
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[4][2][i];
			cube[4][2][i] = cube[5][2][i];
			cube[5][2][i] = cube[3][2][i];
			cube[3][2][i] = cube[1][2][i];
			cube[1][2][i] = tmp[i];
		}
		turn_face(2, '+');
	}
	else {
		char tmp[3];
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[1][2][i];
			cube[1][2][i] = cube[3][2][i];
			cube[3][2][i] = cube[5][2][i];
			cube[5][2][i] = cube[4][2][i];
			cube[4][2][i] = tmp[i];

		}
		turn_face(2, '-');
	}
}

void turnF(char dir) {

	if (dir == '+') {
		char tmp[3];
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[0][2][i];
			cube[0][2][i] = cube[3][2 - i][2];
			cube[3][2 - i][2] = cube[2][2][2 - i];
			cube[2][2][2 - i] = cube[4][i][0];
			cube[4][i][0] = tmp[i];;
		}
		turn_face(1, '+');
	}
	else {
		char tmp[3];
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[4][i][0];
			cube[4][i][0] = cube[2][2][2 - i];
			cube[2][2][2 - i] = cube[3][2 -i][2];
			cube[3][2 - i][2] = cube[0][2][i];
			cube[0][2][i] = tmp[i] ;
		}
		turn_face(1, '-');
	}
}

void turnB(char dir) {

	if (dir == '-') {
		char tmp[3];
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[0][0][i];
			cube[0][0][i] = cube[3][2 - i][0];
			cube[3][2 - i][0] = cube[2][0][2 - i];
			cube[2][0][2 - i] = cube[4][i][2];
			cube[4][i][2] = tmp[i];;
		}
		turn_face(5, '-');
	}
	else {
		char tmp[3];
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[4][i][2];
			cube[4][i][2] = cube[2][0][2 - i];
			cube[2][0][2 - i] = cube[3][2 - i][0];
			cube[3][2 - i][0] = cube[0][0][i];
			cube[0][0][i] = tmp[i];
		}
		turn_face(5, '+');
	}
}

void turnL(char dir) {

	if (dir == '+') {
		char tmp[3];
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[0][i][0];
			cube[0][i][0] = cube[5][2-i][2];
			cube[5][2 -i][2] = cube[2][2 -i][0];
			cube[2][2 - i][0] = cube[1][i][0];
			cube[1][i][0] = tmp[i];
		}
		turn_face(3, dir);
	}
	else {
		char tmp[3];
		for (int i = 0; i < 3; i++) {
			tmp[i]= cube[1][i][0];
			cube[1][i][0] = cube[2][2-i][0];
			cube[2][2 - i][0] = cube[5][2 - i][2];
			cube[5][2 - i][2] = cube[0][i][0];
			cube[0][i][0] = tmp[i];
		}
		turn_face(3, dir);
	}
}

void turnR(char dir) {


	if (dir == '-') {
		char tmp[3];
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[0][i][2];
			cube[0][i][2] = cube[5][2 - i][0];
			cube[5][2 - i][0] = cube[2][2 - i][2];
			cube[2][2 - i][2] = cube[1][i][2];
			cube[1][i][2] = tmp[i];
		}
		turn_face(4, '-');
	}
	else {
		char tmp[3];
		for (int i = 0; i < 3; i++) {
			tmp[i] = cube[1][i][2];
			cube[1][i][2] = cube[2][2-i][2];
			cube[2][2 - i][2] = cube[5][2 - i][0];
			cube[5][2 - i][0] = cube[0][i][2];
			cube[0][i][2] = tmp[i];
		}
		turn_face(4, '+');
	}
}




void turn(char dir1, char dir2) {

	if (dir1 == 'U') {
		turnU(dir2);
	}
	else if (dir1 == 'D') {
		turnD(dir2);
	}
	else if (dir1 == 'F') {
		turnF(dir2);
	}
	else if (dir1 == 'B') {
		turnB(dir2);
	}
	else if (dir1 == 'L') {
		turnL(dir2);
	}
	else if (dir1 == 'R') {
		turnR(dir2);
	}
	else {
		//none
	}


}

int main() {

	int t;
	scanf("%d", &t);


	for (int test = 1; test <= t; test++) {

		int n;
		scanf("%d", &n);
		reset_cube();
		char dir1, dir2;

		for (int i = 0; i < n; i++) {
			scanf(" %c%c", &dir1, &dir2);
			turn(dir1, dir2);
		}
	
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					printf("%c", cube[0][i][j]);
				}
				printf("\n");
			}

	}

}