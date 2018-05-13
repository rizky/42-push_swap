# Push Swap

![pushswap](https://user-images.githubusercontent.com/6814254/39967871-9b2605ee-56c3-11e8-962b-baf0e3e8f4ed.gif)

## Installation:

```
git clone --recurse-submodules https://github.com/rizkyario/42-push_swap.git; cd 42-push_swap; make
```

## Usage:
```
ARG=`ruby -e "puts (1..50).to_a.shuffle.join(' ')"``; ./push_swap $ARG | ./checker -vcat $ARG
```

## Resources:
- https://www.youtube.com/watch?v=SLauY6PpjW4
- https://www.youtube.com/watch?v=egU3YD8OKbw&t=51s
- https://github.com/Binary-Hackers/42_Corrections/tree/master/00_Projects/02_Algorithmic/push_swap/00_new_correction_here
