#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            int avg = round(( (float)red + (float)green + (float)blue) / 3);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            int sepia_red = round(0.393 * red + 0.769 * green + 0.189 * blue);
            int sepia_green = round(0.349 * red + 0.686 * green + 0.168 * blue);
            int sepia_blue = round(0.272 * red + 0.534 * green + 0.131 * blue);

            if (sepia_red > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = sepia_red;
            }

            if (sepia_green > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = sepia_green;
            }

            if (sepia_blue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = sepia_blue;
            }
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            new_image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            new_image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            new_image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = new_image[i][j].rgbtRed;
            image[i][j].rgbtGreen = new_image[i][j].rgbtGreen;
            image[i][j].rgbtBlue = new_image[i][j].rgbtBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int flag_red = 0;
            int flag_green = 0;
            int flag_blue = 0;
            int flag_left = -1;
            int flag_right = 2;
            int flag_top = -1;
            int flag_bottom = 2;

            if (i == 0)
            {
                flag_left = 0;
            }
            else if (i == (height - 1))
            {
                flag_right = 1;
            }

            if (j == 0)
            {
                flag_top = 0;
            }
            else if (j == (width - 1))
            {
                flag_bottom = 1;
            }

            int count = 0;
            for (int k = flag_left; k < flag_right; k++)
            {
                for (int p = flag_top; p < flag_bottom; p++)
                {
                    flag_red += image[i + k][j + p].rgbtRed;
                    flag_green += image[i + k][j + p].rgbtGreen;
                    flag_blue += image[i + k][j + p].rgbtBlue;
                    count++;
                }
            }
            new_image[i][j].rgbtRed = round(flag_red / count);
            new_image[i][j].rgbtGreen = round(flag_green / count);
            new_image[i][j].rgbtBlue = round(flag_blue / count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = new_image[i][j].rgbtRed;
            image[i][j].rgbtGreen = new_image[i][j].rgbtGreen;
            image[i][j].rgbtBlue = new_image[i][j].rgbtBlue;
        }
    }
}
