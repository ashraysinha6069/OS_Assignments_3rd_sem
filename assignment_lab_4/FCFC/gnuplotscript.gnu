clear
reset
unset key
set xtics rotate out
set style data histogram
set style fill solid border
set style histogram clustered
plot for [COL=2:2] 'histodata' using COL:xticlabels(1) title columnheader