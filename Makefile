OUT_DIR = build

all:
		@mkdir -p $(OUT_DIR)
		g++ -std=c++11 Hello/hello.cpp -o $(OUT_DIR)/hello
		g++ -std=c++11 DataType/datatype.cpp -o $(OUT_DIR)/datatype
		g++ -std=c++11 BasicIO/basicIO-1.cpp -o $(OUT_DIR)/basicIO-1
		g++ -std=c++11 BasicIO/basicIO-2.cpp -o $(OUT_DIR)/basicIO-2
		g++ -std=c++11 Operator/operator-1.cpp -o $(OUT_DIR)/operator-1
		g++ -std=c++11 Operator/operator-2.cpp -o $(OUT_DIR)/operator-2
		g++ -std=c++11 Operator/operator-3.cpp -o $(OUT_DIR)/operator-3
		g++ -std=c++11 Ifelse/ifelse-1.cpp -o $(OUT_DIR)/ifelse-1
		g++ -std=c++11 Ifelse/ifelse-2.cpp -o $(OUT_DIR)/ifelse-2
		g++ -std=c++11 Switchcase/switchcase-1.cpp -o $(OUT_DIR)/switchcase-1
		g++ -std=c++11 Switchcase/switchcase-2.cpp -o $(OUT_DIR)/switchcase-2
		g++ -std=c++11 Namespace/namespace.cpp -o $(OUT_DIR)/namespace

clean:
		@rm -rf $(OUT_DIR)