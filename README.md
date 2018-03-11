Manage GIT Submodule  
- git pull && git submodule init && git submodule update && git submodule status

Sort Algos  
- https://www.youtube.com/watch?v=SLauY6PpjW4
- https://www.youtube.com/watch?v=egU3YD8OKbw&t=51s

Test Leaks  
- while true; do { ARG=`ruby -e "puts (-50..49).to_a.shuffle.join(' ')"`; valgrind --leak-check=full ./push_swap $ARG | ./checker $ARG}; done

Corrections  
- https://github.com/Binary-Hackers/42_Corrections/tree/master/00_Projects/02_Algorithmic/push_swap/00_new_correction_here

Current Record:
- 100: 773
- 500: 5478

- 100 : 700 | 900 | 1100 | 1300 | 1500
- 500 : 5500 | 7000 | 8500 | 10000 | 11500

Test commands  
- ARG=`ruby -e "print '-v -c -a 10 ';puts (0..5).to_a.shuffle.join(' ')"`; ./push_swap `echo $ARG` | ./checker `echo $ARG`
- make test ARG="`ruby -e "puts (1..50).to_a.shuffle.join(' ')"`" OPT="-v -c -a 10"
- make test_pw ARG="`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`"  | wc -l
- make test_ch ARG="`ruby -e "puts (1..500).to_a.shuffle.join(' ')"`"
- while true; do { make test ARG="`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`" OPT="-t" }; done

Improvement Task List  
- Rotate vs Rev_Rotate depend on the distribution.
- Devide by < 50%, < 75%, and < 100%