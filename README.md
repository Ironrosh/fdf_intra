# fdf_intra
Small project that takes an input file where rows represent y coordinate, columns represent x coordinate and the values separated by whitespaces represent z coordinate. <br/> Example: <br/>

|    	| x1 	| x2 	| x3 	| x4 	| x5 	|
|----	|----	|----	|----	|----	|----	|
| y1 	| 1  	| 1  	| 1  	| 1  	| 1  	|
| y2 	| 1  	| 2  	| 2  	| 2  	| 1  	|
| y3 	| 1  	| 2  	| 3  	| 2  	| 1  	|
| y4 	| 1  	| 2  	| 2  	| 2  	| 1  	|
| y5 	| 1  	| 1  	| 1  	| 1  	| 1  	|<br/>

And then draws Isometric/Parallel projection based on that file.
<p>How to build and use:<br/>
make<br/>
./fdf file_name</p>
