#include <stdio.h>
#include <stdint.h>

void shadeexceptring(void *img, uint32_t width, uint32_t height,
uint32_t x, uint32_t y, uint32_t r, uint32_t w, uint32_t perc);

int main(int argc, char* argv[]){

    int32_t x_coordinate, y_coordinate, radius, thickness, shade_percent, height, width;
    FILE* pict = fopen("example_image.BMP",'w');

    scanf("Please enter the pixel row of the center of the circle: ", &x_coordinate);
    scanf("Please enter the pixel column of the center of the circle: ", &y_coordinate);
    scanf("Please enter the radius of the circle: ", &radius);
    scanf("Please enter the thickness of the circle: ", &thickness);
    scanf("Please enter the shading percentage: ", &shade_percent);

    fseek(pict, 18, SEEK_SET);
    fread(&width, sizeof(int32_t), 1, pict);  
    fread(&height, sizeof(int32_t), 1, pict); 

    shadeexceptring(pict, width, height, x_coordinate, y_coordinate, radius, thickness, shade_percent);

    fclose(pict);
    return 0;
}