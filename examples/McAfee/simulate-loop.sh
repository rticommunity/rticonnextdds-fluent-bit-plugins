rm -f log.txt
touch log.txt
echo "READY TO START LOOP - PRESS ENTER"
read 
while true; do
    catdelay 250 mcafee.log > log.txt
    sleep 2
done
