# Solution
2022/06/29 released

## Usage
```shell
$ git clone https://github.com/Offliners/RobotLab-Cpp-Training-2022.git
$ cd RobotLab-Cpp-Training-2022/test/sol
$ mkdir build && cd build
$ cmake ..
$ make
$ cd ..

# 執行q1、q2、q4、q5、q6的測試
$ python compare.py
```

執行`compare.py`後，資料夾結構如下:
```shell
sol/
    build/
    output/
    q1/
    q1_testcase/
    q1_output/
    q2/
    q2_testcase/
    q2_output/
    q3/
    q4/
    q4_testcase/
    q4_output/
    q5/
    q5_testcase/
    q5_output/
    q6/
    q6_testcase/
    q6_output/
```

各題解答程式碼都放在`q1` ~ `q6`中，`qx_testcase`為各題的測資，而`qx_output`為程式產生的輸出，最後`output`內會有各題的程式碼與測資結果比較的csv檔案

輸出形式有
* Accept : `AC`
* Wrong Answer : `WA`
* Time Limit Error : `TLE`
* Runtime Error : `RE`

各題的時間限制皆為`1s`，記憶體限制為`1MB`

q3解答 : [Link](q3/q3_ans.md)

解答測試結果 : [Link](result.xlsx)

