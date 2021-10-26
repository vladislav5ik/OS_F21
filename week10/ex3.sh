echo "Vladislav Spigin" > _ex3.txt

#remove the execute permission to all
chmod a-x _ex3.txt >> ex3.txt

#grant all permissions to user and owner
chmod uo=rwx _ex3.txt >> ex3.txt

#grant all permissions to group
chmod g=rwx _ex3.txt >> ex3.txt
