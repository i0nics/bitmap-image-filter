<div id="top"></div>
  
<div align="center">
  <br>
  
  # Bitmap Image Filter
  A C-based Bitmap Image Filter Tool For Blur, Edges, Grayscale, Reflection, and Sepia
  
  [![Contributors][contributors-shield]][contributors-url]
  [![Last Commit][last-commit-shield]][last-commit-url]
  ![GitHub Top Language][shield-github-top-language]
  ![GitHub Latest Release][shield-github-latest-release]
  [![MIT License][license-shield]][license-url]
</div>

<!-- TABLE OF CONTENTS -->
<details id="table_of_contents">
  <summary>Table of Contents</summary>

  - [About The Project](#about-the-project)
    - [Blur](#blur)
    - [Edges](#edges)
    - [Grayscale](#grayscale)
    - [Reflection](#reflection)
    - [Sepia](#sepia)
  - [Getting Started](#getting-started)
  - [License](#license)
  - [Contact](#contact)
  - [Acknowledgments](#acknowledgments)

</details>

<!-- ABOUT THE PROJECT -->
## About The Project

<div align="center">
  
  ![demo][demo] 
  
</div>

The bitmap image filter tool is a C-based program that allows users to choose from blur, edges, grayscale, reflection, and sepia filters and apply it to any 24-bit uncompressed BMP 4.0 image file. Every Bitmap image file consists of 8-bit red, green, and blue channels that can each range from any intensity value between 0 and 255 to produce a wide array of colors. This tool uses various algorithms to modify the RGB values of every pixel of a given BMP image according to the filter specified by the user. These filters are further described below.

### Blur
The blur filter takes an image and produces a softer and less sharp version of the image. To achieve this filter, an algorithm iterates through every pixel in the image, computes the average of each red, green, and blue color intensity value of all directly surrounding pixels, and applies those values to that pixel.

### Edges
The edges filter algorithm utilizes the Sobel operator that uses two 3x3 convolutional matrices to detect and highlght all boundaries between objects in the given image file.

### Grayscale
The grayscale filter takes an image and converts it to black-and-white. A pixel can show a shade of grey when all red, green, and blue values are essentially the same. Hence to achieve this filter, an algorithm iterates through every pixel in the image and takes the average of the pixel's red, green, and blue intensity values to attain an accurate grayscale representation of the current pixel's color and applies the same value to each red, green, and blue subpixel.

### Reflection
The reflection filter takes an image and produces the mirror image of the original picture. To achieve this filter, an algorithm iterates through every row of pixels in the image and essentially flips the entire row to obtain the desired result.

### Sepia
The seoia fiter takes an image and gives it an an old-timey feel by making the whole image look a bit reddish-brown. To achieve this filter, an algorithm iterates through every pixel in the image and utilizes certain formulas that calculates the sepia value for each red, green, and blue subpixel. 

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- GETTING STARTED -->
## Getting Started

Get a local copy up and running by following these simple steps:

* Clone the repo
   ```sh
   git clone https://github.com/i0nics/bitmap-image-filter.git
   ```
* Change to the project directory
   ```sh
   cd bitmap-image-filter
   ```
* Use an example BMP image from the example_input_images folder or use your own 24-bit uncompressed BMP 4.0 image file
* Run the program with a specified filter on a valid BMP image file using the following options
  
  * Blur
    ```sh
    ./filter -b input_image.bmp output_image.bmp
    ```
  * Edges
    ```sh
    ./filter -e input_image.bmp output_image.bmp
    ```
  * Grayscale
   ```sh
   ./filter -g input_image.bmp output_image.bmp
   ```
  * Reflection
  
   ```sh
   ./filter -r input_image.bmp output_image.bmp
   ```
   * Sepia
    ```sh
   ./filter -s input_image.bmp output_image.bmp
   ```
   
<p align="right">(<a href="#top">back to top</a>)</p>


                                
<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#top">back to top</a>)</p>

                                
<!-- CONTACT -->
## Contact

  [![LinkedIn][linkedin-shield-bikram]][linkedin-url-bikram]

Bikram Chatterjee - b_chatterjee@u.pacific.edu

<p align="right">(<a href="#top">back to top</a>)</p>
                                
<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

* [Harvard's CS50 PSET 4](https://cs50.harvard.edu/x/2022/psets/4/)


<p align="right">(<a href="#top">back to top</a>)</p>

<div align="center">
    <br><br>
    Made with ❤️ by i0nics
</div>


[contributors-shield]: https://img.shields.io/github/contributors/i0nics/bitmap-image-filter.svg?style=for-the-badge
[contributors-url]: https://github.com/i0nics/bitmap-image-filter/graphs/contributors
[demo]: demo/demo.gif
[issues-shield]: https://img.shields.io/github/issues/comp195/senior-project-spring-2022-autopath.svg?style=for-the-badge
[issues-url]: https://github.com/comp195/senior-project-spring-2022-autopath/issues
[last-commit-shield]: https://img.shields.io/github/last-commit/comp195/senior-project-spring-2022-autopath?style=for-the-badge
[last-commit-url]: https://img.shields.io/github/last-commit/comp195/senior-project-spring-2022-autopath?style=for-the-badge
[license-shield]: https://img.shields.io/github/license/i0nics/bitmap-image-filter.svg?style=for-the-badge
[license-url]: https://github.com/i0nics/bitmap-image-filter/blob/master/LICENSE.txt
[linkedin-shield-bikram]: https://img.shields.io/badge/-LinkedIn_(Bikram_C.)-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url-bikram]: https://linkedin.com/in/bikramce
[product-screenshot]: images/screenshot.png
[shield-github-latest-release]: https://img.shields.io/github/v/release/i0nics/bitmap-image-filter?include_prereleases&logo=github&style=for-the-badge
[shield-github-top-language]: https://img.shields.io/github/languages/top/i0nics/bitmap-image-filter?logo=github&style=for-the-badge
