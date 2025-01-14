#include <stdio.h>
#include <stdint.h>

void shadeexceptring(void *img, uint32_t x, uint32_t y, uint32_t r, uint32_t w, uint32_t perc);

int main(int argc, char* argv[]){

    int32_t x_coordinate, y_coordinate, radius, thickness, shade_percent, height, width;
    FILE* pict = fopen("example_image.BMP","w");

    printf("Please enter the following parameters in order: X coordinate, Y coordinate, radius, thickness, shade percentage.\n");
    scanf("%d %d %d %d %d", &x_coordinate, &y_coordinate, &radius, &thickness, &shade_percent);

    shadeexceptring(pict, x_coordinate, y_coordinate, radius, thickness, shade_percent);

    fclose(pict);

    return 0;
}