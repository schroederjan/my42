#!/bin/bash

arc=$(uname -a)
grep "physical id" /proc/cpuinfo | sort | uniq | wc -l
grep ^processor /proc/cpuinfo | wc -l
free | grep Mem | awk '{printf("%.2f", $3/$2*100)}'
df --total -h | grep "total" | awk '{printf("Disk Usage: %s/%s (%.1f%%)\n", $3, $2, $3/$2*100)}'
top -bn1 | grep "%Cpu" | awk '{printf("CPU load: %.1f%%\n", (100.0-$8)%100)}'
who --boot | awk '{printf("Last boot: %s %s", $3, $4)}'
[[ $(lsblk | grep "lvm" | wc -l) -gt 0 ]] && echo "yes" || echo "no"
ss -s | grep "TCP:" | tr ',' ' ' | awk '{printf("Connections TCP: %s ESTABLISHED\n", $4)}'
who --count | grep "users" | tr '=' ' ' | awk '{printf("User log: %s\n", $3)}'
ip link | grep "ether" | awk '{printf($2)}'
hostname -I
journalctl _COMM=sudo | grep COMMAND | wc -l
