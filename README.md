# V3.0 #


Additions in this version of the project: <br />
Custom Vector class experiments <br />

Functions tested:<br />
shrink_to_fit()<br />
clear()<br />
push_back()<br />
back()<br />
begin()<br />
All expected outputs were correct.<br />

Experementing with ordinary and custom vectors:<br />

unsigned int sz = 10000; // 100000, 1000000, 10000000, 100000000<br />
    auto start = high_resolution_clock::now();<br />
    std::vector<int> v1;<br />
    for (int i = 1; i <= sz; ++i)<br />
        v1.push_back(i);<br />
    auto end = high_resolution_clock::now();<br />
    duration<double> diff = end - start;<br />
    cout << "standartinio vektoriaus laikas: " << diff.count() << " s\n";<br />

    start = high_resolution_clock::now();<br />
    CustomVector<int> v2;<br />
    for (int i = 1; i <= sz; ++i)<br />
        v2.push_back(i);<br />
    end = high_resolution_clock::now();<br />
    diff = end - start;<br />
    cout << "Custom vektoriaus laikas: " << diff.count() << " s\n";<br />

Results:<br />
| Student count     | vector time 	    |Custom Vector time  | 
  |--------------	|------------------	|--------------------|  
  | 100000         	| 0.0019            | 0.000996           |
  | 1000000        	| 0.020912          | 0.017014 	         |
  | 10000000       	| 0.146934          | 0.12139  	         |         
  | 100000000      	| 1.42236          	| 0.925335  	     |              
        

Atminties perskirstymu palyginimas:<br />
   while (input_file >> grupe)<br />
    {<br />
        if (grupe.size() == grupe.capacity())<br />
        {<br />
            perskirstymas++;<br />
        }<br />
    }<br />
    cout << "Buvo " << perskirstymas << " perskirtymu."<<endl;<br />

Result:<br />
vector - 20 kartu<br />
CustomVector - 20 kartu<br />
    
    
Palyginimas programos veikimo su vektoriais:<br />
Su Custom Vector - "Bendrai darbas su failu 'studentai100000.txt' uztruko: 1.53306 s"<br />
Su vector - "Bendrai darbas su failu 'studentai100000.txt' uztruko: 1.503 s"<br />
    
    
    
    
    
# Unit Tests #

// Tests for the Zmogus class <br />
TEST(ZmogusTest, GetterTests) <br />
{ <br />
    Zmogus zmogus("Just", "Blue"); <br />
    EXPECT_EQ(zmogus.getVardas(), "Just"); <br />
    EXPECT_EQ(zmogus.getPavarde(), "Blue"); <br />
} <br />

TEST(ZmogusTest, SetterTests) <br />
{ <br />
    Zmogus zmogus; <br />
    zmogus.setVardas("Just"); <br /> 
    zmogus.setPavarde("Blue"); <br />
    EXPECT_EQ(zmogus.getVardas(), "Just"); <br />
    EXPECT_EQ(zmogus.getPavarde(), "Blue"); <br />
} <br />

// Tests for the studentas class <br />
TEST(StudentasTest, ConstructorTests) <br />
{ <br />
    std::vector<int> pazymiai = {8, 9, 8}; <br /> 
    studentas stud("Just", "Blue", pazymiai, 9); <br />
    EXPECT_EQ(stud.getVardas(), "Just"); <br />
    EXPECT_EQ(stud.getPavarde(), "Blue"); <br />
    EXPECT_EQ(stud.getGalMed(), 8.6); <br />
} <br />

TEST(StudentasTest, GetterTests) <br />
{ <br />
    std::vector<int> pazymiai = {8, 9, 8}; <br />
    int size = pazymiai.size(); <br /> 
    int egz = 9, suma = 0; <br /> 
    for (int i = 0; i < size; i++) <br />
    { <br /> 
        suma = suma + pazymiai[i]; <br />
    } <br />
    double vid = suma / size; <br />
    studentas stud("Just", "Blue", pazymiai, egz); <br />
    EXPECT_EQ(stud.getGalVid(), vid * 0.4 + 0.6 * egz); <br />
} <br />

TEST(StudentasTest, SetterTests) <br />
{ <br />
    studentas stud; <br />
    stud.setVardas("Just"); <br />
    stud.setPavarde("Blue"); <br />
    stud.setGalutinisVid(5); <br />
    stud.setGalutinisMed(4); v
    EXPECT_EQ(stud.getVardas(), "Just"); <br />
    EXPECT_EQ(stud.getPavarde(), "Blue"); <br />
    EXPECT_EQ(stud.getGalVid(), 5); <br />
    EXPECT_EQ(stud.getGalMed(), 4); <br />
} <br />

// Tests for friend functions <br />
TEST(FriendFunctionTest, OperatorInputTest) <br />
{ <br />
    std::istringstream input("Just Blue 8 9 8 9\n"); <br /> 
    std::vector<studentas> students; <br />
    input >> students; <br />
    EXPECT_EQ(students.size(), 1); <br />
} <br />

# Tests Output #

[ctest] [==========] Running 6 tests from 3 test suites. <br />
[ctest] [----------] Global test environment set-up. <br /> 
[ctest] [----------] 2 tests from ZmogusTest <br />
[ctest] [ RUN      ] ZmogusTest.GetterTests <br />
[ctest] [       OK ] ZmogusTest.GetterTests (0 ms) <br />
[ctest] [ RUN      ] ZmogusTest.SetterTests <br />
[ctest] [       OK ] ZmogusTest.SetterTests (0 ms) <br />
[ctest] [----------] 2 tests from ZmogusTest (0 ms total)<br />
[ctest] <br />
[ctest] [----------] 3 tests from StudentasTest<br />
[ctest] [ RUN      ] StudentasTest.ConstructorTests<br />
[ctest] [       OK ] StudentasTest.ConstructorTests (0 ms)<br />
[ctest] [ RUN      ] StudentasTest.GetterTests<br />
[ctest] error: Expected equality of these values:<br />
[ctest]   stud.getGalVid()<br />
[ctest]     Which is: 8.7333333333333343<br />
[ctest]   vid * 0.4 + 0.6 * egz<br />
[ctest]     Which is: 8.6<br />
[ctest] <br />
[ctest] [  FAILED  ] StudentasTest.GetterTests (3 ms)<br />
[ctest] [ RUN      ] StudentasTest.SetterTests<br />
[ctest] [       OK ] StudentasTest.SetterTests (0 ms)<br />
[ctest] [----------] 3 tests from StudentasTest (3 ms total)<br />
[ctest] <br />
[ctest] [----------] 1 test from FriendFunctionTest<br />
[ctest] [ RUN      ] FriendFunctionTest.OperatorInputTest<br />
[ctest] [       OK ] FriendFunctionTest.OperatorInputTest (0 ms)<br />
[ctest] [----------] 1 test from FriendFunctionTest (0 ms total)<br />
[ctest] <br />
[ctest] [----------] Global test environment tear-down<br />
[ctest] [==========] 6 tests from 3 test suites ran. (7 ms total)<br />
[ctest] [  PASSED  ] 5 tests.<br />
[ctest] [  FAILED  ] 1 test, listed below:<br />
[ctest] [  FAILED  ] StudentasTest.GetterTests<br />
[ctest] <br />
[ctest]  1 FAILED TEST<br />



# Previous releases #
0.1 - initial prototype of the program.
0.2 - added file reading and sorting.
0.3 - code division, random grade generation.
0.4 - file generation, program time analysis.
0.5 - program analysis with 3 data structures.
0.5fix - option to choose between generated and existing files.
1.0 - completed initial program.
1.1 - flags compared, struct and class analysis, class addition.
1.2 - rule of five implemented.
1.5 - Studentas class made derivative from class Zmogus.

## Usage ##
Setup:
Using exe file will create program shortcut, which opens console application. Follow commands there.

"make" - creates all the program files.
"make clean" - cleans all the installed building files.
 Every folder contains independent program with different data structures.
 Folders _Vector_,_Deque_,_List_ contain program based on first division strategy.
 Folders _Vector2_,_Deque2_,_List2_ contain program based on second division strategy.
 _v05.cpp_ file has the main function.
 _v05funkcijos.cpp_ file has the functions used in main.
 _generator.cpp_ file has the function to generate new files.
 _antrastes.h_ file has prototypes of functions and used directories.
 _analize.cpp_ file has the function for analysing programs work.


## Program Testing ##

Number of grades: 5;

   #### Duomenų nuskaitymas

  | Student count | Data structure   	| Time (s)   	|
  |--------------	|------------------	|------------	|
  | 1000         	| Vector           	| 0.008703    |
  |              	| Deque            	| 0.007113   	|
  |              	| List             	| 0.027285   	|
  |              	|                  	|            	|
  | 10000        	| Vector           	| 0.041365  	 |
  |              	| Deque            	| 0.03226    	|
  |              	| List             	| 0.059282  	 |
  |              	|                  	|            	|
  | 100000       	| Vector           	| 0.287954   	|
  |              	| Deque            	| 0.291207 	  |
  |              	| List             	| 0.37059  	  |
  |              	|                  	|            	|
  | 1000000      	| Vector           	| 2.8036  	   |
  |              	| Deque            	| 2.87365  	  |
  |              	| List             	|  3.28074   	|
  |              	|                  	|            	|
  | 10000000     	| Vector           	| 28.761  	   |
  |              	| Deque            	| 42.2874  	  |
  |              	| List             	| 34.9019    	|

  #### Dalijimas i dvi dalis
  
  | Įrašų kiekis 	| Duomenų strukūra 	| Trukmė (s) 	|
  |--------------	|------------------	|------------	|
  | 1000         	| Vector           	| 0.002305   	|
  |              	| Deque            	|  0.005348  	|
  |              	| List             	| 0.000718   	|
  |              	|                  	|            	|
  | 10000        	| Vector           	| 0.017539   	|
  |              	| Deque            	| 0.048986   	|
  |              	| List             	| 0.00885  	  |
  |              	|                  	|            	|
  | 100000       	| Vector           	| 0.204198   	|
  |              	| Deque            	| 0.542224   	|
  |              	| List             	| 0.129268  	 |
  |              	|                  	|            	|
  | 1000000      	| Vector           	|2.56121  	   |
  |              	| Deque            	| 7.26168  	  |
  |              	| List             	| 1.47823  	  |
  |              	|                  	|            	|
  | 10000000     	| Vector           	| 30.5022    	|
  |              	| Deque            	| 49.2346  	  |
  |              	| List             	| 20.2182  	  |

  #### Levekai isvedimas
  
  | Įrašų kiekis 	| Duomenų strukūra 	| Trukmė (s) 	|
  |--------------	|------------------	|------------	|
  | 1000         	| Vector           	| 0.017916 	  |
  |              	| Deque            	| 0.010466  	 |
  |              	| List             	| 0.006007    |
  |              	|                  	|            	|
  | 10000        	| Vector           	| 0.035988  	 |
  |              	| Deque            	| 0.047747  	 |
  |              	| List             	| 0.047978  	 |
  |              	|                  	|            	|
  | 100000       	| Vector           	| 0.419225   	|
  |              	| Deque            	| 0.421703 	  |
  |              	| List             	| 0.12926  	  |
  |              	|                  	|            	|
  | 1000000      	| Vector           	| 2.91622     |
  |              	| Deque            	| 3.19607    	|
  |              	| List             	| 3.40588    	|
  |              	|                  	|            	|
  | 10000000     	| Vector           	| 26.9167    	|
  |              	| Deque            	| 28.6852  	  |
  |              	| List             	| 29.7182    	|

  #### Ketekai isvedimas
  
  | Įrašų kiekis 	| Duomenų strukūra 	| Trukmė (s) 	|
  |--------------	|------------------	|------------	|
  | 1000         	| Vector           	| 0.006318  	 |
  |              	| Deque            	|  0.010766  	|
  |              	| List             	| 0.048581  	 |
  |              	|                  	|            	|
  | 10000        	| Vector           	| 0.03809  	  |
  |              	| Deque            	| 0.046056   	|
  |              	| List             	| 0.048581   	|
  |              	|                  	|            	|
  | 100000       	| Vector           	| 0.28657    	|
  |              	| Deque            	| 0.338569  	 |
  |              	| List             	| 0.321852  	 |
  |              	|                  	|            	|
  | 1000000      	| Vector           	| 3.3089  	   |
  |              	| Deque            	| 3.5264     	|
  |              	| List             	| 3.62349    	|
  |              	|                  	|            	|
  | 10000000     	| Vector           	| 28.3497    	|
  |              	| Deque            	| 32.9531  	  |
  |              	| List             	| 34.3291  	  |
  
  #### Bendras laikas
  
  | Įrašų kiekis 	| Duomenų strukūra 	| Trukmė (s) 	|
  |--------------	|------------------	|------------	|
  | 1000         	| Vector           	| 0.035242  	 |
  |              	| Deque            	| 0.033693  	 |
  |              	| List             	| 0.040733  	 |
  |              	|                  	|            	|
  | 10000        	| Vector           	| 0.132982  	 |
  |              	| Deque            	| 0.175049  	 |
  |              	| List             	| 0.164691   	|
  |              	|                  	|            	|
  | 100000       	| Vector           	| 1.19795    	|
  |              	| Deque            	| 1.5937  	   |
  |              	| List             	| 1.11342    	|
  |              	|                  	|            	|
  | 1000000      	| Vector           	| 11.5899  	  |
  |              	| Deque            	| 17.0633  	  |
  |              	| List             	| 11.7884  	  |
  |              	|                  	|            	|
  | 10000000     	| Vector           	| 114.53     	|
  |              	| Deque            	| 153.1603  	 |
  |              	| List             	| 119.167  	  |
  
  
    #### Dalijimo i dvi dalis strategiju palyginimas 
    (1 strategija kuriant du naujus konteineriu,
    2 strategija kuriant viena nauja ir naudojant senaji konteineri).
  
  | Įrašų kiekis 	| Duomenų strukūra 	| Trukmė (1) 	| Trukmė (2) |
  |--------------	|------------------	|------------	|------------|
  | 1000         	| Vector           	| 0.002305   	| 0.001883   |
  |              	| Deque            	| 0.005348  	 | 0.004232   |
  |              	| List             	| 0.000718   	| 0.001818   |
  |              	|                  	|            	|
  | 10000        	| Vector           	| 0.017539   	| 0.013551   |
  |              	| Deque            	| 0.048986   	| 0.041881   |
  |              	| List             	| 0.00885  	  | 0.027050   |
  |              	|                  	|            	|
  | 100000       	| Vector           	| 0.204198   	| 0.171799   |
  |              	| Deque            	| 0.542224   	| 0.495811   |
  |              	| List             	| 0.129268  	 | 0.268597   |
  |              	|                  	|            	|
  | 1000000      	| Vector           	| 2.56121  	  | 2.159642   |
  |              	| Deque            	| 7.26168  	  | 5.944521   |
  |              	| List             	| 1.47823  	  | 2.610536   |
  |              	|                  	|            	|
  | 10000000     	| Vector           	| 30.5022    	| 26.24518   |
  |              	| Deque            	| 49.2346  	  | 45.56989   |
  |              	| List             	| 20.2182  	  | 27.45686   |
  
  Antroji strategija pagreitino vector ir deque darbą, tačiau sulėtino listo darbą.
  
  
  System:
  Processor	Intel(R) Pentium(R) CPU G4560 @ 3.50GHz, 3504 Mhz, 2 Core(s), 4 Logical Processor(s)
  Installed Physical Memory (RAM)	8.00 GB
  SSD
  
  ## User Manual ##
  Use makefile to connect program files together.
  
1. User is asked for input (f,k or a); f for one time program usage from a file,
k for one time program usage from console, a for program analysis.
2. f -> input file name -> get results.
3. k -> number of homework tasks -> calculate result with (m) median or (v) average -> input students name 
-> input his grades or choose them to be generated -> repeat. Input "baigti darba" to get results.
4. a -> input number of files to be tested -> choose (g) for new file or (s) for existing file -> input file name -> get results.

## Flag performance analysis ##

Flag perfomance analysis with 10 million students (5grades each);

|       | None 	 | O1	   | O2	   | O3    |
|-------|--------|-------|-------|-------|
| Laikas| 110.102|81.9272|71.3786|80.6643|
|       |        |       |       |       |
| Dydis | 3,144KB|3,283KB|3,140KB|3,151KB|

Laikas - time the program took in seconds.
Dydis - .exe file size.

## Struct/Class analysis ##
Used O2 flag since its the fastest.

|Number of students| 100000  | 1000000|10000000|
|------------------|---------|--------|--------|
|Class (sec)       | 0.84666 |7.7331  |71.9592 |
|                  |         |        |        |
|Struct (sec)      | 0.925417|8.6865  |82.3759 |

Overall, class is faster and code is easier to read using it.
The fastest flag was O2, while no flag gave the worst performance.
