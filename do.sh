#!/bin/bash

var_0="MYPROJECT"
var_1="myProject"

var_3=""
var_4=""
CMAKE_VER=2.8

while getopts c:t:n: option
do 
	case "$option" in
		n)
			var_0=${OPTARG^^}
			var_1=$OPTARG
			;;
		t)
			var_3="$var_3 $OPTARG"
			;;
		c)
			var_4="$var_4 $OPTARG"
			;;
		*)
			echo "-n <NAME> : name of the module (camelCase preferred)"
			echo "-c <CLASSNAME> : add a new class to the lib"
			echo "-t <TESTCLASSNAME> : add a new test exec to the lib"
			exit
			;;
	esac
done	

mkdir "$var_1"
mkdir "$var_1/include"
mkdir "$var_1/include/$var_1"
mkdir "$var_1/src"
mkdir "$var_1/cmake"
mkdir "$var_1/tests"
mkdir "$var_1/.github"
mkdir "$var_1/.github/workflows"

. replacer.sh "main_cmake_template.txt" "$var_1/CMakeLists.txt"
. replacer.sh "main_template.txt" "$var_1/main.cxx"
. replacer.sh "test_cmake_template.txt" "$var_1/tests/CMakeLists.txt"
. replacer.sh "github_automation.txt" "$var_1/.github/workflows/auto.yml"

for iterator in $var_4
do
	var_5=$iterator
	. replacer.sh "class_src_template.txt" "$var_1/src/$var_5.cxx"
	. replacer.sh "class_hdr_template.txt" "$var_1/include/$var_1/$var_5.hxx"
done

for iterator in $var_3
do
	var_6=$iterator
	. replacer.sh "test_template.txt" "$var_1/tests/$var_6.cxx"
done
