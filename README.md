We modelled the road network around MUBAS in Blantyre, Malawi, as a weighted, undirected graph. It has 20 nodes (A to T), each one a location. Each edge is a road between two locations, and its weight is the approximate travel time in minutes.

The program uses Dijkstra's algorithm to find the shortest travel time and the route between any two locations.
Open the link below, press Run, then type the start and destination nodes when the program asks for them.

https://onlinegdb.com/S_PcKEq-Q

Example input:

Enter the starting node : A
Enter the destination node : I

Expected output:

RESULT FROM A TO I:
Shortest Distance: 40
Path: A -> B -> G -> H -> I

The program also prints each node as it is visited, along with its distance, before the result

g++ main.cpp -o dijkstra
./dijkstra

Locations
Node	Location	Node	Location
A	MUBAS	K	Mosque
B	Chichiri Shopping Mall	L	Build Africa
C	College of Medicine (COM)	M	Chigumula
D	Queen Elizabeth Hospital	N	National Bank Chichiri
E	Ginnery Corner	O	KFC Blantyre Town
F	Chichiri Secondary	P	Shopwise
G	Museum of Malawi	Q	Nando's
H	Golden Peacock	R	Sana Ginnery Corner
I	Kamuzu Stadium	S	Mount Soche
J	Sanjika Palace	T	Cross Roads
Input rules
Enter a single letter from A to T. 
Any other letter prints.



The graph is connected, undirected and weighted, so it has a minimum spanning tree (MST). With 20 vertices, an MST has exactly 19 edges. It represents the set of roads that connects all 20 locations with the least total travel time and no unnecessary loops.

We chose Kruskal's algorithm for finding the MST. This is explained in the report, and the code in this repository covers only Dijkstra's algorithm.
