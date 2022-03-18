all:
		@mkdir -p bin
		g++ -std=c++11 src/hello.cpp -o bin/hello

clean:
		@rm -rf bin