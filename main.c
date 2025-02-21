#include <stdio.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image/stb_image_write.h"

/**
 * @note 
 * during compiling with the command gcc, use the flag '-lm' to link the math library as it's needed by the included stb library
 * images are just 3D arrays which are stored as array of arrays of arrays, so if we have a 3D channel image which is 3 pixels by 3 pixels, it will be stored just like this:
 * img = {{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
 *        {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}},
 *        {{19, 20, 21}, {22, 23, 24}, {25, 26, 27}}}
 */

/**
 * @name unsigned char * convert_RGB_to_Gray(unsigned char *img, int width, int height, int channels)
 * @brief this function is used to convert RGB image to its equivalent grey image by using the equation: P_grey =  0.2126*P_r + 0.7152*P_g + 0.0722*P_b
 * @param img [IN]: this is the RGB image to be converted where the channels are arranged as R, G, B as in the 3rd dimension of the array
 * @param width [IN]: this is the width of the image in terms of number of pixels
 * @param height [IN]: this is the height of the image in terms of number of pixels
 * @param channels [IN]: this is the number of the channels of the image (it shall be 3 for RGB image)
 * @return unsigned char * : this is pointer to the created grey image 
 */
unsigned char * convert_RGB_to_Gray(unsigned char *img, int width, int height, int channels)
{  
    // TODO: implement this function
    unsigned char * temp;
    return temp;
}


/**
 * @name unsigned char * convert_RGB_to_Binary(unsigned char *img, int width, int height, int channels)
 * @brief this function is used to convert RGB image to its equivalent binary image by first converting the image to a grey image, then writing 255 to a pixel if its 
 *          grey equivalent pixel value is > some_threshold and 0 otherwise. use a threshold of 90.
 * @param img [IN]: this is the RGB image to be converted where the channels are arranged as R, G, B as in the 3rd dimension of the array
 * @param width [IN]: this is the width of the image in terms of number of pixels
 * @param height [IN]: this is the height of the image in terms of number of pixels
 * @param channels [IN]: this is the number of the channels of the image (it shall be 3 for RGB image)
 * @return unsigned char * : this is pointer to the created binary image 
 */
unsigned char * convert_RGB_to_Binary(unsigned char *img, int width, int height, int channels)
{  
    // TODO: implement this function
    unsigned char * temp;
    return temp;
}

/**
 * @name unsigned char * rotate_RGB(unsigned char *img, int width, int height, int channels)
 * @brief this function is used to rotate RGB image by 90 degrees.
 * @param img [IN]: this is the RGB image to be converted where the channels are arranged as R, G, B as in the 3rd dimension of the array
 * @param width [IN]: this is the width of the image in terms of number of pixels
 * @param height [IN]: this is the height of the image in terms of number of pixels
 * @param channels [IN]: this is the number of the channels of the image (it shall be 3 for RGB image)
 * @return unsigned char * : this is pointer to the created rotated image 
 */
unsigned char * rotate_RGB(unsigned char *img, int width, int height, int channels)
{  
    // TODO: implement this function
    unsigned char * temp;
    return temp;
}

int main(void) {

    int width, height, channels;

    unsigned char *img = stbi_load("Assignment_input_image/resized-unsplash.jpg", &width, &height, &channels, 0);

    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }

    printf("Loaded image with a width of %dpx, a height of %dpx and %d channels\n", width, height, channels);

    // convert the RGB image to grey one
    unsigned char *img_grey =  convert_RGB_to_Gray(img, width, height, channels);
    unsigned char *img_binary =  convert_RGB_to_Binary(img, width, height, channels);
    unsigned char *img_rotated =  rotate_RGB(img, width, height, channels);

    stbi_write_jpg("Assignment_output_image/sky_original.jpg", width, height, channels, img, 100);
    stbi_write_jpg("Assignment_output_image/sky_grey.jpg", width, height, 1, img_grey, 100);
    stbi_write_jpg("Assignment_output_image/sky_binary.jpg", width, height, 1, img_binary, 100);
    stbi_write_jpg("Assignment_output_image/sky_rotated.jpg", height, width, channels, img_rotated, 100);

    stbi_image_free(img);
    stbi_image_free(img_grey);
    stbi_image_free(img_binary);
    stbi_image_free(img_rotated);
}