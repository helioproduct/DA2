build:
	g++ -fsanitize=address main.cpp

TESTS="./test"

tests: build
	for file in $TESTS; do \
    	echo $$file  ; \
	done

