# check the number of paramters
if [ "$#" -ne 2 ]; then
        echo "argument test:\tillegal number of parameters"
        exit 1
fi

# check parameters
## argument 1: the directory must exist
if [ -d $PWD/$1 ]; then
        echo "OJ directoy:\t\tfound"
else
        echo "OJ directory:\t\tnot found"
        exit 1
fi
## argument 2: the new directory must not exist
if [ ! -d $PWD/$1/$2 ]; then
        echo "problem directoy:\tnot found"
else
        echo "problem directory:\tfound"
        exit 1
fi

# create working directory
work_dir="$PWD/$1/$2"
mkdir $work_dir

# create files
touch $work_dir/$2.cpp
touch $work_dir/in

if [ -f $work_dir/$2.cpp ] && [ -f $work_dir/in ]; then
	echo "cpp and input files created"
else
	echo "failed to create files"
	exit 1
fi
