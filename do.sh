#{1} projectName - camelCase?
var_0="MYPROJECT"
var_1="myProject"

var_3="Test1 Test2"
var_4="Writer Reader"
CMAKE_VER=2.8

#var_5 = for evey class name, you get one of these
#var_6 = for every test name you get one of these

mkdir "$var_1"
mkdir "$var_1/include"
mkdir "$var_1/include/$var_1"
mkdir "$var_1/src"
mkdir "$var_1/cmake"
mkdir "$var_1/tests"

. replacer.sh "main_cmake_template.txt" "$var_1/CMakeLists.txt"
. replacer.sh "main_template.txt" "$var_1/main.cxx"
. replacer.sh "test_cmake_template.txt" "$var_1/tests/CMakeLists.txt"

for iterator in $var_4
do
	var_5=$iterator
	. replacer.sh "class_src_template.txt"  "$var_1/src/$var_5.cxx"
	. replacer.sh "class_hdr_template.txt"  "$var_1/include/$var_1/$var_5.hxx"
done

for iterator in $var_3
do
	var_6=$iterator
	. replacer.sh "test_template.txt"  "$var_1/tests/$var_6.cxx"
done
