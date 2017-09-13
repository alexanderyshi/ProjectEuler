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
 */

// *******************/*   *\*******************
// !!!!!!!!!!!!!!!/* CHANGE ME *\!!!!!!!!!!!!!!!
// *!*!*!*!*!*!*!*/*           *\*!*!*!*!*!*!*!*
#define PROBLEM_NUM 	10
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

// sum of primes below 2mill
output_t problem10()
{
	long long output = 2; // 2 is known
	for (int i = 3; i<2E6; i+=2)
	{
		if (isPrime(i) == 1)
		{
			output += i;
			cout << i << "\t" << output << "\n";
		}
	}
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

// AYS: problems 1-4 were menial enough that I chose not to redo them