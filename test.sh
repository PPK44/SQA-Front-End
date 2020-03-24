#!/bin/bash
# Script to loop through directories to merge files
​
​
tests="tests/*"
​
# Create files to contain the diff results and
# The general results of which test passed
​
rm diff_log.txt
touch diff_log.txt
​
rm test_results.txt
touch test_results.txt
​
for t in $tests
do
​
    # If its a directory, go inside of it
    if [ -d "$t" ]
    then
        # Make sure the test file exists
        touch $t/trans.out
​
        # Run the script and dump the output in the folder to be compared
        ./auction-system.exe current_user_accounts_file.txt available_items_file.txt daily_transaction_file.txt < $t/test.inp > $t/trans.out 
​
​
​
        # Write a file documenting if the file is ok or not
        if diff $t/trans.out $t/test.out;
        then
            echo "TEST $t: PASS" >> test_results.txt
        else
            # If the file is not good document the issue
            echo "TEST $t: FAIL" >> test_results.txt
​
            echo "TEST $t:" >> diff_log.txt
            diff $t/trans.out $t/test.out >> diff_log.txt
            echo $'\n' >> diff_log.txt
​
        fi
​
​
        # Remove the temporary transaction file
        rm $t/trans.out
    fi
    
    # Clear the terminal at the end of the run
    clear
​
done
