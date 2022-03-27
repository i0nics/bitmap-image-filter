<div id="top"></div>
  
<div align="center">
  <br>
  
  # Bitmap Image Filter
  A C-based Bitmap Image Filter Tool For Blur, Edges, Grayscale, Reflection and Sepia
  
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

The bitmap image filter tool is a C-based program that allows users to choose from blur, edges, grayscale, reflection, and sepia filters and apply it to any 24-bit uncompressed BMP 4.0 image file. Every Bitmap image file consists of 8-bit red, green, and blue channels that can each range from any value between 0 and 255 to produce a wide array of colors. This tool uses various algorithms to modify the RGB values of every pixel of a given BMP image according to the filter specified by the user.

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- GETTING STARTED -->
## Getting Started

Get a local copy up and running by following these simple steps:

* Clone the repo
   ```sh
   git clone https://github.com/i0nics/bitmap-image-filter.git
   ```
* Change to the project dir
   ```sh
   cd bitmap-image-filter
   ```
* Use an example BMP image from the example_input_images folder or use your own 24-bit uncompressed BMP 4.0 image file
* Run the program with a specified filter on a valid BMP image file using the following options

  * Grayscale

   ```sh
   ./filter -g input_image.bmp output_image.bmp
   ```
  * Reflection
  
   ```sh
   ./filter -r input_image.bmp output_image.bmp
   ```
   * Edges
    ```sh
   ./filter -e input_image.bmp output_image.bmp
   ```
   * Blur
    ```sh
   ./filter -b input_image.bmp output_image.bmp
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
