#include <map>
#include <cstring>
#define BIG_NUMBER_SIZE 500

// requires macro BIG_NUMBER_SIZE to be def. else compilation error
// assumes only whole numbers
// i.e. 27 * 2
/*
	starting cond.
		2.14
	i = 1, size = 2
		4.14
		5.14
		5.4
*/
class BigNumber {
	private:
		uint16_t digit[BIG_NUMBER_SIZE]; // larger storage container needed for larger multiplication operations
		unsigned size;

	public:
		BigNumber() : digit(), size(0) { // value initialized
		};

		BigNumber(unsigned starting_val) : digit(), size(0) {
			while (starting_val > 0) {
				digit[size] = starting_val%10;
				starting_val /= 10;
				++size;
			}
		};

		// this is a duplication of the constructor with unsigned, should not be kept like this
		void assign(unsigned starting_val) { 
			std::memset(digit, 0, sizeof(digit));
			size = 0;
			while (starting_val > 0) {
				digit[size] = starting_val%10;
				starting_val /= 10;
				++size;
			}
		}

		void multiply(unsigned multipler){
			// skip first value to simplify indexing logic
			digit[0] *= multipler;
			for (int i = 1; i < BIG_NUMBER_SIZE; ++i) {
				// this index may be left with a value > 10, cleaned up on i+1
				digit[i] *= multipler;
				// carryover taken from last index
				digit[i] += digit[i-1]/10;
				digit[i-1] %= 10;
				if (i >= size) {
					if (digit[i]) {++size;}
				}
			}
		}

		uint8_t getValue(unsigned idx) { // cout cant seem to handle uint8_t, should I return chars for convenience?
			if (idx > size) { 
				return (uint8_t)(0-1);
			}
			return digit[idx];
		}

		unsigned getSize() {
			return size;
		}

		unsigned long long getSumDigits() {
			unsigned long long aggr = 0;
			for (int i = 0; i < size; ++i) {
				aggr += digit[i];
			}
			return aggr;
		}

};

//returns whether any value is prime or not in O(1) run time for many values, else O(0.25*n)
int isPrime(unsigned long long val)
{
	//can reduce number of obvious primes by forcing pattern of incr.
	/*
		num%30:
		1	2	3 	4 	5	6	7	8	9	10
		11	12	13 	14 	15	16	17	18	19	20
		21	22	23 	24 	25	26	27	28	29	30

		out of this pattern we know candidates are not Mult of 2,3,5
		therefore only check
		1  7 11 13 17 19 23 29 [31]
		  +6 +4 +2 +4 +2 +4 +6  +2
		(22 out of every 30 elim.)
	*/

	// 0 - not a prime
	// 1 - is a prime
	int prime_map_under_30[] =
	{
		0,					 //0
		0,1,1,0,1,0,1,0,0,0, //1s
		1,0,1,0,0,0,1,0,1,0, //10s
		0,0,1,0,0,0,0,0,1,0  //20s
	};
	// 0 - not a prime
	// 1 - MAYBE a prime
	int prime_map_over_30[] =
	{
		1,0,0,0,0,0,1,0,0,0,	//1s
		1,0,1,0,0,0,1,0,1,0, 	//10s
		0,0,1,0,0,0,0,0,1,0		//20s
	};

	if (val <= 30)
	{
		return prime_map_under_30[val];
	}
	else
	{
		if(prime_map_over_30[val%30-1] == 0)
		{
			return 0;
		}
	}

	// check "MAYBE"s
	for (int i = 7; i<val/2; i+=2) // 2s, 3s, 5s are easily covered by map
	{
		if (val % i == 0)
		{
			// cout << val << " is divisible by "<< i <<"\n";
			return 0;
		}
	}
	// cout << val << " is prime\n";
	return 1;
}

// returns the nth triangle number via gaussian sum
long getTriangleNumber(int n) {
	return n*(n+1)/2;
}

//returns factorial for whole number
unsigned long long getFactorial(unsigned int n) {
	unsigned long long output = 1;
	for (int i = 2; i <= n; ++i) {
		output *= i;
	}
	return output;
}

//returns the number of divisors of a number
int getNumDivisors(long n) {
	cout  << "num" << n;
	// start with prime factorization
	int divisor = 2;
	int numFactors = 0; 
	std::map<int, int> divMap;
	while (n > 1) {
		if (n%divisor == 0) {
			n /= divisor;
			++numFactors;
			++divMap[divisor];
		}
		else {
			++divisor;
		}
	}
	cout << "numFactors" << numFactors;

	// the number of divisors is equal to product ways to pick 1,2,3,... or none of a prime factor
	// OR the sum of  nC1+nC2+nC3... the former is much easier to calculate
	// (a+1)(b+1)(c+1),... where a,b,c,... are the number of occurrences of prime factors in 
	// primefactorization: x1^a * x2^b * x3^c * ...
	unsigned int numDivisors = 1;
	std::map<int,int>::iterator itr;
	for (itr = divMap.begin(); itr != divMap.end(); ++itr) {
		numDivisors *= itr->second + 1;
		cout << "(" << itr->first <<","<<itr->second<<"),";
	}
	cout << "numDivisors" << numDivisors << "\n";

	return numDivisors;
}

