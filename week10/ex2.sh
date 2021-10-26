d="$HOME/os_f21"
dir1=week01
dir2=week10
tempfile=file.txt
linkfile=_ex2.txt
logfile=ex2.txt

[ -d "${d}/${dir1}" ] &&  echo "Directory $dir1 found." >> $logfile || (echo "Directory $dir1 not found, creating new one." >> $logfile && mkdir $d/$dir1)

echo "Spigin Vladislav" > $d/$dir1/$tempfile
echo "File $dir1/$tempfile created." >> $logfile

[ -d "${d}/${dir2}" ] &&  echo "Directory $dir2 found." >> $logfile || (echo "Directory $dir2 not found, creating new one." >> $logfile && mkdir $d/$dir2)

link $d/$dir1/$tempfile $d/$dir2/$linkfile
echo "Files $dir1/$tempfile and $dir2/$linkfile are linked." >> $logfile

tempfile_inum=$(ls -i "${d}/${dir1}/${tempfile}" | awk '{print $1}')
echo "Inum of $tempfile is $tempfile_inum" >> $logfile
echo "Inum of $linkfile is $(ls -i "${d}/${dir2}/${linkfile}" | awk '{print $1}')" >> $logfile

# trace and remove all links
echo "All links to $tempfile:" >> $logfile
find $d/ -inum "$tempfile_inum" >> $logfile

find $d/ -inum "$tempfile_inum" -exec rm {} \;>> $logfile
echo "All links removed" >> $logfile


