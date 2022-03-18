OUT_DIR = build

all:
		@mkdir -p $(OUT_DIR)
		g++ -std=c++11 src/hello.cpp -o bin/hello

clean:
		@rm -rf $(OUT_DIR)