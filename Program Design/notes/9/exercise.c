#include <stdio.h>

struct color{
// This is the structure for color
	int red, green, blue;
};


struct color make_color(int red, int green, int blue){
// This is a function that returns the structure color
	if(red<0)
		red = 0;
	else if(red>255)
		red = 255;

	if(green<0)
		green = 0;
	else if(green>255)
		green = 255;

	if(blue<0)
		blue = 0;
	else if(blue>255)
		blue = 255;
	struct color c={red, green, blue};
	return c;
}


struct color brighter(struct color c){
	struct color c2;
	if(c.red==0) c.red=3;
	if(c.green==0) c.green=3;
	if(c.blue==0) c.blue=3;

	// if red/.7 is greater than 255 then red=255 else red=red/.7
	c2.red = (c.red/0.7>255)?255:(int)(c.red/0.7);
	c2.green = (c.green/0.7>255)?255:(int)(c.green/0.7);
	c2.blue = (c.blue/0.7>255)?255:(int)(c.blue/0.7);
	
	return c2;
}


int main(){
	struct color ubuntu={56, 12, 42}, color2, color3, color4, color5;
	printf("Ubuntu colors: %d, %d, %d.\n", ubuntu.red, ubuntu.green, ubuntu.blue);

	/*printf("Enter the red value of the new color: ");
	scanf("%d", &color2.red);

	printf("Enter the green value of the new color: ");
	scanf("%d", &color2.green);
	
	printf("Enter the blue value of the new color: ");
	scanf("%d", &color2.blue);
	
	printf("Color2: %d, %d, %d\n", color2.red, color2.green, color2.blue);
	*/
	color3 = make_color(-5, 357, 93);
	printf("Color 3: %d, %d, %d\n", color3.red, color3.green, color3.blue);

	color4 = make_color(255, 215, 0);
	printf("Color 4: %d, %d, %d\n", color4.red, color4.green, color4.blue);

	color5 = brighter(color4);
	printf("Color 5: %d, %d, %d\n", color5.red, color5.green, color5.blue);


	return 0;
}
