for t in "test.in"; do
echo $t
o="test.out"
diff $o <(./MessagesP < $t) || break
done