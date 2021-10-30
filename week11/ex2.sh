echo "Vladislav" > lofsdisk/file1
echo "Spigin" > lofsdisk/file2

# libraries copying
mkdir lofsdisk/bin
cp /bin/{bash,ls,echo,cat} lofsdisk/bin

mkdir lofsdisk/lib
mkdir lofsdisk/usr
mkdir lofsdisk/usr/lib

cp /lib/{libpcre2-8.so.0,libreadline.so.8,libdl.so.2,libpthread.so.0,libtinfo.so.6} lofsdisk/lib/
cp /usr/lib/libc.so.6 lofsdisk/usr/lib/

mkdir lofsdisk/lib64
cp /lib/{libpcre2-8.so.0,libreadline.so.8,libdl.so.2,libpthread.so.0,libtinfo.so.6} lofsdisk/lib64/
cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64

#update liblaries config
sudo ldconfig

cd lofsdisk
#compiling program
gcc ../ex2.c -o ex2.out

echo "CHROOT ----" > ../ex2.txt
#process's root directory is now in lofsdisk directory
sudo chroot . ./ex2.out >> ../ex2.txt
echo "" >> ../ex2.txt
echo "NO CHROOT ----" >> ../ex2.txt
#process's root directory is usual directory in system
./ex2.out >> ../ex2.txt
