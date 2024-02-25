

echo "a) OS and version, release number, kernel version:"
lsb_release -a
echo "Kernel version:"
uname -r
echo

echo "b) All available shells:"
cat /etc/shells
echo

echo "c) Computer CPU information:"
lscpu
echo

echo "d) Memory information:"
free -m
echo

echo "e) Hard disk information:"
df -h
echo

echo "f) File system (Mounted):"
mount | column -t
