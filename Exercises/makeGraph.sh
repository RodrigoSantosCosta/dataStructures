IN=$1
valgrind --tool=callgrind $IN
OUT=$(find callgrind.out.* | tail -n 1)
python gprof2dot.py --format=callgrind --output=$OUT.dot $OUT
dot -Tpng $OUT.dot -o $OUT.png