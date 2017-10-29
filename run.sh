#config
MAKE_ALL_PROBLEMS=false; #default false
KEEP_FINAL_CPP_FILE=false; #default false
#endconfig

if [ -z "$1" ] ; then
	# problem="PROBLEM_NUM"; echo "Running with default PROBLEM_NUM..."
	echo "Please enter the problem you would like to run from the following list:"
	problem_nums=($(grep "problem" PE.cpp | sed 's/[^0-9]*//g'));
	for i in "${problem_nums[@]}"
	do 
		echo "$i";
	done
	exit 0;
# elif ! [[ "$1" =~ '^[0-9]+$' ]] ; then
#    echo "Error: pass in the question number you would like solved" >&2; exit 1

else
	problem=$1; echo "Running with problem number $1..."
fi

TEMP_FILE_NAME="PE.tmp.cpp";
#make a temp copy of the .cpp file
cp PE.cpp $TEMP_FILE_NAME;

#parse file, then append main method
problem_nums=($(grep "problem" PE.cpp | sed 's/[^0-9]*//g'));
#TODO: only compile and run the question number asked for if user explicitly indicates one

echo "int main() {" 							>> $TEMP_FILE_NAME;
echo "std::map<output_t, fptr> fptrMap;" 		>> $TEMP_FILE_NAME;
if [ $MAKE_ALL_PROBLEMS == true ] ; then
	for i in "${problem_nums[@]}"
	do
		echo "fptrMap[$i]=problem$i;" 				>> $TEMP_FILE_NAME;
	done
	echo "...making all problems..."
else
	# !! issue here is that generating the name of all the found problems did not need PROBLEM_NUM before
	echo "fptrMap[$problem]=problem$problem;" 				>> $TEMP_FILE_NAME;
	# echo "fptrMap[$problem]=FUNC_TOKEN_CONCAT($problem);" >> $TEMP_FILE_NAME;
fi
echo "output_t output=fptrMap[$problem]();" 	>> $TEMP_FILE_NAME;
echo "std::cout<<\"\n\"<<output<<\"\n\";}"		>> $TEMP_FILE_NAME;

#compile and remove temp
g++ PE.tmp.cpp -o ./PE.exe;
if [ $KEEP_FINAL_CPP_FILE == false ] ; then
	rm PE.tmp.cpp;
	echo "...removing tmp file..."
fi

echo "...done!"
echo "Executing problem $problem:"
exec ./PE.exe;