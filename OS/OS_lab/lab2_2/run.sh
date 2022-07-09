make 
make my_cp
cd ../busybox-1.32.1/_install
sh find.sh
cd ../../linux-4.9.263
sudo make -j $((`nproc`-1))
cd ..
make qemu
cd lab2_2
