Cheatsheet
- echo "sa" | ./checker 1 2 3

echo "sa\npb\npb\npb\nra\nrb\nrra\nrrb\nsa\npa\npa\npa" | ./checker 8 5 6 3 1 2

echo "sa\npb\npb\npb\nrr\nrrr\nsa\npa\npa\npa" | ./checker 10 7 8 5 3 4

cat instructions.txt | ./checker -v 8 5 6 3 1 2

Split Balance
./push_swap 8 5 6 3 1 2
./push_swap 8 5 6 3 1 2 1 2 1 2 1 2 1 1 2 12
./push_swap 8 5 6 3 1 2 1 2 18 8 8 8 8 8 8 8 8 8 

GIT  
git pull && git submodule init && git submodule update && git submodule status

Quick Sort
https://www.youtube.com/watch?v=SLauY6PpjW4

while true; do { ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`; valgrind --leak-check=full ./push_swap $ARG | ./checker $ARG}; done

while true; do { ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`; leaks ./push_swap $ARG | ./checker $ARG}; done

https://github.com/Binary-Hackers/42_Corrections/tree/master/00_Projects/02_Algorithmic/push_swap/00_new_correction_here

Current Record:
100: 968
500: 8645

100 : 700 | 900 | 1100 | 1300 | 1500
500 : 5500 | 7000 | 8500 | 10000 | 11500

Try to improve with handling case for sorting less than 3 or 4 number

make test ARG="`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`"