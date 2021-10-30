#allocating file (50 MB)
sudo fallocate -l 50M lofs.img
#setup loopback device
sudo losetup -f lofs.img
#creating filesystem
sudo mkfs.ext4 $(losetup -a | grep 'lofs.img'| awk '{print $1}' | cut -d ':' -f 1)
mkdir lofsdisk
#nounting created filesystem on ours
sudo mount $(losetup -a | grep 'lofs.img'| awk '{print $1}' | cut -d ':' -f 1) ./lofsdisk
#grant full access
sudo chmod 777 lofsdisk/
