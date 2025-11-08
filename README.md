## FDF (Fil de Fer / Wireframe)

FDF (Fil de Fer, meaning "Iron Wire" or **Wireframe**) is a project that renders a **landscape wireframe in 2.5D** from elevation data (in the `.fdf` format), utilizing techniques of **linear transformation**, **projection**, and **line rasterization**. Developed with passion and dedication, FDF transforms pixels into 3D shapes!

-----
## 🖼️ Visual Showcase

The following examples demonstrate FDF's rendering capabilities, color interpolation, and bonus features.

![Render of FDF](assets/chess.png)
![Render of FDF](assets/example12.png)
![Render of FDF](assets/lego.png)
![Render of FDF](assets/spiral_tupla.png)
![Render of FDF](assets/:3.png)
-----

## 🚀 Key Features

  * **2.5D Wireframe Rendering:** Plots a complex 3D map onto a 2D screen, creating a wireframe visualization (the **2.5D** concept).
  * **Serial Line Rasterization:** Uses the **Bresenham's line algorithm** to efficiently draw serial lines connecting the map points.
  * **Custom Color Support:** Reads and applies colors defined within the input file.
  * **Color Interpolation:** Applies **color interpolation** to smooth the lines drawn by the Bresenham's algorithm, resulting in a more visually appealing output.

-----

## 🛠️ Technologies and Concepts

| Category | Description |
| :--- | :--- |
| **Main Language** | C |
| **Graphics Libraries** | **MLX42** (Codam's dedicated graphics library built on GLFW and OpenGL) |
| **Geometry** | **3D to 2D Linear Transformation** (Projection) |
| **Mathematics** | **Vector Mathematics** applied to coordinates |
| **Drawing** | **Bresenham's Algorithm** for line drawing |

-----

## ⚙️ Structure and Implementation

The project processes the map through the following stages:

### 1\. File Parsing

The elevation map is read from an input file with the extension `.fdf` in the format:

```
0 0 0 0 0 0 ...
0 0 0 0 1 0 0,0xFF (Optional Color) ...
...
```

  * The elevation data is stored in a 2x2 array: **Points Map**.
  * The optional color information is stored in a separate 2x2 array: **Colors Map**.

### 2\. Allocation and Calculation

After memory allocation, the program performs the mathematical calculations to prepare the data for the rasterized screen:

  * A **3D to 2D linear transformation** (projection) is applied to each point, converting the 3D world coordinates (x, y, z) to the 2D screen coordinates (x', y'), using **vector mathematics**.

### 3\. Rendering

  * The transformed coordinates are connected by lines drawn using the Bresenham's algorithm, leveraging the capabilities of **MLX42**.
  * **Color interpolation** is applied during the line drawing process to ensure smooth transitions between points with different colors.

-----

## 🏆 Implemented Bonuses

The project includes advanced functionalities for map manipulation and visualization:

  * **Rotation:** Implementation of **rotation** calculations around the $x$, $y$, and $z$ axes.
  * **Different Perspectives:** Application of other mathematical perspectives (e.g., Conic/Perspective Projection, Parallel/Isometric Projection), beyond the main one.

-----

## 🖥️ Installation and Execution

To run the project locally, the **MLX42** library and its dependencies must be properly set up on your system.

### 1\. Install Dependencies

You must install the following libraries required by MLX42 (e.g., on Debian/Ubuntu):

```bash
sudo apt install build-essential cmake libglfw3-dev libglew-dev libglu1-mesa-dev libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev
```

### 2\. Clone and Initialize Submodules

The **MLX42** library is included as a Git Submodule. Use the `--recurse-submodules` flag to clone the repository and automatically initialize and update the submodule:

```bash
git clone --recurse-submodules [Your Repo Link Here]
cd fdf
```

### 3\. Compile the Program

You can compile the standard version or the bonus version (which includes rotation and perspective features):

  * **Standard Version:**
    ```bash
    make
    ```
  * **Bonus Version:**
    ```bash
    make bonus
    ```

### 4\. Execute

The program expects a compiled binary (`fdf` or `fdf_bonus`) and an `.fdf` map file as an argument.

  * **Example (Standard):**
    ```bash
    ./fdf <path/to/the/file.fdf>
    ```
  * **Example (Bonus):**
    ```bash
    ./fdf_bonus <path/to/the/file.fdf>
    ```

-----

## 👤 Author

**tlavared** - 42 São Paulo


*Made with ❤️ at 42 São Paulo*
