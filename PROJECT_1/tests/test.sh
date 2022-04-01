make
./MessagesP < test.in
clear
diff test.out Sorted.txt > /dev/null 2>&1
error=$?
if [ $error -eq 1 ] 
then diff test.out Sorted.txt
echo Test failed.
else echo Test passed.
fi