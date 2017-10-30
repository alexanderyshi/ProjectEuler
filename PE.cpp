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
#define PROBLEM_NUM 	5
// *!*!*!*!*!*!*!*/*           *\*!*!*!*!*!*!*!*
// *******************/*   *\*******************

// ***********/* MACROS */***********
#define CHAR_AS_NUM(c) (c-'0') 
using namespace std;

// ***********/* INCLUDES */***********
#include <iostream>
#include <cstdlib>
#include <queue>
#include <math.h>
#include <string>
#include "PE_helper.h"

// ***********/* TYPEDEFS */***********
typedef long long (*fptr)(void);
typedef long long output_t;


// ***********/* PROBLEMS */***********
// sum of digits in 100!
output_t problem20()
{
	// need big number helper from problem 16
	return -1;
}
// counting sundays falling on first of a month, from 1 jan 1901 to 31 dec 2000
output_t problem19()
{
	return -1;
}
// maximum vertical path sum for triangle
output_t problem18()
{
	/*
	75
	95 64
	17 47 82
	18 35 87 10
	20 04 82 47 65
	19 01 23 75 03 34
	88 02 77 73 07 63 67
	99 65 04 28 06 16 70 92
	41 41 26 56 83 40 80 70 33
	41 48 72 33 47 32 37 16 94 29
	53 71 44 65 25 43 91 52 97 51 14
	70 11 33 28 77 73 17 78 39 68 17 57
	91 71 52 38 17 14 91 43 58 50 27 29 48
	63 66 04 68 89 53 67 30 73 16 69 87 40 31
	04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
	*/
	// get next adjacent numbers
		// store in an array and use offsets as function of row number?
		// store in a linked list structure?

	// recursive function (getMax(left index, right index))
	// return max of max(left's left, left's right), max(right's left, right's right)
	return -1;
}

//letters used in listing numbers 1-1000 in words
output_t problem17()
{
	// make an array of the number of letters per digit 1-9
	// sum the digits in this array [1-9]
	// make an array of the number of letters per digit 10-19
	// sum the digits in this array [10-19]
	// make an array of the number of letters for twenties through nineties [2x-9x]
		// for the numbers 20-99, sum the letters for the tens place and the letters for the ones place
		// for the numbers 100-999, sum the hundreds place digit number, the number of letters in "hundred and", and the letters for the respective 1-99 
	// add the digits for "one thousand" 

	// much of the repeating numbers can be implemented by doing something like "digits in eleven * 10 appearances" + "digits in 'hundred and' * 9 appearances"
	return -1;
}

// sum of the digits of 2^1000
output_t problem16()
{

	// need to reimplement this with BigNumber helper format due to double losing precision after 53 places? - limited by mantessa
	// how many digits in 2^1000
	// build an array and iterate through doubling values and evaluating carryover
	// loop through the array and add the digit values
	BigNumber mBNum(1);
	for (int i = 0; i < 1000; ++i) {
		mBNum.multiply(2);
	}

	output_t aggr = 0;
	for (int i = mBNum.getSize() - 1; i >= 0; --i) {
		// cout << mBNum.getValue(i);
		aggr += mBNum.getValue(i);
	}
	return aggr;

}

// lattice paths traversing DOWN RIGHT in a 20x20 grid
output_t problem15()
{
	// find number of combinations of 20D and 20R //n!/(r!*(n-r)!)
	// base case 	D...DDDRRR..R
	// 				D...DDRDRR..R //20 ways to switch the first R, 19 to move the 2nd, 18 to move the 3rd 

	/* 
	DDRR 
	DRDR
	DRRD
	RDDR
	RDRD
	RRDD
	*/ //14688017186506670080 // 335367096786357061827717758976

	// n multichoose k (n+k-1)C(n)
	// return getFactorial(20+21-1)/getFactorial(20)/getFactorial(20-20);
	// return getFactorial(40)/getFactorial(20);
	double val = 1;
	for (int i = 21; i <=40; ++i) {
		val *= i;
		val /= i-20;
	}
	cout.precision(55);
	return val; //137846528820
}

// longest collatz sequence starting under 1 million
output_t problem14()
{
	//if even, divide 2
	//if odd, multiply by 3 and add 1

	// for every even number where you must divide by 2, there was a smaller number that was odd that was used to get there
	// therefore should always start on odd numbers to add the extra step (?) //910107
	// !!AYS it should be noted that for 3n+1 that gives a power of two, that makes the shortest sequence possible
	// i increment in 2s anyways because why not, ideally increment 1s if you don't know the answer already though
	int maxCount = 0;
	int startNum = 0;
	for (int i = 3; i < 1E6; i+=2) { //  numbers in the sequence will pass int, therefore use ULL
		int count = 0;
		unsigned long long num = i;
		while (num > 1) {
			if (num % 2 == 0) {
				num /= 2;
			} else {
				num = num * 3 + 1;
			}
			++count;
		}
		maxCount = maxCount > count ? maxCount : count;
		if (maxCount == count) {
			startNum = i;
			cout << i <<"\t" << count << "\n";
		}
	}
	// should search for a starting number with prime factorization of all odd, and one 2?
	return startNum; // 837799
}

// sum of one hundred 50-digit numbers
output_t problem13()
{
	// !!AYS is resorting to double an efficient or prideful solution for this?
	// maybe i should make a proof for the number of places of significant digits
	// i need and work in ULL to get this average
	string num[] = {
	"37107287533902102798797998220837590246510135740250",
	"46376937677490009712648124896970078050417018260538",
	"74324986199524741059474233309513058123726617309629",
	"91942213363574161572522430563301811072406154908250",
	"23067588207539346171171980310421047513778063246676",
	"89261670696623633820136378418383684178734361726757",
	"28112879812849979408065481931592621691275889832738",
	"44274228917432520321923589422876796487670272189318",
	"47451445736001306439091167216856844588711603153276",
	"70386486105843025439939619828917593665686757934951",
	"62176457141856560629502157223196586755079324193331",
	"64906352462741904929101432445813822663347944758178",
	"92575867718337217661963751590579239728245598838407",
	"58203565325359399008402633568948830189458628227828",
	"80181199384826282014278194139940567587151170094390",
	"35398664372827112653829987240784473053190104293586",
	"86515506006295864861532075273371959191420517255829",
	"71693888707715466499115593487603532921714970056938",
	"54370070576826684624621495650076471787294438377604",
	"53282654108756828443191190634694037855217779295145",
	"36123272525000296071075082563815656710885258350721",
	"45876576172410976447339110607218265236877223636045",
	"17423706905851860660448207621209813287860733969412",
	"81142660418086830619328460811191061556940512689692",
	"51934325451728388641918047049293215058642563049483",
	"62467221648435076201727918039944693004732956340691",
	"15732444386908125794514089057706229429197107928209",
	"55037687525678773091862540744969844508330393682126",
	"18336384825330154686196124348767681297534375946515",
	"80386287592878490201521685554828717201219257766954",
	"78182833757993103614740356856449095527097864797581",
	"16726320100436897842553539920931837441497806860984",
	"48403098129077791799088218795327364475675590848030",
	"87086987551392711854517078544161852424320693150332",
	"59959406895756536782107074926966537676326235447210",
	"69793950679652694742597709739166693763042633987085",
	"41052684708299085211399427365734116182760315001271",
	"65378607361501080857009149939512557028198746004375",
	"35829035317434717326932123578154982629742552737307",
	"94953759765105305946966067683156574377167401875275",
	"88902802571733229619176668713819931811048770190271",
	"25267680276078003013678680992525463401061632866526",
	"36270218540497705585629946580636237993140746255962",
	"24074486908231174977792365466257246923322810917141",
	"91430288197103288597806669760892938638285025333403",
	"34413065578016127815921815005561868836468420090470",
	"23053081172816430487623791969842487255036638784583",
	"11487696932154902810424020138335124462181441773470",
	"63783299490636259666498587618221225225512486764533",
	"67720186971698544312419572409913959008952310058822",
	"95548255300263520781532296796249481641953868218774",
	"76085327132285723110424803456124867697064507995236",
	"37774242535411291684276865538926205024910326572967",
	"23701913275725675285653248258265463092207058596522",
	"29798860272258331913126375147341994889534765745501",
	"18495701454879288984856827726077713721403798879715",
	"38298203783031473527721580348144513491373226651381",
	"34829543829199918180278916522431027392251122869539",
	"40957953066405232632538044100059654939159879593635",
	"29746152185502371307642255121183693803580388584903",
	"41698116222072977186158236678424689157993532961922",
	"62467957194401269043877107275048102390895523597457",
	"23189706772547915061505504953922979530901129967519",
	"86188088225875314529584099251203829009407770775672",
	"11306739708304724483816533873502340845647058077308",
	"82959174767140363198008187129011875491310547126581",
	"97623331044818386269515456334926366572897563400500",
	"42846280183517070527831839425882145521227251250327",
	"55121603546981200581762165212827652751691296897789",
	"32238195734329339946437501907836945765883352399886",
	"75506164965184775180738168837861091527357929701337",
	"62177842752192623401942399639168044983993173312731",
	"32924185707147349566916674687634660915035914677504",
	"99518671430235219628894890102423325116913619626622",
	"73267460800591547471830798392868535206946944540724",
	"76841822524674417161514036427982273348055556214818",
	"97142617910342598647204516893989422179826088076852",
	"87783646182799346313767754307809363333018982642090",
	"10848802521674670883215120185883543223812876952786",
	"71329612474782464538636993009049310363619763878039",
	"62184073572399794223406235393808339651327408011116",
	"66627891981488087797941876876144230030984490851411",
	"60661826293682836764744779239180335110989069790714",
	"85786944089552990653640447425576083659976645795096",
	"66024396409905389607120198219976047599490197230297",
	"64913982680032973156037120041377903785566085089252",
	"16730939319872750275468906903707539413042652315011",
	"94809377245048795150954100921645863754710598436791",
	"78639167021187492431995700641917969777599028300699",
	"15368713711936614952811305876380278410754449733078",
	"40789923115535562561142322423255033685442488917353",
	"44889911501440648020369068063960672322193204149535",
	"41503128880339536053299340368006977710650566631954",
	"81234880673210146739058568557934581403627822703280",
	"82616570773948327592232845941706525094512325230608",
	"22918802058777319719839450180888072429661980811197",
	"77158542502016545090413245809786882778948721859617",
	"72107838435069186155435662884062257473692284509516",
	"20849603980134001723930671666823555245252804609722",
	"53503534226472524250874054075591789781264330331690"};
	// lets start by cutting off the front 18 numbers and 
	// hope that's sufficient to avoid pesky carry overs from the 30 LSD
	// ULL has limit of  18 446 744 073 709 551 615
	// divide all by 100 and add them back up?
	// can parse as double!
	double aggr = 0;
	// if that does not work we need to build a big number handler
	for (int i = 0; i<100;++i) {
		aggr += atof((const char*)&(num[i][0]));
	}
	aggr /= 100; // take average, although in this case does not make a diff since divisor 1e2 does not modify digits, just decimal place
	while (aggr > 1e10) {aggr /= 10;}; //get first 10 digits

	return (output_t)aggr; // truncate double to LL
}
//triangle number with over 500 divisors
output_t problem12()
{
	//2016 via (incorrect) combinatorics - there is an easier way!
	// check code for the helpers used
	int n = 1; //random start value taken from PE example
	while (getNumDivisors(getTriangleNumber(n)) < 500) {
		++n;
	}
	return getTriangleNumber(n); //76576500
}

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
	// TODO: change O(3n^2) to O(n) by using *= and /= algorithm from horizontals/verticals
	// TODO: skip over regions with 0s in this test 
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
