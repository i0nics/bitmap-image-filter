// Programmer: Bikram Chatterjee
// Email: b_chatterjee@u.pacific.edu
// BMP Image filter
// helpers.c

#include "helpers.h"
#include "math.h"
#include <stdio.h>
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float redVal, blueVal, greenVal;
    int grayscaleVal;

    // Iterate through rows
    for (int row = 0; row < height; row++)
    {
        // Iterate through columns
        for (int col = 0; col < width; col++)
        {
            // Obtain RGB values of current image pixel
            redVal = image[row][col].rgbtRed;
            blueVal = image[row][col].rgbtBlue;
            greenVal = image[row][col].rgbtGreen;

            // Compute grayscale value to the average of all three RGB values
            // to attain an accurate grayscale representation of the current pixel's color
            grayscaleVal = round((redVal + blueVal + greenVal) / 3);

            // Set all values to calculated grayscale value
            image[row][col].rgbtRed = image[row][col].rgbtBlue = image[row][col].rgbtGreen = grayscaleVal;
        }
    }

    return;
}

// Convert image to its sepia equivalent
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float redVal, blueVal, greenVal;
    int grayscaleVal;

    // Iterate through rows
    for (int row = 0; row < height; row++)
    {
        // Iterate through columns
        for (int col = 0; col < width; col++)
        {
            // Obtain RGB values of current image pixel
            redVal = image[row][col].rgbtRed;
            blueVal = image[row][col].rgbtBlue;
            greenVal = image[row][col].rgbtGreen;

            // Utilize sepia algorithm to compute sepia RGB values and apply them
            image[row][col].rgbtRed = MIN(round(0.393 * redVal + 0.769 * greenVal + 0.189 * blueVal), 255);
            image[row][col].rgbtGreen = MIN(round(0.349 * redVal + 0.686 * greenVal + 0.168 * blueVal), 255);
            image[row][col].rgbtBlue = MIN(round(0.272 * redVal + 0.534 * greenVal + 0.131 * blueVal), 255);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempPixels;

    // Iterate through rows
    for (int row = 0; row < height; row++)
    {
        // Iterate through columns
        for (int col = 0; col < width / 2; col++)
        {
            // Swap pixels
            tempPixels = image[row][col];
            image[row][col] = image[row][width - (col + 1)];
            image[row][width - (col + 1)] = tempPixels;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    float redValSum, greenValSum, blueValSum;
    int totalSurroundingPixels, surrPixelRow, surrPixelCol;

    // Iterate through rows
    for (int row = 0; row < height; row++)
    {
        // Iterate through columns
        for (int col = 0; col < width; col++)
        {
            redValSum = greenValSum = blueValSum = totalSurroundingPixels = 0;

            // Iterate through current pixel's surrounding pixel rows
            for (int surrRow = -1; surrRow < 2; surrRow++)
            {
                // Iterate through current pixel's surrounding pixel cols
                for (int surrCol = -1; surrCol < 2; surrCol++)
                {
                    // Skip current pixel
                    if (surrRow == row && surrCol == col)
                    {
                        continue;
                    }

                    // Get current surrounding pixel's row and col
                    surrPixelRow = row + surrRow;
                    surrPixelCol = col + surrCol;

                    // Check if surrounding pixel's row or col exists
                    if (surrPixelRow < 0 || surrPixelRow >= height || surrPixelCol < 0 || surrPixelCol >= width)
                    {
                        continue;
                    }

                    // If surrounding pixel exists, count it and add up its RGB values
                    redValSum += image[surrPixelRow][surrPixelCol].rgbtRed;
                    greenValSum += image[surrPixelRow][surrPixelCol].rgbtGreen;
                    blueValSum += image[surrPixelRow][surrPixelCol].rgbtBlue;
                    totalSurroundingPixels += 1;
                }
            }

            // Apply average RGB values of all surrounding pixels to current pixel
            image[row][col].rgbtRed = round(redValSum / totalSurroundingPixels);
            image[row][col].rgbtGreen = round(greenValSum / totalSurroundingPixels);
            image[row][col].rgbtBlue = round(blueValSum / totalSurroundingPixels);
        }
    }

    return;
}

// Detect edges by using Sobel's e
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE originalImage[height][width];
    float redValSum, greenValSum, blueValSum;
    int surrPixelRow, surrPixelCol;
    int matrix_pos, GxRedVal, GxGreenVal, GxBlueVal, GyRedVal, GyGreenVal, GyBlueVal;;
    int GxMatrix[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int GyMatrix[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    // Store original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            originalImage[i][j] = image[i][j];
        }
    }

    // Iterate through rows
    for (int row = 0; row < height; row++)
    {
        // Iterate through columns
        for (int col = 0; col < width; col++)
        {
            matrix_pos = -1;
            GxRedVal = GxGreenVal = GxBlueVal = GyRedVal = GyGreenVal = GyBlueVal = 0;

            // Iterate through current pixel's surrounding pixel rows
            for (int surrRow = -1; surrRow < 2; surrRow++)
            {
                // Iterate through current pixel's surrounding pixel cols
                for (int surrCol = -1; surrCol < 2; surrCol++)
                {
                    // Get current surrounding pixel's row and col
                    surrPixelRow = row + surrRow;
                    surrPixelCol = col + surrCol;

                    matrix_pos += 1;

                    // Check if surrounding pixel's row or col exists
                    if (surrPixelRow < 0 || surrPixelRow >= height || surrPixelCol < 0 || surrPixelCol >= width)
                    {
                        continue;
                    }

                    // Calculate Gx value by multiplying the red, green, or blue color value by the corresponding
                    // Gx convolutional matrix's value
                    GxRedVal += GxMatrix[matrix_pos] * originalImage[surrPixelRow][surrPixelCol].rgbtRed;
                    GxGreenVal += GxMatrix[matrix_pos] * originalImage[surrPixelRow][surrPixelCol].rgbtGreen;
                    GxBlueVal += GxMatrix[matrix_pos] * originalImage[surrPixelRow][surrPixelCol].rgbtBlue;

                    // Calculate Gy value by multiplying the red, green, or blue color value by the corresponding
                    // Gy convolutional matrix's value
                    GyRedVal += GyMatrix[matrix_pos] * originalImage[surrPixelRow][surrPixelCol].rgbtRed;
                    GyGreenVal += GyMatrix[matrix_pos] * originalImage[surrPixelRow][surrPixelCol].rgbtGreen;
                    GyBlueVal += GyMatrix[matrix_pos] * originalImage[surrPixelRow][surrPixelCol].rgbtBlue;

                    // Compute new channel value by taking square root of the sum of Gx squared and Gy squared
                    // MIN function used to cap the resultant value to 255
                    image[row][col].rgbtRed = MIN(round(sqrt(GxRedVal * GxRedVal + GyRedVal * GyRedVal)), 255);
                    image[row][col].rgbtGreen = MIN(round(sqrt(GxGreenVal * GxGreenVal + GyGreenVal * GyGreenVal)), 255);
                    image[row][col].rgbtBlue = MIN(round(sqrt(GxBlueVal * GxBlueVal + GyBlueVal * GyBlueVal)), 255);
                }
            }
        }
    }

    return;
}