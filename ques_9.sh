echo Enter files and word
read word filenames
sed -ie '/'$word'/d'  $filenames
