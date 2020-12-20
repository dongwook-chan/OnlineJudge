# check the number of paramters
if [ "$#" -ne 2 ]; then
        echo "argument test:\tillegal number of parameters"
        exit 1
fi

echo "=== try to create directory and files for problem '$1' ==="

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
fi

# create working directory
work_dir="$PWD/$1/$2"
mkdir $work_dir

# create cpp file
if [ ! -f $work_dir/$2.cpp ]; then
    touch $work_dir/$2.cpp
fi

if [ -f $work_dir/$2.cpp ]; then
	echo "cpp file created"
else
	echo "failed to create cpp file"
	exit 1
fi

# create input files
crawl_res=$(python3 crawler.py)
echo $crawl_res
