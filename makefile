compile: LL_test.cpp 
	 g++  NODE.cpp LL.cpp LL_test.cpp -o LL

run: LL
	 ./LL


clean: LL
	 rm LL
