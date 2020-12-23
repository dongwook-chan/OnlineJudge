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

# execute all input files
for in_file in $(find $work_dir -name 'ex_in[1-9]')
do
    exe=$($work_dir/$1.out < $in_file > $work_dir/my_out${in_file: -1})
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
        echo $(cat $out_file)
        echo "wrong output for example ${out_file: -1}:"
        echo $(cat $work_dir/my_out${out_file: -1})
    fi
done

if [ $pass = true ]; then
    echo "passed all examples"
fi
