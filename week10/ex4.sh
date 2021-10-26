d="$HOME/os_f21/week10"
dir=tmp
file1=file1.txt
file2=file2.txt
link1=link1.txt
link2=link2.txt

mkdir $d/$dir
echo "Spigin Vladislav 1" >> $d/$dir/$file1
echo "Spigin Vladislav 2" >> $d/$dir/$file2

link $d/$dir/$file1 $d/$dir/$link1
link $d/$dir/$file1 $d/$dir/$link2

gcc $d/ex4.c -o ex4
$d/ex4 > $d/ex4.txt
