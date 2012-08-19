
FILTER="-runtime/references,-whitespace/labels"

if [ "$1" = "" ]; then
	find -name '*.cpp' -o -name '*.h' | xargs 'cpplint.py --filter=$FILTER'
else
	cpplint.py --filter=$FILTER $1 
fi
