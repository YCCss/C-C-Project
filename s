#!/bin/bash

usage() {
    echo "使用说明"
    echo "./s <-b> <project_name>	build project"
    echo "./s <-c> <project_name>	clean build & target"
	echo "./s <-r> <project_name>	run program"
}

main() {
    if [ $1 == "-b" ]; then
		if [ -n "$2" ]; then #$2有内容
        	cd $2
			make clean
			make
		else 
			usage
		fi
    elif [ $1 == "-c" ]; then
        if [ -n "$2" ]; then
        	cd $2
			make clean
		else 
			usage
		fi
	elif [ $1 == "-r" ]; then
		if [ -n "$2" ]; then  
        	./$2/mp
		else 
			usage
		fi

    else
        usage
    fi
}


main "$@"