./compiler.sh

echo "Compilation done"

echo "
--- Test 1 ---
"
echo "param : b:27 e:12 a:12 v:4 toto:99 a:11 a:10 b:12 a:9 ar:3 a:100 v:5 c:8
"

./hashage "b:27" "e:12" "a:12" "v:4" "toto:99" "a:11" "a:10" "b:12" "a:9" "ar:3" "a:100" "v:5" "c:8"

echo "
--- Test 2 ---
"
echo "param : b:27 b:12 t:12 v:4 t:99 b:11 t:10 t:12 a:9 t:3 y:100 y:5 y:8
"

./hashage "b:27" "b:12" "t:12" "v:4" "t:99" "b:11" "t:10" "t:12" "a:9" "t:3" "y:100" "y:5" "y:8"