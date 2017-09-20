/*
 * Project Euler Practice Environment
 * Alexander Shi
 *
 * Usage: 	
 *		use the PROBLEM_NUM macro to indicate which problem you'd like to find the answer for
 *		then execute run.sh in any UNIX-like environment, and the solution will be output to your shell
 *			
 * Developing Methods:
 *		problem solutions should follow the signature pattern "output_t problem*()", making sure to not trail spaces
 *		the function need only be implemented, the build script will take care of calling it for you
 *
 * Caution:
 *		the end of this file must have a new line without any comments
 *		the key phrase used in the script is "problem", and can not be included in a line that also contains a digit
 */

// *******************/*   *\*******************
// !!!!!!!!!!!!!!!/* CHANGE ME *\!!!!!!!!!!!!!!!
// *!*!*!*!*!*!*!*/*           *\*!*!*!*!*!*!*!*
#define PROBLEM_NUM 	11
// *!*!*!*!*!*!*!*/*           *\*!*!*!*!*!*!*!*
// *******************/*   *\*******************

// ***********/* MACROS */***********
#define CHAR_AS_NUM(c) (c-'0')
using namespace std;

// ***********/* INCLUDES */***********
#include <iostream>
#include <cstdlib>
#include <map>
#include <queue>
#include <string>
#include "PE_helper.h"

// ***********/* TYPEDEFS */***********
typedef long long (*fptr)(void);
typedef long long output_t;


// ***********/* PROBLEMS */***********

// largest product of 4 adjacent numbers
output_t problem11()
{
	const int SEQUENCE_LENGTH = 4;
	const int ARRAY_DIMM = 20;
	int grid[ARRAY_DIMM][ARRAY_DIMM] = {
		 9,02,22,97,38,15,00,40,00,75,04,05,07,78,52,12,50,77,91, 9,
		49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,04,56,62,00,
		81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,03,49,13,36,65,
		52,70,95,23,04,60,11,42,69,24,68,56,01,32,56,71,37,02,36,91,
		22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80,
		24,47,32,60,99,03,45,02,44,75,33,53,78,36,84,20,35,17,12,50,
		32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70,
		67,26,20,68,02,62,12,20,95,63,94,39,63, 9,40,91,66,49,94,21,
		24,55,58,05,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72,
		21,36,23, 9,75,00,76,44,20,45,35,14,00,61,33,97,34,31,33,95,
		78,17,53,28,22,75,31,67,15,94,03,80,04,62,16,14, 9,53,56,92,
		16,39,05,42,96,35,31,47,55,58,88,24,00,17,54,24,36,29,85,57,
		86,56,00,48,35,71,89,07,05,44,44,37,44,60,21,58,51,54,17,58,
		19,80,81,68,05,94,47,69,28,73,92,13,86,52,17,77,04,89,55,40,
		04,52, 9,83,97,35,99,16,07,97,57,32,16,26,26,79,33,27,98,66,
		88,36,68,87,57,62,20,72,03,46,33,67,46,55,12,32,63,93,53,69,
		04,42,16,73,38,25,39,11,24,94,72,18, 9,46,29,32,40,62,76,36,
		20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,04,36,16,
		20,73,35,29,78,31,90,01,74,31,49,71,48,86,81,16,23,57,05,54,
		01,70,54,71,83,51,54,69,16,92,33,48,61,43,52,01,89,19,67,48
	};
	// there must be some statistical way to solve solve this - means or medians to help?
	// it can definitely be said that atleast one of the values in the range of 4 should be greater than the mean
	// double mean = 0;
	// for (int i = 0; i < 400; ++i)
	// {
	// 	mean += grid[i];
	// }
	// mean /= 20*20;

	// BRUTE FORCE
	unsigned long max_product = 0;
	// ***verticals***
	for (int i = 0; i < ARRAY_DIMM; ++i)
	{
		unsigned long product = 1; // starting identity
		int offset = 0;
		for (int j = 0; j < SEQUENCE_LENGTH + offset; ++j) // first product
		{
			product *= grid[i][j];
			if (product == 0) // handle zeroes
			{
				offset += (j+1)%SEQUENCE_LENGTH;
				product = 1;
			}
			// cout << i << "ROW: j " << j << " < " << SEQUENCE_LENGTH + offset << "\n";
		}
		// cout << product << "\t START ROW " << i <<"\n";
		max_product =  (product > max_product) ? product : max_product;
		for (int j = SEQUENCE_LENGTH + offset; j < ARRAY_DIMM - SEQUENCE_LENGTH; ++j)
		{
			product *= grid[i][j];
			product /= grid[i][j-SEQUENCE_LENGTH];
			// handle zeros 
			if (grid[i][j] == 0)
			{
				if (j + SEQUENCE_LENGTH < ARRAY_DIMM) // enough entries to continue in row
				{
					product = 1;
					int range_end = j+SEQUENCE_LENGTH;
					for (int k = j+1; k <= range_end; ++k) // rebuild product
					{
						product *= grid[i][k];
						if (product == 0) // if zeroes in rebuild, consider whether enough entries remaining
						{
							range_end = k + SEQUENCE_LENGTH;
							if (range_end > ARRAY_DIMM)
							{
								break; // out of entries
							}
							product = 1;
						}
						
					}
					j=range_end; // successful product rebuild
				}
				else
				{
					break; // 0 too close to end
				}
			} // end handle zeroes

			// cout << grid[i][j] << "\t" << product << "\t" << i << "\t" << j << "\n";
			max_product =  (product > max_product) ? product : max_product;
		}
	}
	//***horizontals*** -> same code as verticals, with grid indexes switched
	// alternatively could repeat same code over transpose matrix
	for (int i = 0; i < ARRAY_DIMM; ++i)
	{
		unsigned long product = 1; // starting identity
		int offset = 0;
		for (int j = 0; j < SEQUENCE_LENGTH + offset; ++j) // first product
		{
			product *= grid[j][i];
			if (product == 0) // handle zeroes
			{
				offset += (j+1)%SEQUENCE_LENGTH;
				product = 1;
			}
			// cout << i << "COL: j " << j << " < " << SEQUENCE_LENGTH + offset << "\n";
		}
		// cout << product << "\t START COL " << i <<"\n";
		max_product =  (product > max_product) ? product : max_product;
		for (int j = SEQUENCE_LENGTH + offset; j < ARRAY_DIMM - SEQUENCE_LENGTH; ++j)
		{
			product *= grid[j][i];
			product /= grid[j-SEQUENCE_LENGTH][i];
			// handle zeros 
			if (grid[j][i] == 0)
			{
				if (j + SEQUENCE_LENGTH < ARRAY_DIMM) // enough entries to continue in row
				{
					product = 1;
					int range_end = j+SEQUENCE_LENGTH;
					for (int k = j+1; k <= range_end; ++k) // rebuild product
					{
						product *= grid[k][i];
						if (product == 0) // if zeroes in rebuild, consider whether enough entries remaining
						{
							range_end = k + SEQUENCE_LENGTH;
							if (range_end > ARRAY_DIMM)
							{
								break; // out of entries
							}
							product = 1;
						}
						
					}
					j=range_end; // successful product rebuild
				}
				else
				{
					break; // 0 too close to end
				}
			} // end handle zeroes

			// cout << grid[j][i] << "\t" << product << "\t" << i << "\t" << j << "\n";
			max_product =  (product > max_product) ? product : max_product;
		}
	} // vert max: col 15 rows 6-9, 66*91*88*97 = 51267216
	
	//***diagonals***
	for ( int i = 0; i <= ARRAY_DIMM - SEQUENCE_LENGTH; ++i) 
	{
		unsigned long  product = 1;
		for (int j = 0; j <= ARRAY_DIMM - SEQUENCE_LENGTH; ++j)
		{
			for (int k = 0; k < SEQUENCE_LENGTH; ++k)
			{
				product*=grid[i+k][j+k];
			}
			// cout << "\\ " << product << "\n";
			max_product = (product > max_product) ? product : max_product;
			product = 1;
			for (int k = 0; k < SEQUENCE_LENGTH; ++k)
			{
				product*=grid[ARRAY_DIMM-1-i-k][ARRAY_DIMM-1-j+k];
			}
			// cout << "/ " << product << "\n";
			max_product = (product > max_product) ? product : max_product;
			product = 1;
		}
	} // 70600674
	// Alternate indexing idea:
	//by grabbing the head of the grid array i can access known indexes and advantage of the row-by-row mapping 
	//to create methods to access the next UP/DOWN LEFT/RIGHT element by incrementing the index by some f'n(ARRAY_DIMM)
	// as a result, a traversal going DOWNRIGHT would only require me to access indexes in increments of ARRAY_DIMM+1, 
	// with the check being simple for whether the next element is outside of the grid (idx >= 400), 
	// and whether there are 4 elements in this diagonal by evaluating if (idx + 4*ARRAY_DIMM + 4 >= 400)
	return max_product;
}

// sum of primes below 2mill
output_t problem10()
{
	const int CHECKPOINT_INTERVAL = 1E5;
	long long output = 2; // 2 is known
	int checkpoint = CHECKPOINT_INTERVAL;
	for (int i = 3; i<2E6; i+=2)
	{
		if (isPrime(i) == 1)
		{
			output += i;
			// cout << i << "\t" << output << "\n";
			// cout << ".";
		}
		// else
		// {
		// 	cout << "_";
		// }
		if (i > checkpoint)
		{
			cout << checkpoint << "\n";
			checkpoint += CHECKPOINT_INTERVAL;
		}
	}
	cout << "DONE!\n";
	return output; //142913828922 - this one will take some time to compute
}
// pythagorean triplet a+b+c=1000
output_t problem9()
{
	int b,c;
	int flag = 0;
	// smallest val for c in a possible combo is 334,333,333
	for (c = 334; c <= 998; ++c)
	{
		// iterate on values of c and check respective a,b, combos from s.t. a,b are elements of [1,c-1]
		for (int a = 1; a < c; ++a)
		{
			b = 1000 - c - a;
			if (b > c) // get to region of valid b
			{
				continue;
			}
			if (b < 1) // stop if b no longer valid
			{
				break;
			}
			// cout << a << b << c << "\n";
			if (c*c == a*a + b*b)
			{
				flag = 1;
				break;
			}
		}
		if (flag) {break;}
	}
	return (1000-b-c) * b * c; // 31875000

}

// largest product of 13 contiguous digits
output_t problem8()
{

	const string num =  "73167176531330624919225119674426574742355349194934"
						"96983520312774506326239578318016984801869478851843"
						"85861560789112949495459501737958331952853208805511"
						"12540698747158523863050715693290963295227443043557"
						"66896648950445244523161731856403098711121722383113"
						"62229893423380308135336276614282806444486645238749"
						"30358907296290491560440772390713810515859307960866"
						"70172427121883998797908792274921901699720888093776"
						"65727333001053367881220235421809751254540594752243"
						"52584907711670556013604839586446706324415722155397"
						"53697817977846174064955149290862569321978468622482"
						"83972241375657056057490261407972968652414535100474"
						"82166370484403199890008895243450658541227588666881"
						"16427171479924442928230863465674813919123162824586"
						"17866458359124566529476545682848912883142607690042"
						"24219022671055626321111109370544217506941658960408"
						"07198403850962455444362981230987879927244284909188"
						"84580156166097919133875499200524063689912560717606"
						"05886116467109405077541002256983155200055935729725"
						"71636269561882670428252483600823257530420752963450";

	// unsigned int myVal = 1;
	// for (int i = 0 ; i<13; ++i)	{myVal *= num[i]-'0';}
	// unsigned int output = myVal;
	// 	cout << myVal << "\n";
	// for (int i = 13; i<1000; ++i)
	// {
	// 	if (num[i] == 0) // skip regions with "0"s
	// 	{
	// 		i+=13;
	// 		myVal = 1;
	// 		for (int i = 0 ; i<13; ++i)	{myVal *= num[i]-'0';}
	// 	}
	// 	myVal /= num[i-13] - '0';
	// 	myVal *= num[i]-'0';
	// 	cout << myVal << "\n";
	// 	output = myVal > output ? myVal : output;
	// } // 0 turns into floating point error

	// 1. create a queue for digits seen
	queue<int> myQueue;

	unsigned long long product = CHAR_AS_NUM(num[0]);
	myQueue.push(product);

	unsigned long long max_product = product;
	// 2. iterate through values and push them into back of the queue
	for (int i = 1; i<1000; ++i)
	{
		unsigned int val = CHAR_AS_NUM(num[i]);
		// 2a. if a "0" is seen, flush the queue and reset the running number
		if (val == 0)
		{
			while (!myQueue.empty()){myQueue.pop();}
			do {++i;} while (CHAR_AS_NUM(num[i]) == 0);
			val = CHAR_AS_NUM(num[i]);
			product = val;
			myQueue.push(val);
			// cout << "cleared queue\n";
			continue;
		}

		// 2b. multiply the value of digit into the running num
		product *= val;
		// 2c. add one to the size of the queue
		myQueue.push(val);

		// 2d. if the queue reaches 14 members, dequeue from the front and divide the running num by that val
		if (myQueue.size() == 14)
		{
			product /= myQueue.front();
			myQueue.pop();

		}
		// 2e. if the resulting running num is greater than the stored max, update the stored max
		if (max_product < product)
		{
			max_product = product;
		} 

		// cout << val << "\t" << product << "\t" << max_product << "\t" << myQueue.size() << "\n";

	}
	return max_product; //23514624000
}

//10001st prime
output_t problem7()
{
	//detect primes by using num%i==0 check up to num/2
	//^ is there no way of speeding this up at least?

	int incr[8] = {6, 4, 2, 4, 2, 4, 6, 2};

	//can reduce number of obvious primes by forcing pattern of incr.
	/*
		1	2	3 	4 	5	6	7	8	9	10
		11	12	13 	14 	15	16	17	18	19	20
		21	22	23 	24 	25	26	27	28	29	30

		out of this pattern we know candidates are not Mult of 2,3,5
		therefore only check
		1  7 11 13 17 19 23 29 [31]
		  +6 +4 +2 +4 +2 +4 +6  +2
		(22 out of every 30 elim.)


	*/
	int itr = 31; // 31 is the 11th prime
	int num_prime = 11;
	int add_idx = 0;//addend index
	int is_prime = 1;

	while (num_prime != 10001)
	{
		itr += incr[add_idx++];
		add_idx %= 8;
		//check prime
		// skip i = 2 and i = 3, and all other even numbers since we created a pattern for the approved vals to check
		is_prime = 1;
		for (int i = 5; i<itr/2; i+=2)
		{
			if (itr % i == 0)
			{
				is_prime = 0;
			}
		}
		if (is_prime) {++num_prime;};

	}
	return itr; // 104743
}


// Diff(SmSq,SqSm) 1-100
output_t problem6()
{
	int output = 0;
	int aggr = 0;

	for (int i = 1; i<=100;++i)
	{
		output +=i*i; //sum square
		aggr += i;
	}
	output -= aggr*aggr;
	//what if SmSq < SqSm?
	output = output > 0 ? output : -output;
	return output;//25164150
}

//LCM 1-20
output_t problem5()
{
	const int TOP_VAL =20;
	int output = 1;
	// for (int i=TOP_VAL; i>0;i--)
	// {
	// 	if (output%i !=0)
	// 	{
	// 		output *= i;
	// 		cout << i << "\n";
	// 	}
	// } //694569984
	// for (int i=2; i<=TOP_VAL;i++)
	// {
	// 	if (output%i != 0)
	// 	{
	// 		output *=i;
	// 		cout << i << "\n";
	// 	}
	// }//71279104
	for (int i=2; i<=TOP_VAL;i++)
	{
		if (output%i != 0)
		{
			for (int j = 2; j<=i;j++)
			{
				if ((output*j)%i == 0)
				{
					output *=j;		
					cout << i << "\n";	
				}
			}
		}
	}//232792560
	return output; 
}

// AYS: questions 1-4 were menial enough that I chose not to redo them
