# /**
#  ********************************************************************************
#  * @file    run_tests.sh
#  * @author  Kai Gehry
#  * @date    2025-09-04
#  *
#  * @brief   Runs compiled test files for all implemented data structures.
#  ********************************************************************************
#  */

#Stores the list of files in the test directory
exe_list=$(ls)

for i in $exe_list;
do
    #If the file is a test executable, it is run
    if [[ "$i" = *"tests.exe"* ]]; then
        eval "./$i"
    fi
done