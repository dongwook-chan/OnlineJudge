# usage
## $ ./run.sh { 'problem_number' | 'problem_name' }     # run solution for specified problem
## $ ./run.sh                                           # run solution for the cached problem

# check the number of paramters
if [ "$#" -ge 2 ]; then
	echo "argument test:\tillegal number of parameters"
	exit 1
fi

# get problem
prb=$(cat cached_problem)
if [ "$#" -eq 1 ]; then
    prb=$1
fi

# find working directory
work_dir=$(find . -type d -name $prb | head -n 1)
if [[ $work_dir ]]; then
	echo "working directory:\t$work_dir"
else
	echo "working directory:\tnot found"
	exit 1
fi

echo $prb > cached_problem

# Check if Python or C++ file is non-empty and set file extension
if [ -s "$work_dir/$prb.py" ]; then
    file_extension=".py"
elif [ -s "$work_dir/$prb.cpp" ]; then
    file_extension=".cpp"
else
    echo "No non-empty solution file found."
    exit 1
fi

echo "========= try to compile and execute problem '$prb' with extension '$file_extension' ========="

# Compile and execute based on file extension
if [ "$file_extension" == ".cpp" ]; then
    # compile C++
    cmp_res=$(g++ -std=c++17 $work_dir/$prb.cpp -o $work_dir/$prb.out)
    echo "compile result:\t\t$cmp_res"
    if [ ! -f $work_dir/$prb.out ]; then
        echo "executable file:\tnot found"
        exit 1
    fi
    execute_cmd="$work_dir/$prb.out"
elif [ "$file_extension" == ".py" ]; then
    # Python does not need compilation
    execute_cmd="python3 $work_dir/$prb.py"
fi

# execute all input files
for in_file in $(find $work_dir -name 'ex_in[1-9]')
do
    exe=$($execute_cmd < $in_file > $work_dir/my_out${in_file: -1})
    if [[ $exe ]]; then
        echo $exe
    fi
done

# compare result
pass=true
for out_file in $(find $work_dir -name 'ex_out[1-9]')
do
    dif=$(diff -Bb $out_file $work_dir/my_out${out_file: -1})
    if [[ $dif ]]; then
        pass=false
        echo "correct output for example ${out_file: -1}:"
        cat $out_file
        echo "wrong output for example ${out_file: -1}:"
        cat $work_dir/my_out${out_file: -1}
    fi
done

if [ $pass = false ]; then
    echo ":("
    exit 1
fi

echo "passed all examples and updating git:"
git add $work_dir
git commit -m "solved problem $prb"
git push
