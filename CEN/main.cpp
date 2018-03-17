#include "Graph.hpp"
//#define MICROSOFT
#define LINUX
int countNodes(Node** nodes);

int main() {

	// credit: Storm, from stackoverflow, 11/3/2009
	FILE* fd;
#ifdef MICROSOFT
	fopen_s(&fd, "act.txt", "rb");
#endif
#ifdef LINUX
	fd = fopen("act.txt", "rb");
#endif


	fseek(fd, 0, SEEK_END);
	int lengthOfFile = ftell(fd);

	char* str = new char[lengthOfFile];
	int h = 0;
	while (1) {
		str[h] = fgetc(fd);
		if (feof(fd)) { break; }
	}
	// get number of lines
	int lineCtr = 0;
	for (int i = 0; i < lengthOfFile; i++) {
		if (str[i] == '\n') { lineCtr++; }
	}

	Graph CEN(lineCtr);

	char c[100] = "";
	memset(c, '\0', 100);
	char ctemp[100] = "";
	memset(ctemp, '\0', 100);
	//	printf("c is %s\nGarbage?\n", c);

	int tempIndex, tempX, tempY;
	tempIndex = tempX = tempY = -42;
	
	int i, j;
	i = j = 0;
	
	// populate lines;
	while (i < lengthOfFile) {		// possible 1-off error may delete final line
		while (str[i] != '\n') {
			c[i] = str[i];
			i++;
		}
		for (int j = 0; j < 3; j++) {
			int k = 0;
			while (c[k] != ' ' &&
				c[k] != '\n' &&
				c[k] != '\0') 
			{
				ctemp[k] = c[k]; 
			}
			// convert to number and store temp
			if (j == 0) { tempIndex = atoi(ctemp); }
			if (j == 1) { tempX = atoi(ctemp); }
			if (j == 2) { tempY = atoi(ctemp); }
			memset(ctemp, '\0', 100);
		}
		memset(c, '\0', 100);
		CEN.addNode(tempIndex, tempX, tempY);
		//do stuff
		i++;
	}
	// all nodes added.
	printf("Pause here to check nodes added.\n");

	// now what?
	Node** hull = CEN.makeHull();
	Node** solution = CEN.stretchIn();

}

int countNodes(Node** nodes) {
	int i = 0;
	while (nodes[i] != nullptr) { i++; }
	return i;
}