OUT_DIR = build

all:
		@mkdir -p $(OUT_DIR)
		g++ -std=c++11 Hello/hello.cpp -o $(OUT_DIR)/hello
		g++ -std=c++11 DataType/datatype.cpp -o $(OUT_DIR)/datatype

clean:
		@rm -rf $(OUT_DIR)