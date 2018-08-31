echo Enter file name:
read filename
echo starting line number:
read line1
echo ending line number:
read line2
awk 'NR >= '$line1' && NR <= '$line2'' $filename
