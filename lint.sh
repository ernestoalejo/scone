

if [ "$1" = "" ]; then
	find -name '*.cpp' -o -name '*.h' | xargs 'cpplint.py'
else
	cpplint.py $1
fi
