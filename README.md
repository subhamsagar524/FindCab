# FindCab-Finding Nearby Cabs 
- Design and implement a project as instructed below: 
-   • Create an input file which contains user_id, latitude, longitude, and name (cab driver) of the cabs. 
-   • Obtain latitude and longitude of each cab along with user-id and name of the driver from the input file. 
-   • Convert latitude and longitude of both the user and the cab present in degrees to radians. 
-   • Calculate distance between the users location and the cab using the Great Circle Distance formula. 
-   • If the distance is found to be less than or equal to 10 km, then output the user-id and name of the cab driver to a new file (output file) else take no action. 

- Note: 
Great-circle distance Let λ1,φ1 and λ2,φ2 be the geographical longitude and latitude in radians of two points 1 and 2, and ∆λ, ∆φ be their absolute differences; then ∆σ, the central angle between them, is given by the spherical law of cosines if one of the poles is used as an auxiliary third point on the sphere. 
- ∆σ = arccos (sin φ1 sin φ2 + cos φ1 cos φ2 cos(∆λ)) The problem is normally expressed in terms of finding the central angle ∆σ . Given this angle in radians, the actual arc length d on a sphere of radius r can be trivially computed as 
d = r ∆σ. 

For testing try values 0 80, 45 90 etc...
Or check the input file in src folder.
