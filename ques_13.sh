echo Enter filename:
read filename
echo Enter starting line number:
read line1
echo Enter ending line number:
read line2
awk 'NR >= '$line1' && NR <='$line2'' $filename
