

all:
	@echo "create live cd"
	dd if=/dev/zero of=irbislinux.img bs=1024 count=10240000
	sudo mkfs.ext4 irbislinux.img
	sudo /sbin/losetup -f irbislinux.img
