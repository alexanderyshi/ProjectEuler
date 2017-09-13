TEMP_FILE_NAME="PE.tmp.cpp";
#make a temp copy of the .cpp file
cp PE.cpp $TEMP_FILE_NAME;

#parse file, then append main method
problem_nums=($(grep "problem" PE.cpp | sed 's/[^0-9]*//g'));

echo "int main() {" 							>> $TEMP_FILE_NAME;
echo "std::map<output_t, fptr> fptrMap;" 		>> $TEMP_FILE_NAME;
for i in "${problem_nums[@]}"
do
	echo "fptrMap[$i]=problem$i;" 				>> $TEMP_FILE_NAME;
done
echo "output_t output=fptrMap[PROBLEM_NUM]();" 	>> $TEMP_FILE_NAME;
echo "std::cout<<\"\n\"<<output<<\"\n\";}"		>> $TEMP_FILE_NAME;

#compile and remove temp
g++ PE.tmp.cpp -o ./PE.exe;
rm PE.tmp.cpp;

exec ./PE.exe;