#!/usr/bin/env bash

# Load the configuration file
source vmconfig.txt

# Create the VM
VBoxManage createvm \
	--name $VM_NAME --register

# Set VM Type
VBoxManage modifyvm $VM_NAME \
	--ostype $OSTYPE

# Assign RAM
VBoxManage modifyvm $VM_NAME --memory $MEMORY

# Create a Virtual Hard Disk
VBoxManage createhd \
	--filename $VDI_PATH \
	--size $VDI_SIZE

# Create a SATA Controller and Attach the Hard Disk
VBoxManage storagectl $VM_NAME \
	--name "SATA Controller" \
	--add sata --controller IntelAhci

VBoxManage storageattach $VM_NAME \
	--storagectl "SATA Controller" \
	--port 0 \
	--device 0 \
	--type hdd \
	--medium $VDI_PATH

# Add a DVD Drive and attach the ISO
VBoxManage storagectl $VM_NAME --name "IDE Controller" --add ide
VBoxManage storageattach $VM_NAME \
	--storagectl "IDE Controller" \
	--port 1 \
	--device 0 \
	--type dvddrive \
	--medium $ISO_PATH

# Enable NAT networking
VBoxManage modifyvm $VM_NAME \
	--nic1 nat

# Setup port forwarding
VBoxManage modifyvm $VM_NAME \
	--natpf1 "guestssh,tcp,,2222,,22"

# Start the VM
VBoxManage startvm $VM_NAME
