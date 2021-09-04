#!/bin/bash
# 功能： 提交已完成的题目
# 示例： ./commit 0001
# 输入参数为4位题号

match=$(find . -name "_LeetCode_$1_*" -exec basename {} \;)
if [[ $match != "" ]]
# 如果找到 _LeetCode_$1_xxxx.cpp
then 
    echo "-- Git Add and Commit ${match: 1} --"
    git add .
    git commit -m "Add ${match: 1}"
    echo "Done"
else 
    echo "Question No.$1 Not Found or Already Submit."
fi
