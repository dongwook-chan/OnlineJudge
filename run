# check the number of paramters
if [ "$#" -ne 1 ]; then
	echo "argument test:\tillegal number of parameters"
	exit 1
fi
echo "========= try to compile and execute problem '$1' ========="

# find working directory
work_dir=$(find ~/Git/online-judge -type d -name $1 | head -n 1)
if [[ $work_dir ]]; then
	echo "working directory:\t$work_dir"
else
	echo "working directory:\tnot found"
	exit 1
fi

# compile
cmp_res=$(g++ $work_dir/$1.cpp -o $work_dir/$1.out)
echo "compile result:\t\t$cmp_res"
if [ -f $work_dir/$1.out ]; then
	echo "executable file:\tfound"
else
	echo "executable file:\tnot found"
	exit 1
fi

# execute
exe_res=$($work_dir/$1.out < $work_dir/in > $work_dir/out)
echo "execute result:\t\t$exe_res"

# read output
out=$(cat $work_dir/out)
echo "out file:\n$out"
