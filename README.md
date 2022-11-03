# Quadrilateral-point-distances
Tests used:

1)
Input:<br/>
1 2 1<br/>
1 9 2<br/>
5 5 5<br/>
5 5 6<br/>

Output:
The positions of the points you have entered, ordered by descending latitude, ascending longitude, are:
(5.00, 5.00, 5.00)<br/>
(5.00, 5.00, 6.00)<br/>
(1.00, 2.00, 1.00)<br/>
(1.00, 9.00, 2.00)<br/>
Distance between point (1.00, 2.00, 1.00) and point (1.00, 9.00, 2.00) is 779236 meters.<br/>
Distance between point (1.00, 2.00, 1.00) and point (5.00, 5.00, 5.00) is 556597 meters.<br/>
Distance between point (1.00, 2.00, 1.00) and point (5.00, 5.00, 6.00) is 556597 meters.<br/>
Distance between point (1.00, 9.00, 2.00) and point (5.00, 5.00, 5.00) is 629718 meters.<br/>
Distance between point (1.00, 9.00, 2.00) and point (5.00, 5.00, 6.00) is 629718 meters.<br/>
Distance between point (5.00, 5.00, 5.00) and point (5.00, 5.00, 6.00) is 1 meters.

2)
Input:<br/>
-90 -180 0<br/>
90 179 0<br/>
0 0 0<br/>
1 2 3<br/>

Output:
The positions of the points you have entered, ordered by descending latitude, ascending longitude, are:
(90.00, 179.00, 0.00)<br/>
(1.00, 2.00, 3.00)<br/>
(0.00, 0.00, 0.00)<br/>
(-90.00, -180.00, 0.00)<br/>
Distance between point (-90.00, -180.00, 0.00) and point (90.00, 179.00, 0.00) is 4.47057e+07 meters.<br/>
Distance between point (-90.00, -180.00, 0.00) and point (0.00, 0.00, 0.00) is 2.24026e+07 meters.<br/>
Distance between point (-90.00, -180.00, 0.00) and point (1.00, 2.00, 3.00) is 2.26515e+07 meters.<br/>
Distance between point (90.00, 179.00, 0.00) and point (0.00, 0.00, 0.00) is 2.23031e+07 meters.<br/>
Distance between point (90.00, 179.00, 0.00) and point (1.00, 2.00, 3.00) is 2.20542e+07 meters.<br/>
Distance between point (0.00, 0.00, 0.00) and point (1.00, 2.00, 3.00) is 248918 meters.

3)
Input:<br/>
0 0 0<br/>
1 1 1<br/>
2 2 2<br/>
0 0 0<br/>

Output:
Error: Point with the same position already exists

4)
Input:<br/>
90 180 0<br/>
0 0 0<br/>
1 1 1<br/>
2 2 2<br/>

Output:
Error: Longitude outside of accepted range [-180, 180)

5)
Input:<br/>
180 180 0<br/>
0 0 0<br/>
1 1 1<br/>
2 2 2<br/>

Output:
Error: Latitude outside of accepted range [-90, 90]

