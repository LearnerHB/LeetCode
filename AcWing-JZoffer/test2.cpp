#include <iostream>

using namespace std;

struct 
{
	float x1;
	float y1;
	float x2;
	float y2;
}Box;
float iou(Box b1, Box b2);

int main(int argc, char const *argv[])
{
	Box b1 = {0., 2.0, 2.0, 0.};
	Box b2 = {1.0, 3.0, 3.0, 1.0};

	cout << iou(b1, b2) << endl;
	
	return 0;
}

float iou(Box b1, Box b2){
	if (b2->x1 > b1->x2 && b2->y1 < b1->y2 || b2->x2 < b1->x1 && b2->y2 > b1->y1)
		return 0.0;
	float w1 = b1->x2 - b1->x1;
	float w2 = b2->x2 - b2->x1;
	float h1 = b1->y1 - b1->y2;
	float h2 = b2->y1 - b2->y2;
	float w, h;

	if (!(b2->x1 > b1->x2 && b2->y1 < b1->y2)){	//b2 tl on b1
		if (b2->x2 > b1->x2){
			w = w1 - (b2->x1 - b1->x1);
		}else{
			w = w2;
		}
		if (b2->y2 < b1->y2){
			h = h2 - (b2->y1 - b1->y2);
		}
		else {
			h = h2;
		}

	}else {	//b2 lr on b1
		return iou(b2, b1);
	}
	return (float) ((h*w) / (h1*w1+h2+w2-h*w));
}





