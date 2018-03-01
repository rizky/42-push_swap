Cheatsheet
- echo "sa" | ./checker 1 2 3

echo "sa\npb\npb\npb\nra\nrb\nrra\nrrb\nsa\npa\npa\npa" | ./checker 8 5 6 3 1 2

echo "sa\npb\npb\npb\nrr\nrrr\nsa\npa\npa\npa" | ./checker 10 7 8 5 3 4

cat instructions.txt | ./checker -v 8 5 6 3 1 2