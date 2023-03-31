# V0.4 #


Additions in this version of the project:
New option to generate files of students with random grades,
algorithm for sorting the generated file, finding division point based on specific grade,
creating two new files based on the division.
Program working time analysis.


## Usage ##

 _v04.cpp_ file has the main function.
 _v04funkcijos.cpp_ file has the functions used in main.
 _generator.cpp_ file has the function to generate new files.
 _antrastes.h_ file has prototypes of functions and used directories.
 _analize.cpp_ file has the function for analysing programs work.

## Program Testing ##

Number of grades: 5;

  | Number of students 	| Part of code                                      | Time (sec) 	|
  |---------------------|---------------------------------------------------|-------------|
  | 1000         	      | Failo nuskaitymas                                	| 0.01891    	|
  |              	      | Vektoriaus padalijimas i dvi dalis 	             	| 0.00151     |
  |              	      | Rašymas i faila levekai                	          | 0.00778    	|
  |              	      | Rašymas i faila ketekai                           | 0.00776    	|
  |              	      | Bendras laikas                                   	| 0.03597    	|
  |              	      |                                                  	|            	|
  | 10000        	      | Failo nuskaitymas                                	| 0.04704    	|
  |              	      | Vektoriaus padalijimas i dvi dalis 	             	| 0.01538     |
  |              	      | Rašymas i faila levekai                	          | 0.06965    	|
  |              	      | Rašymas i faila ketekai                           | 0.06632    	|
  |              	      | Bendras laikas                                   	| 0.19839    	|
  |              	      |                                                  	|            	|
  | 100000        	     | Failo nuskaitymas                                	| 0.32369    	|
  |              	      | Vektoriaus padalijimas i dvi dalis 	             	| 0.18782     |
  |              	      | Rašymas i faila levekai                	          | 0.29520    	|
  |              	      | Rašymas i faila ketekai                           | 0.42642    	|
  |              	      | Bendras laikas                                   	| 1.23310     |
  |              	      |                                                  	|            	|
  | 1000000        	    | Failo nuskaitymas                                	| 3.50290    	|
  |              	      | Vektoriaus padalijimas i dvi dalis 	             	| 2.68010     |
  |              	      | Rašymas i faila levekai                	          | 3.23938    	|
  |              	      | Rašymas i faila ketekai                           | 3.18551    	|
  |              	      | Bendras laikas                                   	| 12.6080     |
  |              	      |                                                  	|            	|
  | 10000000        	   | Failo nuskaitymas                                	| 29.9727    	|
  |              	      | Vektoriaus padalijimas i dvi dalis 	             	| 28.3466     |
  |              	      | Rašymas i faila levekai                	          | 25.2744    	|
  |              	      | Rašymas i faila ketekai                           | 28.2289    	|
  |              	      | Bendras laikas                                   	| 111.823     |
