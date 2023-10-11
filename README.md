# Graph

The C++ project to find the graph measurements like - Length, Eccentricity, Radius, Diameter, Centre of Graph

1.Length – Length of the graph is defined as the number of edges contained in the graph.


![image](https://github.com/vikasreddy1406/Graph/assets/96761217/d33b7ca8-69cc-4daa-a632-150077529f5b)


2.Eccentricity of graph – It is defined as the maximum distance of one vertex from other vertex. The maximum distance between a vertex to all other vertices is considered as the eccentricity of the vertex. It is denoted by e(V).


![image](https://github.com/vikasreddy1406/Graph/assets/96761217/d290a8b1-a1ab-452d-a573-4cb777afd97f)


     Eccentricity from:
    (A, A) = 0
    (A, B) = 1
    (A, C) = 2
    (A, D) = 1
        Maximum value  is 2, So Eccentricity is 2



3.Radius of graph – A radius of the graph exists only if it has the diameter. The minimum among all the maximum distances between a vertex to all other vertices is considered as the radius of the Graph G. It is denoted as r(G). It can also be found by finding the minimum value of eccentricity from all the vertices.


![image](https://github.com/vikasreddy1406/Graph/assets/96761217/3c342215-1d23-480a-b223-c20396e9b561)


  Radius: 2
     All available minimum radius: 
     BC → CF,
     BC → CE,
     BC → CD,
     BC → CA



4.Diameter of graph – The diameter of graph is the maximum distance between the pair of vertices. It can also be defined as the maximal distance between the pair of vertices. Way to solve it is to find all the paths and then find the maximum of all. It can also be found by finding the maximum value of eccentricity from all the vertices.


![image](https://github.com/vikasreddy1406/Graph/assets/96761217/138eecbb-a27b-4556-911f-5a2b9a03aabd)


  Diameter: 3
  BC → CF → FG  
 Here the eccentricity of the vertex B is 3 since (B,G) = 3. (Maximum Eccentricity of Graph)



5.Centre of graph – It consists of all the vertices whose eccentricity is minimum. Here the eccentricity is equal to the radius. For example, if the school is at the center of town it will reduce the distance buses has to travel. If eccentricity of two vertex is same and minimum among all other both of them can be the center of the graph.


![image](https://github.com/vikasreddy1406/Graph/assets/96761217/81c782f2-971e-471b-bee2-fdf7e73436ca)


  Centre: A  
  Inorder to find the center of the graph, we need to find the eccentricity of each vertex and
  find the minimum among all of them. The minimum eccentricity vertex will be considered as the center.

  

