#!/bin/bash
# 功能： 添加LeetCode题目文件
# 示例： ./add.sh 0001 twoSum
# 参数1是4位题号，参数2是题名
files=$(ls )
exist=0
for filename in $files
do
    if [ "$filename" == "LeetCode_$1_$2.cpp" ]
    then
        exist=1
    fi
done
if [ "$exist" = 0 ]
then
    echo "-- Add _LeetCode_$1_$2.cpp --"
    touch _LeetCode_$1_$2.cpp
    echo "/*    " >> _LeetCode_$1_$2.cpp
    echo "      " >> _LeetCode_$1_$2.cpp
    echo "*/    " >> _LeetCode_$1_$2.cpp
    echo "Done"
else
    echo "-- LeetCode_$1_$2.cpp Already Exist --"
fi

