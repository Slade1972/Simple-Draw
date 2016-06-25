/*
 Name:		Simple-Draw.ino
 Created:	6/25/2016 1:40:21 PM
 Author:	Slade
*/

// the setup function runs once when you press reset or power the board

#include <Arduboy.h>

int PixX = 0;	//Pixel X Position
int PixY = 0;	//Pixel Y Position

boolean drawOK= false;	//Set a T/F variable to see if the program has started

Arduboy ab;		//Declare the Arduboy

void setup() {
	ab.setFrameRate(60);	//Smooth frame rate.
	ab.begin();		//Turn it on without a Logo
	txtinit();				//Run the next routine
}
void txtinit() {

	ab.clear();				//Clear the screen
	ab.setCursor(2, 0);		//Set the cursor
	ab.print("Simple Draw");	//Write text to the buffer
	ab.setCursor(2, 10);
	ab.print("By Slade 2016");
	ab.setCursor(2, 20);
	ab.print("Press A & B to Begin");
	ab.setCursor(2, 30);
	ab.print("Press A to draw slow");
	ab.display();			//Display the buffer
}

// the loop function runs over and over again until power down or reset
void loop() {

	if (!(ab.nextFrame())) return;	//If not the next frame skip everything.
	
	if (ab.pressed(A_BUTTON + B_BUTTON)) {
		PixX = 0;							//Set co-ordinates of the X & Y position.
		PixY = 0;
		drawOK = true;						//Set flag to true to start drawing.
		ab.clear();
		ab.drawPixel(PixX, PixY, WHITE);
		ab.display();
	}
	if (drawOK) {							//Check to see if true, if so, allow drawing.
		Draw();
	}
}

void Draw() {

	if (ab.buttonsState() == 0) {			//Check to see if no buttons are pressed.
		ab.drawPixel(PixX, PixY, WHITE);	//Turn the current pixel on
		delay(10);							//Wait 10ms
		ab.display();
		ab.drawPixel(PixX, PixY, BLACK);	//turn the current pixel off
		delay(10);
		ab.display();
	}




	if (ab.pressed(UP_BUTTON)) {
		if (ab.getPixel(PixX, PixY) == BLACK) {	//Check to see if the current pixel is off (due to the flashing routine above)
			ab.drawPixel(PixX, PixY, WHITE);	//If so, turn the pixel on, before moving onto the rest of the if/then statement
		}
		PixY--;									//Subtract 1 from the Y co-ordinate.
		ab.drawPixel(PixX, PixY, WHITE);
		ab.display();

		if (PixY <= 0) {						//If we hit the left edge of the screen, don't go any further.
			PixY = 0;
		}
	}

	if (ab.pressed(DOWN_BUTTON)) {
		if (ab.getPixel(PixX, PixY) == BLACK) {
			ab.drawPixel(PixX, PixY, WHITE);
		}
		PixY++;
		ab.drawPixel(PixX, PixY, WHITE);
		ab.display();

		if (PixY >= 63) {
			PixY = 63;
		}
	}

	if (ab.pressed(RIGHT_BUTTON)) {
		if (ab.getPixel(PixX, PixY) == BLACK) {
			ab.drawPixel(PixX, PixY, WHITE);
		}
		PixX++;
		ab.drawPixel(PixX, PixY, WHITE);
		ab.display();

		if (PixX >= 127) {
			PixX = 127;
		}
	}

	if (ab.pressed(LEFT_BUTTON)) {
		if (ab.getPixel(PixX, PixY) == BLACK) {
			ab.drawPixel(PixX, PixY, WHITE);
		}
		PixX--;
		ab.drawPixel(PixX, PixY, WHITE);
		ab.display();

		if (PixX <= 0) {
			PixX = 0;
		}
	}

	if (ab.pressed(A_BUTTON + RIGHT_BUTTON)) {
		if (ab.getPixel(PixX, PixY) == BLACK) {
			ab.drawPixel(PixX, PixY, WHITE);
		}
		PixX++;
		ab.drawPixel(PixX, PixY, WHITE);
		delay(200);
		ab.display();

		if (PixX >= 127) {
			PixX = 127;
		}
	}

	if (ab.pressed(A_BUTTON + LEFT_BUTTON)) {
		if (ab.getPixel(PixX, PixY) == BLACK) {
			ab.drawPixel(PixX, PixY, WHITE);
		}
		PixX--;
		ab.drawPixel(PixX, PixY, WHITE);
		delay(200);
		ab.display();

		if (PixX <= 0) {
			PixX = 0;
		}
	}
	if (ab.pressed(A_BUTTON + UP_BUTTON)) {
		if (ab.getPixel(PixX, PixY) == BLACK) {
			ab.drawPixel(PixX, PixY, WHITE);
		}
		PixY--;
		ab.drawPixel(PixX, PixY, WHITE);
		delay(200);
		ab.display();

		if (PixY <= 0) {
			PixY = 0;
		}
	}

	if (ab.pressed(A_BUTTON + DOWN_BUTTON)) {
		if (ab.getPixel(PixX, PixY) == BLACK) {
			ab.drawPixel(PixX, PixY, WHITE);
		}
		PixY++;
		ab.drawPixel(PixX, PixY, WHITE);
		delay(200);
		ab.display();

		if (PixY >= 63) {
			PixY = 63;
		}
	}




}

