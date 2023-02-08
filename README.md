# FREEQO
Failure-Resilient Eulerian graph Encoding (for) Quantum tOurs. 

## Motivations

The reason behind this tool is to implement the algorithm we introduced in the paper _Directed Graph Encoding in Quantum Computing Supporting Edge-Failure_, available [here](https://link.springer.com/chapter/10.1007/978-3-031-09005-9_6) or inside this repository.

In particular, the main procedure takes as input a multigraph _G_ and a family of unitary matrices _U_ and produces a unitary matrix encoding _G_.

## How to Install and Run

Download the project, making sure to have an up-to-date python version installed in your pc.
Unzip the file and just run the command: 
`python Main.py`

## Input Location 

`Main.py` takes the input from the file named `input.txt`. In order to get the input from another point, do the following operations: 
1. Find the file `Main.py` and open it with a text editor
2. Locate this line of code `file_name = "input.txt"`
3. Change `input.txt` with absolute / relative path to the file you have placed the input in. 

For example, to get the input from `"different_input.txt"`, the line of code should look like this: 
`file_name = "different_input.txt"`

## Input Format

In order for the input to be parsed, it must be written using a specific form. 
+ The first line must contain the number of nodes inside the graph. We will denote such value with *n*
+ The following *n* lines have the following syntax: 
  <code> u : u<sub>1</sub>, u<sub>2</sub>, ..., u<sub>k</sub> </code> <br/>
where _u_ is a node name and u<sub>1</sub>, u<sub>2</sub>, ..., u<sub>k</sub> are _u_'s neighbours in the multigraph.
In order to obtain a multigraph, for example _G_ where there are two edges between _u_ and _v_, just write _u_ : _v_, _v_.
Notice that each one of the _n_ different lines should refer to a different node (no controls have been implemented to check repeated nodes in the input reading). <br/> 
Moreover, there is no particular rule for the node naming convention. Just make sure to use the same names in the matrix definition phase.

+ Then a natural number _R_ is expected
+ The following _R_ lines must have the following form: 
 `[list of comma separated nodes] : M` <br/>
 which has to be interpreted as follows: for all the nodes in the list, the unitary matrix to be applied during the unitarize procedure is *M*.
 This syntax is due to the fact that each node in the inital graph _G_, induces a specific submatrix inside the adjacency matrix of _G_'s line graph. In the unitarize procedure we substitute each one of this submatrix with a unitary matrix. Hence, per each node, we must know which unitary to use. 
 In the case some nodes have no unitary defined, the matrix representing the Discrete Fourier Transform ([DFT](https://en.wikipedia.org/wiki/DFT_matrix)) will be used as replacement. 
 As a special case, if _R_ is zero, all submatrices will be susbtituted with the DFT.
 The syntax for the matrix *M* is the following: write each row of the matrix separating the elements with a space. Then each row is separated from the next one with a semicolon. Moreover, when using complex numbers, rember that in python the imaginary unit is written as _j_ and not _i_.
 For example, the matrix for the *Y* gate is: 
 `0 -1j; j 0`
 
 However, the file `src/input.txt` provides an example of well formatted input. 
 
 ## Output
 
 The program will output some informative lines to tell the keep the user updated on the algorithm stages. 
 Once the procedure is completed, the unitary matrix obtained is printed. The standard output channel is the console, so no automatica redirection to output file is done. 
 
 ## iFREEQO
 
 We also developed a web-based interactive version of FREEQO. Check it out [here](http://encase.uniud.it:3002/#/). 
