# DICOMReader
A C++ library for parsing DICOM file.

##简介
DICOMReader是一个用于解析DICOM文件的轻量级C++库。

注：测试版仅提供Windows平台的动态链接库版本且只能用于C++语言编写的程序。

##安装与使用
Windows版本包含DICOMReader.h、DICOMReader.lib和DICOMReader.dll三个文件。静态链接和动态链接的方法请参考其他DLL的使用方法。

DICOMReader库仅包含DICOMReader一个类，使用时实例化该类并利用该类提供的各个成员方法即可完成DICOM文件的解析。使用结束后需调用close方法关闭DICOMReader中的打开的文件，否则存在内存泄露风险。

##API
###DICOMReader类
####成员方法
* DICOMReader
  * `功能`	构造方法 
  * `语法`
    	* (1)	DICOMReader(void)
    	* (2)	DICOMReader(std::string dictionaryFileURL)
  * `参数`	dictionaryFileURL(2)	数据字典文件的绝对路径
  * `备注`	使用(1)后，DICOMReader对象的数据字典为空，只能解析显示语法的DICOM文件。<br>使用(2)但无法打开数据字典文件或数据字典文件格式错误，该方法会抛出字符串型异常说明错误信息。

* read
  * `功能`	读取DICOM文件并解析
  * `语法`	bool read(std::string fileURL)
  * `参数`	filename	文件的绝对路径
  * `返回值`	DICOM校验成功返回true，否则返回false，表示该文件不是DICOM文件。
  * `备注`	当文件不存在、文件不完整或出现其他解析错误时，该方法会抛出字符串型异常，说明错误信息。
    
* getEndian
  * `功能`	获得解析文件的字节序（端序）
  * `语法`	bool getEndian(void)
  * `参数`	null
  * `返回值`	小端序返回true，大端序返回false。

* getValue
  * `功能`	获得DICOM元素的值
  * `语法`
   	* (1) 	bool getValue(std::string groupNumber, std::string elementNumber, std::string& value)
	* (2)	bool getValue(std::string groupNumber, std::string elementNumber, unsigned short& value)
	* (3)	bool getValue(std::string groupNumber, std::string elementNumber, float& value)
	* (4)	bool getValue(std::string groupNumber, std::string elementNumber, double& value)
	* (5)	bool getValue(std::string groupNumber, std::string elementNumber, unsigned char*& bytes, unsigned long int& bytesLength)
  * `参数`
	* groupNumber(1-5)	组标签
	* elementNumber(1-5)	元素标签
	* value(1)		解析出的字符串型值
	* value(2)		解析出的无符号短整型值
	* value(3)		解析出的单精度浮点型值
	* value(4)		解析出的双精度浮点型值
	* bytes(5)		解析出的字节数组
	* bytesLength(5)	解析出的字节数组的长度
  * `返回值`	数据字典中找到对应元素返回true，否则返回false
  * `备注`	对应元素的值无法以给定类型解析时将抛出字符串型异常。

* close
  * `功能`	关闭DICOMReader对象
  * `语法`	void DICOMReader::close(void)
  * `参数`	null
  * `返回值`	null
  * `备注`	
    释放DICOMReader当前打开文件的字节数组，同时释放DICOMReader对象的数据字典以及其他内部空间。

##许可协议
DICOMReader使用MIT许可证。DICOMReader使用了JsonCpp用于读写JSON类型的数据字典。关于DICOMReader和JsonCpp的详细内容见License文件。
