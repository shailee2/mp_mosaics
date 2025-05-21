
 
# Photomosaic Generator

This project generates photomosaics by reconstructing a source image using thousands of smaller tile images, matched by color similarity in LUV color space. The program is built in **C++** and uses a **k-d tree** for efficient nearest neighbor search.

> This was developed as a class project to explore spatial data structures and image processing in C++. The algorithm supports high-performance tile matching and modular extensibility.

---

## Features

- **Color Matching in LUV Space** for perceptual accuracy
- **k-d Tree Implementation** for fast nearest neighbor search
- **Tile-Based Rendering** of any input image using color-similar tiles
- Fully **modular**, customizable tile resolution and image sets
- Output as a complete mosaic image (.jpg/.png)

---

## How It Works

1. Load a source image and tile image dataset
2. Convert each tile and region of the source image to its average LUV color
3. Build a k-d tree of tile colors
4. For each region of the source image, find the closest-matching tile using the tree
5. Assemble and write out the final mosaic image

---

## What I Learned
- Implementing and optimizing k-d trees
- Working with image data and color space conversions
- Managing large image datasets in memory-efficient ways
- Applying spatial partitioning and recursive design in real systems

## Possible Improvements
- Support non-square or adaptive tiles
- Add parallelization with OpenMP or CUDA
- Port to WebAssembly for browser demo (planned)
-GUI interface for image selection and tile config

## Author
Shailee Patel <br>
Email: shaileepatel05@gmail.com <br>
LinkedIn: linkedin.com/in/shailee-patel-04481b285<br>
GitHub: github.com/shailee2


