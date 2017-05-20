Distribution of least-significant-digit of various bases of prime numbers

Author: jaggz.h is at gmail.com
  Date: 2017-05-19
 
A paper from 2016 discusses the non-random distribution of the remainder
(least significant digit) of prime numbers.  This program displays the
distribution of remainders with varying bases.

Article: https://arxiv.org/abs/1603.03720
  Title: Unexpected biases in the distribution of consecutive primes
Authors: Robert J. Lemke Oliver, and Kannan Soundararajan
   Date: 2016-05-30

Relevant files:
  primesieve-distr.c

Notes:
  1. This is limited to 64 bit integers, and doubles.
  2. It doesn't look at screen width.
     Modify the line: "#define BASES 36", in the .c file, for more/less columns.

Compiling:
  1. Requires (lib)primesieve https://github.com/kimwalisch/primesieve
  2. primesieve installs, on my system, to /usr/local/lib/
     You might need to modify the Makefile to point to another folder
  3. Then run make.  It should compile and run ./primesieve-distr

  Example output (snapshot and text):
  ![Output of primesieve-distr.c](snapshots/sample-totals.png)

  Output in text (cropped to 76 columns)
```Prime modulus distribution.  X-axis is modulus result, Y is the base (of the modulus).
 Total primes tested: 59801401  Current prime: 1186348811
   |     1     2     3     4     5     6     7     8     9    10    11    12
---+------------------------------------------------------------------------
 1 |                                                                        
 2 |100.00                                                                  
 3 | 50.00 50.00                                                            
 4 | 50.00       50.00                                                      
 5 | 25.00 25.00 25.00 25.00                                                
 6 | 50.00                   50.00                                          
 7 | 16.67 16.67 16.67 16.67 16.67 16.67                                    
 8 | 25.00       25.00       25.00       25.00                              
 9 | 16.67 16.67       16.67 16.67       16.67 16.67                        
10 | 25.00       25.00                   25.00       25.00                  
11 | 10.00 10.00 10.00 10.00 10.00 10.00 10.00 10.00 10.00 10.00            
12 | 25.00                   25.00       25.00                   25.00      
13 |  8.33  8.33  8.33  8.33  8.33  8.33  8.33  8.33  8.33  8.33  8.33  8.33
14 | 16.67       16.67       16.67                   16.67       16.67      
15 | 12.50 12.50       12.50             12.50 12.50             12.50      
16 | 12.50       12.50       12.50       12.50       12.50       12.50      
17 |  6.25  6.25  6.25  6.25  6.25  6.25  6.25  6.25  6.25  6.25  6.25  6.25
18 | 16.67                   16.67       16.67                   16.67      
19 |  5.55  5.56  5.56  5.56  5.56  5.56  5.56  5.56  5.55  5.56  5.56  5.56
20 | 12.50       12.50                   12.50       12.50       12.50      
21 |  8.33  8.33        8.33  8.33              8.33        8.33  8.33      
22 | 10.00       10.00       10.00       10.00       10.00                  
23 |  4.54  4.55  4.55  4.55  4.55  4.55  4.55  4.55  4.55  4.55  4.55  4.55
24 | 12.50                   12.50       12.50                   12.50      
25 |  5.00  5.00  5.00  5.00        5.00  5.00  5.00  5.00        5.00  5.00
26 |  8.33        8.33        8.33        8.33        8.33        8.33      
27 |  5.56  5.56        5.56  5.56        5.56  5.55        5.55  5.56      
28 |  8.33        8.33        8.33                    8.33        8.33      
29 |  3.57  3.57  3.57  3.57  3.57  3.57  3.57  3.57  3.57  3.57  3.57  3.57
30 | 12.50                               12.50                   12.50      
31 |  3.33  3.33  3.33  3.33  3.33  3.33  3.33  3.33  3.33  3.33  3.33  3.33
32 |  6.25        6.25        6.25        6.25        6.25        6.25      
33 |  5.00  5.00        5.00  5.00        5.00  5.00        5.00            
34 |  6.25        6.25        6.25        6.25        6.25        6.25      
35 |  4.17  4.17  4.17  4.17        4.17        4.17  4.17        4.17  4.17
36 |  8.33                    8.33        8.33                    8.33      
37 |  2.78  2.78  2.78  2.78  2.78  2.78  2.78  2.78  2.78  2.78  2.78  2.78
38 |  5.55        5.56        5.56        5.56        5.55        5.56      
39 |  4.17  4.17        4.17  4.17        4.17  4.17        4.17  4.17      
40 |  6.25        6.25                    6.25        6.25        6.25      
41 |  2.50  2.50  2.50  2.50  2.50  2.50  2.50  2.50  2.50  2.50  2.50  2.50
42 |  8.33                    8.33                                8.33      
43 |  2.38  2.38  2.38  2.38  2.38  2.38  2.38  2.38  2.38  2.38  2.38  2.38
44 |  5.00        5.00        5.00        5.00        5.00                  
45 |  4.17  4.17        4.17              4.17  4.17              4.17      
46 |  4.54        4.55        4.55        4.55        4.55        4.55      
47 |  2.17  2.17  2.17  2.17  2.17  2.17  2.17  2.17  2.17  2.17  2.17  2.17
48 |  6.25                    6.25        6.25                    6.25      
49 |  2.38  2.38  2.38  2.38  2.38  2.38        2.38  2.38  2.38  2.38  2.38
50 |  5.00        5.00                    5.00        5.00        5.00      
51 |  3.12  3.12        3.12  3.12        3.13  3.13        3.12  3.13      
52 |  4.17        4.17        4.17        4.17        4.17        4.17      
53 |  1.92  1.92  1.92  1.92  1.92  1.92  1.92  1.92  1.92  1.92  1.92  1.92
54 |  5.56                    5.56        5.56                    5.56      
55 |  2.50  2.50  2.50  2.50        2.50  2.50  2.50  2.50              2.50
56 |  4.17        4.17        4.17                    4.17        4.17      
57 |  2.78  2.78        2.78  2.78        2.78  2.78        2.78  2.78      
58 |  3.57        3.57        3.57        3.57        3.57        3.57      
59 |  1.72  1.72  1.72  1.72  1.72  1.72  1.72  1.72  1.72  1.72  1.72  1.72```
