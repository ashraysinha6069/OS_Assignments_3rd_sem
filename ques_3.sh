echo Enter filename:
read file
sed -ie "s/\([^ ]*\) *\([^ ]*\)/\2 \1 /g" $file
