from=$1
to=$2

cat "$from" | \
sed -E "s/\{CMAKE_VER\}/$CMAKE_VER/g" | \
sed -E "s/\{0\}/$var_0/g" | \
sed -E "s/\{1\}/$var_1/g" | \
sed -E "s/\{2\}/$var_2/g" | \
sed -E "s/\{3\}/$var_3/g" | \
sed -E "s/\{4\}/$var_4/g" | \
sed -E "s/\{5\}/$var_5/g" | \
sed -E "s/\{6\}/$var_6/g"  \
> $2
