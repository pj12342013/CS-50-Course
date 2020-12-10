#include "helpers.h"
#include <stdio.h>
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            average = (round(image[i][j].rgbtRed) + round(image[i][j].rgbtGreen) + round(image[i][j].rgbtBlue))/ 3;


            average = round(average);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }

    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    //formula for swap is ( n - 1 - j)
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width/2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp;
    int sumred = 0;
    int sumblue = 0;
    int sumgreen = 0;
    int counter = 0;

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            for(int h = -1; h < 2; h++)
            {
                for(int w = -1; w < 2; w++)
                {
                    //CORNERS
                    //TOP RIGHT CORNER
                    if()


                    //TOP LEFT CORNER


                    //BOTTOM RIGHT CORNER


                    //BOTTOM LEFT CORNER


                    //EDGES
                    //BOTTOM


                    //UP


                    //RIGHT


                    //LEFT


                    //MIDDLE

                }
            }
        }



    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
