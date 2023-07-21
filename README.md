#FIL DE FER


This project is about creating a 3D wireframe model from a 2D map. Here's a simplified explanation of the process:

The project starts with a map that contains only numbers. 
Each number's position on this map represents its x and y coordinates (just like a point on a grid),
while the value of the number itself indicates its height or depth - this is our z coordinate.


The first step is to parse the map. The program does this with a file named "parsing.c",
which works in conjunction with "parsing_utils.c". These two work together to transform the map into a 2D matrix of characters (or chars).


After parsing the map, the program then needs to convert these 3D coordinates into something that can be displayed on a 2D screen. 
It does this with the "projection.c" file. 
This file uses a mathematical trick to create the illusion of 3D on a 2D plane. 
The result is a new matrix of structures, each containing the 2D projections (representations) of the original 3D points.


Finally, the program needs to actually draw this wireframe model. This is where the "rendering.c" file comes in. 
It uses a tool called the minilibx library and a technique called Bresenham's algorithm to create edges and lines on the screen,
 bringing our wireframe model to life.